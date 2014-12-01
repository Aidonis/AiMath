#ifndef _TEST_Matrix_3_H_
#define _TEST_Matrix_3_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\..\AiMath\AiMath.h"

using namespace AiMath;

TEST(matrix3, constructorDefault){
	Matrix3 m;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			EXPECT_FLOAT_EQ(0, m.matrix[row][col]);
		}
	}
}

TEST(matrix3, constructor){
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

TEST(matrix3, copyConstructor){
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);

	Matrix3 m2(m);

	EXPECT_TRUE(m2 == m);
	//verify copy not same object
	EXPECT_FALSE(&m2 == &m) << "expect: " << &m2 << "result: " << &m;
}

TEST(matrix3, equality){
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	EXPECT_TRUE(m == m);
}

TEST(matrix3, Transpose){
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);

	Matrix3 m2(
		1, 4, 7,
		2, 5, 8,
		3, 6, 9);

	m.Transpose();

	EXPECT_TRUE(m == m2);

}

TEST(matrix3, GetTranspose){
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);

	Matrix3 m2(
		1, 4, 7,
		2, 5, 8,
		3, 6, 9);

	EXPECT_TRUE(m.GetTranspose() == m2);
}

//Operator Tests
TEST(matrix3, bracketOperator)
{
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	float* v = m[0];
	float f = v[2];
	EXPECT_EQ(3, f);

	f = m[1][1];
	EXPECT_EQ(5, f);
}

TEST(matrix3, doubleBracketOperator)
{
	Matrix3 m(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);

	EXPECT_FLOAT_EQ(5, m[1][1]);
	EXPECT_FLOAT_EQ(3, m[0][2]);

	EXPECT_FLOAT_EQ(9, m[2][2]);
}

TEST(matrix3, getVector3FromMatrix){
	Matrix3 mRow(
		0, 1, 2,
		3, 4, 5,
		6, 7, 8);

	Matrix3 mCol(
		0, 3, 6,
		1, 4, 7,
		2, 5, 8);

	Vector3 result = Matrix3::GetVector3(ROW, 0, mRow);
	EXPECT_TRUE(result == Vector3(0, 1, 2));

	result = Matrix3::GetVector3(ROW, 1, mRow);
	EXPECT_TRUE(result == Vector3(3, 4, 5));

	result = Matrix3::GetVector3(ROW, 2, mRow);
	EXPECT_TRUE(result == Vector3(6, 7, 8));

	result = Matrix3::GetVector3(COL, 0, mCol);
	EXPECT_TRUE(result == Vector3(0, 1, 2));

	result = Matrix3::GetVector3(COL, 1, mCol);
	EXPECT_TRUE(result == Vector3(3, 4, 5));

	result = Matrix3::GetVector3(COL, 2, mCol);
	EXPECT_TRUE(result == Vector3(6, 7, 8));

}

TEST(matrix3, identity){
	Matrix3 expect(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	EXPECT_TRUE(expect == Matrix3::Identity());
}

TEST(matrix3, transform){
	Matrix3 m(
		3, 12, 3,
		7, 10, 4,
		0, 0, 1);
	Vector3 v(8, 7, 2);
	Vector3 result = m.VectorTransform(v);
	Vector3 expected(114, 134, 2);

	EXPECT_EQ(expected, result);
	EXPECT_EQ(v, Vector3(8, 7, 2));
	EXPECT_EQ(m, Matrix3(
		3, 12, 3,
		7, 10, 4,
		0, 0, 1));

}

TEST(matrix3, orthographicProjection){
	Matrix3 expect(
		1, 0, 0,
		0, 1, 0,
		0, 0, 0);
	Matrix3 result = Matrix3::OrthographicProjection();
	EXPECT_EQ(expect, result);

}



//Operators
//
TEST(matrix3, additionOperator){
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1);

	Matrix3 result = m2 + m1;

	Matrix3 expect(
		10, 10, 10,
		10, 10, 10,
		10, 10, 10);

	EXPECT_TRUE(expect == result);
	EXPECT_TRUE(m1 == Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9));
	EXPECT_TRUE(m2 == Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));

	//verify chaining 
	result = m1 + m2 + result;
	expect = Matrix3(
		20, 20, 20,
		20, 20, 20,
		20, 20, 20);

	EXPECT_TRUE(expect == result);
	EXPECT_TRUE(m1 == Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9));
	EXPECT_TRUE(m2 == Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));
}

