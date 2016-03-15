#ifndef __GRAPH_H
#define __GRAPH_H
#include<vector>
#include<iostream>
#include<sstream>
#include"Arc.h"

using namespace std;

/*����ͼ����*/
class Graph{
public:
	Graph() = default;
	Graph(char **topo, int edg_num, char *demand);  
	void Graph::ShowGraph();
		/*�ҳ��������*/
	void FindNumVert(int f, int t){				
		if (f > t) 
			NumV < f + 1 ? NumV = f + 1 : NumV = NumV;
		else
			NumV < t + 1 ? NumV = t + 1 : NumV = NumV;
	}
	int GetNumV(){ return NumV; }
	int GetStart(){ return start_node; }
	int GetEnd(){ return end_node; }
	vector<int> GetMustPass() { return MustPass; }
	vector<Arc> GetAdj(int i) { return graph[i];}

private:
	int NumV;					//�������
	vector<vector<Arc>>	graph;	//ͼ�����ӱ�
	vector<int> MustPass;		//�ؾ��Ķ���
	int start_node;		
	int end_node;		
};
#endif