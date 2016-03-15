#include"run.h"
#include<algorithm>

/*�󶥵�Obj�����ж������С����*/
void Run::runDij(Graph &g, int obj,vector<int> pass)  
{
	dist = vector<int>(g.GetNumV(),MAX_INT);
	dist[obj] = 0;						//Ŀ��ԭ�������Ϊ0
	for (auto e : g.GetAdj(obj))		//ģ���ڽ��������ʽ
	{
		int index = e.GetTail();
		if (find(pass.begin(), pass.end(), index) != pass.end()) //����ĵ���pass��
		{
			dist[index] = MAX_INT;
			continue;
		}
		PA[index] = e;					//��¼·��	
		dist[index] = e.GetCost();		//Ȩֵ����
		vistied.push_back(index);				
	}
	while (!vistied.empty())  //����δ������
	{
		int Mindist = MAX_INT;
		auto minIndexFirst = vistied.begin();
		int minIndex = 0;

		for (auto tmp = minIndexFirst; tmp != vistied.end(); tmp++)
		{
			if (dist[*tmp] < Mindist)
			{
				Mindist = dist[*tmp];
				minIndex = *tmp;
				minIndexFirst = tmp;	//����ɾ��
			}
		}
		vistied.erase(minIndexFirst);

		//������û�б���Ҫ����
		for (auto e : g.GetAdj(minIndex))
		{
			if (find(pass.begin(), pass.end(), e.GetTail()) != pass.end()) //����ĵ���pass��
				continue;
			if (e.GetCost() + dist[e.GetHead()] < dist[e.GetTail()])
			{
				dist[e.GetTail()] = e.GetCost() + dist[e.GetHead()];
				PA[e.GetTail()] = e;  //��һ������e
				auto it = find(vistied.begin(), vistied.end(), e.GetTail());
				if (it != vistied.end())
					break;
				else
					vistied.push_back(e.GetTail());
			}
		}
	}
}

/*��ÿ��������Dij*/
void Run::runDijSK(Graph &g, int start, int end)
{
	vector<int> Tempass;
	Tempass.push_back(start);
	Tempass.push_back(end);
	for (auto e : SpecSet)		//VS-VS
	{
		runDij(g, e, Tempass);
		for (auto w : SpecSet)
		{
			addPath(g, e, w);
		}
	}
	Tempass.clear();
	Tempass.push_back(start);  //�Ƴ���� ���µ��յ��·��
	for (auto e : SpecSet)
	{
		runDij(g, e, Tempass);
		addPath(g, e, end);
	}
	Tempass.clear();			//�Ƴ��յ� ������㵽ָ�����϶����·��
	Tempass.push_back(end);
	runDij(g, start, Tempass);
	for (auto e:SpecSet)
		addPath(g, start, e);
}

/*���·��*/
void Run::addPath(Graph &g, int s, int t)
{
	dist[s] = MAX_INT;

	Map[s][t].from = s;
	Map[s][t].to = t;
	Map[s][t].cost = dist[t];

	int pre = t;
	if (dist[t] != MAX_INT && s != t)
	{
		Map[s][t].Npath.push_back(t);
		Map[s][t].Apath.push_back(PA[t].GetNum());  //�ڵ�t��ֱ�������ıߴ���
		if (find(SpecSet.begin(), SpecSet.end(), t) != SpecSet.end())
			Map[s][t].SpecNode.push_back(t);			//·����ָ���ڵ���룬�Ժ�sk�ж�
		while (PA[pre].GetHead() != s)
		{
			Map[s][t].Npath.push_back(PA[pre].GetHead());
			pre = PA[pre].GetHead();
			if (find(SpecSet.begin(), SpecSet.end(), pre) != SpecSet.end())
				Map[s][t].SpecNode.push_back(pre);		//ADD
			Map[s][t].Apath.push_back(PA[pre].GetNum());
		}
	}  
	if (find(SpecSet.begin(), SpecSet.end(), s) != SpecSet.end())
		Map[s][t].SpecNode.push_back(s);		//ADD
	Map[s][t].Npath.push_back(s);
	reverse(Map[s][t].Npath.begin(), Map[s][t].Npath.end());
	reverse(Map[s][t].Apath.begin(), Map[s][t].Apath.end());
	reverse(Map[s][t].SpecNode.begin(), Map[s][t].SpecNode.end());
} 

