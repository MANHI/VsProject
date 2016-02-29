/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Nov 17 11:38:29 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpen;
    QAction *actSave;
    QAction *actQuit;
    QAction *actRun;
    QAction *actStop;
    QWidget *centralWidget;
    QLabel *labeljishe;
    QLabel *labeljishe_2;
    QLabel *labeljishe_3;
    QLabel *labeljishe_4;
    QPushButton *pBSend;
    QTextEdit *textEdit;
    QLabel *labelTime;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lEPl;
    QLineEdit *lEZkb;
    QLineEdit *lEZq;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QLabel *DisPl;
    QLabel *DisZkb;
    QLabel *DisZqgs;
    QLabel *DisJg;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *lb_canshow;
    QLabel *label_22;
    QLabel *label_8;
    QLabel *label_3;
    QComboBox *cBHz;
    QLabel *label_2;
    QLabel *lbNode1;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_7;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lEYcsj;
    QLineEdit *lECjcs;
    QLineEdit *lEJg;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_11;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuEdit;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 501);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        actQuit = new QAction(MainWindow);
        actQuit->setObjectName(QString::fromUtf8("actQuit"));
        actRun = new QAction(MainWindow);
        actRun->setObjectName(QString::fromUtf8("actRun"));
        actStop = new QAction(MainWindow);
        actStop->setObjectName(QString::fromUtf8("actStop"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labeljishe = new QLabel(centralWidget);
        labeljishe->setObjectName(QString::fromUtf8("labeljishe"));
        labeljishe->setGeometry(QRect(10, 10, 101, 21));
        QFont font;
        font.setPointSize(12);
        labeljishe->setFont(font);
        labeljishe_2 = new QLabel(centralWidget);
        labeljishe_2->setObjectName(QString::fromUtf8("labeljishe_2"));
        labeljishe_2->setGeometry(QRect(290, 12, 101, 21));
        labeljishe_2->setFont(font);
        labeljishe_3 = new QLabel(centralWidget);
        labeljishe_3->setObjectName(QString::fromUtf8("labeljishe_3"));
        labeljishe_3->setGeometry(QRect(10, 210, 101, 21));
        labeljishe_3->setFont(font);
        labeljishe_4 = new QLabel(centralWidget);
        labeljishe_4->setObjectName(QString::fromUtf8("labeljishe_4"));
        labeljishe_4->setGeometry(QRect(590, 10, 101, 21));
        labeljishe_4->setFont(font);
        pBSend = new QPushButton(centralWidget);
        pBSend->setObjectName(QString::fromUtf8("pBSend"));
        pBSend->setGeometry(QRect(410, 360, 80, 26));
        QFont font1;
        font1.setPointSize(11);
        pBSend->setFont(font1);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 240, 251, 201));
        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(610, 430, 161, 21));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 161, 161));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lEPl = new QLineEdit(layoutWidget);
        lEPl->setObjectName(QString::fromUtf8("lEPl"));

        verticalLayout_2->addWidget(lEPl);

        lEZkb = new QLineEdit(layoutWidget);
        lEZkb->setObjectName(QString::fromUtf8("lEZkb"));

        verticalLayout_2->addWidget(lEZkb);

        lEZq = new QLineEdit(layoutWidget);
        lEZq->setObjectName(QString::fromUtf8("lEZq"));

        verticalLayout_2->addWidget(lEZq);


        horizontalLayout->addLayout(verticalLayout_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(290, 240, 67, 101));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);

        verticalLayout_6->addWidget(label_13);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        verticalLayout_6->addWidget(label_15);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        verticalLayout_6->addWidget(label_16);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        verticalLayout_6->addWidget(label_14);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(370, 240, 61, 101));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        DisPl = new QLabel(layoutWidget2);
        DisPl->setObjectName(QString::fromUtf8("DisPl"));

        verticalLayout_7->addWidget(DisPl);

        DisZkb = new QLabel(layoutWidget2);
        DisZkb->setObjectName(QString::fromUtf8("DisZkb"));

        verticalLayout_7->addWidget(DisZkb);

        DisZqgs = new QLabel(layoutWidget2);
        DisZqgs->setObjectName(QString::fromUtf8("DisZqgs"));

        verticalLayout_7->addWidget(DisZqgs);

        DisJg = new QLabel(layoutWidget2);
        DisJg->setObjectName(QString::fromUtf8("DisJg"));

        verticalLayout_7->addWidget(DisJg);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(440, 240, 23, 101));
        verticalLayout_9 = new QVBoxLayout(layoutWidget3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font2;
        font2.setPointSize(10);
        label_17->setFont(font2);

        verticalLayout_9->addWidget(label_17);

        label_20 = new QLabel(layoutWidget3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);

        verticalLayout_9->addWidget(label_20);

        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);

        verticalLayout_9->addWidget(label_19);

        label_18 = new QLabel(layoutWidget3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font2);

        verticalLayout_9->addWidget(label_18);

        lb_canshow = new QLabel(centralWidget);
        lb_canshow->setObjectName(QString::fromUtf8("lb_canshow"));
        lb_canshow->setGeometry(QRect(680, 40, 61, 16));
        lb_canshow->setFont(font2);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(590, 40, 58, 15));
        label_22->setFont(font2);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 150, 21, 31));
        label_8->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 110, 21, 31));
        label_3->setFont(font1);
        cBHz = new QComboBox(centralWidget);
        cBHz->setObjectName(QString::fromUtf8("cBHz"));
        cBHz->setGeometry(QRect(180, 60, 82, 25));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 70, 58, 15));
        lbNode1 = new QLabel(centralWidget);
        lbNode1->setObjectName(QString::fromUtf8("lbNode1"));
        lbNode1->setGeometry(QRect(680, 70, 58, 15));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(290, 40, 67, 161));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        verticalLayout_3->addWidget(label_10);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_3->addWidget(label_9);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(360, 40, 91, 161));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        lEYcsj = new QLineEdit(widget1);
        lEYcsj->setObjectName(QString::fromUtf8("lEYcsj"));

        verticalLayout_4->addWidget(lEYcsj);

        lECjcs = new QLineEdit(widget1);
        lECjcs->setObjectName(QString::fromUtf8("lECjcs"));

        verticalLayout_4->addWidget(lECjcs);

        lEJg = new QLineEdit(widget1);
        lEJg->setObjectName(QString::fromUtf8("lEJg"));

        verticalLayout_4->addWidget(lEJg);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(460, 40, 31, 161));
        verticalLayout_5 = new QVBoxLayout(widget2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        verticalLayout_5->addWidget(label_4);

        label_12 = new QLabel(widget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        verticalLayout_5->addWidget(label_12);

        label_11 = new QLabel(widget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        verticalLayout_5->addWidget(label_11);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 784, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addAction(actOpen);
        menu->addAction(actSave);
        menu->addAction(actQuit);
        menu_3->addAction(actRun);
        menu_3->addAction(actStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actOpen->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\351\205\215\347\275\256\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        actSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        actQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        actRun->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        actStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        labeljishe->setText(QApplication::translate("MainWindow", " \345\237\272\346\234\254\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        labeljishe_2->setText(QApplication::translate("MainWindow", "\351\253\230\347\272\247\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        labeljishe_3->setText(QApplication::translate("MainWindow", " \345\256\236\346\227\266\346\263\242\345\275\242", 0, QApplication::UnicodeUTF8));
        labeljishe_4->setText(QApplication::translate("MainWindow", "CAN\346\216\247\345\210\266\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        pBSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        labelTime->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\351\242\221      \347\216\207", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\345\215\240 \347\251\272 \346\257\224", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\351\242\221      \347\216\207", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "\345\215\240 \347\251\272 \346\257\224", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\237\344\270\252\346\225\260", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\351\227\264      \351\232\224", 0, QApplication::UnicodeUTF8));
        DisPl->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        DisZkb->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        DisZqgs->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        DisJg->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "HZ", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "g", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "ms", 0, QApplication::UnicodeUTF8));
        lb_canshow->setText(QApplication::translate("MainWindow", "CANxx", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "CAN\347\272\277\350\267\257", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "g", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        cBHz->clear();
        cBHz->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "HZ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "KHZ", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "\350\212\202\347\202\2711", 0, QApplication::UnicodeUTF8));
        lbNode1->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\345\273\266\350\277\237\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\345\210\272\346\277\200\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\351\227\264      \351\232\224", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "g", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
