#include <iostream>
#include <string>
#include <vector>

class GetInput
{
public:
    GetInput(std::istream &i = std::cin) : is(i) {}
    std::string operator()() const
    {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    }

private:
    std::istream &is;
};

int main(void)
{
    GetInput getInput;
    std::vector<std::string> v;
    for(std::string tmp; !(tmp = getInput()).empty(); )
    {
        v.push_back(tmp);
    }

    for(const auto &str : v)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
