#include <iostream>
#include <vector>
#include <numeric>

int main(void)
{
    std::vector<int> v {1, 2, 3, 4};
    std::cout << std::accumlate(v.cbegin(), v.cend(), 0) << std::endl;

    return 0;
}
