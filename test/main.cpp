#include "Speedy.h"

using namespace Speedy;
int main(int argc, char** argv)
{
    
    Matrix m(2,3);

    m(0,0) = 1;

    Matrix m2 {{ 1,  202,    3  },
               { 4,    5,    6  },
               { -7, 821,  900  }};

    std::cout << "M2 : \n" << m2;


    Matrix m3 {{ 1,  202,    3  },
               { 4,    5,    6  },
               { -7, 821,  900  }};

    std::cout << "Sum : \n" << m2 + m3;


    Matrix m4 {{ 0,     0,    3 },
               { 0,     0,    6 },
               { 0,     0,    0 }};


    std::cout << "Product : \n" << m2 * m4;

    std::cout << "Tranpose of M2: \n" << transpose(m2);

    std::cout << "Tranpose of product(m2, m4): \n" << transpose(m2 * m4);
    
    return 0;
}
