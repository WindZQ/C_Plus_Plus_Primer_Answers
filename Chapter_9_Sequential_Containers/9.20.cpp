#include <iostream>
#include <deque>
#include <list>

int main(void)
{
    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> odd, even;
    for(auto i : l)
    {
        (i & 0x1 ? odd : even).push_back(i);
    }

    for(auto i : odd)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    for(auto i : even)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
