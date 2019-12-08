#include <iostream>
#include <string>

int main(void)
{
    std::string result, s;
    while(std::cin >> s)
    {
        result += s + " ";
    }
    std::cout << result << std::endl;

    return 0;
}