/*��ӡMap��Ϣ*/
void Run::ShowMap(Graph &g)
{
	vector<int> t(g.GetMustPass());
	t.push_back(g.GetStart());
	t.push_back(g.GetEnd());
	for (auto e : t)
	{
		for (auto w : t)
		{
			if (e != w)
			{
				vector<int> node = Map[e][w].GetNpath();
				vector<int> arc = Map[e][w].GetApath();
				if (node.size() == 0 || arc.size() == 0)
				{
					//cout << "NO PATH" << endl;
					continue;
				}
				cout << "from " << e << " to " << w << endl;
				cout << "node path" << endl;
				for (auto n : node)
					cout << n << "->";
				cout << endl;
				cout << "arc path" << endl;
				for (auto a : arc)
					cout << a << "|";
				cout << endl;
			}
		}
	}
}

/*�жϴ�����·��*/
void Run::JudgeCycle(Graph &g,Path &lth, Path &rth)
{
	vector<int> PassCycle;
	if (lth.to == rth.from)
	{
		for (auto c : rth.SpecNode)
		{
			if (find(lth.SpecNode.begin(), lth.SpecNode.end(), c) != lth.SpecNode.end() && c != lth.to)
			{
				PassCycle.push_back(c);
			}
		}
		if (PassCycle.size() != 0)
		{
			runDij(g, rth.from, PassCycle);
			Map[rth.from][rth.to].Apath.clear(); //Map update
			Map[rth.from][rth.to].Npath.clear();
			Map[rth.from][rth.to].cost = MAX_INT;
			addPath(g, rth.from, rth.to);
			Fsk[0][rth.from][rth.to] = Map[rth.from][rth.to];
			/*if (rth.from == 2 && rth.to == 1)
			{
				cout << Map[2][1].cost << endl;
				for (auto c : Map[2][1].Npath)
					cout << c << "->";
				cout << endl;
			}*/
		}
		else
			return;
	}
}

/*����SK�㷨*/
void Run::runSk(Graph &g,int start,int end)
{
    const int num = g.GetNumV();		  //�������
	runDijSK(g,g.GetStart(),g.GetEnd());  //����dij
	int size = g.GetMustPass().size();
//	vector<vector<Path>> D(Map);
	/*��0�ε���*/
	for (auto s : SpecSet)
	{
		for (auto b : SpecSet)
		{
			if (b == s)
				continue;
			if (Map[s][b].cost != MAX_INT)
			{
				/*for (auto t : D[b][end].SpecNode)
				{
					if (t == b)
						continue;
					if (find(D[s][b].SpecNode.begin(), D[s][b].SpecNode.end(), t) != D[s][b].SpecNode.end())
						
				}*/
			//	JudgeCycle(g, Map[s][b], Map[b][end]);  //�ж��Ƿ��л�
				Fsk[0][s][b] = Map[s][b] + Map[b][end];
				cout << "path " << s << " to " << b << " cycle " << Fsk[0][s][b].cost << endl;
			}	
			else
				Fsk[0][s][b].cost = MAX_INT;
		}	
	}
		
	/*1 - n-1 �ε���*/
	for (int i = 1; i <= size - 1; i++)
	{
		for (auto j : SpecSet)
		{	
			for (auto k : SpecSet)
			{
				int MinCost = MAX_INT;
				Path minPath;
				int addj = -1;
				int addk = -1;
				if (j == k)
					continue;	
				if (Map[j][k].cost != MAX_INT)  //��·��
				{
					for (auto l : SpecSet)
					{
						if (l == k || l == j)
							continue;
						if (Map[j][k].cost + Fsk[i - 1][k][l].cost < MinCost)
						{
							MinCost = Map[j][k].cost + Fsk[i - 1][k][l].cost;
							minPath = Map[j][k] + Fsk[i - 1][k][l];		//��С·��
							addj = j;
							addk = k;
						}
					}
				}
				else  //D[j][k]��·��
				{
					Fsk[i][j][k].cost = MAX_INT;
					continue;
				}
				/*�����ж� ��Ҫ�ٿ�*/
				if (addk != -1)
				{
					Fsk[i][j][k] = minPath;
					if (Fsk[i][j][k].SpecNode.size() < i)		//sk����
						Fsk[i][j][k].cost = MAX_INT;
					if (Fsk[i][j][k].cost == MAX_INT && Fsk[i - 1][j][k].SpecNode.size() >= size - 1)
						Fsk[i][j][k] = Fsk[i - 1][j][k];
					else if (Fsk[i][j][k].SpecNode.size() >= size &&\
						Fsk[i - 1][j][k].SpecNode.size() >=size &&\
						Fsk[i - 1][j][k].cost < Fsk[i][j][k].cost)
						Fsk[i][j][k] = Fsk[i - 1][j][k];
				}
				else if (Fsk[i-1][j][k].SpecNode.size() >= i+1)
					Fsk[i][j][k] = Fsk[i - 1][j][k];
				else
					Fsk[i][j][k].cost = MAX_INT;
			}
		}
	}

	/*���һ�ε���*/
	Path minPath;
	int minCost = MAX_INT;
	for (auto m : SpecSet)
	{
		for (auto n : SpecSet)
		{
			if (n == m)
				continue;
			if (Map[start][m].cost + Fsk[size - 1][m][n].cost < minCost)
			{
				minCost = Map[start][m].cost + Fsk[size - 1][m][n].cost;
				minPath = Map[start][m] + Fsk[size - 1][m][n];
			}
		}
		Fsk[size][start][end] = minPath;
	}

	/*��ʾ���*/
	cout << "result: " << endl;
	for (auto r : Fsk[size][start][end].Npath)
		cout << r << "->";
	cout << endl;
	cout << Fsk[size][start][end].cost << endl;
}

