#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
	ifstream ifs("E:/code/cpp_primer_answer/C_Plus_Plus_Primer_Answers/data/books.txt");
	if (!ifs)
	{
		std::cerr << "No data?" << std::endl;
		return -1;
	}

	std::vector<std::string> vecLine;
	std::string line;
	while (getline(ifs, line))
		vecLine.push_back(line);

	for (auto &s : vecLine)
	{
		std::istringstream iss(s);
		std::string word;
		while (iss >> word)
			std::cout << word << ", ";
		std::cout << std::endl;
	}

	return 0;
}