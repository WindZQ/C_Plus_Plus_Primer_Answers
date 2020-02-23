#include <iostream>
#include <fstream>
#include "12.19.h"

int main(void)
{
    std::ifstream ifs("../data/book.txt");
    StrBlob sb;
    std::string s;
    while(getline(ifs, s))
    {
        sb.push_back(s);
    }
    for(StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr())
    {
        std::cout << sbp.deref() << std::endl;
    }

    return 0;
}
