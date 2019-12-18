#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> ivec {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto i : ivec)
    {
        std::cout << ((i & 0x1) ? i * 2 : i) << "\t";
    }
    std::cout << std::endl;

    return 0;
}
