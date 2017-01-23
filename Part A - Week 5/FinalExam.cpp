//#include <iostream>
//
//int main()
//{
//	using namespace std;
//
//	int a = 2, b = -3, c = 2;
//
//	bool tval1 = false, tval2 = true;
//
//	char ch = 'b';
//
//	cout << "1)\t" << b + c * a << endl;
//	cout << "2)\t" << c % 5 / 2 << endl;
//	cout << "3)\t" << -a * c++ << endl;
//	cout << "4)\t" << boolalpha << (tval1 && tval2) << endl;
//	cout << "5)\t" << (ch += 2) << endl;
//
//
//
//	cin.get();
//	cin.get();
//
//	return 0;
//
//}

////templates what gets printed
//
//#include <iostream>
//
//using namespace std;
//
//template <class T1, class T2>
//
//int mystery(T1& a, T2 b, int c)
//
//{
//
//	T1 t = a;
//
//	a = a + b;
//
//	return (a - t + c);
//
//}
//
//int main(void)
//
//{
//
//	int a = 3;
//
//	double b = 2.5;
//
//	int c = 1;
//
//	cout << " answer 1 is " << mystery(a, 2, c) << endl;
//
//	cout << " answer 2 is " << mystery(a, 1, c) << endl;
//
//	a = 5;
//
//	cout << " answer 3 is " << mystery(a, b, c) << endl;
//
//	a = 2;
//
//	b = 2.5;
//
//	cout << " answer 4 is " << mystery(a, b, b) << endl;
//
//	cout << " answer 5 is " << mystery(a, mystery(a, b, b), c) << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//
//}

//What does the following print

#include <iostream>

#include <vector>

#include <algorithm>

#include <numeric>

using namespace std;

int main()

{

	vector<int> data(5, 1);

	int sum{ 0 };

	cout << sum << endl;

	for (auto element : data)

		sum += element;

	cout << sum << endl;

	for (auto p = ++data.begin(); p != --data.end(); ++p)

		sum += *p;

	cout << sum << endl;

	sum = 0;

	data.push_back(2);

	data.push_back(3);

	for (auto element : data)

		sum += element;

	cout << sum << endl;

	cout << accumulate(data.begin(), data.end(), data[0]) << endl;

	cin.get();
	cin.get();


	return 0;
}