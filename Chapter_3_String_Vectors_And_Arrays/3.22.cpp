#include <iostream>
#include <vector>
#include <cctype>
#include <string>

int main(void)
{
    std::vector<std::string> text;
    text.push_back("aaaaaaaaaa aaaaaaaaa aaaaaa");
    text.push_back("");
    text.push_back("bbbbbbbbbbbbbb bbbbbbbbbbb bbbbbbbbbbbbb");

    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for(auto &c : *it)
        {
            if(isalpha(c))
            {
                c = toupper(c);
            }
        }
    }

    for(auto it : text)
    {
        std::cout << it << std::endl;
    }

    return 0;
}
