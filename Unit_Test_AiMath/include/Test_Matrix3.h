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

#endif