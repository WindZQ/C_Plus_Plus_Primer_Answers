#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
    if(first == last)
    {
        std::cout << "over!" << std::endl;
        return;
    }

    std::cout << *first << "\t";
    print(++first, last);
}

int main(void)
{
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec.cbegin(), vec.cend());

    return 0;
}
