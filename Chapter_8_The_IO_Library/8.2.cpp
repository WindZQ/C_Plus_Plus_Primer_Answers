#include <iostream>
#include <string>

std::istream &func(std::istream &is)
{
    std::string buf;
    while(is >> buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main(void)
{
    std::istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;

    return 0;
}
