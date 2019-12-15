#include <iostream>

int main(void)
{
    int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    using int_array = int[4];

    for(int_array& p : ia)
    {
        for(int q : p)
        {
            std::cout << q << "\t";
        }
    }
    std::cout << std::endl;

    for(size_t i = 0; i != 3; ++i)
    {
        for(size_t j = 0; j != 4; ++j)
        {
            std::cout << ia[i][j] << "\t";
        }
    }
    std::cout << std::endl;

    for(int_array*p = ia; p != ia + 3; ++p)
    {
        for(int *q = *p; q != *p + 4; ++q)
        {
            std::cout << *q << "\t";
        }
    }
    std::cout << std::endl;

    return 0;
}
