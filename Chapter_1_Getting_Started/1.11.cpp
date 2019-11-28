#include <iostream>

void printRange(int low, int high)
{
    if(low > high)
    {
        printRange(high, low);
        return;
    }

    while(low <= high)
    {
        std::cout << low << std::endl;
        ++low;
    }
}

int main(void)
{
    int low, high;
    std::cout << "Please input two number:";
    std::cin >> low >> high;

    printRange(low, high);
    return 0;
}
