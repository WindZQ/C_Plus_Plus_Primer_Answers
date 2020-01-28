#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();
    while(begin != v.end())
    {
        ++begin;
        v.insert(begin, 42);
        ++begin;
    }

    for(auto i : v)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
