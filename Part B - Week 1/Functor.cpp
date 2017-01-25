#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Gen
{
private:
	double _x;
	double _incr;

public:
	Gen(double x0, double increment)
		: _x{ x0 }, _incr{ increment }
	{}

	double operator()()
	{
		_x += _incr;
		return _x * _x;
	}
};

double integrate(Gen& g, int n)
{
	vector<double> fx(n);

	generate(fx.begin(), fx.end(), g);

	return (accumulate(fx.begin(), fx.end(), 0.0) / n);
}

int main()
{
	const int n{ 10000 };

	Gen g{ 0.0, 1.0 / n };

	cout << "Integration program x**2" << endl;
	cout << integrate(g, n) << endl;

	cin.get();
	cin.get();

	return 0;
}

