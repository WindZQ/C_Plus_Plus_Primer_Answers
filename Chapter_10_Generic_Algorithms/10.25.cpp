#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    vs.erase(std::unique(vs.begin(), vs.end(), vs.end()));
}

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimdups(words);
    auto iter = std::stable_partition(words.begin(), words.end(), bind(check_size, -1, sz));
    for_each(words.begin(), iter, [](const std::string &s) { std::cout << s << " "; });
}

int main(void)
{
    std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    biggies(v, 4);

    return 0;
}
