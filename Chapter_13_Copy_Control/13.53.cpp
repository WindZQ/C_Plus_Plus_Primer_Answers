#include <iostream>
#include <string>
#include "13.53.h"

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
    std::cout << "call swap" << std::endl;
}

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0)
{
    std::cout << "call constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
{
    p.ps = 0;
    std::cout << "call move constructor" << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs)
{
    std::swap(*this, rhs);
    return *this;
}

HasPtr::~HasPtr()
{
    std::cout << "call destructor" << std::endl;
    delete ps;
}
