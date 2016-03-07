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
			return lth.weight > rth.weight; // 为了实现从小到大的顺序
		}

public:
	int index; // 结点位置
	int weight; // 权值
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
	// 打印最短路径
	void print_spaths() const;
	// 求最短路径
	void shortest_paths(const vector<int> Mp,int start_node,int end_node);
	//判断是否是NA
	bool judgeNA(const vector<int> Mp, int start_node, int end_node);

	void DFS(const vector<int> Mp, int start_node, vector<int> &visited);
	void DFSTraver(const vector<int> Mp, int start_node, vector<int> &visited);
	int Locate(int node);
private:
	vector<vector<int> >	 graph;             // 图的数组表示
	int                      node_count;        // 结点个数
	const int                no_edge;           // 无通路
	//const int				 start_node;	    //起始顶点
	//const int                end_node;          // 目的结点
	//vector<int>              s_path_index;      // 最短路径
	//int                      shortest_path;     // 最短路径的长度
	//vector<int>				 MustPass;			//必须经过的点
};

#endif
