#include <iostream>
#include <vector>
#include <iterator>
#include <string>

void checkAndPrint(const std::vector<int> &vec)
{
    std::cout << "size :" << vec.size() << "  contents :[";
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << (it != vec.end() - 1 ? "," : "");
    }
    std::cout << "]\n" << std::endl;
}

void checkAndPrint(const std::vector<std::string> &vec)
{
    std::cout << "size :" << vec.size() << "  contents :[";
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << (it != vec.end() - 1 ? "," : "");
    }
    std::cout << "]\n" << std::endl;

}

int main(void)
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    checkAndPrint(v1);
    checkAndPrint(v2);
    checkAndPrint(v3);
    checkAndPrint(v4);
    checkAndPrint(v5);
    checkAndPrint(v6);
    checkAndPrint(v7);

    return 0;
}
