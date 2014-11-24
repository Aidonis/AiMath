#ifndef _TEST_Matrix_3_H_
#define _TEST_Matrix_3_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\..\AiMath\AiMath.h"

using AiMath::Matrix3;

TEST(matrix3, constructorDefault)
{
	Matrix3 m;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			EXPECT_FLOAT_EQ(0, m.matrix[row][col]);
		}
	}
}

TEST(matrix3, constructor)
{
	Matrix3 m(
		10, 11, 12,
		20, 21, 22,
		30, 31, 32);

	EXPECT_FLOAT_EQ(10, m.matrix[0][0]);
	EXPECT_FLOAT_EQ(11, m.matrix[0][1]);
	EXPECT_FLOAT_EQ(12, m.matrix[0][2]);
	EXPECT_FLOAT_EQ(20, m.matrix[1][0]);
	EXPECT_FLOAT_EQ(21, m.matrix[1][1]);
	EXPECT_FLOAT_EQ(22, m.matrix[1][2]);
	EXPECT_FLOAT_EQ(30, m.matrix[2][0]);
	EXPECT_FLOAT_EQ(31, m.matrix[2][1]);
	EXPECT_FLOAT_EQ(32, m.matrix[2][2]);

}

#endif