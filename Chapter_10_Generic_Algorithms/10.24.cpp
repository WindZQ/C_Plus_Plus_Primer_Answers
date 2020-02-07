#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool check_size(const std::string s, size_t i)
{
    return i > s.size();
}

int main(void)
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
    std::string s("12345");

    auto it = std::find_if(v.cbegin(), v.cend(), bind(check_size, s, _1));
    if (it != v.end())
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
