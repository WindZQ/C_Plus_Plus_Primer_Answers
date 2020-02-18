#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

void word_transform(std::ifstream& rule_file, std::ifstream& input)
{
	auto rule_map = buildMap(rule_file);
	std::string text;
	while (getline(input, text))
	{
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				std::cout << " ";
			std::cout << transform(word, rule_map);
		}
		std::cout << std::endl;
	}
}

std::map<std::string, std::string> buildMap(std::ifstream& rule_file)
{
	std::map<std::string, std::string> m;
	std::string key;
	std::string value;
	
	while (rule_file >> key && getline(rule_file, value))
	{
		if (value.size() > 1)
			m[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return m;
}

std::string transform(const std::string& s, std::map<std::string, std::string>& m)
{
	auto it = m.find(s);
	if (it != m.cend())
		return it->second;
	else
		return s;
}

int main(void)
{
	ifstream ifs_rules("../data/transform_rules.txt");
	ifstream ifs_txt("../data/for_transform.txt");
	
	word_transform(ifs_rules, ifs_txt);
	return 0;
}
