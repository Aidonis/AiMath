#ifndef _TEST_Matrix_4_H_
#define _TEST_Matrix_4_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "AiMath.h"

using namespace AiMath;

TEST(matrix4, constructor)
{
	Matrix4 m(
		10, 11, 12, 13,
		20, 21, 22, 23,
		30, 31, 32, 33,
		40, 41, 42, 43);

	EXPECT_FLOAT_EQ(10, m.matrix[0][0]);
	EXPECT_FLOAT_EQ(11, m.matrix[0][1]);
	EXPECT_FLOAT_EQ(12, m.matrix[0][2]);
	EXPECT_FLOAT_EQ(13, m.matrix[0][3]);
	EXPECT_FLOAT_EQ(20, m.matrix[1][0]);
	EXPECT_FLOAT_EQ(21, m.matrix[1][1]);
	EXPECT_FLOAT_EQ(22, m.matrix[1][2]);
	EXPECT_FLOAT_EQ(23, m.matrix[1][3]);
	EXPECT_FLOAT_EQ(30, m.matrix[2][0]);
	EXPECT_FLOAT_EQ(31, m.matrix[2][1]);
	EXPECT_FLOAT_EQ(32, m.matrix[2][2]);
	EXPECT_FLOAT_EQ(33, m.matrix[2][3]);
	EXPECT_FLOAT_EQ(40, m.matrix[3][0]);
	EXPECT_FLOAT_EQ(41, m.matrix[3][1]);
	EXPECT_FLOAT_EQ(42, m.matrix[3][2]);
	EXPECT_FLOAT_EQ(43, m.matrix[3][3]);

}

TEST(matrix4, copyConstructor)
{
	Matrix4 m(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);

	Matrix4 m2(m);

	EXPECT_TRUE(m2 == m);
	//verify copy not same object
	EXPECT_FALSE(&m2 == &m) << "expect: " << &m2 << "result: " << &m;
}

#endif