#include <iostream>
#include <string>

void replace(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    auto curr = s.begin();
    while(curr != s.end() - oldVal.size())
    {
        if(oldVal == string(curr, curr + oldVal.size()))
        {
            curr = s.erase(curr, curr + oldVal.size());
            curr = s.insert(curr, newVal.begin(), newVal.end());
            curr += newVal.size();
        }
        else
        {
            ++curr;
        }
    }
}

int main(void)
{
    std::string s("To drive straight thru is a foolish, tho courageous act.");
    replace(s, "tho", "though");
    replace(s, "thru", "through");

    std::cout << s << std::endl;

    return 0;
}
