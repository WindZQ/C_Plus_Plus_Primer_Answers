#include <iostream>
#include <string>
#include <memory>

int main(void)
{
    std::unique_ptr<std::string> p1(new std::string("hello"));
    std::cout << *p1 << std::endl;
    p1.reset(nullptr);

    return 0;
}
