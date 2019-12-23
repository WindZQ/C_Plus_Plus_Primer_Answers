#include <iostream>
#include <string>

int main(void)
{
    std::string read, tmp;
    while(std::cin >> read)
    {
        if(read == tmp)
        {
            break;
        }
        else
        {
            tmp = read;
        }

        if(std::cin.eof())
        {
            std::cout << "no world was repeated. " << std::endl;
        }
        else
        {
            std::cout << read << " occurs twice in succession. " << std::endl;
        }
    }

    return 0;
}
