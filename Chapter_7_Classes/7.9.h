#ifndef _7.9_H_
#define _7.9_H_

#include <iostream>
#include <string>

struct Person
{
    std::string const & getName() const { return name; }
    std::string const & getAddtess() const { return address;}

    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
    return is >> person.name >> person.address;
}

std::ostream &print(std::ostream &os, const Person &person)
{
    return os << person.name << " " << person.address;
}

#endif
