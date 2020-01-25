#include <iostream>
#include <string>
#include <vector>
#include <list>

int main(void)
{
	std::list<int> ilst(5, 4);
	std::vector<int> ivc(5, 5);

	std::vector<double> dvc(ilst.begin(), ilst.end());
	for (auto i : ilst) 
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	
	for (auto d : dvc) 
	{
		std::cout << d << "\t";
	}
	std::cout << std::endl;

	std::vector<double> dvc2(ivc.begin(), ivc.end());
	for (auto i : ivc) 
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	for (auto d : dvc2) 
	{
		std::cout << d << "\t";
	}

	return 0;
}