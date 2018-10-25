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

   std::vector<std::string> readGrid()const ;

   void findWords(std::vector<std::string>& vec, const int& direction, const int& i, const int& j) const;

   void moveUp(int& i, int& j) const;
   void moveDown(int& i, int& j) const;
   void moveRight(int& i, int& j) const;
   void moveLeft(int& i, int& j) const;
   void moveUL(int& i, int& j) const;
   void moveUR(int& i, int& j) const;
   void moveDL(int& i, int& j) const;
   void moveDR(int& i, int& j) const;

private:
	matrix<char> mat;

	void generateWords(void(grid::*f)(int &, int &) const,
		std::vector<std::string>& vec,
		const int& starti,
		const int& startj) const;
};

