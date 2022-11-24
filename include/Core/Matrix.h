#ifndef SPEEDY_MATRIX_H
#define SPEEDY_MATRIX_H

#include "Expression.h"
#include <vector>
#include <initializer_list>

namespace Speedy {

template<typename T>
class Matrix : public Expression<T>
{

public:
Matrix()
{}

Matrix(size_t rows, size_t cols) : dims(rows,cols)
{
    data.resize(rows * cols, {});
}

Matrix(const Expression<T>& expression)
{
    dims = expression.size();
    data.resize(dims.rows * dims.cols);

    for(int i = 0; i < dims.rows; i++)
        for(int j = 0; j < dims.cols; j++)
            this->operator()(i,j) = expression(i,j);
}

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

T operator() (size_t row, size_t col) const override
{
    if(row > dims.rows || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

T& operator() (size_t row, size_t col)
{
    if(row > dims.rows || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

Dims size() const override
{
    return dims;
}


private:
    Dims                dims;
    std::vector<T>      data;
};

template<typename T>
bool operator==(const Matrix<T>& left, const Matrix<T>& right)
{
    if(left.size() != right.size()) return false;

    for(int i = 0; i < left.size().rows; i++)
        for(int j = 0; j < left.size().cols; j++)
            if(left(i,j) != right(i,j))  return false;

    return true;
}

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