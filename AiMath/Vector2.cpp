#include "AiMath.h"

namespace AiMath
{
	
	Vector2::Vector2(){
		x = 0;
		y = 0;
	}

	Vector2::Vector2(float a_x, float a_y){
		x = a_x;
		y = a_y;
	}

	Vector2::~Vector2(){

	}

	float Vector2::EulerAngle(const Vector2& a_Vector){
		Vector2 VectorA = (*this);
		VectorA = VectorA.getNormal();

		Vector2 VectorB = a_Vector;
		VectorB = VectorB.getNormal();

		float euler = acos((VectorA).DotProduct(VectorB));

		return euler;
	}

	float Vector2::DotProduct(const Vector2& a_Vector){
		return (x * a_Vector.x) + (y * a_Vector.y);
	}

	//Return the normalized values of the Vector2. Does not modify original
	Vector2 Vector2::getNormal(){
		Vector2 temp = (*this);
		temp.Normalize();
		return temp;
	}

	//Normalize the original Vector2
	void  Vector2::Normalize(){
		float mag = Magnitude();

		//Check for divide by 0
		if (mag){
			*this /= mag;
		}
	}

	//Return the Magnitude of Vector2
	float  Vector2::Magnitude(){
		float first = x * x;
		float second = y * y;

		return sqrt(first + second);
	}

	Vector2 Vector2::Lerp(const Vector2& a_endVector, const float& a_interpPoint){
		Vector2 start = (*this);
		Vector2 end = a_endVector;

		Vector2 InterpolatedVector = (*this) + (end - start) * a_interpPoint;

		return InterpolatedVector;
	}

	//Operators
	//Addition

	//Sum of Vector 2's
	Vector2 Vector2::operator+ (const Vector2& a_addVector){
		Vector2 temp;
		temp.x = x + a_addVector.x;
		temp.y = y + a_addVector.y;

		//Return sum of two Vector 2's
		return temp;
	}

	//Sum of Vector 2 and scalar
	Vector2 Vector2::operator+ (const float& a_addNum){
		Vector2 temp;
		temp.x = x + a_addNum;
		temp.y = y + a_addNum;

		//Return sum of Vector2 and scalar
		return temp;
	}

	Vector2& Vector2::operator+= (const Vector2& a_addVector){
		(*this) = (*this) + a_addVector;
		return (*this);
	}

	Vector2& Vector2::operator+= (const float& a_addNum){
		(*this) = (*this) + a_addNum;
		return(*this);
	}

	//Subtraction

	//Difference between Vector 2's 
	Vector2 Vector2::operator- (const Vector2& a_diffVector){
		Vector2 temp;
		temp.x = x - a_diffVector.x;
		temp.y = y - a_diffVector.y;

		//Return the difference between Vector 2's
		return temp;
	}

	//Sum of Vector 2 and scalar
	Vector2 Vector2::operator- (const float& a_subNum){
		Vector2 temp;
		temp.x = x - a_subNum;
		temp.y = y - a_subNum;

		//Return sum of Vector2 and scalar
		return temp;
	}

	Vector2& Vector2::operator-= (const Vector2& a_subVector){
		(*this) = (*this) - a_subVector;
		return (*this);
	}

	Vector2& Vector2::operator-= (const float& a_subScalar){
		(*this) = (*this) - a_subScalar;
		return (*this);
	}

	//Scalar Multiplication

	Vector2 Vector2::operator* (const float& a_Scalar){
		Vector2 temp = (*this);

		temp.x *= a_Scalar;
		temp.y *= a_Scalar;

		return temp;
	}

	Vector2& Vector2::operator*= (const float& a_Scalar){
		(*this) = (*this) * a_Scalar;
		return (*this);
	}

	//Scalar Division

	Vector2 Vector2::operator/ (const float& a_Scalar){
		Vector2 temp = (*this);

		temp.x /= a_Scalar;
		temp.y /= a_Scalar;

		return temp;
	}

	Vector2& Vector2::operator/= (const float& a_Scalar){
		(*this) = (*this) / a_Scalar;
		return (*this);
	}

	//Assignment Operator

	Vector2& Vector2::operator= (const Vector2& a_Source){

		if (this == &a_Source){
			return (*this);
		}

		x = a_Source.x;
		y = a_Source.y;

		return (*this);
	}

	bool Vector2::operator== (const Vector2& a_Source){
		if (x == a_Source.x && y == a_Source.y){
			return true;
		}
		else{
			return false;
		}
	}
};