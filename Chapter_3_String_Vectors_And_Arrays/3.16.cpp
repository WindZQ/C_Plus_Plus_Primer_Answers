#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main(void)
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    std::cout << "v1 size:" << v1.size() << std::endl;
    std::cout << "v2 size:" << v2.size() << std::endl;
    std::cout << "v3 size:" << v3.size() << std::endl;
    std::cout << "v4 size:" << v4.size() << std::endl;
    std::cout << "v5 size:" << v5.size() << std::endl;
    std::cout << "v6 size:" << v6.size() << std::endl;
    std::cout << "v7 size:" << v7.size() << std::endl;

    std::cout << "v1 content: ";
    for(auto i : v1)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v1 content: ";
    for(auto i : v1)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v2 content: ";
    for(auto i : v2)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v3 content: ";
    for(auto i : v3)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v4 content: ";
    for(auto i : v4)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v5 content: ";
    for(auto i : v5)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v6 content: ";
    for(auto i : v6)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    std::cout << "v7 content: ";
    for(auto i : v7)
    {
        std::cout << i << " \t";
    }
    std::cout << std::endl;

    return 0;
}
