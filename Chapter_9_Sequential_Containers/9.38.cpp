#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    std::vector<int> v;

    for(int i = 0; i < 100; ++i)
    {
        std::cout << "capacity: " << v.capacity() << " size: " << v.size() << std::endl;
        v.push_back(i);
    }

    return 0;
}
