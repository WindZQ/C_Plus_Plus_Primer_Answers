#include <iostream>
#include <string>
#include <fstream>

void find_not_in(const std::string &s, std::string &result)
{
    std::string not_in("dfpg");
    int size = 0;
    if(s.find_first_of(not_in) == std::string ::npos)
    {
        result = result.size() < s.size() ? s : result;
    }
}

int main(void)
{
    ifstream ifs("../../data/letter.txt");
    if(!ifs)
    {
        return -1;
    }

    std::string longest;

    for(std::string curr; ifs >> curr)
    {
        find_not_in(curr, longest);
    }
    std::cout << longest << std::endl;

    return 0;
}
