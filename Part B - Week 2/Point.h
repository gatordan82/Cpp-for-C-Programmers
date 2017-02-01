#ifndef _POINT_H
#define _POINT_H

#include "Duo.h"
#include <cmath>

template <class T=double>
class Point : public Duo<T>
{
public:
	double length() const;
};



template<class T>
inline double Point<T>::length() const
{
	return sqrt(_first * _first + _second * _second);
}


#endif // !_POINT_H