#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	for (Sales_item item; cin >> item; cout << item << endl);
	return 0;
}