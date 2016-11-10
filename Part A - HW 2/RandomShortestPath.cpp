#include "Bag.h"
#include "Edge.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
	using namespace std;

	// Bag unit tests
	Bag<int> b1{};
	assert(b1.isEmpty());
	assert(b1.size() == 0);

	b1.add(1);
	assert(b1.size() == 1);
	b1.add(5);
	assert(b1.size() == 2);
	cout << "Bag elements: " << endl;
	for (const auto& e : b1)
		cout << e << endl;

	b1.remove(1);
	assert(b1.size() == 1);
	b1.remove(5);
	assert(b1.size() == 0);
	assert(b1.isEmpty());

	Bag<int> b2{};
	size_t b2Size{ 20 };
	for (int i = 0; i < b2Size; ++i)
		b2.add(i);
	assert(b2.size() == b2Size);
	cout << "\nNew bag elements" << endl;
	for (const auto& e : b2)
		cout << e << endl;

	cout << "\nTest Edge constructors" << endl;
	Edge<double> e1(1, 2, 2.0);
	Edge<double> e2(2, 0, 1.0);
	Edge<double> e3(2, 1, 2.0);
	Edge<double> e4(2, 1);
	Edge<double> e5(1);
	Edge<double> e6;
	Edge<double> e7(2, 1, 0.0);

	cout << "e1\t" << e1.toString() << endl;
	cout << "e2\t" << e2.toString() << endl;
	cout << "e3\t" << e3.toString() << endl;
	cout << "e4\t" << e4.toString() << endl;
	cout << "e5\t" << e5.toString() << endl;
	cout << "e6\t" << e6.toString() << endl;

	cout << "e1 < e2? " << (e1 < e2) << endl;
	cout << "e1 > e2? " << (e1 > e2) << endl;
	cout << "e4 == e7? " << (e4 == e7) << endl;

	Bag<Edge<double>> edgeList{};
	edgeList.add(e1);
	edgeList.add(e2);
	edgeList.add(e3);

	cout << "\nEdges as inputted: " << endl;
	for (const auto& e : edgeList)
		cout << e.toString() << endl;



	std::array<double, 2> range{ 0.0, 10.0 };

	Graph random(10, 0.2, range);
	cout << random.toString() << endl;

	cin.get();

	return 0;
}