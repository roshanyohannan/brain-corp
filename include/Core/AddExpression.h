#include "Expression.h"

#ifndef SPEEDY_ADD_EXPRESSION_H
#define SPEEDY_ADD_EXPRESSION_H

namespace Speedy{

class AddExpression : public Expression
{
public:

AddExpression(const Expression& left, const Expression& right)
: op1 (left),
  op2 (right)
{
	if(op1.size() != op2.size())
		throw(std::invalid_argument("Dimensions of operands for addition do not match")); 
}

int operator() (int row, int col) const override
{
	return op1(row, col) + op2(row, col);
}

Dims size() const override
{
	return op1.size();
}


private:
	const Expression& op1;
	const Expression& op2;
};

AddExpression operator+ (const Expression& left, const Expression& right)
{
	return AddExpression(left, right);
}

} //namespace 




#endif