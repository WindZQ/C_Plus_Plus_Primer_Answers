#include <iostream>

void print(int i)
{
    std::cout << i << std::endl;
}

void print(const int *begin, const int *end)
{
    while(begin != end)
    {
        std::cout << *begin++ << std::endl;
    }
}

void print(const int ia[], size_t size)
{
    for(size_t i = 0; i != size; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
}

void print(int (&arr)[2])
{
    for(auto i : arr)
    {
        std::cout << i << std::endl;
    }
}

int main(void)
{
    int i = 0, j[2] = {0, 1};

    print(i);
    print(std::begin(j), std::end(j));
    print(j, std::end(j) - std::begin(j));
    print(j);

    return 0;
}
