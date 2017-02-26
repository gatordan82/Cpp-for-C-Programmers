#include "Tree.h"
#include "IntNode.h"
#include "IdNode.h"
#include "UnaryNode.h"
#include "BinaryNode.h"

std::ostream& operator<<(std::ostream& os, const Tree& t)
{
	t.p->print(os);

	return os;
}

Tree::Tree(int n)
{
	p = new IntNode(n);
}

Tree::Tree(char id)
{
	p = new IdNode(id);
}

Tree::Tree(char* op, Tree t)
{
	p = new UnaryNode(op, t);
}

Tree::Tree(char* op, Tree left, Tree right)
{
	p = new BinaryNode(op, left, right);
}

Tree::Tree(const Tree& t)
{
	p = t.p;
	++p->use;
}

Tree::~Tree()
{
	if (--p->use == 0)
		delete p;
}

void Tree::operator=(const Tree& t)
{
	++t.p->use;

	if (--p->use == 0)
		delete p;
	p = t.p;
}

int Tree::eval()
{
	return p->eval();
}

