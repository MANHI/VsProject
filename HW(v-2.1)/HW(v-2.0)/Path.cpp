#include "Path.h"

Path& Path::operator=(Path &rth)
{
	this->Npath = rth.GetNpath();
	this->Apath = rth.GetApath();
	this->cost  = rth.GetCost();
	this->from  = rth.GetFrom();
	this->to    = rth.GetTo();
	this->SpecNode = rth.SpecNode;
	return *this;
}

Path Path::operator+(Path &rth)
{
	Path tem = *this;
	tem.cost = this->cost + rth.cost;   //权值相加
	for (int i = 0; i < rth.Apath.size(); i++)		//把rth的边加入this中
		tem.Apath.push_back(rth.Apath[i]);

	for (int i = 1; i < rth.Npath.size(); i++)     //注意不添加第一个，会重复
		tem.Npath.push_back(rth.Npath[i]);

	for (int i = 0; i < rth.SpecNode.size(); i++)		//注意不添加第一个，会重复
		if (find(tem.SpecNode.begin(), tem.SpecNode.end(), rth.SpecNode[i]) == tem.SpecNode.end())
			tem.SpecNode.push_back(rth.SpecNode[i]);
	return tem;
}