TEST(matrix3, subtractOperator){
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1);

	Matrix3 result = m2 - m1;

	Matrix3 expect(
		8, 6, 4,
		2, 0, -2,
		-4, -6, -8);
	EXPECT_TRUE(expect == result);
	EXPECT_TRUE(m1 == Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9));
	EXPECT_TRUE(m2 == Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));

	//verify chaining 
	result = m2 - m1 - m1;
	expect = Matrix3(
		7, 4, 1,
		-2, -5, -8,
		-11, -14, -17);

	EXPECT_TRUE(expect == result);
	EXPECT_TRUE(m1 == Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9));
	EXPECT_TRUE(m2 == Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));
}

TEST(matrix3, additionAssignemntOperator)
{
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1);
	Matrix3 expect(
		10, 10, 10,
		10, 10, 10,
		10, 10, 10);
	EXPECT_TRUE(expect == (m1 += m2));
	EXPECT_TRUE(m2 ==
		Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));
}

TEST(matrix3, subtractAssignemntOperator)
{
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1);
	Matrix3 expect(
		-8, -6, -4,
		-2, 0, 2,
		4, 6, 8);
	EXPECT_TRUE(expect == (m1 -= m2));
	EXPECT_TRUE(m2 ==
		Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));
}

TEST(matrix3, productOperatorVector2){
	Matrix3 m(
		3, 12, 6,
		7, 10, 4,
		5, 2, 9);
	Vector2 v(
		8,
		7);
	Vector2 result = m * v;
	Vector2 expected(
		114,
		130);

	EXPECT_EQ(expected, result);
	EXPECT_EQ(v, Vector2(8, 7));
	EXPECT_EQ(m, Matrix3(
		3, 12, 6,
		7, 10, 4,
		5, 2, 9));

	EXPECT_TRUE(v == (Matrix3::Identity() * v));
}

TEST(matrix3, productOperatorVector3)
{
	Matrix3 m(
		3, 12, 6,
		7, 10, 4,
		5, 2, 9);
	Vector3 v(
		8,
		7,
		2);
	Vector3 result = m * v;
	Vector3 expected(
		120,
		134,
		72);

	EXPECT_EQ(expected, result);
	EXPECT_EQ(v, Vector3(8, 7, 2));
	EXPECT_EQ(m, Matrix3(
		3, 12, 6,
		7, 10, 4,
		5, 2, 9));

	EXPECT_TRUE(v == (Matrix3::Identity() * v));
}

TEST(matrix3, productAssignemntOperator)
{
	Matrix3 m1(
		0, 1, 2,
		3, 4, 5,
		6, 7, 8);
	Matrix3 m2(
		0, 1, 2,
		3, 4, 5,
		6, 7, 8);
	m1 *= m2;
	Matrix3 expect(
		15, 18, 21,
		42, 54, 66,
		69, 90, 111);

	EXPECT_TRUE(expect == m1);
	EXPECT_TRUE(m2 == Matrix3(
		0, 1, 2,
		3, 4, 5,
		6, 7, 8));

	m1 = Matrix3(
		9, 6, 3,
		8, 5, 2,
		7, 4, 1);
	m2 = Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	m1 *= m2;
	expect = Matrix3(
		54, 72, 90,
		42, 57, 72,
		30, 42, 54);

	EXPECT_TRUE(expect == m1);
	EXPECT_TRUE(m2 == Matrix3(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9));

	//verify multiply identity equals same matrix
	EXPECT_TRUE(m2 == (m2 *= Matrix3::Identity()));
}
#endif