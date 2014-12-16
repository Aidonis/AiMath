#ifndef _TEST_AMath_H_
#define _TEST_AMath_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "AiMath.h"

using namespace AiMath;

TEST(aimath, DegToRad){
	//45 degrees to .7853975 rads
	EXPECT_NEAR(.7853975, AMath::DegreesToRadians(45), .001);
}

TEST(aimath, RadToDeg){
	// .7853975 rads to 45 degrees
	EXPECT_NEAR(45.0f, AMath::RadiansToDegrees(.7853975), .001);
}

TEST(aimath, staticLerp){
	float start = 0;
	float end = 10;

	float r = AMath::LERP(start, end, 0);
	EXPECT_FLOAT_EQ(0, r);

	r = AMath::LERP(start, end, 1);
	EXPECT_FLOAT_EQ(10, r);

	r = AMath::LERP(start, end, .5);
	EXPECT_FLOAT_EQ(5, r);

}

TEST(aimath, isPowerOfTwo){
	unsigned int i = 10;
	EXPECT_FALSE(AMath::IsPowerOfTwo(i));

	i = 128;
	EXPECT_TRUE(AMath::IsPowerOfTwo(i));

	i = 0;
	EXPECT_FALSE(AMath::IsPowerOfTwo(i));

	i = 1;
	EXPECT_TRUE(AMath::IsPowerOfTwo(i));

	i = 127;
	EXPECT_FALSE(AMath::IsPowerOfTwo(i));
}

TEST(aimath, getNextPowerOfTwo){
	EXPECT_EQ(0, AMath::GetNextPowerOfTwo(0));
	EXPECT_EQ(2, AMath::GetNextPowerOfTwo(2));
	EXPECT_EQ(8, AMath::GetNextPowerOfTwo(6));
	EXPECT_EQ(16, AMath::GetNextPowerOfTwo(9));
	EXPECT_EQ(1073741824, AMath::GetNextPowerOfTwo(1073741823));
}

#endif