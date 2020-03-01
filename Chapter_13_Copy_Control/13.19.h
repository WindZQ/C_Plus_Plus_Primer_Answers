#ifndef _13_19_H
#define _13_19_H

#include <string>

class Employee
{
public:
	Employee();
	Employee(const std::string &name);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

	const int id() const { return id_; }

private:
	std::string name_;
	int id_;
	static int s_increment;
};

#endif