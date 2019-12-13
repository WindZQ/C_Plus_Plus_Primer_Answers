#include <iostream>

int main(void)
{
    const int size = 10;
    int arr[size];
    for(auto ptr = arr; ptr != arr + size; ++ptr)
    {
        *ptr = 0;
    }

    for(auto i : arr)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
