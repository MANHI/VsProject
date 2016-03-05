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
	/*���� > �Ǵ�С�������� < �ǴӴ�С����*/
	return lth.weight > rth.weight;}	// Ϊ��ʵ�ִ�С�����˳��
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