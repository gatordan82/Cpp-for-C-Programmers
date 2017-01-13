#include "Graph.h"
#include "WeightedQuickUnionPathCompressionUF.h"
#include "MinPriorityQueue.h"

using namespace std;

int main()
{
	vector<int> test{ 1,8,5,6,3,4,0,9,7,2 };

	cout << "Pre-heapify: " << endl;
	for (const auto& p : test)
		cout << p << " ";

	cout << "\n\n";

	MinPriorityQueue<int> minPQ{ test };

	cout << "Post-heapify: " << endl;
	while (!minPQ.isEmpty())
	{
		cout << minPQ.min() << " ";
		minPQ.removeMin();
	}

	cin.get();
	cin.get();

	return 0;
}