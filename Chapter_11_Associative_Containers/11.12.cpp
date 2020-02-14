#include <vector>
#include <utility>
#include <string>
#include <iostream>

int main(void)
{
    std::vector<std::pair<std::string, int>> v;
    std::string str;
    int i;

    while(std::cin >> str >> i)
    {
        v.push_back(std::pair<std::string, int>(str, i));
    }

    for(const auto &p : v)
    {
        std::cout << p.first << ":" << p.second << std::endl;
    }

    return 0;
}
