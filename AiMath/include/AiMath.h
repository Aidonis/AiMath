#ifndef _AI_Math_H_
#define _AI_Math_H_

#include <math.h>
#include <iostream>

#define PI 3.14159

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


	//Common Math Functions
	class AMath{
	public:
		//Degrees to radians
		static float DegreesToRadians(float a_angleInDegrees){
			return a_angleInDegrees * (PI / 180);
		}
		//Radians to degrees
		static float RadiansToDegrees(float a_angleInRadians){
			return a_angleInRadians * (180 / PI);
		}
		//Linear Interpolation of percentage between two scalar values
		//Percent between 0 and 1
		static float LERP(float a_begin, float a_end, float a_percent){
			return (a_begin + (a_end - a_begin) * a_percent);
		}

		//Power of two check
		static bool IsPowerOfTwo(const unsigned int a_num){
			unsigned int n = a_num;
			//shifts bits to the right until it gets a set bit that is most significant or not
			while (((n & 1) == 0) && n > 1){
				n >>= 1; //shift right 1 space
			}
			return (n == 1);
		}

		//Get next power of two if not already power of two. Else return given value
		static unsigned int GetNextPowerOfTwo(const unsigned int a_value){
			unsigned int v = a_value;
			//check case of 0
			if (a_value == 0){
				return 0;
			}

			/*copy the most significant bit to all lower bits, then add 1 which results in carry that
			sets all lower bits to 0 and one bit beyond to 1.  If the original number was a power of 2
			then the decrement will reduce it by one less, so then round up to original value.
			*/
			v--;
			v |= v >> 1;
			v |= v >> 2;
			v |= v >> 4;
			v |= v >> 8;
			v |= v >> 16;
			v++;

			return v;
		}

		//returns true if given result is within delta of expected result using
		//formula: (fabs(result - expected) < delta)
		static bool FloatEquals(const float& a_result, const float& a_expected, const float a_delta)
		{
			return (fabs(a_result - a_expected) < a_delta);
		}

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
		friend bool operator==(const Vector3& lhs, const Vector3& rhs);

	};

	class Vector4{
	public:
		Vector4();
		~Vector4();

		Vector4(float a_x, float a_y, float a_z, float a_w);

		float x, y, z, w;

		//Construct and return a Vector4 from hex value
		//Input 0x00000000 to 0xFFFFFFFF
		//Output 0 to 255
		// x = red, y = green, z = blue, w = alpha
		Vector4(const unsigned int a_hex);

		//Copy Contructer
		Vector4(const Vector4& a_other);

		//static Vector4 ConstructFromHex

		//
		float Magnitude();

		Vector4 getNormal();
		Vector4& Normalize();

		float DotProduct(const Vector4& other);

		//Operators
		Vector4 operator+ (const Vector4& a_addVector);
		Vector4& operator+= (const Vector4& a_addVector);

		Vector4 operator- (const Vector4& a_subVector);
		Vector4& operator-= (const Vector4& a_subVector);

		Vector4 operator* (const float& a_Scalar);
		Vector4& operator*= (const float& a_Scalar);

		Vector4& operator= (const Vector4& a_Source);
		bool operator== (const Vector4& a_Source);
		friend bool operator== (const Vector4& lhs, const Vector4& rhs);
		bool operator!= (const Vector4& rhs);
		friend bool operator!= (const Vector4& lhs, const Vector4 rhs);

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

		friend bool operator!= (const Matrix3& a_Lhs, const Matrix3& a_Rhs);

		float* operator[](int rhs);

		friend std::ostream& operator<<(std::ostream& out, const Matrix3& m);
	};

	class Matrix4
	{
	public:

		Matrix4();

		Matrix4(const float& a_00,
			const float& a_01,
			const float& a_02,
			const float& a_03,
			const float& a_10,
			const float& a_11,
			const float& a_12,
			const float& a_13,
			const float& a_20,
			const float& a_21,
			const float& a_22,
			const float& a_23,
			const float& a_30,
			const float& a_31,
			const float& a_32,
			const float& a_33);


		Matrix4(const Matrix4& a_Source);

		float matrix[4][4];

		~Matrix4();

		static Vector4 GetVector4(MATRIX_MAJOR type, int index, const Matrix4& matrix);

		Matrix4& Transpose();
		Matrix4 GetTranspose();

		Vector3 VectorTransform(const Vector3 &a_Point);
		Matrix4 OrthographicProjection(const float left, const float right, const float top, const float bottom, const float near, const float far);

		static Matrix4 Identity();
		
		static Matrix4 SetupRotation(AXIS a_Axis, float a_Radians);

		static Matrix4 SetupScale(const Vector3& a_Vector);

		static Matrix4 SetupTranslation(const Vector3& a_Vector);

		//Operators
		friend Matrix4 operator+ (const Matrix4& a_Lhs, const Matrix4& a_Rhs);
		Matrix4& operator+= (const Matrix4& a_AddMatrix);

		friend Matrix4 operator- (const Matrix4& a_SubMatrix);
		Matrix4& operator-= (const Matrix4& a_SubMatrix);

		friend Matrix4 operator* (const Matrix4& a_Lhs, const Matrix4& a_Rhs);
		friend Vector4 operator*(const Matrix4& a_Lhs, const Vector4& a_Rhs);
		Matrix4& operator*= (const Matrix4& a_FactorMatrix);
		Matrix4& operator*= (const float& a_FactorScalar);

		Matrix4& operator= (const Matrix4& a_Source);
		friend bool operator== (const Matrix4& a_Lhs, const Matrix4& a_Rhs);
		const bool operator!= (const Matrix4& a_Term);

		float* operator[](int rhs);
	};
}
#endif