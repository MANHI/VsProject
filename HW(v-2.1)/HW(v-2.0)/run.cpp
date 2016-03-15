#include"run.h"
#include<algorithm>

/*求顶点Obj到所有顶点的最小距离*/
void Run::runDij(Graph &g, int obj,vector<int> pass)  
{
	dist = vector<int>(g.GetNumV(),MAX_INT);
	dist[obj] = 0;						//目标原点距离设为0
	for (auto e : g.GetAdj(obj))		//模拟邻接链表的形式
	{
		int index = e.GetTail();
		if (find(pass.begin(), pass.end(), index) != pass.end()) //如果改点在pass中
		{
			dist[index] = MAX_INT;
			continue;
		}
		PA[index] = e;					//记录路径	
		dist[index] = e.GetCost();		//权值存入
		vistied.push_back(index);				
	}
	while (!vistied.empty())  //集合未计算完
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
				minIndexFirst = tmp;	//留着删除
			}
		}
		vistied.erase(minIndexFirst);

		//看看有没有边需要更新
		for (auto e : g.GetAdj(minIndex))
		{
			if (find(pass.begin(), pass.end(), e.GetTail()) != pass.end()) //如果改点在pass中
				continue;
			if (e.GetCost() + dist[e.GetHead()] < dist[e.GetTail()])
			{
				dist[e.GetTail()] = e.GetCost() + dist[e.GetHead()];
				PA[e.GetTail()] = e;  //上一条边是e
				auto it = find(vistied.begin(), vistied.end(), e.GetTail());
				if (it != vistied.end())
					break;
				else
					vistied.push_back(e.GetTail());
			}
		}
	}
}

/*对每个顶点求Dij*/
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
	Tempass.push_back(start);  //移除起点 更新到终点的路径
	for (auto e : SpecSet)
	{
		runDij(g, e, Tempass);
		addPath(g, e, end);
	}
	Tempass.clear();			//移除终点 更新起点到指定集合顶点的路径
	Tempass.push_back(end);
	runDij(g, start, Tempass);
	for (auto e:SpecSet)
		addPath(g, start, e);
}

/*添加路径*/
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
		Map[s][t].Apath.push_back(PA[t].GetNum());  //节点t的直接相连的边存入
		if (find(SpecSet.begin(), SpecSet.end(), t) != SpecSet.end())
			Map[s][t].SpecNode.push_back(t);			//路径中指定节点插入，以后sk判断
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

/*打印Map信息*/
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

/*判断处理环的路径*/
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

/*运行SK算法*/
void Run::runSk(Graph &g,int start,int end)
{
    const int num = g.GetNumV();		  //顶点个数
	runDijSK(g,g.GetStart(),g.GetEnd());  //运行dij
	int size = g.GetMustPass().size();
//	vector<vector<Path>> D(Map);
	/*第0次迭代*/
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
			//	JudgeCycle(g, Map[s][b], Map[b][end]);  //判断是否有环
				Fsk[0][s][b] = Map[s][b] + Map[b][end];
				cout << "path " << s << " to " << b << " cycle " << Fsk[0][s][b].cost << endl;
			}	
			else
				Fsk[0][s][b].cost = MAX_INT;
		}	
	}
		
	/*1 - n-1 次迭代*/
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
				if (Map[j][k].cost != MAX_INT)  //有路径
				{
					for (auto l : SpecSet)
					{
						if (l == k || l == j)
							continue;
						if (Map[j][k].cost + Fsk[i - 1][k][l].cost < MinCost)
						{
							MinCost = Map[j][k].cost + Fsk[i - 1][k][l].cost;
							minPath = Map[j][k] + Fsk[i - 1][k][l];		//最小路径
							addj = j;
							addk = k;
						}
					}
				}
				else  //D[j][k]无路径
				{
					Fsk[i][j][k].cost = MAX_INT;
					continue;
				}
				/*条件判断 需要再看*/
				if (addk != -1)
				{
					Fsk[i][j][k] = minPath;
					if (Fsk[i][j][k].SpecNode.size() < i)		//sk条件
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

	/*最后一次迭代*/
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

	/*显示结果*/
	cout << "result: " << endl;
	for (auto r : Fsk[size][start][end].Npath)
		cout << r << "->";
	cout << endl;
	cout << Fsk[size][start][end].cost << endl;
}

/*运行SK66算法*/
void Run::runSk66(Graph &g,int start,int end)
{
	runDijSK(g,g.GetStart(), g.GetEnd());		//运行dijALL
	vector<vector<Path>> D(Map);
	for (auto w : g.GetMustPass())
	{
		F[0][w] = D[w][end];
		/*cout << "第 i " << 0 << " 次迭代 " << w << " 的路径 " << endl;
		for (auto i : F[0][w].GetNpath())
			cout << i << "->";
		cout << endl;*/
	}
	vector<int> viSet(g.GetMustPass());
	//viSet.push_back(start);
	int size = g.GetMustPass().size();

	for (int i = 1; i <= size-1; i++)  // 1 -- n-1次迭代
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
					minPath = D[j][k] + F[i - 1][k];	//这一步错了！！！
				//	cout << minPath.GetCost() << " minPath.cost " << endl;
				}
			}
			F[i][j] = minPath;
			cout << "第 i " << i << " 次迭代 " << j << " 的路径 "  << endl;
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