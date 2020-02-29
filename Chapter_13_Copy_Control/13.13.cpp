#include <iostream>
#include <vector>
#include <initializer_list>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl;}
    X &operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl;}
    ~X() { std::cout << "~X()" << std::endl;}
};

void f(const X &rx, X x)
{
    std::vector<X> v;
    v.reserve(2);
    v.push_back(rx);
    v.push_back(x);
}

int main(void)
{
    X *px = new X;
    f(*px, *px);
    delete px;

    return 0;
}
