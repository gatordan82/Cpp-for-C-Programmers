#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog
{
private:
	string _name;

public:
	Dog()
	{
		cout << "Nameless dog created." << endl;
		_name = "nameless";
	}

	Dog(string name)
	{
		cout << "Dog is created: " << name << endl;
		_name = name;
	}

	~Dog()
	{
		cout << "Dog is destroyed: " << _name << endl;
	}

	void bark()
	{
		cout << "Dog " << _name << " rules!" << endl;
	}

};

void foo()
{
	auto p = make_shared<Dog>("Tank");
	{
		shared_ptr<Dog> p2 = p;
		p2->bark();
		cout << p.use_count() << endl;
	}

	p->bark();
}

int main()
{
	foo();

	cin.get();
}