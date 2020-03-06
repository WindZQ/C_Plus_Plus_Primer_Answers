#include <iostream>
#include <vector>
#include "13.44.h"


void foo(String x)
{
	std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.c_str() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main(void)
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> v;
	v.reserve(8);
	v.push_back(s0);
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	v.push_back(baz());
	v.push_back("good job");

	for (const auto &s : svec)
	{
		std::cout << s.c_str() << std::endl;
	}
	
	return 0;
}