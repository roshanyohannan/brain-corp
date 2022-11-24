#ifndef SPEEDY_MATRIX_H
#define SPEEDY_MATRIX_H

#include "Expression.h"
#include <vector>
#include <initializer_list>

namespace Speedy {

///! \brief     Represents an arbitrary sized matrix of M x N dynamically allocated elements.
template<typename T>
class Matrix : public Expression<T>
{

public:
//! \brief      Default constructor that creates a 0x0 matrix
Matrix()
{}

//! \brief       Parameterized constructor that creates a row x col sized matrix. All elements are default intialized.
//! \param rows  Row count 
//! \param cols  Column count 
Matrix(size_t rows, size_t cols) : dims(rows,cols)
{
    data.resize(rows * cols, {});
}

//! \brief              Constructor that evaluates an expression tree and assigns elementwise result to the new matrix
//! \param expression   expression object that needs to be evaluated 
Matrix(const Expression<T>& expression)
{
    dims = expression.size();
    data.resize(dims.rows * dims.cols);

    for(int i = 0; i < dims.rows; i++)
        for(int j = 0; j < dims.cols; j++)
            this->operator()(i,j) = expression(i,j);
}


//! \brief              Constructor that takes an initialization list and constructs a matrix. Rows and columns are deduced automatically
//! \details            Usage: Matrix<double> m3 {{ 1.0,   0.0,    0.0 },
//!                                               { 0.0,   1.0,    0.0 },
//!                                               { 0.0,   0.0,    1.0 }};
//! \param list         Initialization list. The column count should  be consistent across rows else invalid_argument exception is thrown 
Matrix(std::initializer_list<std::vector<T>> list)
{
    dims.rows = list.size();
    dims.cols = list.size() == 0 ? 0 : list.begin()->size();

    for(const auto& row : list)
    {
        if(row.size() != dims.cols) throw(std::invalid_argument("inconsistent column count"));

        data.insert(data.end(), row.begin(), row.end());
    }
}

//! \brief      Accessor for the row,col element of the matrix.
//! \param row  index of row. It should be less than row count of the matrix else invalid_argument exception is thrown 
//! \param col  index of column. It should be less than col count of the matrix else invalid_argument exception is thrown
T operator() (size_t row, size_t col) const override
{
    if(row > dims.rows || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

//! \brief      Mutator for the row,col element of the matrix
//! \param row  index of row. It should be less than row count of the matrix else invalid_argument exception is thrown 
//! \param col  index of column. It should be less than col count of the matrix else invalid_argument exception is thrown
T& operator() (size_t row, size_t col)
{
    if(row > dims.rows || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

//! \brief     Accessor for matrix dimensions
Dims size() const override
{
    return dims;
}


private:
    Dims                dims;       //!< Dimensions of the matrix
    std::vector<T>      data;       //!< Underlying data of the matrix stored in a continguous container (std vector) which supports random element access
};


//! \brief Equality operator for two matrices. Performs elementwise equality check
template<typename T>
bool operator==(const Matrix<T>& left, const Matrix<T>& right)
{
    if(left.size() != right.size()) return false;

    for(int i = 0; i < left.size().rows; i++)
        for(int j = 0; j < left.size().cols; j++)
            if(left(i,j) != right(i,j))  return false;

    return true;
}

//! \brief Compund Addition operator. Adds the given right handside expression to the matrix and updates it in place.
template<typename T>
Matrix<T>& operator+= (Matrix<T>& left, const Expression<T>& expression)
{
    if(left.size() != expression.size())
        throw(std::invalid_argument("matrices are incompatible for addition"));

    for(int row = 0; row < left.size().rows; row++)
        for(int col = 0; col < left.size().cols; col++)
            left(row,col) += expression(row, col);

    return left;    
}

//! \brief Compund Multiplication operator. Multiplies the given right handside expression to the matrix and updates it in place.
template<typename T>
Matrix<T>& operator*= (Matrix<T>& matrix, const Expression<T>& expression)
{
    Dims left  = matrix    .size();
    Dims right = expression.size();

    if(left.cols != right.rows)
        throw(std::invalid_argument("matrices are incompatible for multiplication"));

    Matrix<T> result(left.rows, right.cols);

    for(int row = 0; row < left.rows; row++)
        for(int col = 0; col < right.cols; col++)
        {
            T sum{};
            for(int k = 0; k < left.cols; k++)  sum += matrix(row,k) * expression(k, col);
            result(row,col) = sum;
        }

    std::swap(matrix, result);

    return matrix;
}

} // namespace

#endif