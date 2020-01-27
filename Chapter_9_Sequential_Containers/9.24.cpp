#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> v;
	std::cout << v.at(0) << "\t";       
	std::cout << v[0] << "\t";        
	std::cout << v.front() << "\t";    
	std::cout << *v.begin() << "\t"; 
	
	return 0;
}