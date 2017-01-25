#include <map>
#include <unordered_map>
#include <string>
#include <iostream>



//int main()
//{
//	using namespace std;
//
//	map<unsigned long, string> worker{};
//	unordered_map<unsigned long, unsigned int> payroll{};
//
//	unsigned int totalPay{ 0 };
//
//	worker[99567800] = "Harold Fish";
//	payroll[99567800] = 67300;
//
//	worker[8567800] = "Phillip Fish";
//	payroll[8567800] = 87300;
//
//	for (auto& p{ worker.begin() }; p != worker.end(); ++p)
//	{
//		cout << "Name " << p->second << "\t id no. "
//			<< p->first << endl;
//	}
//
//	for (auto& p{ payroll.begin() }; p != payroll.end(); ++p)
//	{
//		totalPay += p->second;
//	}
//
//	cout << "Payroll totals $" << totalPay << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}