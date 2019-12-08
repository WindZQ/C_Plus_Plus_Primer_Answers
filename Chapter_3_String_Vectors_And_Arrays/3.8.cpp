#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string s = "this is a string";

    decltype(s.size()) i = 0;
    while(i != s.size())
    {
        s[i] = 'X';
        ++i;
    }
    std::cout << s << std::endl;
    for(i = 0; i != s.size(); ++i)
    {
        s[i] = 'Y';
    }
    std::cout << s << std::endl;

    return 0;
}
