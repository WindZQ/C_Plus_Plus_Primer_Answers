#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

int main(void)
{
    std::ifstream ifs("../data/books.txt");
    std::istream_iterator<string> in(ifs), eof;
    std::vector<string> vec;
    std::copy(in, eof, back_inserter(vec));

    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
