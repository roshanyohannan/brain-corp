#include "Expression.h"

#ifndef SPEEDY_TRANSPOSE_EXPRESSION_H
#define SPEEDY_TRANSPOSE_EXPRESSION_H

namespace Speedy{

template<typename T>
class TransposeExpression : public Expression<T>
{
public:
TransposeExpression(const Expression<T>& expression)
: op1 (expression)
{}

T operator() (int row, int col) const override
{
  return op1(col, row);
}

Dims size() const override
{
  return op1.size();
}


private:
  const Expression<T>& op1;
};

template<typename T>
TransposeExpression<T> transpose (const Expression<T>& expression)
{
  return TransposeExpression<T>(expression);
}

} //namespace 




#endif