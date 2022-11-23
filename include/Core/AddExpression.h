#include "Expression.h"

#ifndef SPEEDY_ADD_EXPRESSION_H
#define SPEEDY_ADD_EXPRESSION_H

namespace Speedy{

template <typename T>
class AddExpression : public Expression<T>
{
public:

AddExpression(const Expression<T>& left, const Expression<T>& right)
: op1 (left),
  op2 (right)
{
  if(op1.size() != op2.size())
    throw(std::invalid_argument("Dimensions of operands for addition do not match")); 
}

T operator() (size_t row, size_t col) const override
{
  return op1(row, col) + op2(row, col);
}

Dims size() const override
{
  return op1.size();
}


private:
  const Expression<T>& op1;
  const Expression<T>& op2;
};


template <typename T>
AddExpression<T> operator+ (const Expression<T>& left, const Expression<T>& right)
{
  return AddExpression<T>(left, right);
}

} //namespace 




#endif