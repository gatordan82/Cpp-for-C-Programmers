#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

template <typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last)
{
	for (; first != last; first++)
		*first = (*first) * (*first);
}

//int main()
//{
//	vector<int> test{ 1, 2, 3, 4 };
//
//	cout << "Before:\n(";
//	for (const auto& e : test)
//		cout << e << ", ";
//	cout << ")\n\n";
//
//	square(test.begin(), test.end());
//
//	cout << "After:\n(";
//	for (const auto& e : test)
//		cout << e << ", ";
//	cout << ")\n\n";
//
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}