#include <iostream>
#include <string>
#include <cctype>

bool any_capital(std::string const &str)
{
    for(auto ch : str)
    {
        if(isupper(ch))
        {
            return true;
        }
    }

    return false;
}

void to_lowercase(std::string &str)
{
    for(auto &ch : str)
    {
        ch = tolower(ch);
    }
}

int main(void)
{
    std::string hello("Hello World!");
    std::cout << any_capital(hello) << std::endl;

    to_lowercase(hello);
    std::cout << hello << std::endl;

    return 0;
}
