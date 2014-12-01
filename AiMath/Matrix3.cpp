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

	Vector3 Matrix3::GetVector3(MATRIX_MAJOR type, int index, const Matrix3& matrix)
	{
		float x, y, z;
		if (type == ROW)
		{
			x = matrix.matrix[index][0];
			y = matrix.matrix[index][1];
			z = matrix.matrix[index][2];
		}
		else
		{
			x = matrix.matrix[0][index];
			y = matrix.matrix[1][index];
			z = matrix.matrix[2][index];
		}
		return Vector3(x, y, z);
	}

	//Transpose the matrix
	Matrix3& Matrix3::Transpose(){
		Matrix3 result;
		for (int row = 0; row < 3; row++){
			//get the row'th column from this object
			Vector3 v = Matrix3::GetVector3(COL, row, *this);
			//set the temp matrix's row'th row to the vector's values
			result.matrix[row][0] = v.x;
			result.matrix[row][1] = v.y;
			result.matrix[row][2] = v.z;
		}
		*this = result;
		return *this;
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
		temp.y = a_Point.x * matrix[1][0] + a_Point.y * matrix[1][1] + a_Point.z * matrix[1][2];
		temp.z = a_Point.x * matrix[2][0] + a_Point.y * matrix[2][1] + a_Point.z * matrix[2][2];
		return temp;
	}

	//Returns 3x3 orthographic projection
	Matrix3 Matrix3::OrthographicProjection(){
		Matrix3 r = Matrix3::Identity();
		r.matrix[2][2] = 0;
		return r;
	}

	//Returns new rotation matrix
	Matrix3 Matrix3::SetupRotation(float a_Radians){
		Matrix3 m = Matrix3::Identity();
		m.matrix[0][0] = cos(a_Radians);
		m.matrix[0][1] = -sin(a_Radians);

		m.matrix[1][0] = sin(a_Radians);
		m.matrix[1][1] = cos(a_Radians);
		return m;
	}

	//Returns new translation matrix
	Matrix3 Matrix3::SetupTranslation(Vector2& a_Translation){
		Matrix3 m = Matrix3::Identity();
		m.matrix[0][2] = a_Translation.x;
		m.matrix[1][2] = a_Translation.y;
		return m;
	}

	//Returns new scale matrix
	Matrix3 Matrix3::SetupScale(Vector2& a_Scale){
		Matrix3 m = Matrix3::Identity();
		m.matrix[0][0] = a_Scale.x;
		m.matrix[1][1] = a_Scale.y;
		return m;
	}

	//Matrix3 Operators

	Matrix3 Matrix3::operator+ (const Matrix3& rhs){
		Matrix3 result = (*this);
		result += rhs;
		return result;
	}

	Matrix3& Matrix3::operator+= (const Matrix3& rhs){
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				matrix[row][col] += rhs.matrix[row][col];
			}
		}
		return (*this);
	}

	Matrix3 Matrix3::operator+ (const float& rhs){
		Matrix3 result = (*this);
		result += rhs;
		return result;
	}

	Matrix3& Matrix3::operator+= (const float& rhs){
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				matrix[row][col] += rhs;
			}
		}
		return (*this);
	}

	Matrix3 Matrix3::operator- (const Matrix3& rhs){
		Matrix3 result = (*this);
		result -= rhs;
		return result;
	}

	Matrix3 Matrix3::operator- (const float& rhs){
		Matrix3 result = (*this);
		result -= rhs;
		return result;
	}

	Matrix3& Matrix3::operator-= (const Matrix3& rhs){
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				matrix[row][col] -= rhs.matrix[row][col];
			}
		}
		return (*this);
	}

	Matrix3& Matrix3::operator-= (const float& rhs){
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				matrix[row][col] -= rhs;
			}
		}
		return (*this);
	}

	Matrix3 Matrix3::operator*(const Matrix3& rhs)
	{
		Matrix3 result = *this;
		result *= rhs;
		return result;
	}

	Matrix3& Matrix3::operator*=(const Matrix3& rhs)
	{
		//need to use a temp because use the object during the process and can't modify during.
		Matrix3 result;
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				Vector3 rowVector = Matrix3::GetVector3(ROW, row, *this);
				Vector3 colVector = Matrix3::GetVector3(COL, col, rhs);
				result.matrix[row][col] = rowVector.DotProduct(colVector);
			}
		}
		return *this = result;
	}

	Vector3 operator*(const Matrix3& lhs, const Vector3& rhs){
		Vector3 result;
		Vector3 row = Matrix3::GetVector3(ROW, 0, lhs);
		result.x = row.DotProduct(rhs);
		row = Matrix3::GetVector3(ROW, 1, lhs);
		result.y = row.DotProduct(rhs);
		row = Matrix3::GetVector3(ROW, 2, lhs);
		result.z = row.DotProduct(rhs);
		return result;
	}

	Vector2 operator*(const Matrix3& lhs, const Vector2& rhs){
		Vector2 result;
		//Convert to Vector3
		Vector3 v(rhs.x, rhs.y, 1);
		Vector3 row = Matrix3::GetVector3(ROW, 0, lhs);
		result.x = row.DotProduct(v);
		row = Matrix3::GetVector3(ROW, 1, lhs);
		result.y = row.DotProduct(v);
		return result;
	}

	Matrix3& Matrix3::operator= (const Matrix3& rhs){
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				matrix[row][col] = rhs.matrix[row][col];
			}
		}
		return *this;
	}

	
	//Returns true if every element is equal to the element in the same position in the given matrix
	bool operator== (const Matrix3& lhs, const Matrix3& rhs){
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

	bool operator==(const Vector3& lhs, const Vector3& rhs){
		if (&lhs == &rhs)
			return true;
		if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
			return true;
		return false;
	}

	bool operator!= (const Matrix3& lhs, const Matrix3& rhs){
		return !(lhs == rhs);
	}

	float* Matrix3::operator[](int rhs){
		return matrix[rhs];
	}

	std::ostream& operator<<(std::ostream& out, const Matrix3& m)
	{
		out << "Matrix3\n******************\n";
		out << "** " << m.matrix[0][0] << "\t" << m.matrix[0][1] << "\t" << m.matrix[0][2] << "  **\n";
		out << "** " << m.matrix[1][0] << "\t" << m.matrix[1][1] << "\t" << m.matrix[1][2] << "  **\n";
		out << "** " << m.matrix[2][0] << "\t" << m.matrix[2][1] << "\t" << m.matrix[2][2] << "  **\n";
		out << "******************\n";
		return out;
	}
}