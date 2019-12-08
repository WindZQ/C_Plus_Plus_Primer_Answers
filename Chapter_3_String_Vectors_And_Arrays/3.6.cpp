#include <iostream>
#include <string>
#incldue <cctype>

int main(void)
{
    std::string s = "this is a string";
    for(auto &x : s)
    {
        x = 'X';
    }

    std::cout << s << std::endl;
    return 0;
}
