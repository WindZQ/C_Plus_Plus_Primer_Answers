#include <iostream>

int main(void)
{
    int number1, number2;
    std::cout << "Please intput two number:";
    std::cin >> number1 >> number2;
    std::cout << "The two number add:" << number1 + number2 << "\t" << "The two number mul:" << number1 * number2 << std::endl;
    return 0;
}
