#ifndef __GRAPH_H
#define __GRAPH_H

#include<iostream>
using namespace std;

/******���ڽӱ���ʵ������ͼ******/
#define Max_Node_Num 20
#define ERROR -1;
#define SUCCESS 1;

typedef struct InfoType{
	int tail; 
	int head;
}InfoType;

typedef struct ArcNode{   //���Ľṹ
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;		  //�û������Ϣ��ָ�룬��ͷ��β�Ľڵ�
}ArcNode;

typedef struct VNode{     //����Ľṹ
	int data;
	ArcNode *firstArc;	  //ָ���һ����
}VNode,AdjList[Max_Node_Num];

typedef struct Graph{     //ͼ�Ľṹ
	int vexnum, arcnum;
	AdjList vertices;
}Graph;

int CreateGraph(Graph&,int,int);   
void DestroyGraph(Graph& );
int GetVNodeDegree(Graph &, int, int &, int &);
void DFSGraph(Graph&, int);
void DFSTraver(Graph&);


#endif