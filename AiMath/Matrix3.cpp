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

	Matrix3::~Matrix3(){

	}

}