#include"Node_Graph.h"

void ss_shortest_paths::shortest_paths(const vector<int> Mp, int start_node, int end_node) {
	vector<path_info> path(node_count);
	priority_queue<node_info, vector<node_info> > min_heap;

	vector<int>              s_path_index;      // ���·��
	int                      shortest_path;     // ���·���ĳ���

	min_heap.push(node_info(start_node, 0));    // ����ʼ������

	while (true) {
		node_info top = min_heap.top();    // ȡ�����ֵ
		min_heap.pop();

		// �ѵ���Ŀ�Ľ��
		if (top.index == end_node) {
			break;
		}
		// δ���������
		for (int i = 0; i < node_count; ++i) {
			// ����top.index��i���бߣ��Ҵ�·����С��ԭ�ȴ�ԭ�㵽i��·���� 
			if (graph[top.index][i] != no_edge &&
				(top.weight + graph[top.index][i]) < path[i].weight) {
				min_heap.push(node_info(i, top.weight + graph[top.index][i]));
				path[i].front_index = top.index;
				path[i].weight = top.weight + graph[top.index][i];
			}
		}
		if (min_heap.empty()) {
			break;
		}
	}

	shortest_path = path[end_node].weight;
	int index = end_node;
	s_path_index.push_back(index);
	while (true) {
		index = path[index].front_index;
		s_path_index.push_back(index);
		if (index == start_node) {
			break;
		}
	}
	//Print
	cout << "min weight : " << shortest_path << endl;
	cout << "path: ";
	copy(s_path_index.rbegin(), s_path_index.rend(),
		ostream_iterator<int>(cout, " "));
	cout << endl;
}

/*�ı�����ȱ���*/
void ss_shortest_paths::DFS(const vector<int> Mp,int start_node, vector<int> &visited)
{
	DFSTraver(Mp,start_node,visited);  //ֻ����һ����
}

void ss_shortest_paths::DFSTraver(const vector<int> Mp,int Vnode, vector<int> &visited)
{
	//int index;
	if (visited[Vnode] == 1)
		return;
	//cout << Vnode << endl;
	visited[Vnode] = 1;
	for (int i = 0; i < node_count; i++)
	{
		if (graph[Vnode][i] != -1)
			DFSTraver(Mp,i, visited);
	}
}

/*ֻ����㿪ʼ���������ֻ����һ�������ұ���ȫ��ָ���Ľڵ㣬����NA*/
bool ss_shortest_paths::judgeNA(const vector<int> Mp, int start_node, int end_node)
{
	vector<int> visited;
	for (int i = 0; i < node_count; i++)        //��ʼ��
		visited.push_back(0);

	DFS(Mp, start_node, visited);  //����

	for (auto c : visited)
		cout << c << " ";
	cout << endl;
	if (visited[end_node] == 0)
		return false;
	for (int i = 0; i < Mp.size(); i++)
	{
		if (visited[Mp[i]] == 0)
			return false;
	}
	return true;

}