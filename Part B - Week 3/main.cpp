#include <utility>

#include "Tree.h"
#include "IdNode.h"


int main()
{
	using namespace std;


	valtab['A'] = 3;
	valtab['B'] = 4;

	cout << "A = 3, B = 4" << endl;

	Tree t1 = Tree("*", Tree("-", 5), Tree("+", 'A', 4));
	Tree t2 = Tree("+", Tree("-", 'A', 1), Tree("+", t1, 'B'));

	cout << "t1 = " << t1 << " ; t2 = " << t2 << endl;
	cout << "t1:" << t1.eval() << " t2:" << t2.eval() << endl;

	cin.get();
	cin.get();


	return 0;
}