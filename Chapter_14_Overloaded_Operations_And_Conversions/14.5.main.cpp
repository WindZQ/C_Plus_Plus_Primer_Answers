#include "14.5.h"

int main(void)
{
	Book book1(123, "CP5", "Lippman", "2012");
	Book book2(123, "CP5", "Lippman", "2012");

	if (book1 == book2)
	{
		std::cout << book1 << std::endl;
	}
	
	return 0;
}