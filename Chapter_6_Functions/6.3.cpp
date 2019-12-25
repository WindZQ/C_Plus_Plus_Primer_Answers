#include <iostream>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

int main(void)
{
    std::cout << fact(5) << std::endl;
    return 0;
}
