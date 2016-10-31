#include "Bag.h"
#include "Edge.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

	using namespace std;

	Bag<int> test;
	test.add(5);
	test.add(10);
	test.add(11);

	for (const auto x : test)
		cout << x << endl;

	cout << "\nRemoved item: 10" << endl;
	int z = 10;
	test.remove(z);

	for (const auto x : test)
		cout << x << endl;

	Edge<double> e1(1, 2, 2.0);
	Edge<double> e2(2, 0, 1.0);
	Edge<double> e3(2, 1, 2.0);
	Edge<double> e4(2, 1);
	Edge<double> e5(1);
	Edge<double> e6;

	cout << "e1\t" << e1.toString() << endl;
	cout << "e2\t" << e2.toString() << endl;
	cout << "e3\t" << e3.toString() << endl;
	cout << "e4\t" << e4.toString() << endl;
	cout << "e5\t" << e5.toString() << endl;
	cout << "e6\t" << e6.toString() << endl;

	cout << "e1 < e2? " << (e1 < e2) << endl;

	std::vector<Edge<double>> edgeList {e1, e2, e3};

	cout << "\nEdges as inputted: " << endl;
	for (const auto& e : edgeList)
		cout << e.toString() << endl;

	sort(edgeList.begin(), edgeList.end());
	
	cout << "\nEdges after sorting: " << endl;
	for (const auto& e : edgeList)
		cout << e.toString() << endl;

	cout << "\n" << endl;

	std::array<double, 2> range{ 0.0, 10.0 };

	Graph random(10, 0.2, range);
	cout << random.toString() << endl;

	cin.get();

	return 0;
}