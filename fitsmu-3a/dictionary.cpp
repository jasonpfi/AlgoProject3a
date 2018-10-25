#include "dictionary.h"
#include <iostream>

dictionary::dictionary(std::ifstream& stream)
{
	this->words = std::vector<std::string>();

	std::string next;
	while (!stream.eof())
	{
		stream >> next;
		this->words.push_back(next);
	}

	//this->selectionSort();
}

void dictionary::selectionSort()
{
	for (int i = 0; i < this->words.size()-1; i++)
	{
		int least(i);
		for (int j = i + 1; j < this->words.size(); j++)
		{
			if (this->words.at(least) > this->words.at(j))
			{
				least = j;
			}
		}
		std::string tmp(this->words.at(i));
		this->words.at(i) = this->words.at(least);
		this->words.at(least) = tmp;
	}
}

int dictionary::binarySearch(const std::string& target) const
{
	int front(0);
	int back(this->words.size()-1);

	while (front < back)
	{
		int mid((front + back) / 2);
		std::string midValue = this->words.at(mid);
		if (target == midValue)
		{
			return mid;
		}
		else if (target < midValue)
		{
			back = mid-1;
		}
		else
		{
			front = mid+1;
		}
	}

	return -1;
}
