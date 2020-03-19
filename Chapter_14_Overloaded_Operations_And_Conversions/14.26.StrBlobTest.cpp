#include <iostream>
#include "14.26.StrBlob.h"

int main(void)
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) 
	{
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }

    StrBlobPtr iter(sb2);
    std::cout << iter[2] << std::endl;
	
	return 0;
}
