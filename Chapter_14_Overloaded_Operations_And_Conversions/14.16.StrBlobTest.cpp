#include <iostream>
#include "14.16.StrBlob.h"

int main(void)
{
    StrBlob sb{ "Hello", "World", "Pezy" };

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr()) 
	{
        std::cout << iter.deref() << " ";
    }
	
    std::cout << std::endl;
	
	return 0;
}
