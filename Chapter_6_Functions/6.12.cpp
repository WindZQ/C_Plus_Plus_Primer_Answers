#include <iostream>
#include <string>

void swap(int &lhs, int &rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main(void)
{
    for(int left, right; std::cout << "Please Enter:\n", std::cin >> left >> right;)
    {
        swap(left, right);
        std::cout << left << "\t" << right << std::endl;
    }

    return 0;
}
