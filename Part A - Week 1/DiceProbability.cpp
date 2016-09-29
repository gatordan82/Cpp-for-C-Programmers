// The following program computes the probability for dice possibilities

#include <iostream>  // drops .h still available 
#include <random>
#include <ctime>

using namespace std;

const int sides{ 6 };  // replaces many sharp defines

int main()
{
	const int n_dice{ 2 };

	uniform_int_distribution<unsigned> u(1, sides);
	default_random_engine e(time(0));

	cout << "\nEnter number of trials: ";

	int trials;
	cin >> trials;

	int* outcomes = new int[n_dice * sides + 1]();

	for (int j = 0; j < trials; ++j)
		outcomes[u(e) + u(e)]++;

	cout << "probability\n";

	for (int j = 2; j < n_dice * sides + 1; ++j)
	{
		cout << "j = " << j << " p = "
			<< static_cast<double>(outcomes[j]) / trials
			<< endl;
	}

	delete[] outcomes;

	cin.get();
	cin.get();

	return 0;
}