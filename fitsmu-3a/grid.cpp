#include "grid.h"

grid::grid(std::ifstream& stream)
{
	int rows;
	int cols;

	stream >> rows;
	stream >> cols;

	mat = matrix<char>(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			stream >> mat[i][j];
		}
	}
}

std::vector<std::string> grid::readGrid() const
{
   std::vector<std::string> candidateWords;

   for (int i = 0; i < this->mat.cols(); i++)
   {
      for (int j = 0; j < this->mat.rows(); j++)
      {
         for (int k = 0; k < 8; k++)
         {
            this->findWords(candidateWords, k, i, j);
         }
      }
   }

   return candidateWords;
}

void grid::findWords(std::vector<std::string>& vec, const int& direction,
      const int& i, const int& j) const
{
   std::string word = "";

   switch (direction)
   {
		case 0:
			this->generateWords(&grid::moveUp, vec, i, j);
			break;
		case 1:
			this->generateWords(&grid::moveDown, vec, i, j);
			break;
		case 2:
			this->generateWords(&grid::moveRight, vec, i, j);
			break;
		case 3:
			this->generateWords(&grid::moveLeft, vec, i, j);
			break;
		case 4:
			this->generateWords(&grid::moveUR, vec, i, j);
			break;
		case 5:
			this->generateWords(&grid::moveUL, vec, i, j);
			break;
		case 6:
			this->generateWords(&grid::moveDR, vec, i, j);
			break;
		case 7:
			this->generateWords(&grid::moveDL, vec, i, j);
			break;
   }
}

void grid::generateWords(void(grid::*f) (int&, int&) const, std::vector<std::string>& vec,
      const int& starti, const int& startj) const
{
	int i(starti);
	int j(startj);
	std::string word = "";

	for (int k = 0; k < this->mat.rows(); k++)
	{
		word += mat[i][j];
		(this->*f)(i, j);

		if (k >= 4)
			vec.push_back(word);
	}
}

void grid::moveUp(int& i, int& j) const
{
   j--;

   if (j == -1)
      j = mat.rows() - 1;
}

void grid::moveDown(int& i, int& j) const
{
	j++;

	if (j == mat.rows())
		j = 0;
}

void grid::moveRight(int& i, int& j) const
{
	i++;
	if (i == mat.cols())
		i = 0;
}

void grid::moveLeft(int& i, int& j) const
{
	i--;
	if (i == -1)
		i = mat.cols() - 1;
}

void grid::moveUL(int& i, int& j) const
{
	moveUp(i, j);
	moveLeft(i, j);
}

void grid::moveUR(int& i, int& j) const
{
	moveUp(i, j);
	moveRight(i, j);
}

void grid::moveDL(int& i, int& j) const
{
	moveDown(i, j);
	moveLeft(i, j);
}

void grid::moveDR(int& i, int& j) const
{
	moveDown(i, j);
	moveRight(i, j);
}
