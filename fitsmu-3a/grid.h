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

 

private:
	matrix<char> mat;

	void moveUp(int& i, int& j) const;
	void moveDown(int & i, int & j) const;
	void moveRight(int & i, int & j) const;
	void moveLeft(int & i, int & j) const;
	void generateWords(void(*f)(int &, int &), std::vector<std::string>& vec, const int& iterations, const int& starti, const int& startj);
};

