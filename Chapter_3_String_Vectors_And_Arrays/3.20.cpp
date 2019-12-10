#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(void)
{
    std::vector<int > ivec;
    int i;

    while(std::cin >> i)
    {
        ivec.push_back(i);
    }

    for(int i = 0; i < ivec.size() - 1; ++i)
    {
        std::cout << ivec[i] + ivec[i + 1] << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;

    int m = 0, n = ivec.size() - 1;
    while(m < n)
    {
        std::cout << ivec[m] + ivec[n] << std::endl;
        ++m;
        --n;
    }

    return 0;
}
