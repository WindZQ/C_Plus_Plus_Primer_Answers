#include <iostream>
#include <vector>
#include <string>

int main(void)
{
	std::vector<std::string> scores = { "F", "D", "C", "B", "A", "A++" };
	for (int g; std::cin >> g;)
	{
	    std::string letter;
		if (g < 60)
		{
			letter = scores[0];
		}
		else
		{
			letter = scores[(g - 50) / 10];
			if (g != 100)
				letter += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
			std::cout << letter << std::endl;
		}
	}

	return 0;
}