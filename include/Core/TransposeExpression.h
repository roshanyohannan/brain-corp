#include "Expression.h"

#ifndef SPEEDY_TRANSPOSE_EXPRESSION_H
#define SPEEDY_TRANSPOSE_EXPRESSION_H

namespace Speedy{

class TransposeExpression : public Expression
{
public:
TransposeExpression(const Expression& expression)
: op1 (expression)
{}

int operator() (int row, int col) const override
{
  return op1(col, row);
}

Dims size() const override
{
  return op1.size();
}


private:
  const Expression& op1;
};

TransposeExpression transpose (const Expression& expression)
{
  return TransposeExpression(expression);
}

} //namespace 




#endif