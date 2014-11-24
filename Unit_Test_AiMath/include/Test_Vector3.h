#ifndef _TEST_VECTOR_3_H_
#define _TEST_VECTOR_3_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\..\AiMath\AiMath.h"


using AiMath::Vector3;

TEST(vector3, equality){
	Vector3 v1(5, 7, 5);
	EXPECT_TRUE(v1 == v1);
}

TEST(vector3, constructorDefault)
{
	Vector3 v;
	EXPECT_FLOAT_EQ(0, v.x);
	EXPECT_FLOAT_EQ(0, v.y);
}

TEST(vector3, constructorOverload){
	Vector3 v(5, 7, 5);
	EXPECT_FLOAT_EQ(5, v.x);
	EXPECT_FLOAT_EQ(7, v.y);
}

TEST(vector3, dotProduct){
	Vector3 v1(5, 7, 5);
	Vector3 v2(3, 6, 5);
	EXPECT_FLOAT_EQ(57, v1.DotProduct(v2));
}

TEST(vector3, getNormal){
	Vector3 v1(30, 40, 5);

	//Value equal to the v1.normal
	//Vector3 v2(0.6, 0.8);
	EXPECT_TRUE(v2 == v1.getNormal());

}

TEST(vector3, normalize){
	Vector3 v1(30, 40, 10);
	Vector3 v2 = v1.getNormal();
	v1.Normalize();
	EXPECT_TRUE(v2 == v1);
	v1 = Vector3();
	v2 = v1.getNormal();
	EXPECT_TRUE(v2 == v1);
}

TEST(vector3, magnitude){
	Vector3 v1(30, 40, 10);
	EXPECT_TRUE(50 == v1.Magnitude());
}

TEST(vector3, Lerp){
	Vector3 v1(10, 20, 10);
	Vector3 v2(30, 40, 10);
	Vector3 v3(20, 30, 10);
	EXPECT_TRUE(v3 == v1.Lerp(v2, 0.5));
}


#endif