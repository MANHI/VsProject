#ifndef __GRAPH_H
#define __GRAPH_H

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/******���ڽӱ���ʵ������ͼ******/
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
	int heigh;		//Ȩ
}ArcInfo;

class ArcNode{   //���Ľṹ
public:
	ArcType adjvex;
	ArcNode *nextarc;
	ArcInfo info;		  //�û������Ϣ��ָ��
};

class VNode{     //����Ľṹ
public:
	NodeType data;
	ArcNode *firstArc;	  //ָ���һ����
};

class Graph{     //ͼ�Ľṹ
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
void MiniSpanTree_PRIM(Graph&,vector<vector<int>> &);  //����ͼ
 

#endif