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

/*����һ��ͼ(HR�洢����Ȩֵ����������С������*/
int CreateGraph(Graph &G,int vexnum,int arcnum,vector<vector<int>> &HR)
{
	int value;
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	for (int i = 0; i < vexnum; i++)   //��ʼ��
	{
		VNode tmp;
		cout << "���붥���ֵ " << endl;
		cin >> value;
		tmp.data = value;
		tmp.firstArc = NULL;
		G.vertices.push_back(tmp);  //��������vector
	}
	for (int i = 0; i < G.arcnum;i++)
	{
		ArcNode *arc = new ArcNode;
		int tail, t;
		int head, h;
		int heigh;
		cout << "intput head and tail and height" << endl;
		cin >> head >> tail >> heigh;; //���뻡ͷ��β

		t = FindIndex(G,tail);  //�ҳ�����ֵ��index
		h = FindIndex(G,head);

		arc->info.head = h;
		arc->info.tail = t;
		arc->info.heigh = heigh;

		HR[h][t] = HR[t][h] = heigh;  //�洢Ȩֵ
		if (tail < 0 || head < 0)
			return ERROR;
		arc->adjvex = h;
		//�����ͷ��������
		arc->nextarc = G.vertices[t].firstArc;
		G.vertices[t].firstArc = arc;
	}
}

/*����һ��ͼ*/
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

/*�õ�����V�Ķ�*/
int GetVNodeDegree(Graph &G, int v,int &indegree, int &outdegree)
{
	if (v < 0)   //����򵥵Ĵ����㲻����ͼG��
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

/*������ȱ���ͼ*/
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

/*������ȱ���ͼ*/
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

/*����С������(����ķ�㷨),�ӵ�u���ڵ����*/
void MiniSpanTree_PRIM(Graph& G, vector<vector<int>> &HR)
{
	int *lowcost = new int[G.vexnum + 1];  //�洢Ȩֵ
	int *closet = new int[G.vexnum + 1];	//�洢������U��
	int *used = new int[G.vexnum+1];
 	int i, j, k, min, flag;
	for (i = 0; i < G.vexnum; i++)  //��ʼ��,�Ӷ���0��ʼ
	{
		lowcost[i] = HR[0][i];
		closet[i] = 0;
		used[i] = 0;
	}
	used[0] = 1;
	cout << "��С�������ıߣ�" << endl;
	for (i = 1; i < G.vexnum; i++)  //O(n^2)
	{
		min = Infinity;
		k = 0;
		for (j = 1; j < G.vexnum; j++)  //�����СȨֵ
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
		for (j = 1; j < G.vexnum; j++)  //����
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