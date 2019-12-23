#include <iostream>
#include <vector>

bool is_prefix(const std::vector<int> &lhs, const std::vector<int>& rhs)
{
    if(lhs.size() > rhs.size())
    {
        return is_prefix(rhs, lhs);
    }

    for(unsigned i = 0; i != lhs.size(); ++i)
    {
        if(lhs[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    std::vector<int> l{0, 1, 1, 2};
    std::vector<int> r{0, 1, 1, 2, 3, 5, 8};
    std::cout << (is_prefix(r, l) ? "yes\n" : "no\n");

    return 0;
}
