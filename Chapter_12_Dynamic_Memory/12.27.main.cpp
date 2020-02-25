#include <iostream>
#include <string>
#include <fstream>
#include "12.27.h"

void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	std::ifstream ifs("../data/storyDataFile.txt");
	runQueries(ifs);
	return 0;
}