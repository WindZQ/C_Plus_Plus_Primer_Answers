#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::size_t bigerThan6(std::vector<std::string> const &v)
{
    return count_if(v.cbegin(), v.cend(),
                    [](std::string const &s)
                    {
                        return s.size() > 6;
                    });
}

int main(void)
{
    std::vector<std::string> v{ "1234", "123456", "1234567", "1234567", "1234567", "1234567" };
    std::cout << "ex10.20: " << bigerThan6(v) << std::endl;

    return 0;
}
