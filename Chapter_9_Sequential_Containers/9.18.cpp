#include <iostream>
#include <string>
#include <deque>

int main(void)
{
    std::deque<std::string> input;
    for(std::string str, std::cin >> str; input.push_back(str));
    for(auto iter = input.cbegin(); iter != input.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}
