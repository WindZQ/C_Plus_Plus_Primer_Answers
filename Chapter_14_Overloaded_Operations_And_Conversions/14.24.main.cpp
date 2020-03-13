#include <iostream>
#include "14.24.h"

int main(void)
{

	Date lhs(9999999), rhs(1);
	std::cout << (lhs -= 12000) << std::endl;

	return 0;
}