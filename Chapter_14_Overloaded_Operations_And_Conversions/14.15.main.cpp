#include "14.15.h"

int main(void)
{
	Book cp5_1(12345, "CP5", "Lippmen", "2012", 2);
	Book cp5_2(12345, "CP5", "Lippmen", "2012", 4);

	std::cout << cp5_1 + cp5_2 << std::endl;
	
	return 0;
}