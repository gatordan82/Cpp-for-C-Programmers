#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>

int main()
{
	using namespace std;

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

	vector<pair<int, int>> pairTest{};
	vector<int> numbers{};

	for (int i = 0; i < 10; ++i)
	{
		pairTest.push_back({ 10 - i, i });
		numbers.push_back(10 - i);
	}
		

	cout << "Pre-heapify: " << endl;
	for (const auto& p : pairTest)
		cout << "(" << p.first << ", " << p.second << ")" << endl;

	make_heap(pairTest.begin(), pairTest.end(), 
		[](const auto& left, const auto& right)
	{
		return left.first > right.first;
	});

	cout << "\n\nPost-heapify: " << endl;
	for (const auto& p : pairTest)
		cout << "(" << p.first << ", " << p.second << ")" << endl;

	cout << "\n\n";
	make_heap(numbers.begin(), numbers.end(), greater<>{});
	for (const auto& e : numbers)
		cout << e << endl;

	cin.get();
	cin.get();

}