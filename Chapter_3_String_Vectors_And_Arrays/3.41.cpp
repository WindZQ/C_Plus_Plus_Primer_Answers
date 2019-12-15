#include <iostream>
#include <vector>

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4,5, 6, 7, 8, 9};
    std::vector<int> v(std::begin(arr), std::end(arr));

    for(auto i : v)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
