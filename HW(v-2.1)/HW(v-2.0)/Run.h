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
		for (int i = 0; i < g.GetNumV(); i++)		//��Ϊ���ֳ�ʼ��
		{
			vector<int> node;
			Path tmp(0, 0, MAX_INT, node, node,node);
			vector<Path> t;
			for (int j = 0; j < g.GetNumV(); j++)
				t.push_back(tmp);
			Map.push_back(t);
			F.push_back(t);  //��ʼ��Fsk
		}
		for (int i = 0; i <= g.GetNumV(); i++)
			Fsk.push_back(F);
	}

	void runDij(Graph &g, int s, vector<int> pass);
	void Dij(Graph &g, int s,vector<int> pass);		//�Լ�д��Dij����,passΪ�����Ķ���
	void runSk(Graph &g, int start, int end);
	void runSk66(Graph &g, int start, int end);
	void ShowMap(Graph &g);
	//void runDijSk66(Graph &g, int start, int end);
	void runDijSK(Graph &g, int start, int end);
	void addPath(Graph &g, int s, int t);
	void ShowResult(Graph &g);
	void JudgeCycle(Graph &g,Path &lth, Path &rth);		//����

private:
	vector<vector<Path>> Map;	//����2����·����ͼ
	vector<int> dist;	//Ŀ�궥�㵽���ⶥ�����С����
	vector<int> SpecSet;		//ָ������ļ���
	vector<Arc> PA;				//��¼·��
	list<int> vistied;			//�������
	vector<vector<Path>> F;		 //SK66��¼
	vector<vector<vector<Path>>> Fsk;	//sk������¼
};
#endif
