#include <iostream>
#include <cstdint>

using namespace std;

enum class days : std::int8_t
{
	SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

// Output stream operator
ostream& operator<<(ostream& out, const days& d)
{
	out << static_cast<int>(d);
	return out;
}

// Prefix operator
inline days operator++(days& d)
{
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

// Postfix operator
inline days operator++(days& d, int)
{
	days temp = d;
	d = static_cast<days>((static_cast<int>(d) + 1) % 7);
	return temp;
}

int main()
{
	days today{ days::MONDAY };
	cout << "Demonstrate enum class" << endl;
	cout << "Monday value is " << today << endl;

	cout << "Increment value is " << ++today << endl;
	cout << "Increment value is " << today++ << endl;
	cout << "Increment value is " << today << endl;

	cin.get();

	return 0;

}