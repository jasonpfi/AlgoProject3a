#include <iostream>
#include <fstream>
#include <string>
#include "grid.h"
#include "dictionary.h"

void findMatches(const grid& g, const dictionary& d);

// main method
// Search the dictionary with every possible word greater than 5 characters in
//  the grid
int main()
{
	std::cout << "Word Search Program" << std::endl;

	//// Load dictionary
	std::ifstream wordFile("data/dictionary_sorted.txt");
	dictionary wordList(wordFile);
	wordFile.close();

	// sort dictionary
	wordList.selectionSort();

	std::ofstream sortedFile("sortedDictionary.txt");
	sortedFile << wordList;
	sortedFile.close();

	std::cout << "Enter file name that can be found in the data folder: ";
	std::string fileName;
	std::cin >> fileName;

	std::ifstream f(("data/" + fileName).c_str());

   // Instantiate grid object
	grid g(f);

	f.close();

	findMatches(g, wordList);

   std::cout << std::endl;

   std::cin.get();
   return 0;
} // End main

void findMatches(const grid& g, const dictionary& d)
{
	// Get all of the possible words from the grid
	std::vector<std::string> candidateWords(g.readGrid());

	std::cout << "Words in the grid found in the dictionary: " << std::endl;

	// Iterate through the vector of possible words. If the word is found in
	//  the dictionary, print it to the screen
	std::vector<std::string>::iterator it;
	int printIndex = 0;
	for (it = candidateWords.begin(); it != candidateWords.end(); it++)
	{
		if (d.binarySearch(*it) != -1)
		{
			std::cout << *it << ", ";
			printIndex++;

			if (printIndex % 5 == 0)
				std::cout << std::endl;
		}
	}
} // End findMatches