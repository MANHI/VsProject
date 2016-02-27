#ifndef __GRAPH_H
#define __GRAPH_H

#include<iostream>
using namespace std;

/******用邻接表来实现有向图******/
#define Max_Node_Num 20
#define ERROR -1;
#define SUCCESS 1;

typedef struct InfoType{
	int tail; 
	int head;
}InfoType;

typedef struct ArcNode{   //弧的结构
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;		  //该弧相关信息的指针，弧头弧尾的节点
}ArcNode;

typedef struct VNode{     //顶点的结构
	int data;
	ArcNode *firstArc;	  //指向第一条弧
}VNode,AdjList[Max_Node_Num];

typedef struct Graph{     //图的结构
	int vexnum, arcnum;
	AdjList vertices;
}Graph;

int CreateGraph(Graph&,int,int);   
void DestroyGraph(Graph& );
int GetVNodeDegree(Graph &, int, int &, int &);
void DFSGraph(Graph&, int);
void DFSTraver(Graph&);


#endif