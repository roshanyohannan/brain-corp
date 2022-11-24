#ifndef SPEEDY_MULTIPLY_EXPRESSION_H
#define SPEEDY_MULTIPLY_EXPRESSION_H

#include "Expression.h"

namespace Speedy{

template<typename T>
class MultiplyExpression : public Expression<T>
{
public:

MultiplyExpression(const Expression<T>& left, const Expression<T>& right)
: op1 (left),
  op2 (right)
{
  if(left.size().cols != right.size().rows)
    throw(std::invalid_argument("matrices are incompatible for multiplication")); 
}

T operator() (size_t row, size_t col) const override
{
  T sum = 0;
  
  for(int k = 0; k < op1.size().cols; k++)
    sum += op1(row, k) * op2(k, col);

  return sum;
}

Dims size() const override
{
  return Dims(op1.size().rows, op2.size().cols);
}


private:
  const Expression<T>& op1;
  const Expression<T>& op2;
};

template<typename T>
MultiplyExpression<T> operator* (const Expression<T>& left, const Expression<T>& right)
{
  return MultiplyExpression<T>(left, right);
}

} //namespace 




#endif