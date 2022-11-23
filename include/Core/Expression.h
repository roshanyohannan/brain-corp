#include <stdint.h>

#ifndef SPEEDY_EXPRESSION_H
#define SPEEDY_EXPRESSION_H

namespace Speedy {

struct Dims
{
    Dims(size_t r, size_t c) : rows(r), cols(c)
    { }

    Dims()
    { }

    size_t rows = 0;
    size_t cols = 0;
};


template<typename T>
class Expression
{
public:
    virtual T       operator()  (size_t row, size_t col)  const = 0;
    virtual Dims    size        ()                        const = 0;
};



bool operator== (const Dims& left, const Dims& right)
{
    return (left.rows == right.rows) && (left.cols == right.cols);
}

bool operator!= (const Dims& left, const Dims& right)
{
    return !(left == right);
}


} // namespace

#endif