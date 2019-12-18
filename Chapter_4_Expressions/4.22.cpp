#include <iostream>

int main(void)
{
    for(unsigned g; std::cin >> g;)
    {
        auto result = g > 90 ? "high pass" : g < 60 ? "fail" : g < 75 ? "low pass" : "pass";
        std::cout << result << std::endl;

    }
    return 0;
}
