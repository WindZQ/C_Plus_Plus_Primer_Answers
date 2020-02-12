#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

int main(void)
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while(std::cin >> word)
    {
        ++word_count[word];
    }

    for(const auto &elem : word_count)
    {
        std::cout << elem.first << " : " << elem.second << std::endl;
    }
    return 0;
}
