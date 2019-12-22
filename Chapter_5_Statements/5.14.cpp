#include <iostream>
#include <string>

int main(void)
{
    std::pair<std::string, int> max_duplicated;
    int count = 0;
    for(std::string str, prestr; std::cin >> str; prestr = str)
    {
        if(str == prestr)
        {
            ++count;
        }
        else
        {
            count = 0;
        }
        if(count > max_duplicated.second)
        {
            max_duplicated = {prestr, count};
        }
    }

    if(max_duplicated.first.empty())
    {
        std::cout << "There's no duplicated string. " << std::endl;
    }
    else
    {
        std::cout << "the word" << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << std::endl;
    }

    return 0;
}
