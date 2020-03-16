#include <iostream>
#include <algorithm>
#include <vector>

class IsEqual
{
public:
    IsEqual(int v) : value(v) {}
    bool operator()(int elem)
    {
        return elem == value;
    }

private:
    int value;
};

int main(void)
{
    std::vector<int> v = {3, 2, 1, 4, 3, 7, 8, 6};
    std::replace_if(v.begin(), v.end(), IsEqual(3), 5);
    for(int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
