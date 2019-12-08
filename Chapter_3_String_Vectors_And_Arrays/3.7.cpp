#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string s = "this is a string";
    for(char x : s)
    {
        x = 'X';
    }
    std::cout << s << std::endl;

    return 0;
}
