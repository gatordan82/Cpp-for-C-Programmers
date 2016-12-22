#include <iostream>

typedef enum Days
{
	SUN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT
} Days;

inline Days operator++(Days d)
{
	return static_cast<Days>((static_cast<int>(d) + 1) % 7);
}

using std::ostream;

ostream& operator<<(ostream& out, const Days& d)
{
	switch (d)
	{
	case SUN:
		out << "SUN"; break;
	case MON:
		out << "MON"; break;
	case TUE:
		out << "TUE"; break;
	case WED:
		out << "WED"; break;
	case THU:
		out << "THU"; break;
	case FRI:
		out << "FRI"; break;
	case SAT:
		out << "SAT"; break;
	}

	return out;
}

//int main()
//{
//	using namespace std;
//	Days d = MON, e;
//	e = ++d;
//
//	cout << d << '\t' << e << endl;
//
//	cin.get();
//	cin.get();
//
//	return 0;
//}