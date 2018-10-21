#include "dictionary.h"

dictionary::dictionary(std::ifstream& stream)
{
	words = std::vector<std::string>();

	std::string next;
	while (!stream.eof())
	{
		stream >> next;
		words.push_back(next);
	}

	selectionSort();
}

void dictionary::selectionSort()
{
	for (int i = 0; i < words.size()-1; i++)
	{
		int least(i);
		for (int j = i + 1; j < words.size(); j++)
		{
			if (words.at(least) > words.at(j))
			{
				least = j;
			}
		}
		std::string tmp(words.at(i));
		words.at(i) = words.at(least);
		words.at(least) = tmp;
	}
}

int dictionary::binarySearch(const std::string& target) const
{
	if (words.size() == 0) return false;

	int front(0);
	int back(words.size());

	while (front < back)
	{
		int mid((front + back) / 2);
		if (target == words.at(mid))
		{
			return mid;
		} 
		else if (target < words.at(mid))
		{
			back = mid;
		}
		else
		{
			front = mid;
		}
	}

	return false;
}