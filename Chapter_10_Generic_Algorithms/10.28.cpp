#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

template<typename Sequence>
void print(Sequence const &seq)
{
    for(const auto &i : seq)
    {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::list<int> lst1;
    std::copy(v.cbegin(), v.cend(), inserter(lst1, lst1.begin()));
    print(lst1);

    std::list<int> lst2;
    std::copy(v.cbegin(), v.cend(), back_inserter(lst2));
    print(lst2);

    std::list<int> lst3;
    std::copy(v.cbegin(), v.cend(), front_inserter(lst3));
    print(lst3);

    return 0;
}
