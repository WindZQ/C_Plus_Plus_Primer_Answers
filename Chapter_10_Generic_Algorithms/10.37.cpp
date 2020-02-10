#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>

int main(void)
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> l;

    std::copy(v.crbegin() + 3, v.crend() + 8, std::back_inserter(l));

    for(auto i : l)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
