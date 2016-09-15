#include "MyContainer.h"



template <class T, int n>
MyContainer::MyContainer(int n)
{
	a = new T[n];
}



template <class T, int n>
explicit MyContainer::MyContainer(T* b) : MyContainer(int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
}



template<class T, int n>
MyContainer::MyContainer(const MyContainer& b) : MyContainer(int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = b.a[i];
}



template<class T, int n>
MyContainer::MyContainer(MyContainer &&b) noexcept
{
	a = b.a;
	b.a = nullptr;
}



template<class T, int n>
MyContainer& MyContainer::operator=(MyContainer &&b) noexcept
{
	a = b.a;
	b.a = nullptr;
	return this*;
}



template <class T, int n>
MyContainer::~MyContainer()
{
	delete[] a;
}



template<class T, int n>
void MyContainer::swap(MyContainer& b)
{
	MyContainer temp = std::move(b);
	b = std::move(*this);
	*this = move(temp);
}

