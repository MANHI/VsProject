#include"Graph.h"

bool visit[Max_Node_Num];

/*创建一个图*/
int CreateGraph(Graph &G,int vexnum,int arcnum)
{
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	for (int i = 0; i < vexnum; i++)   //初始化
	{
		G.vertices[i].data = i;    //先简单的,后续可以输入data值
		G.vertices[i].firstArc = NULL;
	}
	for (int i = 0; i < arcnum; i++)
	{
		ArcNode *arc = new ArcNode;
		int tail;
		int head;
		cout << "intput head and tail" << endl;
		cin >> head >> tail;  //输入弧头弧尾
		if (tail < 0 || head < 0)
			return ERROR;
		arc->adjvex = head;
		//插入表头到链表中
		arc->nextarc = G.vertices[tail].firstArc;
		G.vertices[tail].firstArc = arc;
	}
}

/*销毁一个图*/
void DestroyGraph(Graph& G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		ArcNode *tmp = new ArcNode;
		tmp = G.vertices[i].firstArc;
		while (tmp)
		{
			ArcNode *p = tmp;
			tmp = tmp->nextarc;
			delete p;
		}
		G.vertices[i].firstArc = NULL;
	}
	G.arcnum = 0;
	G.vexnum = 0;
}

/*得到顶点V的度*/
int GetVNodeDegree(Graph &G, int v,int &indegree, int &outdegree)
{
	if (v < 0)   //这里简单的代表顶点不存在图G中
		return 0;
	ArcNode *tmp = G.vertices[v].firstArc;
	while (tmp)
	{
		outdegree++;
		tmp = tmp->nextarc;
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		tmp = G.vertices[i].firstArc;
		while (tmp)
		{
			if (tmp->adjvex == v)
				indegree++;
			tmp = tmp->nextarc;
		}
		
	}
	return outdegree + indegree;
}

void DFSGraph(Graph& G,int v)
{
	visit[v] = true;
	cout << v << " ";
	ArcNode *arc = G.vertices[v].firstArc;
	while (arc)
	{
		if (visit[arc->adjvex] == false)
			DFSGraph(G, arc->adjvex);
		arc = arc->nextarc;
	}
}

void DFSTraver(Graph& G)
{
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (visit[i] == false)
			DFSGraph(G, i);
	}
}

void BFSGraph(Graph& G)
{
	queue<int> q;
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			cout << i << " ";
			q.push(i);
			ArcNode *arc = G.vertices[i].firstArc;
			while (arc)
			{
				if (!visit[i])
				{
					visit[i] = true;
					cout << i << " ";
					q.pop();
				}
				arc = arc->nextarc;
			}
		}
	}
}