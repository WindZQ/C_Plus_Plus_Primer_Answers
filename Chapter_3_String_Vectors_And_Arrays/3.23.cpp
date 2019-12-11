#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> ivec(10, 42);

    for(auto &it : ivec)
    {
        it *= 2;
        std::cout << it << std::endl;
    }

    return 0;
}
