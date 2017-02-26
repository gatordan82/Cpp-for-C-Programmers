#ifndef _MY_CONTAINER_H
#define _MY_CONTAINER_H

#include <utility>

template <class T, int n>
class my_container
{
private:
	T* a;

public:
	my_container();
	explicit my_container(T* b);
	my_container(const my_container& b);
	my_container(my_container&& b) noexcept;

	~my_container();

	my_container& operator=(my_container&& b) noexcept;

	void swap(my_container& b);
};



template<class T, int n>
inline my_container<T, n>::my_container()
{
	a = new T[n];
}

template<class T, int n>
inline my_container<T, n>::my_container(T * b)
	: my_container()
{
	for (int i{ 0 }; i < n; ++i)
		a[i] = b[i];
}

template<class T, int n>
inline my_container<T, n>::my_container(const my_container& b)
	: my_container()
{
	for (int i{ 0 }; i < n; ++i)
		a[i] = b.a[i];
}

template<class T, int n>
inline my_container<T, n>::my_container(my_container&& b) noexcept
{
	a = b.a;
	b.a = nullptr;
}

template<class T, int n>
inline my_container<T, n>::~my_container()
{
	delete[] a;
}

template<class T, int n>
inline my_container& my_container<T, n>::operator=(my_container&& b) noexcept
{
	a = b.a;
	b.a = nullptr;

	return *this;
}

template<class T, int n>
inline void my_container<T, n>::swap(my_container& b)
{
	my_container temp = std::move(b);
	b = std::move(*this);
	*this = std::move(temp);
}







#endif // !_MY_CONTAINER_H