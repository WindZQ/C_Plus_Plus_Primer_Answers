#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool isLesserThanOrEqualTo6(const std::string &s, std::string::size_type sz)
{
    return s.size() <= sz;
}

int main(void)
{
    std::vector<string> authors{ "1234567", "1234", "1234567890", "1234567", "12345" };
    std::cout << count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6)) << std::endl;

    return 0;
}
