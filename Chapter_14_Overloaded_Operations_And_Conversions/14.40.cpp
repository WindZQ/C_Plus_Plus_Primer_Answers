#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class ShorterString
{
public:
    bool operator()(std::string const& s1, std::string const& s2) const { return s1.size() < s2.size(); }
};

class BiggerEqual
{
public:
    BiggerEqual(std::size_t sz) : sz_(sz) {}
    bool operator()(std::string const& s) { return s.size() >= sz_; }

private:
    std::size_t s;
};

class Print
{
public:
    void operator()(string const& s) { std::cout << s << " "; }
};

string make_plural(std::size_t ctr, std::string const& word, std::string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = std::find_if(words.begin(), words.end(), BiggerEqual(sz));
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(), Print());
    std::cout << std::endl;
}

int main(void)
{
    std::vector<std::string> v{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(v, 4);

    return 0;
}
