#include <fstream>
#include <iostream>

#include "7.26.h"

int main(int argc, char **argv)
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], ofstream::app);

	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << std::endl;
				total = trans;
			}
		}
		print(output, total) << std::endl;
	}
	else
	{
		std::cerr << "No data?" << std::endl;
	}

	return 0;
}