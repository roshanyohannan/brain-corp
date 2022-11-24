#ifndef SPEEDY_MULTIPLY_EXPRESSION_H
#define SPEEDY_MULTIPLY_EXPRESSION_H

#include "Expression.h"

namespace Speedy{

//! \brief      An Expression that represents the product of two matrices or expressions
//! \details    The MultiplyExpression object evaluates and returns elements of the product matrix when its function call operator is invoked. 
template<typename T>
class MultiplyExpression : public Expression<T>
{
public:
//! \brief        Constructor for the MultiplyExpression class. Throws invalid argument exception when multiplication incompatible matrices are provided
//! \param left   Left hand side matrix or expression
//! \param right  Right hand side matrix or expression
MultiplyExpression(const Expression<T>& left, const Expression<T>& right)
: op1 (left),
  op2 (right)
{
  if(left.size().cols != right.size().rows)
    throw(std::invalid_argument("matrices are incompatible for multiplication")); 
}

//! \brief      Performs multiplication & sum of given row of left matrix and column of the right matrix
//! \param row  Index of the row of the result matrix. 
//! \param col  Index of the column  of the result matrix. 
//! \return     The element at index row,col in the result matrix
T operator() (size_t row, size_t col) const override
{
  T sum = 0;
  
  for(int k = 0; k < op1.size().cols; k++)
    sum += op1(row, k) * op2(k, col);

  return sum;
}

//! \brief      Returns the dimensions of the multiplication result of the two matrices
//! \return     Dimensions of the matrix product 
Dims size() const override
{
  return Dims(op1.size().rows, op2.size().cols);
}


private:
  const Expression<T>& op1;       //!< The left hand side expression of the product 
  const Expression<T>& op2;       //!< The right hand side expression of the product
};


//! \brief      A wrapper function that returns a Multiplication expression for the given matrices
//! \details    Product will not be evaluated until later when the expression is finally assigned to a Matrix object - that will triggers evaluation 
//!             of each element of the expression in the expression tree
//! \return     A MultiplyExpression object representing the product of the two matrices
template<typename T>
MultiplyExpression<T> operator* (const Expression<T>& left, const Expression<T>& right)
{
  return MultiplyExpression<T>(left, right);
}

} //namespace 




#endif