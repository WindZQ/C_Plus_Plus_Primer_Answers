#ifndef _7.5_H_
#define _7.5_H_

#include <string>

class Person
{
	std::string name;
	std::string address;
public:
	auto get_name() const -> std::string const& { return name; }
	auto get_addr() const -> std::string const& { return address; }
};

#endif