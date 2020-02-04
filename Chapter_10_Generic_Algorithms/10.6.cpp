#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_n(v.begin(), v.size(), 0);

    for(auto i : v)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
