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
