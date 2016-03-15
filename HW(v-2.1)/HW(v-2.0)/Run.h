#ifndef __RUN_H
#define __RUN_H

#include "Graph.h"
#include "Arc.h"
#include "Path.h"
#include <list>
#define MAX_INT 9999

class Run{
public:
	Run() = default;
	Run(Graph g) : dist(vector<int>(g.GetNumV())),
		SpecSet(g.GetMustPass()),
		PA(vector<Arc>(g.GetNumV())){
		for (int i = 0; i < g.GetNumV(); i++)		//改为这种初始化
		{
			vector<int> node;
			Path tmp(0, 0, MAX_INT, node, node,node);
			vector<Path> t;
			for (int j = 0; j < g.GetNumV(); j++)
				t.push_back(tmp);
			Map.push_back(t);
			F.push_back(t);  //初始化Fsk
		}
		for (int i = 0; i <= g.GetNumV(); i++)
			Fsk.push_back(F);
	}

	void runDij(Graph &g, int s, vector<int> pass);
	void Dij(Graph &g, int s,vector<int> pass);		//自己写的Dij函数,pass为跳过的顶点
	void runSk(Graph &g, int start, int end);
	void runSk66(Graph &g, int start, int end);
	void ShowMap(Graph &g);
	//void runDijSk66(Graph &g, int start, int end);
	void runDijSK(Graph &g, int start, int end);
	void addPath(Graph &g, int s, int t);
	void ShowResult(Graph &g);
	void JudgeCycle(Graph &g,Path &lth, Path &rth);		//处理环

private:
	vector<vector<Path>> Map;	//任意2点间的路径地图
	vector<int> dist;	//目标顶点到任意顶点的最小距离
	vector<int> SpecSet;		//指定顶点的集合
	vector<Arc> PA;				//记录路径
	list<int> vistied;			//标记数组
	vector<vector<Path>> F;		 //SK66记录
	vector<vector<vector<Path>>> Fsk;	//sk迭代记录
};
#endif
