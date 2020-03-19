#include <iostream>
#include "14.27.28.StrBlob.h"


int main(void)
{
    StrBlob sb1{ "a", "b", "c" };
    StrBlob sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) 
	{
        for (StrBlobPtr iter = sb1.begin(); iter < sb1.end(); ++iter)
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }

    ConstStrBlobPtr iter(sb2);
    std::cout << (iter + 2).deref() << std::endl;
	
	return 0;
}
