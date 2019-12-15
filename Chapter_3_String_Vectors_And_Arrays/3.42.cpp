#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[10] = {0};

    for(int i = 0; i != v.size(); ++i)
    {
        arr[i] = v[i];
    }

    for(auto i : arr)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
