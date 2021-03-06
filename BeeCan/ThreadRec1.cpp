#include "Threadrec1.h"
#include <fcntl.h>
#include <math.h>
#include <iostream>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <sys/ioctl.h>
#include <iostream>
using namespace std;

ThreadRec1::ThreadRec1(int argc, char** argv) {
    s = -1;
    running = 1;
    filter = NULL;
    filter_count = 0;
    m_argv = argv;
    m_argc = argc;
}

ThreadRec1::~ThreadRec1() {

}

//线程函数
void ThreadRec1::run() {
    MyRecieve(m_argc, m_argv);
}

void ThreadRec1::stop() {
    running = 0;
}

int ThreadRec1::add_filter(u_int32_t id, u_int32_t mask) {
    filter = (can_filter*) realloc(filter,
            sizeof(struct can_filter) * (filter_count + 1));
    if (!filter)
        return -1;

    filter[filter_count].can_id = id;
    filter[filter_count].can_mask = mask;
    filter_count++;

    printf("id: 0x%08x mask: 0x%08x\n", id, mask);
    return 0;
}

void ThreadRec1::print_usage(char *prg) {
    fprintf(
            stderr,
            "Usage: %s [<can-interface>] [Options]\n"
                "Options:\n"
                " -f, --family=FAMILY\t" "protocol family (default PF_CAN = %d)\n"
                " -t, --type=TYPE\t" "socket type, see man 2 socket (default SOCK_RAW = %d)\n"
                " -p, --protocol=PROTO\t" "CAN protocol (default CAN_RAW = %d)\n"
                "     --filter=id:mask[:id:mask]...\n"
                "\t\t\t" "apply filter\n"
                " -h, --help\t\t" "this help\n"
                " -o <filename>\t\t" "output into filename\n"
                " -d\t\t\t" "daemonize\n"
                "     --version\t\t" "print version information and exit\n",
            prg, PF_CAN, SOCK_RAW, CAN_RAW);
}

int ThreadRec1::MyRecieve(int argc, char **argv) {
    struct can_frame frame;
    struct ifreq ifr;
    struct sockaddr_can addr;
    FILE *out = stdout;
    char *interface = "can1";
    char *optout = NULL;
    char *ptr;
    char buf[BUF_SIZ];
    int family = PF_CAN, type = SOCK_RAW, proto = CAN_RAW;
    int n = 0, err;
    int nbytes, i;
    int opt, optdaemon = 0;
    uint32_t id, mask;
    signal(SIGPIPE, SIG_IGN);
    struct option long_options[] = { { "help", no_argument, 0, 'h' }, {
            "family", required_argument, 0, 'f' }, { "protocol",
            required_argument, 0, 'p' }, { "type", required_argument, 0, 't' },
            { "filter", required_argument, 0, FILTER_OPTION1 }, { "version",
                    no_argument, 0, VERSION_OPTION1 }, { 0, 0, 0, 0 }, };

//	char *ps[5] = {"candump","can1"," "};
    while ((opt = getopt_long(argc, argv, "f:t:p:o:d", long_options, NULL))
            != -1) {
        switch (opt) {
        case 'd':
            optdaemon++;
            break;

        case 'h':
            print_usage(basename(argv[0]));
            exit(0);

        case 'f':
            family = strtoul(optarg, NULL, 0);
            break;

        case 't':
            type = strtoul(optarg, NULL, 0);
            break;

        case 'p':
            proto = strtoul(optarg, NULL, 0);
            break;

        case 'o':
            optout = optarg;
            break;

        case FILTER_OPTION1:
            ptr = optarg;
            while (1) {
                id = strtoul(ptr, NULL, 0);
                ptr = strchr(ptr, ':');
                if (!ptr) {
                    fprintf(stderr,
                            "filter must be applied in the form id:mask[:id:mask]...\n");
                    exit(1);
                }
                ptr++;
                mask = strtoul(ptr, NULL, 0);
                ptr = strchr(ptr, ':');
                add_filter(id, mask);
                if (!ptr)
                    break;
                ptr++;
            }
            break;

        case VERSION_OPTION1:
            printf("candump %s\n", VERSION);
            exit(0);

        default:
            fprintf(stderr, "Unknown option %c\n", opt);
            break;
        }
    }
    if (optind != argc)
        interface = argv[optind];

    printf("interface = %s, family = %d, type = %d, proto = %d\n", interface,
            family, type, proto);

    if ((s = socket(family, type, proto)) < 0) {
        perror("socket");
        return 1;
    }

    addr.can_family = family;
    strncpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));
    if (ioctl(s, SIOCGIFINDEX, &ifr)) {
        perror("ioctl");
        return 1;
    }
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (filter) {
        if (setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, filter,
                filter_count * sizeof(struct can_filter)) != 0) {
            perror("setsockopt");
            exit(1);
        }
    }

    if (optout) {
        out = fopen(optout, "a");
        if (!out) {
            perror("fopen");
            exit ( EXIT_FAILURE);
        }
    }

    while (running) {
        if ((nbytes = read(s, &frame, sizeof(struct can_frame))) < 0) {
            perror("read");
            return 1;
        } else {
            if (frame.can_id & CAN_EFF_FLAG)
                n = snprintf(buf, BUF_SIZ, "<0x%08x> ",
                        frame.can_id & CAN_EFF_MASK);
            else
                n = snprintf(buf, BUF_SIZ, "<0x%03x> ",
                        frame.can_id & CAN_SFF_MASK);

            n += snprintf(buf + n, BUF_SIZ - n, "[%d] ", frame.can_dlc);
            for (i = 0; i < frame.can_dlc; i++) {
                n += snprintf(buf + n, BUF_SIZ - n, "%02x ", frame.data[i]);
            }
            if (frame.can_id & CAN_RTR_FLAG)
                n += snprintf(buf + n, BUF_SIZ - n, "remote request");

            QString qStr = QString(buf);

            do {
                err = fflush(out);
                if (err == -1 && errno == EPIPE) {
                    err = -EPIPE;
                    fclose(out);
                    out = fopen(optout, "a");
                    if (!out)
                        exit ( EXIT_FAILURE);
                }
            } while (err == -EPIPE);

            n = 0;
            emit mesRecv1(buf);

        }
    }

    return 0;
}
