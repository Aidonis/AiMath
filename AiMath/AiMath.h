#ifndef _AI_Math_H_
#define _AI_Math_H_

#include <math.h>
#include <iostream>

namespace AiMath{
	class Vector2
	{
	public:
		Vector2();
		~Vector2();

		Vector2(float a_x, float a_y);

		float x, y;

		Vector2 operator + (const Vector2& a_addVector);  //
		Vector2 operator + (const float& a_addScalar);  //

		Vector2 operator += (const Vector2& a_addVector);  //
		Vector2 operator += (const float& a_addScalar);  //

		Vector2 operator - (const Vector2& a_subVector);  //
		Vector2 operator - (const float& a_subScalar);  //

		Vector2 operator -= (const Vector2& a_subVector); //
		Vector2 operator -= (const float& a_subScalar); //

		Vector2 operator * (const float& a_Scalar);
		Vector2 operator *= (const float& a_Scalar);

		Vector2 operator / (const float& a_Scalar);
		Vector2 operator /= (const float& a_Scalar);

		Vector2 operator = (const Vector2& a_Source);
		bool operator == (const Vector2& a_Source);

	};
}
#endif