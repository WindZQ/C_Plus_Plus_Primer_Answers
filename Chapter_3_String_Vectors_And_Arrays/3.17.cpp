#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(void)
{
    std::vector<std::string> v;
    std::string s;

    while(std::cin >> s)
    {
        v.push_back(s);
    }

    for(auto &str : v)
    {
        for(auto &c : str)
        {
            c = toupper(c);
        }
    }

    for(auto i : v)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
