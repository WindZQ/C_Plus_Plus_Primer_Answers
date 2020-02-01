#include <iostream>
#include <string>

int main(void)
{
    std::string numbers("0123456789");
    std::string s("ab2c3d7R4E6");

    std::cout << "numeric characters: ";
    for(int pos = 0; (pos = s.find_first_of(numbers, pos)) != std::string::npos; ++pos)
    {
        std::cout << s[pos] << "\t";
    }
    std::cout << std::endl;

    std::cout << "alphabetic characters: ";
    for(int pos = 0; (pos = s.find_first_not_of(numbers, pos)) != std::string::npos; ++pos)
    {
        std::cout << s[pos] << "\t";
    }
    std::cout << std::endl;

    return 0;
}
