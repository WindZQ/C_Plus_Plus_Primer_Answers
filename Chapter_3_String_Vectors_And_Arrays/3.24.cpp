#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(void)
{
    std::vector<int> ivec;
    int i = 0;
    while(std::cin >> i)
    {
        ivec.push_back(i);
    }

    for(auto it = ivec.begin(); it != ivec.end() - 1; ++it)
    {
        std::cout << *it + *(it + 1) << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;

    auto it1 = ivec.begin();
    auto it2 = ivec.end() - 1;
    while(it1 < it2)
    {
        std::cout << *it1 + *it2 << std::endl;
        ++it1;
        --it2;
    }

    return 0;
}
