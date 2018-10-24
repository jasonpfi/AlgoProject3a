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

std::vector<std::string> grid::readGrid()
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

   for (int i = 0; i < candidateWords.size(); i++)
   {
      std::cout << candidateWords.at(i) << ", ";
   }

   return candidateWords;
}

void grid::findWords(std::vector<std::string>& vec, int direction, int i, int j)
{
   std::string word = "";

   switch (direction)
   {
      case 0:
         for (int k = 0; k < this->mat.rows(); k++)
         {
            this->moveUp(i, j);
            word = word + mat[i][j];

            if (k >= 4)
            {
               vec.push_back(word);
            }
         }
   }
}

void grid::moveUp(int& i, int& j)
{
   j--;

   if (j == -1)
      j = this->mat.rows() - 1;
   if (j == this->mat.rows())
      j = 0;
}
