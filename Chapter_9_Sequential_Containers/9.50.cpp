#include <iostream>
#include <vector>
#include <string>

int sum_of_int(const std::vector<std::string> &v)
{
    int sum = 0;
    for(auto i : v)
    {
        sum += stoi(i);
    }
    return sum;
}

float sum_of_float(const std::vector<std::string> &v)
{
    float sum = 0.0;
    for(auto i : v)
    {
        sum += stof(i);
    }
    return sum;
}

int main(void)
{
    std::vector<std::string> v = {"1", "2", "3", "4.5"};
    std::cout << sum_of_int(v) << std::endl;
    std::cout << sum_of_float(v) << std::endl;

    return 0;
}
