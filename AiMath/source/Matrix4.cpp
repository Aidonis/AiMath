#include "AiMath.h"

namespace AiMath{

	Matrix4::Matrix4(){
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				matrix[row][col] = 0;
			}
		}
	}

	Matrix4::Matrix4(const Matrix4& a_Matrix){
			{
				*this = a_Matrix;
			}
	}

	Matrix4::Matrix4(const float& a_00,
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
		const float& a_33)
	{
		matrix[0][0] = a_00;
		matrix[0][1] = a_01;
		matrix[0][2] = a_02;
		matrix[0][3] = a_03;
		matrix[1][0] = a_10;
		matrix[1][1] = a_11;
		matrix[1][2] = a_12;
		matrix[1][3] = a_13;
		matrix[2][0] = a_20;
		matrix[2][1] = a_21;
		matrix[2][2] = a_22;
		matrix[2][3] = a_23;
		matrix[3][0] = a_30;
		matrix[3][1] = a_31;
		matrix[3][2] = a_32;
		matrix[3][3] = a_33;
	}

	Matrix4::~Matrix4(){

	}

	Vector4 Matrix4::GetVector4(MATRIX_MAJOR type, int index, const Matrix4& matrix)
	{
		float x, y, z, w;
		if (type == ROW)
		{
			x = matrix.matrix[index][0];
			y = matrix.matrix[index][1];
			z = matrix.matrix[index][2];
			w = matrix.matrix[index][3];
		}
		else
		{
			x = matrix.matrix[0][index];
			y = matrix.matrix[1][index];
			z = matrix.matrix[2][index];
			w = matrix.matrix[3][index];
		}
		return Vector4(x, y, z, w);
	}

	//Transpose the matrix
	Matrix4& Matrix4::Transpose(){
		Matrix4 result;
		for (int row = 0; row < 4; row++){
			//get the row'th column from this object
			Vector4 v = Matrix4::GetVector4(COL, row, *this);
			//set the temp matrix's row'th row to the vector's values
			result.matrix[row][0] = v.x;
			result.matrix[row][1] = v.y;
			result.matrix[row][2] = v.z;
			result.matrix[row][3] = v.w;
		}
		*this = result;
		return *this;
	}

	//Returns a new matrix that's the transpose of the original
	Matrix4 Matrix4::GetTranspose()
	{
		Matrix4 result = *this;
		result.Transpose();
		return result;
	}

	Matrix4 Matrix4::Identity(){
		Matrix4 temp;
		temp.matrix[0][0] = 1;
		temp.matrix[0][1] = 0;
		temp.matrix[0][2] = 0;
		temp.matrix[0][3] = 0;

		temp.matrix[1][0] = 0;
		temp.matrix[1][1] = 1;
		temp.matrix[1][2] = 0;
		temp.matrix[1][3] = 0;

		temp.matrix[2][0] = 0;
		temp.matrix[2][1] = 0;
		temp.matrix[2][2] = 1;
		temp.matrix[2][3] = 0;

		temp.matrix[2][0] = 0;
		temp.matrix[2][1] = 0;
		temp.matrix[2][2] = 0;
		temp.matrix[2][3] = 1;

		return temp;
	}

	Vector3 Matrix4::VectorTransform(const Vector3& a_Point){
		Vector3 temp;
		temp.x = a_Point.x * matrix[0][0] + a_Point.y * matrix[0][1] + a_Point.z * matrix[0][2];
		temp.y = a_Point.x * matrix[1][0] + a_Point.y * matrix[1][1] + a_Point.z * matrix[1][2];
		temp.z = a_Point.x * matrix[2][0] + a_Point.y * matrix[2][1] + a_Point.z * matrix[2][2];
		return temp;
	}

	//Returns 4x4 orthographic projection
	Matrix4 Matrix4::OrthographicProjection(const float left, const float right, const float top, const float bottom, const float near, const float far){
		Matrix4 r = Matrix4::Identity();
		r.matrix[0][0] = 2.0f / (right - left);
		r.matrix[0][3] = -1.0f * ((right + left) / (right - left));
		r.matrix[1][1] = 2.0f / (top - bottom);
		r.matrix[1][3] = -1.0f * ((top + bottom) / (top - bottom));
		r.matrix[2][2] = -1.0f * (2 / (far - near));
		r.matrix[2][3] = -1.0f * ((far + near) / (far - near));
		return r;
	}

	//Returns new rotation matrix around the given axis
	Matrix4 Matrix4::SetupRotation(AXIS a_Axis, float a_Radians){
		Matrix4 m = Matrix4::Identity();
		switch (a_Axis)
		{
		case X:
			m.matrix[1][1] = cos(a_Radians);
			m.matrix[1][2] = -sin(a_Radians);
			m.matrix[2][1] = sin(a_Radians);
			m.matrix[2][2] = cos(a_Radians);
			return m;
		case Y:
			m.matrix[0][0] = cos(a_Radians);
			m.matrix[0][2] = sin(a_Radians);
			m.matrix[2][0] = -sin(a_Radians);
			m.matrix[2][2] = cos(a_Radians);
			return m;
		case Z:
			m.matrix[0][0] = cos(a_Radians);
			m.matrix[0][1] = -sin(a_Radians);
			m.matrix[1][0] = sin(a_Radians);
			m.matrix[1][1] = cos(a_Radians);
			return m;
		}
	}

	//Returns new translation matrix
	Matrix4 Matrix4::SetupTranslation(const Vector3& a_Translation){
		Matrix4 m = Matrix4::Identity();
		m.matrix[0][3] = a_Translation.x;
		m.matrix[1][3] = a_Translation.y;
		m.matrix[2][3] = a_Translation.z;
		return m;
	}

	//Returns new scale matrix
	Matrix4 Matrix4::SetupScale(const Vector3& a_Scale){
		Matrix4 m = Matrix4::Identity();
		m.matrix[0][0] = a_Scale.x;
		m.matrix[1][1] = a_Scale.y;
		m.matrix[2][2] = a_Scale.z;
		return m;
	}

	//Matrix4 Operators

	Matrix4 operator+ (const Matrix4& a_Lhs, const Matrix4& a_Rhs){
		Matrix4 m;
		m = a_Lhs;
		m += a_Rhs;
		return m;
	}

	Matrix4& Matrix4::operator+= (const Matrix4& a_Rhs){
		for (int row = 0; row < 4; row++){
			for (int col = 0; col < 4; col++){
				matrix[row][col] += a_Rhs.matrix[row][col];
			}
		}
		return (*this);
	}

	Matrix4 operator- (const Matrix4& a_Lhs, const Matrix4& a_Rhs){
		Matrix4 m;
		m = a_Lhs;
		m -= a_Rhs;
		return m;
	}

	Matrix4& Matrix4::operator-= (const Matrix4& a_Rhs){
		for (int row = 0; row < 4; row++){
			for (int col = 0; col < 4; col++){
				matrix[row][col] -= a_Rhs.matrix[row][col];
			}
		}
		return (*this);
	}

	Matrix4 operator*(const Matrix4& a_Lhs, const Matrix4& a_Rhs)
	{
		Matrix4 m;
		m = a_Lhs;
		m *= a_Rhs;
		return m;
	}

	Matrix4& Matrix4::operator*=(const Matrix4& a_Rhs)
	{
		//need to use a temp because use the object during the process and can't modify during.
		Matrix4 result;
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				Vector4 rowVector = Matrix4::GetVector4(ROW, row, *this);
				Vector4 colVector = Matrix4::GetVector4(COL, col, a_Rhs);
				result.matrix[row][col] = rowVector.DotProduct(colVector);
			}
		}
		return *this = result;
	}

	Vector4 operator*(const Matrix4& a_Lhs, const Vector4& a_Rhs){
		Vector4 result;
		Vector4 row = Matrix4::GetVector4(ROW, 0, a_Lhs);
		result.x = row.DotProduct(a_Rhs);
		row = Matrix4::GetVector4(ROW, 1, a_Lhs);
		result.y = row.DotProduct(a_Rhs);
		row = Matrix4::GetVector4(ROW, 2, a_Lhs);
		result.z = row.DotProduct(a_Rhs);
		return result;
	}

	Matrix4& Matrix4::operator= (const Matrix4& a_Rhs){
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				matrix[row][col] = a_Rhs.matrix[row][col];
			}
		}
		return *this;
	}


	//Returns true if every element is equal to the element in the same position in the given matrix
	bool operator== (const Matrix4& a_Lhs, const Matrix4& a_Rhs){
		if (&a_Lhs == &a_Rhs)
			return true;

		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (a_Lhs.matrix[row][col] != a_Rhs.matrix[row][col])
					return false;
			}
		}
		return true;
	}

	bool operator!= (const Matrix4& a_Lhs, const Matrix4& a_Rhs){
		return !(a_Lhs == a_Rhs);
	}

	float* Matrix4::operator[](int a_Rhs){
		return matrix[a_Rhs];
	}

	std::ostream& operator<<(std::ostream& out, const Matrix4& m)
	{
		out << "Matrix4\n*********************\n";
		out << "** " << m.matrix[0][0] << "\t" << m.matrix[0][1] << "\t" << m.matrix[0][2] << "\t" << m.matrix[0][3] << "  **\n";
		out << "** " << m.matrix[1][0] << "\t" << m.matrix[1][1] << "\t" << m.matrix[1][2] << "\t" << m.matrix[1][3] << "  **\n";
		out << "** " << m.matrix[2][0] << "\t" << m.matrix[2][1] << "\t" << m.matrix[2][2] << "\t" << m.matrix[2][3] << "  **\n";
		out << "** " << m.matrix[3][0] << "\t" << m.matrix[3][1] << "\t" << m.matrix[3][2] << "\t" << m.matrix[3][3] << "  **\n";
		out << "*********************\n";
		return out;
	}
}