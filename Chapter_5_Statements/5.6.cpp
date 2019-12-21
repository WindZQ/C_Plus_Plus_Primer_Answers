#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    std::vector<std::string> scores = { "F", "D", "C", "B", "A", "A++" };

    int grade = 0;
    while (std::cin >> grade)
    {
        std::string lettergrade = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
        lettergrade += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
        std::cout << lettergrade << std::endl;
    }


    return 0;
}
