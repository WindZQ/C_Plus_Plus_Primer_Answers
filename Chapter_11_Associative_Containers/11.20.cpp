#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::map<std::string, std::size_t> counts;
    for(std::string word; std::cin >> word;)
    {
        auto result = counts.insert({word, 1});
        if(!result.second)
        {
            ++result.first->second;
        }
    }

    for(auto const &count : counts)
    {
        std::cout << count.first << " " << count.second << ((count.second > 1) ? "times\n" : "time\n");
    }

    return 0;
}
