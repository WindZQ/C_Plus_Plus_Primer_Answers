#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto it = v.crbegin(); it != v.crend(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
