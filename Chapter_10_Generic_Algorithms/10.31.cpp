#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main9(void)
{
    std::vector<int> v;
    std::istream_iterator<int> int_it(std::cin), int_eof;

    std::unique_copy(int_it, int_eof, std::back_inserter(v));
    std::sort(v.begin(), v.end());

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
