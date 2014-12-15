#ifndef _TEST_AiMath_H_
#define _TEST_AiMAth_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "AiMath.h"

using namespace AiMath;

TEST(amath, DegToRad){
	//45 degrees to .7853975 rads
	EXPECT_NEAR(.7853975, AMath::DegreesToRadians(45), .001);
}

TEST(amath, RadToDeg){
	// .7853975 rads to 45 degrees
	EXPECT_NEAR(45.0f, AMath::RadiansToDegrees(.7853975), .001);
}

#endif