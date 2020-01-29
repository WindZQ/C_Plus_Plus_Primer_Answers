#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter, *iter);
        }
        ++iter;
        std::cout << i++ << std::endl;
    }

    for(auto i : vi)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
