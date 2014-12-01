#ifndef _AI_Math_H_
#define _AI_Math_H_

#include <math.h>
#include <iostream>

namespace AiMath{
	
	enum MATRIX_MAJOR
	{
		ROW,
		COL
	};

	enum AXIS
	{
		X,
		Y,
		Z
	};

	class Vector2{
	public:
		Vector2();
		~Vector2();

		Vector2(float a_x, float a_y);
		Vector2(const Vector2& other);
		float x, y;

		//Euler angle between two Vector2
		float EulerAngle(const Vector2& a_Vector);

		//Dot Product between two Vector2
		float DotProduct(const Vector2& a_Vector);

		//Normalized Vector2
		Vector2 getNormal();
		Vector2& Normalize();

		//Magnitude of Vector2
		float Magnitude();

		//Linear Interpolation
		Vector2 Lerp(const Vector2& a_TerminatingVector, const float& a_InterpPoint);

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
		friend bool operator== (const Vector2& a_Lhs, const Vector2& a_Rhs);

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
		Vector3 getNormal();
		Vector3& Normalize();

		//Magnitude of Vector3
		float Magnitude();

		//Linear Interpolation
		Vector3 Lerp(const Vector3& a_endVector, const float& a_percent);

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

		Matrix3(const Matrix3& a_Matrix3);

		Matrix3(const float& a_00,
			const float& a_01,
			const float& a_02,
			const float& a_10,
			const float& a_11,
			const float& a_12,
			const float& a_20,
			const float& a_21,
			const float& a_22);

		float matrix[3][3];

		~Matrix3();

		static Vector3 GetVector3(MATRIX_MAJOR type, int index, const Matrix3& matrix);
		
		//Returns this matrix transposed
		Matrix3& Transpose();

		//Returns a new matrix the transpose of this matrix
		Matrix3 GetTranspose();

		Vector3 VectorTransform(const Vector3 &a_Point);

		static Matrix3 Identity();

		//Returns 3x3 orthographic projection matrix
		static Matrix3 OrthographicProjection();

		//Returns new rotation matrix.
		// Radians > 0 = counterclockwise rotation
		// Radians < 0 = clockwise rotation
		static Matrix3 SetupRotation(float a_Radians);

		//Returns new translation matrix
		static Matrix3 SetupTranslation(Vector2& a_Translation);

		//Returns new scaled matrix
		static Matrix3 SetupScale(Vector2& a_Scale);

		//Operators
		Matrix3	operator+ (const Matrix3& a_AddMatrix);
		Matrix3	operator+ (const float& a_AddScalar);
		Matrix3& operator+= (const Matrix3& a_AddMatrix);
		Matrix3& operator+= (const float& a_AddScalar);

		Matrix3	operator- (const Matrix3& a_SubMatrix);
		Matrix3	operator- (const float& a_SubScalar);
		Matrix3& operator-= (const Matrix3& a_SubMatrix);
		Matrix3& operator-= (const float& a_SubScalar);

		Matrix3	operator* (const Matrix3& a_FactorMatrix);
		Matrix3	operator* (const float& a_FactorScalar);
		Matrix3& operator*= (const Matrix3& a_FactorMatrix);
		Matrix3& operator*= (const float& a_FactorScalar);

		friend Vector2 operator*(const Matrix3& lhs, const Vector2& rhs);
		friend Vector3 operator*(const Matrix3& lhs, const Vector3& rhs);

		Matrix3& operator= (const Matrix3& a_Source);
		friend bool operator== (const Matrix3& a_Lhs, const Matrix3& a_Rhs);
		friend bool operator==(const Vector3& lhs, const Vector3& rhs);
		friend bool operator!= (const Matrix3& a_Lhs, const Matrix3& a_Rhs);

		float* operator[](int rhs);
	};

	class Matrix4
	{
	public:

		Matrix4();

		Matrix4(const float& a_00,
			const float& a_01,
			const float& a_02,
			const float& a_10,
			const float& a_11,
			const float& a_12,
			const float& a_20,
			const float& a_21,
			const float& a_22);


		Matrix4(const Matrix4 &a_Source);

		float matrix[4][4];

		~Matrix4();

		void Transpose();

		Vector3 VectorTransform(const Vector3 &a_Point);

		static Matrix4 Identity();

		Vector3 Scale(const Vector3 &a_Vector);

		static Matrix4 MakeXRotationMatrix(float a_Radians);
		static Matrix4 MakeYRotationMatrix(float a_Radians);
		static Matrix4 MakeZRotationMatrix(float a_Radians);

		//Operators
		Matrix4	operator+ (const Matrix4& a_AddMatrix);
		Matrix4	operator+ (const float& a_AddScalar);
		Matrix4	operator+= (const Matrix4& a_AddMatrix);
		Matrix4	operator+= (const float& a_AddScalar);

		Matrix4	operator- (const Matrix4& a_SubMatrix);
		Matrix4	operator- (const float& a_SubScalar);
		Matrix4	operator-= (const Matrix4& a_SubMatrix);
		Matrix4	operator-= (const float& a_SubScalar);

		Matrix4	operator* (const Matrix4& a_FactorMatrix);
		Matrix4	operator* (const float& a_FactorScalar);
		Matrix4	operator*= (const Matrix4& a_FactorMatrix);
		Matrix4	operator*= (const float& a_FactorScalar);

		Matrix4& operator= (const Matrix4& a_Source);
		const bool operator== (const Matrix4& a_Term);
		const bool operator!= (const Matrix4& a_Term);

		float* operator[](int rhs);
	};
}
#endif