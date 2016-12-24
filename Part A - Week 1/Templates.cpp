#include <iostream>
#include <complex>

namespace templates
{
	template <class T>
	inline void swap(T& d, T& s)
	{
		T temp = d;
		d = s;
		s = temp;
	}

	template <class Summable>
	Summable sum(const Summable data[],
		int size,
		Summable s = 0)
	{
		for (int i = 0; i < size; ++i)
			s += data[i];

		return s;
	}
}

int main()
{
	using namespace std;

	int m = 5, n = 10;
	double x = 5.3, y = 10.6;
	complex<double> r(2.4, 3.5), s(3.4, 6.7);

	cout << "inputs: " << m << ", " << n << endl;
	templates::swap(m, n);
	cout << "outputs: " << m << ", " << n << endl;

	cout << "inputs: " << x << ", " << y << endl;
	templates::swap(x, y);
	cout << "outputs: " << x << ", " << y << endl;
	
	cout << "inputs: " << r << ", " << s << endl;
	templates::swap(r, s);
	cout << "outputs: " << r << ", " << s << endl;

	cout << 'A' << endl;
	cout << static_cast<int>('A') << endl;

	cin.get();
	cin.get();

	return 0;

}