#ifndef _TEST_VECTOR_2_H_
#define _TEST_VECTOR_2_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\AiMath\AiMath.h"

using AiMath::Vector2;

TEST(vector2, constructorDefault)
{
	Vector2 v;
	EXPECT_FLOAT_EQ(0, v.x);
	EXPECT_FLOAT_EQ(0, v.y);
}

TEST(vector2, constructorOverload){
	Vector2 v(5, 7);
	EXPECT_FLOAT_EQ(5, v.x);
	EXPECT_FLOAT_EQ(7, v.y);
}

TEST(vector2, dotProduct){
	Vector2 v1(5, 7);
	Vector2 v2(3, 6);
	EXPECT_FLOAT_EQ(57, v1.DotProduct(v2));
}

TEST(vector2, normal){
	Vector2 v1(30, 40);
	v1.Normal();

}

#endif