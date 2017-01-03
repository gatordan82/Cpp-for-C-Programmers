#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

int main()
{
	using namespace std;

	vector<int> v{ 5, 4, 6, 9, 0, 1, 2, 3 };
	vector<int> w = v;

	cout << "v (pre-heapify): " << endl;
	for (const auto& e : v)
		cout << e << ", ";

	make_heap(v.begin(), v.end());

	cout << "\n\n" << "v (post-heapify): " << endl;
	for (const auto& e : v)
		cout << e << ", ";

	cout << "\n\n" << "w (post-(min)heapify): " << endl;
	make_heap(w.begin(), w.end(), greater<>{});
	for (const auto& e : w)
		cout << e << ", ";

	cout << endl;

	while (w.size() > 0)
	{
		pop_heap(w.begin(), w.end(), greater<>{});
		auto min = w.back();
		w.pop_back();
		
		cout << "Popped off min key." << endl;
		for (const auto& e : w)
			cout << e << ", ";

		cout << "\n\n";
	}

	cout << endl;

	cin.get();
	cin.get();

}