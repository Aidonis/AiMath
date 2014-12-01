#include "AiMath.h"

namespace AiMath{

	Vector4::Vector4(){
		x = y = z = w = 0.0f;
	}

	Vector4::Vector4(float a_x, float a_y, float a_z, float a_w){
		x = a_x;
		y = a_y;
		z = a_z;
		w = a_w;
	}

	Vector4::~Vector4(){

	}

	//Construct from hex number

	Vector4::Vector4(const unsigned int a_hex){
		unsigned int mask = 0x000000FF;
		unsigned int color = a_hex;

		w = color & mask;
		color = color >> 8;

		z = color & mask;
		color = color >> 8;

		y = color & mask;
		color = color >> 8;

		x = color & mask;
	}

	Vector4::Vector4(const Vector4& other){
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
	}

	float Vector4::Magnitude(){
		return sqrt((x*x) + (y * y) + (z * z) + (w * w));
	}

	Vector4 Vector4::getNormal(){
		Vector4 v = *this;
		v.Normalize();
		return v;
	}

	Vector4& Vector4::Normalize(){
		Vector4 temp = (*this);
		float mag = Magnitude();

		if (mag){
			temp *= (1 / mag);
		}
		return temp;
	}

	float Vector4::DotProduct(const Vector4& other){
		return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
	}

	//Operators
	Vector4 Vector4::operator+(const Vector4& a_rhs){
		Vector4 v = (*this);
		v += a_rhs;
		return v;
	}

	Vector4& Vector4::operator+=(const Vector4& a_rhs){
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		w += a_rhs.w;
		return (*this);
	}

	Vector4 Vector4::operator-(const Vector4& a_rhs){
		Vector4 v = (*this);
		v -= a_rhs;
		return v;
	}

	Vector4 Vector4::operator*(const float& a_rhs){
		Vector4 v = (*this);
		v *= a_rhs;
		return v;
	}
	
	Vector4& Vector4::operator*=(const float& a_rhs){
		x *= a_rhs;
		y *= a_rhs;
		z *= a_rhs;
		w *= a_rhs;
		return (*this);
	}

	Vector4& Vector4::operator-=(const Vector4& a_rhs){
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		w -= a_rhs.w;
		return(*this);
	}

	Vector4& Vector4::operator= (const Vector4& rhs){
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return (*this);
	}

	bool Vector4::operator==(const Vector4& rhs)
	{
		if (this == &rhs)
		{
			//same object
			return true;
		}
		if (x == rhs.x &&
			y == rhs.y &&
			z == rhs.z &&
			w == rhs.w)
		{
			return true;
		}
		return false;
	}

	bool Vector4::operator!=(const Vector4& rhs)
	{
		return !(*this == rhs);
	}

	bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		if (&lhs == &rhs)
			return true;
		if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w)
			return true;
		return false;
	}

	bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{
		if (&lhs == &rhs)
			return false;
		if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w)
			return false;
		return true;
	}
}