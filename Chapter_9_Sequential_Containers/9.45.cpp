#include <iostream>
#include <string>

std::string add_pre_and_suffix(std::string name, std::string const &pre, std::string const &su)
{
    name.insert(name.begin(), pre.cbegin(), pre.cend());
    return name.append(su);
}

int main(void)
{
    std::string name("Huang");
    std::cout << add_pre_and_suffix(name, "Mr.", " Jr.") << std::endl;

    return 0;
}
