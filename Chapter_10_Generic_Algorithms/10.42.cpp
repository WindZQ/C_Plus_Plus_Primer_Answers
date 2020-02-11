#include <iostream>
#include <string>
#include <list>


void elimDups(std::list<std::string> &words)
{
    words.sort();
    words.unique();
}

int main(void)
{
    std::list<std::string> l{"aa", "aa", "aa", "aassss", "aas", "aa"};
    elimDups(l);

    for(const auto &e : l)
    {
        std::cout << e << "\t";
    }
    std::cout << std::endl;

    return 0;
}
