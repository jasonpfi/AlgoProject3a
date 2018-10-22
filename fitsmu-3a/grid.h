#pragma once
#include <fstream>
#include "d_matrix.h"

class grid
{
public:
	grid(std::ifstream& stream);

	char at(const int& i, const int& j) const
	{
		return mat[i][j];
	};

private:
	matrix<char> mat;
};

