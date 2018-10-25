#include <iostream>
#include <fstream>
#include <string>
#include "grid.h"
#include "dictionary.h"

void search(const dictionary& d);

int main()
{
    std::cout << "Word Search Program" << std::endl;

	//// Load dictionary
	std::ifstream wordFile("data/dictionary_sorted.txt");
	dictionary wordList(wordFile);
	wordFile.close();

	// Load grid
	std::cout << "Enter file name that can be found in the data folder: ";

	std::string fileName;
	// std::cin >> fileName;

	std::ifstream f("data/input15.txt");

	grid g(f);

	f.close();

    std::vector<std::string> results(g.readGrid());
	std::cout << "Total words generated: " << results.size() << std::endl;

	std::cin.get();
	return 0;
}

void search(const dictionary& d);
