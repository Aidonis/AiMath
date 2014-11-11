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

	//Operators
	//Addition

	//Sum of Vector 2's
	Vector2 Vector2::operator + (const Vector2& a_addVector){
		Vector2 temp;
		temp.x = x + a_addVector.x;
		temp.y = y + a_addVector.y;

		//Return sum of two Vector 2's
		return temp;
	}

	//Sum of Vector 2 and scalar
	Vector2 Vector2::operator + (const float& a_addScalar){
		Vector2 temp;
		temp.x = x + a_addScalar;
		temp.y = y + a_addScalar;

		//Return sum of Vector2 and scalar
		return temp;
	}

	Vector2	Vector2::operator += (const Vector2& a_addVector){
		(*this) = (*this) + a_addVector;
		return (*this);
	}

	Vector2 Vector2::operator += (const float& a_addScalar){
		(*this) = (*this) + a_addScalar;
		return(*this);
	}

	//Subtraction

	//Difference between Vector 2's 
	Vector2 Vector2::operator - (const Vector2& a_diffVector){
		Vector2 temp;
		temp.x = x - a_diffVector.x;
		temp.y = y - a_diffVector.y;

		//Return the difference between Vector 2's
		return temp;
	}

	//Sum of Vector 2 and scalar
	Vector2 Vector2::operator - (const float& a_diffScalar){
		Vector2 temp;
		temp.x = x - a_diffScalar;
		temp.y = y - a_diffScalar;

		//Return sum of Vector2 and scalar
		return temp;
	}

	Vector2 Vector2::operator -=(const Vector2& a_subVector){
		(*this) = (*this) - a_subVector;
		return (*this);
	}

	Vector2 Vector2::operator -=(const float& a_subScalar){
		(*this) = (*this) - a_subScalar;
		return (*this);
	}

	//Scalar Multiplication

	Vector2 Vector2::operator * (const float& a_Scalar){
		Vector2 temp = (*this);

		temp.x *= a_Scalar;
		temp.y *= a_Scalar;
	}

	Vector2 Vector2::operator *= (const float& a_Scalar){
		(*this) = (*this) * a_Scalar;
		return (*this);
	}

	//Scalar Division

	Vector2 Vector2::operator / (const float& a_Scalar){
		Vector2 temp = (*this);

		temp.x /= a_Scalar;
		temp.y /= a_Scalar;
	}

	Vector2 Vector2::operator /= (const float& a_Scalar){
		(*this) = (*this) * a_Scalar;
		return (*this);
	}

	//Assignment Operator

	Vector2 Vector2::operator = (const Vector2& a_Source){

		if (this == &a_Source){
			return (*this);
		}

		x = a_Source.x;
		y = a_Source.y;

		return (*this);
	}

	bool Vector2::operator == (const Vector2& a_Source){
		if (x == a_Source.x && y == a_Source.y){
			return true;
		}
		else{
			return false;
		}
	}
};