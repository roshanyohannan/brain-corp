#include "Speedy.h"

using namespace Speedy;
int main(int argc, char** argv)
{
    
    Matrix<int> m(2,3);

    m(0,0) = 1;

    Matrix<int> m2 {{ 1,  202,    3  },
                    { 4,    5,    6  },
                    { -7, 821,  900  }};

    std::cout << "M2 : \n" << m2;


    Matrix<int> m3 {{ 1,  202,    3  },
                    { 4,    5,    6  },
                    { -7, 821,  900  }};

    std::cout << "Sum : \n" << m2 + m3;


    Matrix<int> m4 {{ 0,     0,    3 },
                    { 0,     0,    6 },
                    { 0,     0,    0 }};


    std::cout << "Product : \n" << m2 * m4;

    std::cout << "Tranpose of M2: \n" << transpose(m2);

    std::cout << "Tranpose of product(m2, m4): \n" << transpose(m2 * m4);

    Matrix<float> m5 {{ 1.3f, 2.4f, 3.4f },
                      { 1.3f, 2.4f, 3.4f },
                      { 1.3f, 2.4f, 3.4f }};
    
    Matrix<float> m6 {{ 1.0f, 1.0f, 1.0f },
                      { 1.0f, 1.0f, 1.0f },
                      { 1.0f, 1.0f, 1.0f }};

    std::cout << "M5: \n" << m5;
    std::cout << "M6: \n" << m6;

    std::cout << "Adding float matrices m5 and m6: \n" << m5 * m6;


    return 0;
}
