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
