#include "grid.h"


void moveUp(const matrix<char>& mat, int& i, int& j);
void moveDown(const matrix<char>& mat, int& i, int& j);
void moveRight(const matrix<char>& mat, int& i, int& j);
void moveLeft(const matrix<char>& mat, int& i, int& j);
void moveUL(const matrix<char>& mat, int& i, int& j);
void moveUR(const matrix<char>& mat, int& i, int& j);
void moveDL(const matrix<char>& mat, int& i, int& j);
void moveDR(const matrix<char>& mat, int& i, int& j);

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

void grid::findWords(std::vector<std::string>& vec, const int& direction, const int& i, const int& j) const
{
   std::string word = "";

   switch (direction)
   {
		case 0:
			this->generateWords(moveUp, vec, i, j);
			break;
		case 1:
			this->generateWords(moveDown, vec, i, j);
			break;
		case 2:
			this->generateWords(moveRight, vec, i, j);
			break;
		case 3:
			this->generateWords(moveLeft, vec, i, j);
			break;
		case 4:
			this->generateWords(moveUR, vec, i, j);
			break;
		case 5:
			this->generateWords(moveUL, vec, i, j);
			break;
		case 6:
			this->generateWords(moveDR, vec, i, j);
			break;
		case 7:
			this->generateWords(moveDL, vec, i, j);
			break;
   }
}

void grid::generateWords(void(*f) (const matrix<char>&, int&, int&), std::vector<std::string>& vec, const int& starti, const int& startj) const
{
	int i(starti);
	int j(startj);
	std::string word = "";

	for (int k = 0; k < this->mat.rows(); k++)
	{
		word += mat[i][j];
		(*f)(this->mat, i, j);

		if (k >= 4)
			vec.push_back(word);
	}
}

void moveUp(const matrix<char>& mat, int& i, int& j)
{
   j--;

   if (j == -1)
      j = mat.rows() - 1;
}

void moveDown(const matrix<char>& mat, int& i, int& j)
{
	j++;

	if (j == mat.rows())
		j = 0;
}

void moveRight(const matrix<char>& mat, int& i, int& j)
{
	i++;
	if (i == mat.cols())
		i = 0;
}

void moveLeft(const matrix<char>& mat, int& i, int& j)
{
	i--;
	if (i == -1)
		i = mat.cols() - 1;
}

void moveUL(const matrix<char>& mat, int& i, int& j)
{
	moveUp(mat, i, j);
	moveLeft(mat, i, j);
}

void moveUR(const matrix<char>& mat, int& i, int& j)
{
	moveUp(mat, i, j);
	moveRight(mat, i, j);
}

void moveDL(const matrix<char>& mat, int& i, int& j)
{
	moveDown(mat, i, j);
	moveLeft(mat, i, j);
}

void moveDR(const matrix<char>& mat, int& i, int& j)
{
	moveDown(mat, i, j);
	moveRight(mat, i, j);
}