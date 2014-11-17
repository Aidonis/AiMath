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

	void Matrix3::Transpose(){
		matrix[0][1] = matrix[1][0];
		matrix[0][2] = matrix[2][0];
		matrix[1][0] = matrix[0][1];
		matrix[1][2] = matrix[2][1];
		matrix[2][0] = matrix[0][2];
		matrix[2][1] = matrix[1][2];
	}

	Vector3 Matrix3::VectorTransform(const Vector3& a_Point){
		Vector3 temp;
		temp.x = a_Point.x * matrix[0][0] + a_Point.y * matrix[0][1] + a_Point.z * matrix[0][2];
		temp.x = a_Point.x * matrix[1][0] + a_Point.y * matrix[1][1] + a_Point.z * matrix[1][2];
		temp.x = a_Point.x * matrix[2][0] + a_Point.y * matrix[2][1] + a_Point.z * matrix[2][2];
		return temp;
	}

	Matrix3 Matrix3::Identity()
	{
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
}