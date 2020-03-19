#include <iostream>
#include <vector>
#include "14.26.StrVec.h"

int main(void)
{
    StrVec v;
    v.reserve(6);
    std::cout << "capacity(reserve to 6): " << v.capacity() << std::endl;

    v.reserve(4);
    std::cout << "capacity(reserve to 4): " << v.capacity() << std::endl;

    v.push_back("hello");
    v.push_back("world");

    v.resize(4);

    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << std::endl;
    std::cout << "-EOF-" << std::endl;

    vec.resize(1);

    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << std::endl;
    std::cout << "-EOF-" << std::endl;

    StrVec list{ "hello", "world", "pezy" };

    for (auto i = list.begin(); i != list.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    const StrVec const_list{ "hello", "world", "pezy" };
    if (vec_list == const_list)
        for (const auto &str : const_list)
            std::cout << str << " ";
    std::cout << std::endl;

    const StrVec const_list_small{ "hello", "pezy", "ok" };
    std::cout << (const_list_small < const_vec_list) << std::endl;

    std::cout << const_list_small[1] << std::endl;
	
	return 0;
}
