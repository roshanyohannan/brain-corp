#include "Expression.h"

#ifndef SPEEDY_TRANSPOSE_EXPRESSION_H
#define SPEEDY_TRANSPOSE_EXPRESSION_H

namespace Speedy{

template<typename T>
class TransposeExpression : public Expression<T>
{
public:
TransposeExpression(const Expression<T>& expression)
: op (expression)
{}

T operator() (size_t row, size_t col) const override
{
  return op(col, row);
}

Dims size() const override
{
  return { op.size().cols, op.size().rows };
}


private:
  const Expression<T>& op;
};

template<typename T>
TransposeExpression<T> transpose (const Expression<T>& expression)
{
  return TransposeExpression<T>(expression);
}

} //namespace 




#endif