// 
// Convert this program to C++
// change to C++ io : See lines 10, 12, 32
// change to one line comments : See lines 1:8
// change defines of constants to const : See line 14
// change array to vector<> : See lines 11, 12, 16, 26, 31
// inline any short function : See line 15-20, 31
// 

#include <iostream>
#include <vector>
using namespace std;

const size_t N = 40;

inline void sum(int& p, int n, vector<int> d) {
	p = 0;
	for (int i = 0; i < n; ++i) p += d[i];

}

int main()
{

	int accum = 0;
	vector<int> data(static_cast<size_t>(N));

	for (int i = 0; i < N; ++i)
		data[i] = i;

	sum(accum, N, data);
	cout << "sum is " << accum << endl;

	return 0;
}