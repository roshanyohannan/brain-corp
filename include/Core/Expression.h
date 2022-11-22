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


struct Expression
{
	virtual int 	operator()	(int row, int col)	const = 0;
	virtual Dims 	size		()					const = 0;
};




} // namespace

#endif