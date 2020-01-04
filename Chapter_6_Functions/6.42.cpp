#include <iostream>
#include <string>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main(void)
{
    std::cout << "singual: " << make_plural(1, "success", "es") << "\t" << make_plural(1, "failure") << std::endl;
    std::cout << "plural : " << make_plural(2, "success", "es") << "\t" << make_plural(2, "failure") << std::endl;

    return 0;
}
