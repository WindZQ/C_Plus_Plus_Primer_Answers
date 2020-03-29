#include <iostream>
#include <vector>
class Sales_data{ };

template<typename T>
int compare(const T& lhs, const T& rhs)
{
    if(lhs < rhs) return -1;
    if(rhs < lhs) return  1;
    return 0;
}

int main(void)
{
    std::cout << compare(1, 0) << std::endl;
    std::vector<int> vec1{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    std::cout << compare(vec1, vec2) << std::endl;

    return 0;
}
