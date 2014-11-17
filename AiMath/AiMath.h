#ifndef _AI_Math_H_
#define _AI_Math_H_

#include <math.h>
#include <iostream>

namespace AiMath{
	
	class Vector2{
	public:
		Vector2();
		~Vector2();

		Vector2(float a_x, float a_y);

		float x, y;

		//Euler angle between two Vector2
		float EulerAngle(const Vector2& a_Vector);

		//Dot Product between two Vector2
		float DotProduct(const Vector2& a_Vector);

		//Normalized Vector2
		Vector2 Normal();
		void Normalize();

		//Magnitude of Vector2
		float Magnitude();

		//Linear Interpolation
		Vector2 Lerp(const Vector2& a_TerminatingVector, const float& a_InterpolationPoint);

		//Operators

		Vector2 operator+ (const Vector2& a_addVector);  //
		Vector2 operator+ (const float& a_addScalar);  //

		Vector2& operator+= (const Vector2& a_addVector);  //
		Vector2& operator+= (const float& a_addScalar);  //

		Vector2 operator- (const Vector2& a_subVector);  //
		Vector2 operator- (const float& a_subScalar);  //

		Vector2& operator-= (const Vector2& a_subVector); //
		Vector2& operator-= (const float& a_subScalar); //

		Vector2 operator* (const float& a_Scalar);
		Vector2& operator*= (const float& a_Scalar);

		Vector2 operator/ (const float& a_Scalar);
		Vector2& operator/= (const float& a_Scalar);

		Vector2& operator= (const Vector2& a_Source);
		bool operator== (const Vector2& a_Source);

	};

	class Vector3{
	public:
		Vector3();
		~Vector3();

		Vector3(float a_x, float a_y, float a_z);

		float x, y, z;

		//Euler angle between two Vector3
		float EulerAngle(const Vector3& a_Vector);

		//Dot Product between two Vector3
		float DotProduct(const Vector3& a_Vector);

		Vector3 CrossProduct(const Vector3 &a_Term);

		//Normalized Vector3
		Vector3 Normal();
		void Normalize();

		//Magnitude of Vector3
		float Magnitude();

		//Linear Interpolation
		Vector3 Lerp(const Vector3& a_TerminatingVector, const float& a_InterpolationPoint);

		//Operators

		Vector3 operator+ (const Vector3& a_addVector);  //
		Vector3 operator+ (const float& a_addScalar);  //

		Vector3& operator+= (const Vector3& a_addVector);  //
		Vector3& operator+= (const float& a_addScalar);  //

		Vector3 operator- (const Vector3& a_subVector);  //
		Vector3 operator- (const float& a_subScalar);  //

		Vector3& operator-= (const Vector3& a_subVector); //
		Vector3& operator-= (const float& a_subScalar); //

		Vector3 operator* (const float& a_Scalar);
		Vector3& operator*= (const float& a_Scalar);

		Vector3 operator/ (const float& a_Scalar);
		Vector3& operator/= (const float& a_Scalar);

		Vector3& operator= (const Vector3& a_Source);
		bool operator== (const Vector3& a_Source);

	};

	class Matrix3
	{
	public:

		Matrix3();

		Matrix3(const float& a_00,
			const float& a_01,
			const float& a_02,
			const float& a_10,
			const float& a_,
			const float& a_5,
			const float& a_6,
			const float& a_7,
			const float& a_8);


		Matrix3(const Matrix3 &a_Source);

		float matrix[3][3];

		~Matrix3();

		void Transpose();

		Vector3 VectorTransform(const Vector3 &a_Point);

		static Matrix3 IdentityMatrix();

		Vector3 Scale(const Vector3 &a_Vector);

		static Matrix3 MakeXRotationMatrix(float a_Radians);
		static Matrix3 MakeYRotationMatrix(float a_Radians);
		static Matrix3 MakeZRotationMatrix(float a_Radians);

		//Operators
		Matrix3	operator+ (const Matrix3& a_AddMatrix);
		Matrix3	operator+ (const float& a_AddScalar);
		Matrix3	operator+= (const Matrix3& a_AddMatrix);
		Matrix3	operator+= (const float& a_AddScalar);

		Matrix3	operator- (const Matrix3& a_SubMatrix);
		Matrix3	operator- (const float& a_SubScalar);
		Matrix3	operator-= (const Matrix3& a_SubMatrix);
		Matrix3	operator-= (const float& a_SubScalar);

		Matrix3	operator* (const Matrix3& a_FactorMatrix);
		Matrix3	operator* (const float& a_FactorScalar);
		Matrix3	operator*= (const Matrix3& a_FactorMatrix);
		Matrix3	operator*= (const float& a_FactorScalar);

		Matrix3 operator= (const Matrix3& a_Source);
		const bool operator== (const Matrix3& a_Term);
		const bool operator!= (const Matrix3& a_Term);
	};
}
#endif