#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename T, unsigned size>
T* begin_def(T(&arr)[size])
{
    return arr;
}

template<typename T, unsigned size>
T* end_def(T (&arr)[size])
{
    return arr + size;
}

int main(void)
{
    std::string s[] = { "sssss","ss","ss","ssssszzzz" };
    std::cout << *(begin_def(s)+1) << std::endl;
    std::cout << *(end_def(s) - 1) << std::endl;
    return 0;
}
