#include <iostream>
#include <string>

void swap(int *&lft, int *&rht)
{
    auto tmp = lft;
    lft = rht;
    rht = tmp;
}

int main(void)
{
    int i = 42, j = 88;
    auto lft = &i;
    auto rht = &j;
    swap(lft, rht);
    std::cout << *lft << "\t" << *rht << std::endl;

    return 0;
}
