#include <iostream>
#include <vector>

int main(void)
{
    std::vector<unsigned> scores(11, 0);
    unsigned grade;
    while(std::cin >> grade)
    {
        if(grade <= 100)
            ++*(scores.begin() + grade / 10);
    }

    for(auto s : scores)
    {
        std::cout << s << "\t";
    }
    std::cout << std::endl;

    return 0;
}
