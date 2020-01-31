#include <iostream>
#include <string>

void replace(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    for(size_t pos = 0; pos <= s.size() - oldVal.size();)
    {
        if(s[pos] == oldVal[0] && s.substr(pos, oldVal.size() == oldVal))
        {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        }
        else
        {
            ++pos;
        }
    }
}

int main(void)
{
    std::string s("To drive straight thru is a foolish, tho courageous act.");
    replace(s,"tho","though");
    replace(s, "thru", "through");

    std::cout << s << std::endl;

    return 0;
}
