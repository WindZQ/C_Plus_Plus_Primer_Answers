#include <iostream>
#include <string>
#include <memory>

int main(void)
{
	int n = 5;
	std::allocator<std::string> alloc;
	auto p = alloc.allocate(n);
	std::string s;
	auto q = p;
	while (std::cin >> s && q != p + n)
	{
		alloc.construct(q++, s);
	}
	while (q != p)
	{
		std::cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);

	return 0;
}
