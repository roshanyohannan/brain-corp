#include "Speedy.h"

using namespace Speedy;
int main(int argc, char** argv)
{
    
    std::cout << "Version: " << version() << "\n";

    Matrix<int> m0;

    std::cout << m0.size().rows << " - " << m0.size().cols << "\n";

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

    //std::cout << "M5: \n" << m5;
    //std::cout << "M6: \n" << m6;

    //std::cout << "Adding float matrices m5 and m6: \n" << m5 * m6;

    Matrix<double> m21{{ 5.0,   0.0,    0.0 },
                       { 0.0,   5.0,    0.0 },
                       { 0.0,   0.0,    5.0 }};


   Matrix<int> m7(10,10);

   std::cout << "M7 before assignment: \n" << m7;
   
   m7 = m4;

   std::cout << "M7 after assignment: \n" << m7;

   m7 += m3;

   std::cout << "M7 after assignment: \n" << m7;
   

   Matrix<double> m22 {{ 1.0,   1.0,    8.0 },
                       { 11.0,  1.0,    1.0 },
                       { 1.0,   1.0,    0.0 }};

   std::cout << "M22 before: \n" << m22;

   std::cout << "M22 * M21 product: \n" << m22 * m21 << "\n"; 

   m22 *= m21;

   std::cout << "M22 now: \n" << m22; 

   Matrix<double> m23 = transpose(m22);

   std::cout << "Transpose M23 is \n" << m23; 

   

   return 0;
}
