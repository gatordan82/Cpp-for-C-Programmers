#ifndef _MY_CONTAINER_2_H
#define _MY_CONTAINER_2_H

#include <utility>

template <class T, int n>
class MyContainer2
{
private:
	T* a;
public:
	MyContainer2();
	explicit MyContainer2(T* b);
	MyContainer2(const MyContainer2& b);
	MyContainer2(MyContainer2&& b) noexcept;

	~MyContainer2();

	MyContainer2& operator=(MyContainer2&& b) noexcept;

	void swap(MyContainer2& b);
};


template<class T, int n>
inline MyContainer2<T, n>::MyContainer2()
{
	a = new T[n];
}

template<class T, int n>
inline MyContainer2<T, n>::MyContainer2(T * b)
	: MyContainer2{}
{
	for (size_t i{ 0 }; i < n; ++i)
		a[i] = b[i];
}

template<class T, int n>
inline MyContainer2<T, n>::MyContainer2(const MyContainer2& b)
	: MyContainer2{}
{
	for (size_t i{ 0 }; i < n; ++i)
		a[i] = b.a[i];
}

template<class T, int n>
inline MyContainer2<T, n>::MyContainer2(MyContainer2&& b) noexcept
{
	a = b.a;
	b.a = nullptr;
}

template<class T, int n>
inline MyContainer2<T, n>::~MyContainer2()
{
	delete[] a;
}

template<class T, int n>
inline MyContainer2& MyContainer2<T, n>::operator=(MyContainer2&& b) noexcept
{
	a = b.a;
	b.a = nullptr;
	return *this;
}

template<class T, int n>
inline void MyContainer2<T, n>::swap(MyContainer2& b)
{
	MyContainer2 temp = std::move(b);
	b = std::move(*this);
	*this = std::move(temp);
}



#endif // !_MY_CONTAINER_2_H