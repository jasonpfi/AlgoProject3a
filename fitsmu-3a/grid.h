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

 

private:
	matrix<char> mat;

	void generateWords(void(*f)(const matrix<char>&, int &, int &), 
		std::vector<std::string>& vec, 
		const int& starti, 
		const int& startj) const;
};

