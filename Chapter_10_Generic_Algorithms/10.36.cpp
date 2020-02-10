#include <iostream>
#include <list>
#include <algorithm>

int main(void)
{
    std::list<int> l{1, 2, 0, 4, 5, 6, 7, 0, 9};
    auto it = std::find(l.crbegin(), l.crend(), 0);

    std::cout << std::distance(it, l.crend()) << std::endl;
    return 0;
}
