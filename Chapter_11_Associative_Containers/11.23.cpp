#include <iostream>
#include <string>
#include <string>

int main(void)
{
    std::multimap<std::string, std::string> families;
    for(std::string lname, cname; std::cin >> cname >> lname; families.emplace(lname, cname));
    for(auto const &family : families)
    {
        std::cout << family.second << " " << family.first << std::endl;
    }

    return 0;
}
