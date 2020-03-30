#include <iostream>
#include <string>

template<typename Arr>
void print(Arr const& arr)
{
    for (auto const& elem : arr)
        std::cout << elem << std::endl;
}

int main(void)
{
    std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1 };
    print(i);
    print(c);
    print(s);

    return 0;
}
