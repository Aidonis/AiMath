#ifndef _TEST_VECOTOR_4_H_
#define _TEST_VECTOR_4_H_

//Google Test API include
#include "gtest/gtest.h"

//Code to test
#include "..\..\AiMath\AiMath.h"

using AiMath::Vector4;

TEST(vector4, constructorDefault)
{
	Vector4 v;
	EXPECT_FLOAT_EQ(0, v.x);
	EXPECT_FLOAT_EQ(0, v.y);
	EXPECT_FLOAT_EQ(0, v.z);
	EXPECT_FLOAT_EQ(0, v.w);
}

TEST(vector4, constructorFloats)
{
	Vector4 v(1.3f, 2.5f, -5.0f, -3.14159f);
	EXPECT_FLOAT_EQ(1.3f, v.x);
	EXPECT_FLOAT_EQ(2.5f, v.y);
	EXPECT_FLOAT_EQ(-5.0f, v.z);
	EXPECT_FLOAT_EQ(-3.14159f, v.w);
}

TEST(vector4, constructorHex)
{
	Vector4 v1(0x00000000);
	Vector4 v2(0xFFFFFFFF);
	Vector4 red(0xFF0000FF);
	Vector4 green(0x00FF00FF);
	Vector4 blue(0x0000FF7F);

	EXPECT_EQ(Vector4(), v1);
	EXPECT_EQ(Vector4(255, 255, 255, 255), v2);
	EXPECT_EQ(Vector4(255, 0, 0, 255), red);
	EXPECT_EQ(Vector4(0, 255, 0, 255), green);
	EXPECT_EQ(Vector4(0, 0, 255, 127), blue);
}

TEST(vector4, constructorCopy)
{
	Vector4 v(1, 2, 3, 4);
	Vector4 v2(v);
	EXPECT_FLOAT_EQ(1, v.x);
	EXPECT_FLOAT_EQ(2, v.y);
	EXPECT_FLOAT_EQ(3, v.z);
	EXPECT_FLOAT_EQ(4, v.w);

	//verify param still same
	EXPECT_TRUE(&v != &v2);
	EXPECT_TRUE(v == v2);
}

#endif