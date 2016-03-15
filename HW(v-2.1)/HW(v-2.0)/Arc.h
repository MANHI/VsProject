#ifndef __ARC_H
#define __ARC_H
#include<vector>
#include<iostream>

using namespace std;

/*�ߵĽṹ*/
class Arc{
public:
	Arc() = default;
	Arc(int n, int h, int t, int c) :num(n), head(h), tail(t), cost(c){};
	int GetNum() { return num; }
	int GetHead(){ return head; }
	int GetTail(){ return tail; }
	int GetCost(){ return cost; }

private:
	int num;
	int head;
	int tail;
	int cost;
};

#endif
