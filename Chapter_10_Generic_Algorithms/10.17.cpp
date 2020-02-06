#include <iostream>
#include <string>
#include <algorithm>
#include "7.26.h"

int main(void)
{
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> v{ d1, d2, d3, d4, d5 };

    std::sort(v.begin(), v.end(), [](const Sales_data &sd1, const Sales_data &sd2)
    {
        return sd1.isbn().size() < sd2.isbn().size();
    });

    for (const auto &element : v)
    {
        std::cout << element.isbn() << "\t";
    }
    std::cout << std::endl;

    return 0;
}
