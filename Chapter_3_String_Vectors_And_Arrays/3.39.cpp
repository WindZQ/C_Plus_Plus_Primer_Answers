#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
    std::string s1("aaaaaaaaaa"), s2("bbbbbbbbbb");
    if (s1 == s2)
        std::cout << "same string." << std::endl;
    else if (s1 > s2)
        std::cout << "aaaaaaaaaa > bbbbbbbbbb" << std::endl;
    else
        std::cout << "aaaaaaaaaa < bbbbbbbbbb" << std::endl;

    std::cout << "=========" << std::endl;

    const char* cs1 = "aaaaaaaaaa";
    const char* cs2 = "bbbbbbbbbb";
    auto result = strcmp(cs1, cs2);
    if (result == 0)
        std::cout << "same string." << std::endl;
    else if (result < 0)
        std::cout << "aaaaaaaaaa < bbbbbbbbbb" << std::endl;
    else
        std::cout << "aaaaaaaaaa > bbbbbbbbbb" << std::endl;

    return 0;
}
