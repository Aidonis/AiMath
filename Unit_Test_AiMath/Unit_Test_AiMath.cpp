// Unit_Test_AiMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "gtest/gtest.h"
#include "Test_Vector2.h"
#include "Test_Vector3.h"
#include "Test_Matrix3.h"
#include "Test_Matrix4.h"
#include "Test_Vector4.h"
#include "Test_AiMath.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//method initializes Google framework and must be called BEFORE RUN_ALL_TESTS
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
	It must be called only once in the code because multiple calls lead to conflicts and are not supported.
	*/
	return RUN_ALL_TESTS();
}