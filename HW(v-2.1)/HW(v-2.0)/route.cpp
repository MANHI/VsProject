#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include "Graph.h"
#include "Run.h"
//你要完成的功能总入口
void search_route(char *topo[5000], int edge_num, char *demand)
{
	Graph G(topo, edge_num, demand);
//	G.ShowGraph();
	Run r(G);
//	r.runAllDij(G, G.GetStart(), G.GetEnd());
//	
	//r.runSk66(G,G.GetStart(),G.GetEnd());
	//r.ShowResult(G);
	r.runSk(G, G.GetStart(), G.GetEnd());
	r.ShowMap(G);
	
}
