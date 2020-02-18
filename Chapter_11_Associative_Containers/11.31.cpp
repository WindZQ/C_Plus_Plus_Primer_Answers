#include <iostream>
#include <map>
#include <string>

int main(void)
{
	std::multimap<std::string, std::string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };

	std::string author = "pezy";
	std::string work = "CP5";

	auto found = authors.find(author);
	auto count = authors.count(author);
	while (count)
	{
		if (found->second == work)
		{
			authors.erase(found);
			break;
		}
		++found;
		--count;
	}

	for (const auto &author : authors)
	{
		std::cout << author.first << "\t" << author.second << std::endl;		
	}

	return 0;
}