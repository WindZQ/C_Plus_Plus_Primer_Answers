#include <iostream>
#include <string>

int main(void)
{
    std::string rsp;
    do
    {
        std::cout << "Input two strings:";
        std::string str1, str2;
        std::cin >> str1 >> str2;
        std::cout << (str1 <= str2 ? str1 : str2)
                  << " is less than the other. " << std::endl
                  << "More? Enter yes or no:";
        std::cin >>rsp;
    }while(tolower(rsp[0]) == 'y');

    return 0;
}
