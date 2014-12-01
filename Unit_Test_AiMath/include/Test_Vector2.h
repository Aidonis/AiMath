#ifndef _TEST_VECTOR_2_H_
#define _TEST_VECTOR_2_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "..\..\AiMath\AiMath.h"

using AiMath::Vector2;

TEST(vector2, equality){
	Vector2 v1(5, 7);
	Vector2 v2(7, 5);
	EXPECT_TRUE(v1 == v1);
	EXPECT_FALSE(v1 == v2);
}

TEST(vector2, constructorDefault){
	Vector2 v;
	EXPECT_FLOAT_EQ(0, v.x);
	EXPECT_FLOAT_EQ(0, v.y);
}

TEST(vector2, copyConstructor){
	Vector2 v(1, 2);
	Vector2 v2(v);
	EXPECT_EQ(v, v2);
	EXPECT_EQ(v, v);

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
	Vector2 v3(0,0);
	EXPECT_TRUE(v3 == v3.getNormal());
	EXPECT_TRUE(v2 == v1.getNormal());

}

TEST(vector2, normalize){
	Vector2 v1(30, 40);
	Vector2 v2 = v1.getNormal();
	v1.Normalize();
	EXPECT_TRUE(v2 == v1);
	v1 = Vector2();
	v2 = v1.getNormal();
	EXPECT_TRUE(v2 == v1);
	Vector2 v3;
	v2 = v3.Normalize();
	EXPECT_TRUE(v3 == v2);
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

TEST(vector2, assignmentOperator){
	Vector2 v1(5, 10);
	Vector2 v2 = v1;
	EXPECT_TRUE(v2 == v1);

	//change v1 and verify v2 did not change
	v1.x = 10;
	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(5, 10));

	//verify chaining is possible a=b=c
	Vector2 v3 = v2 = v1;

	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(10, 10));
	EXPECT_TRUE(v3 == Vector2(10, 10));
}

TEST(vector2, additionOperator){

	Vector2 v1(10, 10);
	Vector2 v2(5, 5);
	Vector2 v3 = v1 + v2;

	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(5, 5));
	EXPECT_TRUE(v3 == Vector2(15, 15));

	//chaining
	v3 = v1 + v1 + v2;
	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(5, 5));
	EXPECT_TRUE(v3 == Vector2(25, 25));
}

TEST(vector2, additionAssignmentOperator){
	Vector2 v1(5, 5);
	Vector2 v2(10, 10);
	v1 += v2;

	EXPECT_TRUE(v1 == Vector2(15, 15));
	EXPECT_TRUE(v2 == Vector2(10, 10));

	//verify chaining
	(v2 += Vector2(1, 1)) += Vector2(4, 4);

	EXPECT_TRUE(v2 == Vector2(15, 15));
}

TEST(vector2, subtractOperator){
	Vector2 v1(10, 10);
	Vector2 v2(5, 5);
	Vector2 v3 = v1 - v2;

	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(5, 5));
	EXPECT_TRUE(v3 == Vector2(5, 5));

	//chaining
	v3 = v1 - v2 - v2;
	EXPECT_TRUE(v1 == Vector2(10, 10));
	EXPECT_TRUE(v2 == Vector2(5, 5));
	EXPECT_TRUE(v3 == Vector2(0, 0));

}

#endif