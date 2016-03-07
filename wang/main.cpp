#include "Node_Graph.h"
#include "time.h"
int main()
{
	clock_t startTime, endTime;
	double duration;
	startTime = clock();
	vector<int> mp = { 1,3, 4 };  //必须经过的顶点集合
	const int size = 5;
	vector<vector<int> > graph(size);
	for (int i = 0; i < size; ++i) {
		graph[i].resize(size);
	}
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			graph[i][j] = -1;
		}
	}
	/*graph[0][1] = 2;
	graph[0][2] = 3;
	graph[0][3] = 4;
	graph[1][2] = 3;
	graph[1][5] = 2;
	graph[1][4] = 7;
	graph[2][5] = 9;
	graph[2][6] = 2;
	graph[3][6] = 2;
	graph[4][7] = 3;
	graph[4][8] = 3;
	graph[5][6] = 1;
	graph[5][8] = 3;
	graph[6][9] = 1;
	graph[6][8] = 5;
	graph[7][10] = 3;
	graph[8][10] = 2;
	graph[9][8] = 2;
	graph[9][10] = 2;*/

	graph[0][4] = 3;
	graph[4][1] = 2;
	graph[1][2] = 5;
	graph[2][4] = 6;
	graph[3][1] = 1;
	graph[1][3] = 3;

	ss_shortest_paths ssp(graph);  //10是结束顶点，起始顶点是0
	int start_node = 0, end_node = 3;
	//ssp.shortest_paths(mp, 0, 3);
	/*ssp.shortest_paths(mp, 2, 5);
	ssp.shortest_paths(mp, 5, 6);
	ssp.shortest_paths(mp, 6, 8);
	ssp.shortest_paths(mp, mp[mp.size()-1], end_node);*/

 	if (ssp.judgeNA(mp, start_node, end_node) == false)
		printf_s("NA\n");
	else
		printf_s("NO  NA\n");
	//ssp.print_spaths();
	/*计算花费的时间*/
	endTime = clock();
	duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "times use: " << duration << endl;
	return 0;
}