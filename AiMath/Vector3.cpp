#include "AiMath.h"

namespace AiMath
{

	Vector3::Vector3(){
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3::Vector3(float a_x, float a_y, float a_z){
		x = a_x;
		y = a_y;
		z = a_z;
	}

	Vector3::~Vector3(){

	}

	float Vector3::EulerAngle(const Vector3& a_Vector){
		Vector3 VectorA = (*this);
		VectorA = VectorA.getNormal();

		Vector3 VectorB = a_Vector;
		VectorB = VectorB.getNormal();

		float euler = acos((VectorA).DotProduct(VectorB));

		return euler;
	}

	float Vector3::DotProduct(const Vector3& a_Vector){
		return (x * a_Vector.x) + (y * a_Vector.y) + (z * a_Vector.z);
	}

	Vector3 Vector3::CrossProduct(const Vector3 &a_Term){
		return Vector3((y * a_Term.z) - (z * a_Term.y),
					   (z * a_Term.x) - (x * a_Term.z),
					   (x * a_Term.y) - (y * a_Term.x));
	}

	Vector3 Vector3::getNormal(){
		Vector3 temp = (*this);
		float mag = Magnitude();

		if (mag){
			temp /= mag;
		}
		return temp;
	}
	Vector3& Vector3::Normalize(){
		float mag = Magnitude();
		if (mag){
			x /= mag;
			y /= mag;
			z /= mag;
		}
		return (*this);
	}

	float  Vector3::Magnitude(){
		float first = x * x;
		float second = y * y;
		float third = z * z;

		return sqrt(first + second + third);
	}

	Vector3 Vector3::Lerp(const Vector3& a_endVector, const float& a_percent){
		Vector3 start = *this;
		Vector3 end = a_endVector;

		return (start + (end - start) * a_percent);
	}

	//Operators
	//Addition

	//Sum of Vector 2's
	Vector3 Vector3::operator+ (const Vector3& a_addVector){
		Vector3 temp;
		temp.x = x + a_addVector.x;
		temp.y = y + a_addVector.y;
		temp.z = z + a_addVector.z;

		//Return sum of two Vector 2's
		return temp;
	}

	//Sum of Vector 2 and scalar
	Vector3 Vector3::operator+ (const float& a_addNum){
		Vector3 temp;
		temp.x = x + a_addNum;
		temp.y = y + a_addNum;
		temp.z = z + a_addNum;

		//Return sum of Vector3 and scalar
		return temp;
	}

	Vector3& Vector3::operator+= (const Vector3& a_addVector){
		(*this) = (*this) + a_addVector;
		return (*this);
	}

	Vector3& Vector3::operator+= (const float& a_addNum){
		(*this) = (*this) + a_addNum;
		return(*this);
	}

	//Subtraction

	//Difference between Vector 2's 
	Vector3 Vector3::operator- (const Vector3& a_diffVector){
		Vector3 temp;
		temp.x = x - a_diffVector.x;
		temp.y = y - a_diffVector.y;
		temp.z = z - a_diffVector.z;

		//Return the difference between Vector 2's
		return temp;
	}

	//Difference between Vector 2 and scalar
	Vector3 Vector3::operator- (const float& a_subNum){
		Vector3 temp;
		temp.x = x - a_subNum;
		temp.y = y - a_subNum;
		temp.z = z - a_subNum;

		//Return sum of Vector3 and scalar
		return temp;
	}

	Vector3& Vector3::operator-= (const Vector3& a_subVector){
		(*this) = (*this) - a_subVector;
		return (*this);
	}

	Vector3& Vector3::operator-= (const float& a_subScalar){
		(*this) = (*this) - a_subScalar;
		return (*this);
	}

	//Scalar Multiplication

	Vector3 Vector3::operator* (const float& a_Scalar){
		Vector3 temp = (*this);

		temp.x *= a_Scalar;
		temp.y *= a_Scalar;
		temp.z *= a_Scalar;

		return temp;
	}

	Vector3& Vector3::operator*= (const float& a_Scalar){
		(*this) = (*this) * a_Scalar;
		return (*this);
	}

	//Scalar Division

	Vector3 Vector3::operator/ (const float& a_Scalar){
		Vector3 temp = (*this);

		temp.x /= a_Scalar;
		temp.y /= a_Scalar;
		temp.z /= a_Scalar;

		return temp;
	}

	Vector3& Vector3::operator/= (const float& a_Scalar){
		(*this) = (*this) / a_Scalar;
		return (*this);
	}

	//Assignment Operator

	Vector3& Vector3::operator= (const Vector3& a_Source){

		if (this == &a_Source){
			return (*this);
		}

		x = a_Source.x;
		y = a_Source.y;
		z = a_Source.z;

		return (*this);
	}

	bool Vector3::operator==(const Vector3& other)
	{
		//check if same object
		if (this == &other)
			return true;
		if (x == other.x &&
			y == other.y &&
			z == other.z)
			return true;
		return false;
	}
};