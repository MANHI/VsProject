#include"Graph.h"
int main()
{
	int vexnum, arcnum;
	Graph G;
	cout << "vexnum and arcnum" << endl;
	cin >> vexnum >> arcnum;
	CreateGraph(G, vexnum, arcnum);
	cout << "DfsTraver" << endl;
	BFSGraph(G);
	return 0;
}