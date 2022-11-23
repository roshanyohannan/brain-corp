#include "Speedy.h"
#include <gtest/gtest.h>

using namespace Speedy;

TEST(Construction, EmptyMatrix)
{
	Matrix<int> m;
	
	Dims result{};

	EXPECT_EQ(m.size(), result);
}


TEST(Construction, SizedMatrix)
{
	Matrix<int> m(2,2);
	
	Dims result(2,2);

	EXPECT_EQ(m.size(), result);

	for(int i = 0; i < 2; i++)
		for(int j =0; j < 2; j++)
			EXPECT_EQ(m(i,j), 0);
}

TEST(Construction, InitializationList)
{
	Matrix<int> m  {{ 1,  0,  0 },
                    { 0,  1,  0 },
                    { 0,  0,  1 }};
	
	Dims result(3,3);

	EXPECT_EQ(m.size(), result);

	for(int i = 0; i < 2; i++)
		for(int j =0; j < 2; j++)
			EXPECT_EQ(m(i,j), (i == j ? 1 : 0));	
}

TEST(Construction, Copy)
{
	Matrix<int> a  {{ 1,  0,  0 },
                    { 0,  1,  0 },
                    { 0,  0,  1 }};

    Matrix<int> b(a);

	EXPECT_EQ(a.size(), b.size());
	EXPECT_TRUE(a == b);
}


TEST(Operations, Addition)
{
	Matrix<int> a  {{ 1,  1,  1 },
                    { 2,  2,  2 },
                    { 3,  3,  3 }};

	Matrix<int> b  {{ 8,  8,  8 },
                	{ 7,  7,  7 },
                	{ 6,  6,  6 }};


    Matrix<int> result = a + b;

    Matrix<int> expected {{ 9,  9,  9 },
						  { 9,  9,  9 },
						  { 9,  9,  9 }};

	EXPECT_TRUE(expected == result);
}

TEST(Operations, CompoundAddition)
{
	Matrix<int> a  {{ 1,  1,  1 },
                    { 2,  2,  2 },
                    { 3,  3,  3 }};

	Matrix<int> b  {{ 8,  8,  8 },
                	{ 7,  7,  7 },
                	{ 6,  6,  6 }};


    a += b;

    Matrix<int> expected {{ 9,  9,  9 },
						  { 9,  9,  9 },
						  { 9,  9,  9 }};

	EXPECT_TRUE(a == expected);
}


TEST(Operations, Multiplication)
{
	Matrix<int> a  {{ 1,  1 },
                    { 2,  2 },
                    { 3,  3 }};

	Matrix<int> b  {{ 8,  8,  8 },
                	{ 7,  7,  7 }};


    Matrix<int> result = a * b;

    Matrix<int> expected {{ 15,  15,  15 },
						  { 30,  30,  30 },
						  { 45,  45,  45 }};

	EXPECT_TRUE(expected == result);
}

TEST(Operations, CompoundMultiplication)
{
	Matrix<int> a  {{ 1,  1 },
                    { 2,  2 },
                    { 3,  3 }};

	Matrix<int> b  {{ 8,  8,  8 },
                	{ 7,  7,  7 }};


    a *= b;

    Matrix<int> expected {{ 15,  15,  15 },
						  { 30,  30,  30 },
						  { 45,  45,  45 }};

	EXPECT_TRUE(a == expected);
}

TEST(Operations, Transpose)
{
	Matrix<int> a  {{ 1,  1,  1 },
                    { 2,  2,  2 },
                    { 3,  3,  3 }};

    Matrix<int> result = transpose(a);

    Matrix<int> expected {{ 1, 2, 3 },
						  { 1, 2, 3 },
						  { 1, 2, 3 }};

	EXPECT_TRUE(expected == result);
}
