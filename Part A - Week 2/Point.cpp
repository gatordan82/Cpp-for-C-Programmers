#include <iostream>

class Point
{
private: 
	double x, y;

public:
	Point(double x, double y) 
		: x{ x }, y{ y } 
	{};
	Point()
		: x{ 0 }, y{ 0 }
	{};

	double getX() const { return x; }
	void setX(double v) { x = v; }

	double getY() const { return y; }
	void setY(double v) { y = v; }

};

Point operator+(Point& p1, Point& p2)
{
	Point sum = { p1.getX() + p2.getX(), p1.getY() + p2.getY() };
	return sum;
}

using std::ostream;

ostream& operator<<(ostream& out, const Point& p)
{
	out << "( " << p.getX() << ", " << p.getY() << " )";
	return out;
}

int main()
{
	using namespace std;
	
	Point a = { 3.5, 2.5 }, b = { 2.5, 4.5 }, c;
	cout << "a = " << a << " b = " << b << endl;
	cout << "sum = " << a + b << endl;

	cin.get();
	cin.get();

	return 0;
}