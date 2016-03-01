#ifndef __GRAPH_H
#define __GRAPH_H

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/******用邻接表来实现有向图******/
#define ERROR -1
#define SUCCESS 1
#define MAX_VEX_NUM 20
#define Infinity 65535

using ArcType = int;
using NodeType = int;
using VRType = int;

typedef struct ArcInfo
{
	NodeType tail;
	NodeType head;
	int heigh;		//权
}ArcInfo;

class ArcNode{   //弧的结构
public:
	ArcType adjvex;
	ArcNode *nextarc;
	ArcInfo info;		  //该弧相关信息的指针
};

class VNode{     //顶点的结构
public:
	NodeType data;
	ArcNode *firstArc;	  //指向第一条弧
};

class Graph{     //图的结构
public:
	int vexnum;
	int arcnum;
	vector<VNode> vertices;
};

int  FindIndex(Graph &G, const NodeType n);
int  CreateGraph(Graph&, int, int ,vector<vector<int>> &);
void DestroyGraph(Graph& );
int  GetVNodeDegree(Graph &, int, int &, int &);
void DFSGraph(Graph&, int, vector<bool>&);
void DFSTraver(Graph&, vector<bool>&);
void BFSGraph(Graph&, vector<bool>&);
void MiniSpanTree_PRIM(Graph&,vector<vector<int>> &);  //无向图
 

#endif