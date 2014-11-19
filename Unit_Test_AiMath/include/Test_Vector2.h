#ifndef _TEST_VECTOR_2_H_
#define _TEST_VECTOR_2_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\AiMath\AiMath.h"

using AiMath::Vector2;

TEST(vector2, equality){
	Vector2 v1(5, 7);
	EXPECT_TRUE(v1 == v1);
}

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

TEST(vector2, getNormal){
	Vector2 v1(30, 40);
	Vector2 v2(0.6, 0.8);
	EXPECT_TRUE(v2 == v1.getNormal());

}

TEST(vector2, normalize){
	Vector2 v1(30, 40);
	Vector2 v2 = v1.getNormal();
	v1.Normalize();
	EXPECT_TRUE(v2 == v1);
}

TEST(vector2, magnitude){
	Vector2 v1(30, 40);
	EXPECT_TRUE(50 == v1.Magnitude());
}

TEST(vector2, Lerp){
	Vector2 v1(10, 20);
	Vector2 v2(30, 40);
	Vector2 v3(20, 30);
	EXPECT_TRUE(v3 == v1.Lerp(v2, 0.5));
}


#endif