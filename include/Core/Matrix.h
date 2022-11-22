#include "Expression.h"
#include <vector>
#include <initializer_list>

#ifndef SPEEDY_MATRIX_H
#define SPEEDY_MATRIX_H

namespace Speedy {

class Matrix : public Expression
{

public:
Matrix(int rows, int cols) : dims(rows,cols)
{
    data.resize(rows * cols, 0);
}

Matrix(const Expression& expression)
{
    dims = expression.size();
    data.resize(dims.rows * dims.cols);

    for(int i = 0; i < dims.rows; i++)
        for(int j = 0; j < dims.cols; j++)
            this->operator()(i,j) = expression(i,j);
}

Matrix(std::initializer_list<std::vector<int>> list)
{
    dims.rows = list.size();
    dims.cols = list.size() == 0 ? 0 : list.begin()->size();

    for(const auto& row : list)
    {
        if(row.size() != dims.cols) throw(std::invalid_argument("column count is inconsistent"));

        data.insert(data.end(), row.begin(), row.end());
    }
}

int operator() (int row, int col) const override
{
    if(row < 0 || row > dims.rows || col < 0 || col > dims.cols)
        throw(std::invalid_argument("argument is outside bounds"));

    return data[row * dims.cols + col];
}

int& operator() (int row, int col)
{
    if(row < 0 || row > dims.rows || col < 0 || col > dims.cols)
        throw(std::invalid_argument("argument is outside bounds"));

    return data[row * dims.cols + col];
}

Dims size() const override
{
    return dims;
}

private:
    Dims                dims;
    std::vector<int>    data;
};


} // namespace

#endif