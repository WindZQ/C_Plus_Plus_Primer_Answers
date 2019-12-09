#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
    std::string s = "this, is. a : string!";
    std::string result;

    for(auto x : s)
    {
        if(!ispunct(x))
        {
            result += x;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
