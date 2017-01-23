#include <iostream>
#include "UndirectedGraph.h"

using namespace std;

//static const int GRAPH_NODES_COUNT = 50;

//double calculateAveragePath(double density, pair<double, double> distRange) {
//    double totalCost = 0.0, curCost;
//    int unfoundCount = 0;
//    UndirectedGraph graph(GRAPH_NODES_COUNT, 0.2, distRange);
//    for (int i = 1; i < GRAPH_NODES_COUNT; i++) {
//        curCost = graph.findShortestPath(0, i);
//        if (curCost != numeric_limits<double>::max()) {
//            totalCost += curCost;
//        } else {
//            unfoundCount++;
//        }
//    }
//    return totalCost / (GRAPH_NODES_COUNT - 1 - unfoundCount);
//}

int main() {
	string filename = "testgraph.txt";
	UndirectedGraph graph(filename);
	vector<Edge*> mst;
	double dist = graph.findKruskalMST(mst);

	cout << "MST is " << dist;

	return EXIT_SUCCESS;
}