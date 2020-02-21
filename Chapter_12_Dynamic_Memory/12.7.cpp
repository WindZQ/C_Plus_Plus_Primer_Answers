#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> alloc_vector()
{
    return std::make_shared<std::vector<int>>();
}

void assign_vector<std::shared_ptr<std::vector<int>> p)
{
    int i;
    while(std::cin >> i)
    {
        p->push_back(i);
    }
}

void print_vector(std::shared_ptr<std::vector<int>> p)
{
    for(auto i : *p)
    {
        std::cout << i << std::endl;
    }
}

int main(void)
{
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);

    return 0;
}
