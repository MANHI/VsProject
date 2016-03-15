#ifndef __PATH_H
#define __PATH_H
#include<vector>
#include<iostream>
using namespace std;

/*����·������*/
class Path{
public:
	Path() = default;
	Path(int s, int t, int c, vector<int> &n, vector<int> &a,vector<int> &b)
		:from(s), to(t), cost(c), Npath(n), Apath(a),SpecNode(b){};
	Path& operator=(Path &rth);
	Path operator+ (Path &rth);

	vector<int>& GetNpath(){ return Npath; }
	vector<int>& GetApath(){ return Apath; }
	int GetFrom() { return from; }
	int GetTo(){ return to; }
	int GetCost(){ return cost; }
	void SetCost(int i){ cost = i; }

	/*��ʱ�������������Ϊpublic*/
	vector<int> SpecNode;		//·����ָ������
	int from;		//ͷ
	int to;			//β
	int cost;		//Ȩֵ
	vector<int> Npath;  //·���Ͻڵ�Ĵ洢
	vector<int> Apath;	//·���ϱߵĴ洢
private:
	
	
};


#endif