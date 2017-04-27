#include <iostream>
#include <cmath>

using namespace std;


int main()
{

	size_t emptyTiles{ 6 };
	size_t emptyTiles2{ 5 };

	size_t result = emptyTiles >> 1;
	size_t result2 = emptyTiles2 >> 1;
	size_t result3 = 1 + (emptyTiles2 - 1) / 2;

	cout << emptyTiles << ">> 1 = " << result << endl;
	cout << emptyTiles2 << ">> 1 = " << result2 << endl;
	cout << result3 << endl;

	cin.get();
	cin.get();

	return 0;
}