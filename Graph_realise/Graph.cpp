#include"Graph.h"

int FindIndex(Graph &G, const NodeType n)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == n)
			return i;
	}
	return ERROR;
}

/*创建一个图(HR存储弧的权值，用来求最小生成树*/
int CreateGraph(Graph &G,int vexnum,int arcnum,vector<vector<int>> &HR)
{
	int value;
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	for (int i = 0; i < vexnum; i++)   //初始化
	{
		VNode tmp;
		cout << "输入顶点的值 " << endl;
		cin >> value;
		tmp.data = value;
		tmp.firstArc = NULL;
		G.vertices.push_back(tmp);  //构建顶点vector
	}
	for (int i = 0; i < G.arcnum;i++)
	{
		ArcNode *arc = new ArcNode;
		int tail, t;
		int head, h;
		int heigh;
		cout << "intput head and tail and height" << endl;
		cin >> head >> tail >> heigh;; //输入弧头弧尾

		t = FindIndex(G,tail);  //找出顶点值的index
		h = FindIndex(G,head);

		arc->info.head = h;
		arc->info.tail = t;
		arc->info.heigh = heigh;

		HR[h][t] = HR[t][h] = heigh;  //存储权值
		if (tail < 0 || head < 0)
			return ERROR;
		arc->adjvex = h;
		//插入表头到链表中
		arc->nextarc = G.vertices[t].firstArc;
		G.vertices[t].firstArc = arc;
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

/*深度优先遍历图*/
void DFSGraph(Graph& G,int v,vector<bool>& visit)
{
	visit[v] = true;
	cout << G.vertices[v].data << " ";
	ArcNode *arc = G.vertices[v].firstArc;
	while (arc)
	{
		if (visit[arc->adjvex] == false)
			DFSGraph(G, arc->adjvex,visit);
		arc = arc->nextarc;
	}
}

void DFSTraver(Graph& G,vector<bool>& visit)
{
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (visit[i] == false)
			DFSGraph(G, i,visit);
	}
}

/*广度优先遍历图*/
void BFSGraph(Graph& G,vector<bool>& visit)
{
	queue<int> q;
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			cout << G.vertices[i].data << " ";
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

/*求最小生成树(普里姆算法),从第u个节点出发*/
void MiniSpanTree_PRIM(Graph& G, vector<vector<int>> &HR)
{
	int *lowcost = new int[G.vexnum + 1];  //存储权值
	int *closet = new int[G.vexnum + 1];	//存储顶点在U中
	int *used = new int[G.vexnum+1];
 	int i, j, k, min, flag;
	for (i = 0; i < G.vexnum; i++)  //初始化,从顶点0开始
	{
		lowcost[i] = HR[0][i];
		closet[i] = 0;
		used[i] = 0;
	}
	used[0] = 1;
	cout << "最小生成树的边：" << endl;
	for (i = 1; i < G.vexnum; i++)  //O(n^2)
	{
		min = Infinity;
		k = 0;
		for (j = 1; j < G.vexnum; j++)  //求出最小权值
		{
			if (used[j] == 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		if (i == 1)
			flag = 0;
		else
			flag = closet[k];
		used[k] = 1;
		cout << G.vertices[k].data << " " << G.vertices[flag].data << endl;
		for (j = 1; j < G.vexnum; j++)  //更新
		{
			if (HR[k][j] < lowcost[j] && used[j] == 0)
			{
				lowcost[j] = HR[k][j];
				closet[j] = k;
			}
		}
	}
	delete[] lowcost;
	delete[] closet;
	delete[] used;
}