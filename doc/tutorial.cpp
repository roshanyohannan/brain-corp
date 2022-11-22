#include "Speedy.h"

using namespace Speedy

int main(int argc, char** argv)
{
    //Constructors
    Matrix<int> m0;                                 // Create empty matrix size 0x0
    
    Matrix<int> m1(3,3);                            // Create a square matrix of size 3x3 with all elements set to 0

    Matrix<float> m2(2,3);                          // Create a single precision matrix with 2 rows and 3 columns
                                                    // all elements are initialized to 0.0f

    Matrix<double> m3 {{ 1.0,   0.0,    0.0 },      // Create a matrix from intializer list. Rows and columns are deduced automatically
                       { 0.0,   1.0,    0.0 },
                       { 0.0,   0.0,    1.0 }};



    //Assignment
    Matrix<float> m5(100, 100);
   
    m5 = m2;                                         // OK: Assignment within same type works and a deep copy is created

    m5 = m0;                                         // Compilation error. Cannot assign to a matrix with a different base data type 

    m5 += m2;                                        // OK: m5 is updated in place

    Matrix<float> m6(6, 7);
    m5 += m6;                                        // Runtime error. Matrices of different sizes cannot be added

    Matrix<float> x(2, 3);
    Matrix<float> y(3, 2);
    x *= y;                                          // OK. Compatible matrices can be multiplied 


    //Element Access
    m1(2, 2) = 42;                                   // Access element at row, col via function call operator. Indexing is zero based


    //Dimensions
    Dims dim = m1.size();                            // Access count of rows and columns in a matrix


    //Transpose
    Matrix<int> a {{ 1,  2 },
                   { 3,  4 }};

    Matrix<int> b = transpose(a);                    // Transpose of matrix is evaluated lazily


    //Multiplication
    Matrix<int> d = a * b;                           // Multiplication is evaluated lazily

    
    //Expressions
    Matrix<int> e = (a + b) * transpose(a * b);      // Arbitrarily long expressions are evaluated efficiently due to lazy evaluation


    //Print
    std::cout << e;                                 // Pretty print matrix (or expressions) using regular cout
    std::cout << a * b;


    //Version info
    std::cout << "Version: " << version();          // Print Semver format version (Major.Minor.Patch)



    return 0;
}