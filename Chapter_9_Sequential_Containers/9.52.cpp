#include <iostream>
#include <string>
#include <stack>
#include <cctype>

std::string calc(std::string l, std::string r, std::string op)
{
	std::string s;
	if (op == "-")
		s = to_string(stoi(l) - stoi(r));
	return s;
}

int main(void)
{
	std::string s("1+2*(7-4)");
	std::stack<std::string> stack;
	for (auto iter = s.begin(); iter != s.end();)
	{
		if (*iter == '(')
		{
			stack.push(string(1, *iter));
			++iter;
			while (*iter != ')')
			{
				stack.push(string(1, *iter));
				++iter;
			}
		}
		else if (*iter == ')')
		{
			std::string r = stack.top(); stack.pop();
			std::string op = stack.top(); stack.pop();
			std::string l = stack.top(); stack.pop();
			stack.pop();
			stack.push(calc(l, r, op));
			++iter;
		}
		else
		{
			++iter;
		}

	}

	while (!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	return 0;
}