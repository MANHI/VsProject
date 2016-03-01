#include"Graph.h"
int main()
{
	int vexnum, arcnum;
	vector<bool> visit;
	vector<vector<int>> HR;  //�洢Ȩֵ
	Graph G;
	cout << "vexnum and arcnum" << endl;
	cin >> vexnum >> arcnum;
	for (int i = 0; i < vexnum; i++)
		visit.push_back(false);
	for (int i = 0; i < vexnum; i++)
	{
		vector<int> t;
		for (int j = 0; j < vexnum; j++)
			t.push_back(Infinity);
		HR.push_back(t);
	}
	CreateGraph(G, vexnum,arcnum,HR);
	cout << "Traver" << endl;
	BFSGraph(G,visit);
	cout << "MiniSpanTree: " << endl;
	MiniSpanTree_PRIM(G,HR);
	return 0;
}