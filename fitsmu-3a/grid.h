#pragma once
#include <fstream>
#include "d_matrix.h"
#include <vector>

class grid
{
public:
	grid(std::ifstream& stream);

	char at(const int& i, const int& j) const
	{
		return mat[i][j];
	};

   std::vector<std::string> readGrid();

   void findWords(std::vector<std::string>& vec, int direction, int i, int j);

   void moveUp(int& i, int& j);

private:
	matrix<char> mat;
};

