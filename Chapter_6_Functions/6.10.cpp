#include <iostream>
#include <string>

void swap(int *lhs, int *rhs)
{
    int tmp;
    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

int main(void)
{
    for(int lft, rft; std::cout << "Please Enter:\n", std::cin >> lft >> rft;)
    {
        swap(&lft, &rft);
        std::cout << lft << " " << rft << std::endl;
    }

    return 0;
}
