#include <stdio.h>
#include <iostream>

void swap_int(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void swap_double(double* i, double* j)
{
	double temp = *i;
	*i = *j;
	*j = temp;
}

inline void swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}

inline void swap(double& i, double& j)
{
	double temp = i;
	i = j;
	j = temp;
}

//int main()
//{
//	int m = 5, n = 10;
//	double x = 5.3, y = 10.6;
//	printf("inputs: %d, %d\n", m, n);
//	swap_int(&m, &n);
//	printf("outputs: %d, %d\n", m, n);
//	printf("double inputs: %lf, %lf\n", x, y);
//	swap_double(&x, &y);
//	printf("double outputs: %lf, %lf\n", x, y);
//
//	using namespace std;
//	cout << "inputs: " << m << ", " << n << endl;
//	swap(m, n);
//	cout << "outputs: " << m << ", " << n << endl;
//
//	cout << "double inputs: " << x << ", " << y << endl;
//	swap(x, y);
//	cout << "double outputs: " << x << ", " << y << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}