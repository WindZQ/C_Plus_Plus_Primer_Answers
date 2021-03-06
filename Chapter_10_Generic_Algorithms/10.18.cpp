#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);

    auto piovt = partition(vs.begin(), vs.end(),
                           [sz](const std::string &s)
                           {
                               return s.size() >= sz;
                           });
    for(auto it = vs.cbegin(); it != piovt; ++it)
    {
        std::cout << *it << "\t";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };

    std::cout << "ex10.18: ";
    biggies_partition(v, 4);
    std::cout << std::endl;

    return 0;
}
