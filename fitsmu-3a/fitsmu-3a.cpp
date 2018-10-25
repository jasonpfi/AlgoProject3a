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

   search(wordList);

	std::cin.get();
	return 0;
}

void search(const dictionary& d)
{

	// std::cout << "Enter file name that can be found in the data folder: ";
	std::string fileName;
	// std::cin >> fileName;

	std::ifstream f("data/input15.txt");

	grid g(f);

	f.close();

   std::vector<std::string> candidateWords(g.readGrid());

   std::cout << "Words in the grid found in the dictionary: " << std::endl;

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

   //std::cout << "Total words generated: " << candidateWords.size() << std::endl;
}
