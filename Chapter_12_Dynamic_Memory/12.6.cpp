#include <iostream>
#include <vector>

std::vector<int> *alloc_vector()
{
    return new std::vector<int>();
}

void assign_vector(std::vector<int> *p)
{
    int i;
    while(std::cin >> i)
    {
        p->push_back(i);
    }
}

void print_vector(std::vector<int> *p)
{
    for(auto i : p)
    {
        std::cout << i << std::endl;
    }
}

int main(void)
{
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);
    delete p;

    return 0;
}
