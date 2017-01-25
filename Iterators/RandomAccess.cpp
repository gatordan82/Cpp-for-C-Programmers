#include <cstddef>
#include <random>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>


template <typename RandomAccess>
RandomAccess pickRandEl(RandomAccess first,
	RandomAccess last)
{
	srand(time(0));
	ptrdiff_t temp = last - first;
	return first + rand() % temp;
}

int main()
{
	using namespace std;

	string test{ "Testing" };
	vector<short> test2{ 1, 2, 3, 4, 5 };

	for (size_t i{ 0 }; i < 5; ++i)
	{
		char random{ *pickRandEl(test.begin(), test.end()) };
		short rand2{ *pickRandEl(test2.begin(), test2.end()) };
		cout << "Random character from " << test
			<< " is: " << random << endl;
		cout << "Random number from {1, 2, 3, 4, 5}"
			<< " is: " << rand2 << endl;
	}

	cin.get();
	cin.get();

	return 0;
}