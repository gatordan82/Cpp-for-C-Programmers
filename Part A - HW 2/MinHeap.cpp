#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>
#include "IndexMinPriorityQueue.h"
#include <string>

//int main()
//{
//	using namespace std;
//
//	vector<string> strings{ "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };
//	IndexMinPriorityQueue<string, size_t> pq{ strings.size() };
//
//	cout << "Is the priority queue empty? " << boolalpha << pq.isEmpty() << "\n\n";
//
//	for (size_t i{ 0 }; i < strings.size(); ++i)
//	{
//		pq.insert(strings[i], i);
//	}
//
//	size_t idx1{ 5 };
//	pq.changeKey(string{ "Times" }, idx1);
//	cout << "Contains Index " << idx1 << " (key)? " 
//		 << boolalpha << pq.containsIndex(idx1) << "(" << pq.keyOf(idx1) << ")" << endl;
//	pq.deleteIndex(idx1);
//	
//
//	cout << "(Min key, Min index): " << endl;
//	while (!pq.isEmpty())
//	{
//		string minKey = pq.minKey();
//		size_t minIndex = pq.minIndex();
//
//		size_t i = pq.removeMin();
//		cout << minKey << ", " << minIndex << endl;
//	}
//	cout << "\n\n";




	//vector<int> v{ 5, 4, 6, 9, 0, 1, 2, 3 };
	//vector<int> w = v;

	//cout << "v (pre-heapify): " << endl;
	//for (const auto& e : v)
	//	cout << e << ", ";

	//make_heap(v.begin(), v.end());

	//cout << "\n\n" << "v (post-heapify): " << endl;
	//for (const auto& e : v)
	//	cout << e << ", ";

	//cout << "\n\n" << "w (post-(min)heapify): " << endl;
	//make_heap(w.begin(), w.end(), greater<>{});
	//for (const auto& e : w)
	//	cout << e << ", ";

	//cout << endl;

	//while (w.size() > 0)
	//{
	//	pop_heap(w.begin(), w.end(), greater<>{});
	//	auto min = w.back();
	//	w.pop_back();
	//	
	//	cout << "Popped off min key." << endl;
	//	for (const auto& e : w)
	//		cout << e << ", ";

	//	cout << "\n\n";
	//}

	//cout << endl;

	//vector<pair<int, int>> pairTest{};
	//vector<int> numbers{};

	//for (int i = 0; i < 10; ++i)
	//{
	//	pairTest.push_back({ 10 - i, i });
	//	numbers.push_back(10 - i);
	//}
	//	

	//cout << "Pre-heapify: " << endl;
	//for (const auto& p : pairTest)
	//	cout << "(" << p.first << ", " << p.second << ")" << endl;

	//make_heap(pairTest.begin(), pairTest.end(), 
	//	[](const auto& left, const auto& right)
	//{
	//	return left.first > right.first;
	//});

	//cout << "\n\nPost-heapify: " << endl;
	//for (const auto& p : pairTest)
	//	cout << "(" << p.first << ", " << p.second << ")" << endl;

	//cout << "\n\n";
	//make_heap(numbers.begin(), numbers.end(), greater<>{});
	//for (const auto& e : numbers)
	//	cout << e << endl;

//	cin.get();
//	cin.get();
//
//}