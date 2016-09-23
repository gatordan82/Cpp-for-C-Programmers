#include <iostream>
#include <vector>

// sum() returns the sum of all elements in the vector
inline int sum(std::vector<int>& v)
{
	int sum{ 0 };

	for (int i = 0; i < v.size; ++i)
		sum += v[i];

	return sum;
}

int main()
{
	const int N = 40;

	std::vector<int> d;

	// fill vector with values 0, 1, 2, ..., N
	for (int i = 0; i < N; ++i)
		d.push_back(i);

	std::cout << "sum is " << sum(d) << std::endl;

	std::cin.get();

	return 0;
}