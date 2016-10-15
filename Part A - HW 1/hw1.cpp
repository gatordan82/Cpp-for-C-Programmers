// C++ for C Programmers, Part A
// Homework 1: Convert a C program to C++
//
// Program computes the sum of values in a vector (resizing array)
//
// Daniel K. Benjamin
// 9/27/2016

#include <iostream>
#include <vector>

// sum() returns the sum of all elements in a generic vector v,
// with arguments that are summable
template <class Summable>
inline Summable sum(std::vector<Summable>& v)
{
	Summable sum{ 0 };

	for (const auto& e : v)
		sum += e;

	return sum;
}

int main()
{
	const int N {40};

	std::vector<int> d;

	// fill vector with values 0, 1, 2, ..., N
	for (int i = 0; i < N; ++i)
		d.push_back(i);

	std::cout << "sum is " << sum(d) << std::endl;

	return 0;
}