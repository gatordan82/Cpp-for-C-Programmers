#ifndef _DUO_H
#define _DUO_H

template <class T=double>
class Duo
{
protected:
	T _first;
	T _second;

public:
	Duo();
	Duo(const T& first);
	Duo(const T& first, const T& second);

	virtual ~Duo();

	void setFirst(const T& first);
	void setSecond(const T& second);
	const T& getFirst() const;
	const T& getSecond() const;
};


template<class T>
inline Duo<T>::Duo()
	: _Duo{ 0.0, 0.0 }
{
}

template<class T>
inline Duo<T>::Duo(const T& first)
	: Duo{ first, 0.0 }
{
}

template<class T>
inline Duo<T>::Duo(const T& first, const T& second)
	: _first{ first },
	_second{ second }
{
}

template<class T>
inline Duo<T>::~Duo()
{
}

template<class T>
inline void Duo<T>::setFirst(const T& first)
{
	_first = first;
}

template<class T>
inline void Duo<T>::setSecond(const T& second)
{
	_second = second;
}

template<class T>
inline const T& Duo<T>::getFirst() const
{
	return _first;
}

template<class T>
inline const T& Duo<T>::getSecond() const
{
	return _second;
}






#endif // !_DUO_H