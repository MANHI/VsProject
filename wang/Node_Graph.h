#ifndef __NODE_GRAPH_H
#define __NODE_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iterator>
using namespace std;

class node_info
{
public:
	node_info(int i, int w)
		: index(i), weight(w) {}
	node_info()
		: index(0), weight(0) {}
	node_info(const node_info & ni)
		: index(ni.index), weight(ni.weight) {}

	friend
		bool operator < (const node_info& lth, const node_info& rth) {
			return lth.weight > rth.weight; // Ϊ��ʵ�ִ�С�����˳��
		}

public:
	int index; // ���λ��
	int weight; // Ȩֵ
};

class path_info
{
public:
	path_info(): front_index(0), weight(numeric_limits<int>::max()) {}

public:
	int front_index;
	int weight;
};

class ss_shortest_paths
{
public:
	ss_shortest_paths(const vector<vector<int> >& g)
		:no_edge(-1), node_count(g.size()),graph(g){};
	// ��ӡ���·��
	void print_spaths() const;
	// �����·��
	void shortest_paths(const vector<int> Mp,int start_node,int end_node);
	//�ж��Ƿ���NA
	bool judgeNA(const vector<int> Mp, int start_node, int end_node);

	void DFS(const vector<int> Mp, int start_node, vector<int> &visited);
	void DFSTraver(const vector<int> Mp, int start_node, vector<int> &visited);
	int Locate(int node);
private:
	vector<vector<int> >	 graph;             // ͼ�������ʾ
	int                      node_count;        // ������
	const int                no_edge;           // ��ͨ·
	//const int				 start_node;	    //��ʼ����
	//const int                end_node;          // Ŀ�Ľ��
	//vector<int>              s_path_index;      // ���·��
	//int                      shortest_path;     // ���·���ĳ���
	//vector<int>				 MustPass;			//���뾭���ĵ�
};

#endif
