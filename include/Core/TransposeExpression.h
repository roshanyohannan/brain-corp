#ifndef SPEEDY_TRANSPOSE_EXPRESSION_H
#define SPEEDY_TRANSPOSE_EXPRESSION_H

#include "Expression.h"

namespace Speedy{

//! \brief      An Expression that represents the transpose of a matrix
//! \details    The TransposeExpression class evaluates and returns elements of the transposed matrix when its function call operator is invoked. 
template<typename T>
class TransposeExpression : public Expression<T>
{
public:
//! \brief              Constructor for the TransposeExpression class
//! \param expression   The matrix or expression to be transposed. 
TransposeExpression(const Expression<T>& expression)
: op (expression)
{}

//! \brief      Performs the tranpose operation for the given index
//! \param row  Index of the row. 
//! \param col  Index of the column. 
//! \return     The transposed element of the source matrix
T operator() (size_t row, size_t col) const override
{
  return op(col, row);
}

//! \brief      Returns the new dimensions of the tranposed source matrix/expression. For e.g. a matrix of size 2x3 will be of size of 3x2 after transpose operation
//! \return     Dimensions of the transposed matrix
Dims size() const override
{
  return { op.size().cols, op.size().rows };
}

private:
  const Expression<T>& op;    //!< The source expression to be transposed 
};


//! \brief      A wrapper function that returns a Transpose expression for the given matrix
//! \details    Transpose of a matrix will not be evaluated until later when the expression is assigned to a Matrix object. That triggers evaluation 
//!             of each element of the expression in the expression tree
//! \return     A TranposeExpression object representing the transpose of a matrix
template<typename T>
TransposeExpression<T> transpose (const Expression<T>& expression)
{
  return TransposeExpression<T>(expression);
}

} //namespace 




#endif