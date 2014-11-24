#include "AiMath.h"

namespace AiMath{

	Matrix3::Matrix3(){
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				matrix[row][col] = 0;
			}
		}
	}

	Matrix3::Matrix3(const Matrix3& a_Matrix){
		{
			*this = a_Matrix;
		}
	}

	Matrix3::Matrix3(
		const float& a_00,
		const float& a_01,
		const float& a_02,
		const float& a_10,
		const float& a_11,
		const float& a_12,
		const float& a_20,
		const float& a_21,
		const float& a_22)
	{
		matrix[0][0] = a_00;
		matrix[0][1] = a_01;
		matrix[0][2] = a_02;
		matrix[1][0] = a_10;
		matrix[1][1] = a_11;
		matrix[1][2] = a_12;
		matrix[2][0] = a_20;
		matrix[2][1] = a_21;
		matrix[2][2] = a_22;
	}

	Matrix3::~Matrix3(){

	}

	//Transpose the matrix
	void Matrix3::Transpose(){
		float temp[3][3];
		temp[0][0] = matrix[0][0];
		temp[0][1] = matrix[1][0];
		temp[0][2] = matrix[2][0];
		temp[1][0] = matrix[0][1];
		temp[1][1] = matrix[1][1];
		temp[1][2] = matrix[2][1];
		temp[2][0] = matrix[0][2];
		temp[2][1] = matrix[1][2];
		temp[2][2] = matrix[2][2];
	}

	//Returns a new matrix that's the transpose of the original
	Matrix3 Matrix3::GetTranspose()
	{
		Matrix3 result = *this;
		result.Transpose();
		return result;
	}

	Matrix3 Matrix3::Identity(){
		Matrix3 temp;
		temp.matrix[0][0] = 1;
		temp.matrix[0][1] = 0;
		temp.matrix[0][2] = 0;

		temp.matrix[1][0] = 0;
		temp.matrix[1][1] = 1;
		temp.matrix[1][2] = 0;

		temp.matrix[2][0] = 0;
		temp.matrix[2][1] = 0;
		temp.matrix[2][2] = 1;

		return temp;
	}

	Vector3 Matrix3::VectorTransform(const Vector3& a_Point){
		Vector3 temp;
		temp.x = a_Point.x * matrix[0][0] + a_Point.y * matrix[0][1] + a_Point.z * matrix[0][2];
		temp.x = a_Point.x * matrix[1][0] + a_Point.y * matrix[1][1] + a_Point.z * matrix[1][2];
		temp.x = a_Point.x * matrix[2][0] + a_Point.y * matrix[2][1] + a_Point.z * matrix[2][2];
		return temp;
	}

	//Matrix3 Operators

	//
	Matrix3& Matrix3::operator= (const Matrix3& rhs)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				matrix[row][col] = rhs.matrix[row][col];
			}
		}
		return *this;
	}

	/*
	Returns true if every element is equal to the element in the same position in the given matrix, else return false.
	*/
	bool operator== (const Matrix3& lhs, const Matrix3& rhs)
	{
		if (&lhs == &rhs)
			return true;

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				if (lhs.matrix[row][col] != rhs.matrix[row][col])
					return false;
			}
		}
		return true;
	}

	bool operator!= (const Matrix3& lhs, const Matrix3& rhs)
	{
		return !(lhs == rhs);
	}
}