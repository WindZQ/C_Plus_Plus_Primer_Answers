#include <iostream>
#include <map>
#include <string>
#include <vector>


class Families
{
public:
    using Child = std::pair<std::string, std::string>;
    using Children = std::vector<Child>;
    using Data = std::map<std::string, Children>;

    void add(std::string const &last_name, std::string const &first_name, std::string birthday)
    {
        auto child = make_pair(first_name, birthday);
        _data[last_name].push_back(child);
    }

    void print() const
    {
        for(auto const &pair : _data)
        {
            std::cout << pair.first << ":\n";
            for(auto const &child : pair.second)
            {
                std::cout << child.first << " " << child.second << std::endl;
            }
            std::cout << std::endl;
        }
    }

private:
    Data _data;
};

int main(void)
{
    Families families;
    auto msg = "Please enter last name, first name and birthday:\n";
    for (std::string l, f, b; std::cout << msg, std::cin >> l >> f >> b; families.add(l, f, b));
    families.print();

    return 0;
}
