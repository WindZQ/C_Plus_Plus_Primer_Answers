#include <iostream>
#include <vector>
#include <iterator>

bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2)
{
    if((pe1 - pb1) != (pe2 - pb2))
    {
        return false;
    }
    else
    {
        for(int *i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
        {
            if(*i != *j)
            {
                return false;
            }
        }
    }
}

int main(void)
{
    int arr1[3] = { 0, 1, 2 };
    int arr2[3] = { 0, 2, 4 };

    if (compare(std::begin(arr1), std::end(arr1), std::begin(arr2), std::end(arr2)))
        std::cout << "The two arrays are equal." << std::endl;
    else
        std::cout << "The two arrays are not equal." << std::endl;

    std::cout << "==========" << std::endl;

    std::vector<int> vec1 = { 0, 1, 2 };
    std::vector<int> vec2 = { 0, 1, 2 };

    if (vec1 == vec2)
        std::cout << "The two vectors are equal." << std::endl;
    else
        std::cout << "The two vectors are not equal." << std::endl;

    return 0;
}
