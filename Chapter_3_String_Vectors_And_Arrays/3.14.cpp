#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(void)
{
    std::vector<int> v;
    int i;

    while(std::cin >> i)
    {
        v.push_back(i);
    }
    return 0;
}
