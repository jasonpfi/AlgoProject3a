#include <iostream>
#include <fstream>
#include <string>
#include "grid.h"
#include "dictionary.h"

int main()
{
    std::cout << "Word Search Program" << std::endl;

	// Load dictionary
	std::ifstream wordFile("data/dictionary.txt");
	dictionary wordList(wordFile);
	wordFile.close();

	// Load grid
	std::cout << "Enter file name that can be found in the data folder: ";

	std::string fileName;
	// std::cin >> fileName;

	std::ifstream f("data/input15.txt");

	grid g(f);

	f.close();

    g.readGrid();

	std::cin.get();
	return 0;
}
