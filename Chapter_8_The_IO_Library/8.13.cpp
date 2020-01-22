#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

bool valid(const std::string &str)
{
    return isdigit(str[0]);
}

std::string format(const std::string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main(void)
{
    ifstream ifs("../data/phonenumbers.txt");
    if(!ifs)
    {
        std::cerr << "No phone numbers!" << std::endl;
        exit(1);
    }

    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while(getline(ifs, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for(const auto &entry : people)
    {
        std::ostringstream formatted, badNums;
        for(const auto &nums : entry.phones)
        {
            if(!valid(nums))
            {
                badNums << "\t" << nums;
            }
            else
            {
                formatted << "\t" << format(nums);
            }
        }

        if(badNums.str().empty())
        {
            std::cout << entry.name << "\t" << formatted.str() << std::endl;
        }
        else
        {
            std::cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << std::endl;
        }
    }

    return 0;
}
