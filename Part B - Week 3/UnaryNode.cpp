#include "UnaryNode.h"



UnaryNode::UnaryNode(char* a, Tree b)
	: op{ a },
	opnd{ b }
{
}

void UnaryNode::print(std::ostream& os)
{
	os << "(" << op << opnd << ")";
}


UnaryNode::~UnaryNode()
{
}

int UnaryNode::eval()
{
	switch (op[0])
	{
	case '-':
		return (-opnd.eval());
	case '+':
		return (+opnd.eval());
	default:
		std::cerr << "no operand\n" << std::endl;
		return 0;
	}
}
