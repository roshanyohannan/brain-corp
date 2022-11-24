#ifndef SPEEDY_ADD_EXPRESSION_H
#define SPEEDY_ADD_EXPRESSION_H

#include "Expression.h"

namespace Speedy{

//! \brief      An Expression that represents the sum of two matrices or expressions
//! \details    The AddExpression object evaluates and returns elements of the result matrix when its function call operator is invoked. 
template <typename T>
class AddExpression : public Expression<T>
{
public:
//! \brief        Constructor for the AddExpression class. Throws invalid argument exception when operands are incompatible matrices
//! \param left   Left hand side matrix or expression
//! \param right  Right hand side matrix or expression
AddExpression(const Expression<T>& left, const Expression<T>& right)
: op1 (left),
  op2 (right)
{
  if(op1.size() != op2.size())
    throw(std::invalid_argument("Dimensions of operands for addition do not match")); 
}

//! \brief      Performs element wise sum of given matrices for the given row and col index
//! \param row  Index of the row of the result matrix. 
//! \param col  Index of the column  of the result matrix. 
//! \return     The element at index row,col in the result matrix
T operator() (size_t row, size_t col) const override
{
  return op1(row, col) + op2(row, col);
}

//! \brief      Returns the dimensions of the result of the sum of two matrices.
//! \return     Dimensions of the summed matrix
Dims size() const override
{
  return op1.size();
}


private:
  const Expression<T>& op1;     //!< The left operand / expression of the sum 
  const Expression<T>& op2;     //!< The right operand / expression of the sum 
};


//! \brief      A wrapper function that returns a Addition expression for the given matrices
//! \details    Sum will not be evaluated until later when the expression is finally assigned to a Matrix object - that will triggers evaluation 
//!             of each element of the expression in the expression tree
//! \return     An AddExpression object representing the sum of the two matrices
template <typename T>
AddExpression<T> operator+ (const Expression<T>& left, const Expression<T>& right)
{
  return AddExpression<T>(left, right);
}

} //namespace 




#endif