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

	//Operators
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

	bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		if (&lhs == &rhs)
			return true;
		if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w)
			return true;
		return false;
	}
}