/*����SK66�㷨*/
void Run::runSk66(Graph &g,int start,int end)
{
	runDijSK(g,g.GetStart(), g.GetEnd());		//����dijALL
	vector<vector<Path>> D(Map);
	for (auto w : g.GetMustPass())
	{
		F[0][w] = D[w][end];
		/*cout << "�� i " << 0 << " �ε��� " << w << " ��·�� " << endl;
		for (auto i : F[0][w].GetNpath())
			cout << i << "->";
		cout << endl;*/
	}
	vector<int> viSet(g.GetMustPass());
	//viSet.push_back(start);
	int size = g.GetMustPass().size();

	for (int i = 1; i <= size-1; i++)  // 1 -- n-1�ε���
	{
		for (auto j : viSet)
		{
			int min = MAX_INT;
			Path minPath;
			for (auto k : g.GetMustPass())
			{
				if (D[j][k].GetCost() + F[i - 1][k].GetCost() < min && j != k)
				{
					min = D[j][k].GetCost() + F[i - 1][k].GetCost();
			//		cout << D[j][k].GetCost() << " D[j][k].cost " << j << " " << k << endl;
					//cout << Map[j][k].GetCost() << " M[j][k].cost " << endl;
					minPath = D[j][k] + F[i - 1][k];	//��һ�����ˣ�����
				//	cout << minPath.GetCost() << " minPath.cost " << endl;
				}
			}
			F[i][j] = minPath;
			cout << "�� i " << i << " �ε��� " << j << " ��·�� "  << endl;
			for (auto i : F[i][j].GetNpath())
				cout << i << "->";
			cout << endl;
		}
	}
	int minCost = MAX_INT;
	Path minPath;
	
	for (auto i : g.GetMustPass())
	{
		if (D[start][i].GetCost() + F[size-1][i].GetCost() < minCost)
		{
			minCost = D[start][i].GetCost() + F[size - 1][i].GetCost();
			minPath = D[start][i] + F[size - 1][i];
		}
	}
	F[size][start] = minPath;
	cout << "size" << g.GetMustPass().size() << endl;
}

void Run::ShowResult(Graph &g)
{
	int size = g.GetMustPass().size();
	cout << size << endl;
	for (auto i : F[size][g.GetStart()].GetApath())
		cout << i << "|";
	cout << endl;
	for (auto i : F[size][g.GetStart()].GetNpath())
		cout << i << ",";
	cout << endl;
	cout << "cost is: " << F[size][g.GetStart()].GetCost() << endl;
}