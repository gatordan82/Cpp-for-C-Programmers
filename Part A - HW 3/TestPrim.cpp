#include "Graph.h"
#include "PrimMST.h"

using namespace std;

int main()
{
	Graph sample{ "sample.txt" };

	PrimMST mst{ sample };

	cout << "Minimum Spanning Tree Edges: " << endl;
	for (const auto& e : mst.edges())
		cout << e << endl;

	cout << "\n\nMST Weight: " << mst.weight() << endl;
		
	cin.get();
	cin.get();

	return 0;
}