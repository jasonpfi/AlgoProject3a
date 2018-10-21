#pragma once
#include <string>
#include <vector>
#include <fstream>

class dictionary
{
public:
	dictionary(std::ifstream& stream);

	int binarySearch(const std::string& target) const;

private:
	std::vector<std::string> words;

	void selectionSort();
};

