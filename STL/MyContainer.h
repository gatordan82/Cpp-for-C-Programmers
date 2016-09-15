#pragma once
#ifndef _STL_MYCONTAINER_H
#define _STL_MYCONTAINER_H

template <class T, int n>
class MyContainer
{
private:
	T* a;

public:
	MyContainer(int n);
	MyContainer(T* b);
	MyContainer(const MyContainer& b);
	MyContainer(MyContainer &&b) noexcept;
	MyContainer& operator=(MyContainer &&b) noexcept;
	~MyContainer();

	void swap(MyContainer& b);
};

#endif

