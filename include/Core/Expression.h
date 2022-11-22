#include <stdint.h>

#ifndef SPEEDY_EXPRESSION_H
#define SPEEDY_EXPRESSION_H

namespace Speedy {

struct Dims
{
	Dims(int r, int c) : rows(r), cols(c)
	{ }

	Dims()
	{ }

	int rows = 0;
	int cols = 0;
};


class Expression
{
public:
	virtual int 	operator()	(int row, int col)	const = 0;
	virtual Dims 	size		()					const = 0;
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