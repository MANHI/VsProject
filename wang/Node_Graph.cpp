#include"Node_Graph.h"

void ss_shortest_paths::shortest_paths(const vector<int> Mp, int start_node, int end_node) {
	vector<path_info> path(node_count);
	priority_queue<node_info, vector<node_info> > min_heap;

	vector<int>              s_path_index;      // 最短路径
	int                      shortest_path;     // 最短路径的长度

	min_heap.push(node_info(start_node, 0));    // 将起始结点入队

	while (true) {
		node_info top = min_heap.top();    // 取出最大值
		min_heap.pop();

		// 已到达目的结点
		if (top.index == end_node) {
			break;
		}
		// 未到达则遍历
		for (int i = 0; i < node_count; ++i) {
			// 顶点top.index和i间有边，且此路径长小于原先从原点到i的路径长 
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

/*改变后的深度遍历*/
void ss_shortest_paths::DFS(const vector<int> Mp,int start_node, vector<int> &visited)
{
	DFSTraver(Mp,start_node,visited);  //只遍历一个树
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

/*只从起点开始深度搜索，只能有一颗树并且遍历全部指定的节点，否则NA*/
bool ss_shortest_paths::judgeNA(const vector<int> Mp, int start_node, int end_node)
{
	vector<int> visited;
	for (int i = 0; i < node_count; i++)        //初始化
		visited.push_back(0);

	DFS(Mp, start_node, visited);  //遍历

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