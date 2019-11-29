#include <iostream>

int main(void)
{
    int currVal = 0, value = 0;

    if(std::cin >> currVal)
    {
        int cnt = 1;
        while(std::cin >> value)
        {
            if(value == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = value;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}
