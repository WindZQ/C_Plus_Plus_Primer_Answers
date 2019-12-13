#include <iostream>
#include <vector>

int main(void)
{
    int arr[10] = {0};
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }

    int arr2[10] = {0};
    for(int i = 0; i < 10; ++i)
    {
        arr2[i] = arr[i];
    }

    std::vector<int> v(10);
    for(int i = 0; i != 10; ++i)
    {
        v[i] = arr[i];
    }

    std::vector<int> v2(v);
    for(auto i : v2)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
