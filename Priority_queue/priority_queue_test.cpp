#include<iostream>
#include<queue>

using namespace std;

class Node{
public:
		Node() = default;
		Node(int w) : weight(w){};
		int weight;
friend
bool operator < (const Node& lth, const Node& rth) {
	/*这样 > 是从小到大排序 < 是从大到小排序*/
	return lth.weight > rth.weight;}	// 为了实现从小到大的顺序
};

int main(void)
{
	priority_queue<Node, vector<Node>> min_heap;
	for (int i = 0; i < 10; i++)
	{
		Node n(i);
		min_heap.push(n);
	}
	Node t = min_heap.top();
	cout <<  t.weight<< endl;
}