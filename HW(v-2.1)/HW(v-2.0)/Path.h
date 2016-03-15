#ifndef __PATH_H
#define __PATH_H
#include<vector>
#include<iostream>
using namespace std;

/*保存路径的类*/
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

	/*暂时方便起见，都设为public*/
	vector<int> SpecNode;		//路径中指定顶点
	int from;		//头
	int to;			//尾
	int cost;		//权值
	vector<int> Npath;  //路径上节点的存储
	vector<int> Apath;	//路径上边的存储
private:
	
	
};


#endif