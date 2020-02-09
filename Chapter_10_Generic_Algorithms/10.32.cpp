#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "Sales_item.h"

int main(void)
{
    std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
    std::vector<Sales_item> vec;

    while (in_iter != in_eof)
    {
        vec.push_back(*in_iter++);
    }

    std::sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end)
    {
        end = std::find_if(beg, vec.cend(), [beg](const Sales_item &item) { return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }

    return 0;
}
