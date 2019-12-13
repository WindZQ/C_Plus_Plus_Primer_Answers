#include <iostream>

int main(void)
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < 10; ++i)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}
