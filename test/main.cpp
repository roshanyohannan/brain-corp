#include "Speedy.h"

using namespace Speedy;
int main(int argc, char** argv)
{
	
	std::cout << "Hello world \n";
	Matrix m(2,3);

	m(0,0) = 1;

	Matrix m2 {{ 1,  202,  3 },
			   { 4,  5,  6 },
			   { -7,  821,  900 }};

	m2(2,2) = -1;
	std::cout << m2;

	return 0;
}