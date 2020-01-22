#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main(void)
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while(getline(std::cin, line))
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

    for(auto &p : people)
    {
        std::cout << p.name << "\t";
        for(auto &s : p.phones)
        {
            std::cout << s << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
