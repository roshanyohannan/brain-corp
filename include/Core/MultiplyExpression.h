#include "Expression.h"

#ifndef SPEEDY_MULTIPLY_EXPRESSION_H
#define SPEEDY_MULTIPLY_EXPRESSION_H

namespace Speedy{

class MultiplyExpression : public Expression
{
public:

MultiplyExpression(const Expression& left, const Expression& right)
: op1 (left),
  op2 (right)
{
  if(left.size().cols != right.size().rows)
    throw(std::invalid_argument("Given Matrices are incompatible for multiplication")); 
}

int operator() (int row, int col) const override
{
  int sum = 0;
  
  for(int k = 0; k < op1.size().cols; k++)
    sum += op1(row, k) * op2(k, col);

  return sum;
}

Dims size() const override
{
  return Dims(op1.size().rows, op2.size().cols);
}


private:
  const Expression& op1;
  const Expression& op2;
};

MultiplyExpression operator* (const Expression& left, const Expression& right)
{
  return MultiplyExpression(left, right);
}

} //namespace 




#endif