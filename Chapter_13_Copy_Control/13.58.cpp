#include <iostream>
#include <vector>
#include <algorithm>

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    std::sort(data.begin(), data.end());
    std::cout << "&&" << std::endl;
    return *this;
}

Foo Foo::sorted() const &
{
    std::cout << "const &" << std::endl;
    return Foo(*this).sorted();
}

int main(void)
{
    Foo().sorted();
    Foo f;
    f.sorted();

    return 0;
}
