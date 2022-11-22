#include "Expression.h"
#include <vector>
#include <initializer_list>

#ifndef SPEEDY_MATRIX_H
#define SPEEDY_MATRIX_H

namespace Speedy {

template<typename T>
class Matrix : public Expression<T>
{

public:
Matrix()
{}

Matrix(int rows, int cols) : dims(rows,cols)
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

T operator() (int row, int col) const override
{
    if(row < 0 || row > dims.rows || col < 0 || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

T& operator() (int row, int col)
{
    if(row < 0 || row > dims.rows || col < 0 || col > dims.cols)
        throw(std::invalid_argument("out-of-bounds access"));

    return data[row * dims.cols + col];
}

Dims size() const override
{
    return dims;
}

Matrix<T>& operator+= (const Expression<T>& expression)
{
    if(dims != expression.size())
        throw(std::invalid_argument("matrices are incompatible for addition"));

    for(int row = 0; row < dims.rows; row++)
        for(int col = 0; col < dims.cols; col++)
            this->operator()(row,col) += expression(row, col);

    return *this;    
}

Matrix<T>& operator*= (const Expression<T>& expression)
{
    Dims other = expression.size();

    if(dims.cols != other.rows)
        throw(std::invalid_argument("matrices are incompatible for multiplication"));

    for(int row = 0; row < dims.rows; row++)
        for(int col = 0; col < other.cols; col++)
        {
            T sum{};
            for(int k = 0; k < dims.cols; k++)  sum += this->operator()(row,k) * expression(k, col);
            this->operator()(row,col) = sum;
        }

    return *this;    
}


private:
    Dims                dims;
    std::vector<T>      data;
};


} // namespace

#endif