#include "Graph.h"

Graph::Graph(char **topo, int edg_num, char *demand)
{
	for (int i = 0; i < 600; i++)
	{
		vector<Arc> a;
		graph.push_back(a);
	}

	int index, from, to, cost, start, end, tmp;
	char c;
	for (int i = 0; i < edg_num; i++)
	{
		int index, from, to, cost;
		stringstream ss(topo[i]);
		ss >> index >> c >> from >> c >> to >> c >> cost;
		Arc arcs(index, from, to, cost);
		graph[from].push_back(arcs);    //将边加入图的邻接表中
		FindNumVert(from, to);			//找出节点的总数
	}
	stringstream sdemand(demand);
	sdemand >> start_node >> c >> end_node >> c;   //存入指定的顶点集合
	do{
		sdemand >> tmp;
		MustPass.push_back(tmp);
	} while (sdemand >> c);
}

void Graph::ShowGraph(){
	cout << "Print Graph Information:" << endl;
	cout << "Grpah have " << NumV << " node " << endl;
	cout << "each arc show :" << endl;
	for (int i = 0; i < NumV; i++)
	{
		for (auto c : graph[i])
			cout << c.GetNum() << " " << c.GetHead() << " " << c.GetTail() << " " << c.GetCost() << endl;
	}
	cout << "MustPass node show :" << endl;
	for (auto c : MustPass)
		cout << c << "|";
	cout << endl;
}