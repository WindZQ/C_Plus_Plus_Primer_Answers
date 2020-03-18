#include <iostream>
#include "14.18.StrBlob.h"


int main(void)
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2{ "a", "b", "b" };

    if (sb1 > sb2) 
	{
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }
	
	return 0;
}
