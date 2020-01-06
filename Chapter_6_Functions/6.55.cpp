#include <iostream>
#include <vector>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return b != 0 ? a / b : 0;
}

int main(void)
{
    int func(int, int);
    std::vector<decltype(func)*> v;
    v.push_back(add);
    v.push_back(subtract);
    v.push_back(multiply);
    v.push_back(divide);

    for(auto i : v)
    {
        std::cout << i(6, 2) << "\t";
    }
    std::cout << std::endl;

    return 0;
}
