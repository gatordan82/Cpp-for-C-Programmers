#include <cmath>
#include <iostream>

class point
{
private:
	double x, y;

public:
	point() : point(0, 0) {}
	point(double u) : x(u), y(0.0) {}
	point(double u, double v) : x(u), y(v) {}
	operator double() { return sqrt(x * x + y * y); }
	friend std::ostream& operator<<(std::ostream& out, const point& p)
	{
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}

	point operator+(point p)
	{
		return point(x + p.x, y + p.y);
	}
};

int main()
{
	return 0;
}

