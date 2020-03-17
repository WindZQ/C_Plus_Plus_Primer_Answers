#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

int main(void)
{
    auto data = {1, 2, 3, 4};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i) { return 0 == mod(input, i); };
    auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
    std::cout << (is_divisible ? "Yes" : "No!") << std::endl;

    return 0;
}
