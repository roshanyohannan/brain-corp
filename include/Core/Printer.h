#include "Matrix.h"
#include <ostream>
#include <iomanip>

#ifndef SPEEDY_PRINTER_H
#define SPEEDY_PRINTER_H


std::ostream& operator << (std::ostream& out, const Speedy::Matrix& matrix)
{
    for(int i = 0; i < matrix.size().rows; i++)
    {
        out << "(";
        
        for(int j = 0; j < matrix.size().cols; j++)
            out << std::setw(10) << matrix(i,j);
        
        out << ")";
        out << std::endl;
    }

    return out;
}



#endif