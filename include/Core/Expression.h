#include <stdint.h>

#ifndef SPEEDY_EXPRESSION_H
#define SPEEDY_EXPRESSION_H

namespace Speedy {

//! \brief      Count of Rows and Columns in a given matrix
struct Dims
{
    Dims(size_t r, size_t c) : rows(r), cols(c)
    { }

    Dims()
    { }

    size_t rows = 0;
    size_t cols = 0;
};


//! \brief      Abstract class representing a matrix or an operation betweem two matrices 
//! \details    This class provides the interface required to build computation tree at run time and evaluate elements of the result. It allows representing 
//!             any matrix expression, for e.g. A + B * C, without computing the result eagerly. This allows delaying evaluation till the result matrix is  
//!             computed element wise thus avoiding the creation of temporary matrices to hold the result of B*C and achieving result within a single iteration (loop fusion).
//!             Note that this can also be done at compile time using CRTP technique (and avoid the performance penalty for run time dispatch in virtual functions)
template<typename T>
class Expression
{
public:
    //! \brief      interface to evaluate the row, col element of a given expression
    //! \param row  Index of the row of the result matrix. 
    //! \param col  Index of the column  of the result matrix. 
    //! \return     The element at index row,col in the result matrix
    virtual T       operator()  (size_t row, size_t col)  const = 0;
    

    //! \brief      interface to return dimensions of the expression
    //! \return     Dimensions of the expression
    virtual Dims    size        ()                        const = 0;
};


//! \brief      Equality operator for Dimensions structure
bool operator== (const Dims& left, const Dims& right)
{
    return (left.rows == right.rows) && (left.cols == right.cols);
}

//! \brief      Inequal operator for Dimensions structure
bool operator!= (const Dims& left, const Dims& right)
{
    return !(left == right);
}


} // namespace

#endif