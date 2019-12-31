#include <iostream>

int larger_one(int i, const int *p)
{
    return (i > *p) ? i : *p;
}

int main(void)
{
    int i = 6;
    std::cout << larger_one(7, &i) << std::endl;

    return 0;
}
