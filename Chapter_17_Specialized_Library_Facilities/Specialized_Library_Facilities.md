## 练习17.1

> 定义一个保存三个 int 值的 tuple，并将其成员分别初始化为10、20和30。

```cpp
#include <iostream>
#include <tuple>
#include <vector>

int main()
{
	std::tuple<int, int, int> threeI(10, 20, 30);
	std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> someVal("constants", {"a", "bb"}, {"ccc", 3});

	return 0;
}
```
  
## 练习17.2

> 定义一个 tuple，保存一个 string、一个vector<string> 和一个 pair<string, int>。

参见17.1。
  
## 练习17.3

> 重写12.3节中的 TextQuery 程序，使用 tuple 代替 QueryResult 类。你认为哪种设计更好？为什么？

第一种设计更好，第二种设计更容易实现，但不容易重构。  
```cpp
#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <set>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "StrBlob.h"
#include "DebugDelete.h"
#include <tuple>

class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, StrBlob> query(const std::string&) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, StrBlob f) : sought(s), lines(p), file(f) { }
	std::set<StrBlob::size_type>::iterator begin() const { return lines->begin(); }
	std::set<StrBlob::size_type>::iterator end() const { return lines->end(); }
	// std::shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }
	const StrBlob& get_file() const { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	StrBlob file;
};

TextQuery::TextQuery(std::ifstream &ifs)
{
	std::string text_line;

	while(std::getline(ifs, text_line))
	{
		file.push_back(text_line);
		int line_number = file.size() - 1;
		std::istringstream line(text_line);
		std::string text_word;
		while(line >> text_word)
		{
			std::string word;
			std::copy_if(text_word.begin(), text_word.end(), std::back_inserter(word), isalpha);
			// std::cout << word << std::endl;
			auto &wm_lines = word_map[word];
			if(!wm_lines)
				wm_lines.reset(new std::set<line_no>, DebugDelete());
			wm_lines->insert(line_number);
		}
	}
}

std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, StrBlob> TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
	auto loc = word_map.find(sought);
	if(loc == word_map.end())
		return std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, StrBlob>(sought, nodata, file);
	else
		return std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, StrBlob>(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " /*<< make_plural(qr.lines->size(), "time", "s")*/ << std::endl;
	for(auto num : *qr.lines)
	{
		ConstStrBlobPtr p(qr.file, num);
		os << "\t(line " << num + 1 << ") " << p.deref() << std::endl;
	}
		
	return os;
}

#endif
```
  
## 练习17.4

> 编写并测试你自己版本的 findBook 函数。

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
#include <unordered_set>
#include <algorithm>
#include <tuple>

namespace std
{
	template <>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s) const
	{
		return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

typedef std::tuple<std::vector<Sales_data>::size_type, std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator> matches;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
	std::vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
		if(found.first != found.second)
			ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s)
	{
		auto trans = findBook(files, s);
		if(trans.empty())
		{
			std::cout << s << " not found in any stores" << std::endl;
			continue;
		}
		for(const auto &store : trans)
			os << "store " << std::get<0>(store) << " sales: " << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << std::endl;
	}
}

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    std::vector<Sales_data> vs1 = {sales_data1, sales_data3};
    std::vector<Sales_data> vs2 = {sales_data2};
    std::vector<std::vector<Sales_data>> vvs = {vs1, vs2};

    reportResults(std::cin, std::cout, vvs);

 //    std::cout << std::hex << std::hash<std::string>()("001-01") << std::endl;
 //    std::cout << std::hex << std::hash<unsigned>()(1) << std::endl;
 //    std::cout << std::hex << std::hash<double>()(100) << std::endl;

 //    std::unordered_multiset<Sales_data> SDset;
 //    SDset.emplace(sales_data1);
 //    SDset.emplace("001-03", 1, 200);
 //    SDset.emplace(sales_data3);

	// for(const auto &item : SDset)
	// 	std::cout << "the hash code of " << item.isbn() <<":\n0x" << std::hex << std::hash<Sales_data>()(item) << "\n";

    return 0;
}
```
  
## 练习17.5

> 重写 findBook，令其返回一个 pair，包含一个索引和一个迭代器pair。

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
#include <unordered_set>
#include <algorithm>
#include <utility>

namespace std
{
	template <>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s) const
	{
		return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

typedef std::pair<std::vector<Sales_data>::size_type, std::pair<std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator>> matches;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
	std::vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
		if(found.first != found.second)
			ret.push_back(std::make_pair(it - files.cbegin(), std::make_pair(found.first, found.second)));
	}
	return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s)
	{
		auto trans = findBook(files, s);
		if(trans.empty())
		{
			std::cout << s << " not found in any stores" << std::endl;
			continue;
		}
		for(const auto &store : trans)
			os << "store " << store.first << " sales: " << std::accumulate(store.second.first, store.second.second, Sales_data(s)) << std::endl;
	}
}

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    std::vector<Sales_data> vs1 = {sales_data1, sales_data3};
    std::vector<Sales_data> vs2 = {sales_data2};
    std::vector<std::vector<Sales_data>> vvs = {vs1, vs2};

    reportResults(std::cin, std::cout, vvs);

 //    std::cout << std::hex << std::hash<std::string>()("001-01") << std::endl;
 //    std::cout << std::hex << std::hash<unsigned>()(1) << std::endl;
 //    std::cout << std::hex << std::hash<double>()(100) << std::endl;

 //    std::unordered_multiset<Sales_data> SDset;
 //    SDset.emplace(sales_data1);
 //    SDset.emplace("001-03", 1, 200);
 //    SDset.emplace(sales_data3);

	// for(const auto &item : SDset)
	// 	std::cout << "the hash code of " << item.isbn() <<":\n0x" << std::hex << std::hash<Sales_data>()(item) << "\n";

    return 0;
}
```

## 练习17.6

> 重写 findBook，不使用tuple和pair。

```cpp
#include <iostream>
#include <string>
#include "Sales_data.h"
#include <unordered_set>
#include <algorithm>
#include <utility>

namespace std
{
	template <>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data &s) const
	{
		return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

struct matches
{
	std::vector<Sales_data>::size_type index;
	std::vector<Sales_data>::const_iterator first;
	std::vector<Sales_data>::const_iterator last;
	matches(std::vector<Sales_data>::size_type index_, std::vector<Sales_data>::const_iterator first_, std::vector<Sales_data>::const_iterator last_) : index(index_), first(first_), last(last_) {}
};

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book)
{
	std::vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
		if(found.first != found.second)
			ret.push_back(matches(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(std::istream &in, std::ostream &os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s)
	{
		auto trans = findBook(files, s);
		if(trans.empty())
		{
			std::cout << s << " not found in any stores" << std::endl;
			continue;
		}
		for(const auto &store : trans)
			os << "store " << store.index << " sales: " << std::accumulate(store.first, store.last, Sales_data(s)) << std::endl;
	}
}

int main()
{
    Sales_data sales_data1("001-01", 1, 100);
    Sales_data sales_data2("001-01", 2, 100);
    Sales_data sales_data3("001-02", 2, 80);

    std::vector<Sales_data> vs1 = {sales_data1, sales_data3};
    std::vector<Sales_data> vs2 = {sales_data2};
    std::vector<std::vector<Sales_data>> vvs = {vs1, vs2};

    reportResults(std::cin, std::cout, vvs);

 //    std::cout << std::hex << std::hash<std::string>()("001-01") << std::endl;
 //    std::cout << std::hex << std::hash<unsigned>()(1) << std::endl;
 //    std::cout << std::hex << std::hash<double>()(100) << std::endl;

 //    std::unordered_multiset<Sales_data> SDset;
 //    SDset.emplace(sales_data1);
 //    SDset.emplace("001-03", 1, 200);
 //    SDset.emplace(sales_data3);

	// for(const auto &item : SDset)
	// 	std::cout << "the hash code of " << item.isbn() <<":\n0x" << std::hex << std::hash<Sales_data>()(item) << "\n";

    return 0;
}
```
  
## 练习17.7

> 解释你更倾向于哪个版本的findBook，为什么。

tuple版本的findBook，更简洁。  
  
## 练习17.8

> 在本节最后一段代码中，如果我们将Sales_data()作为第三个参数传递给accumulate，会发生什么？

返回的Sales_data中的bookNo成员为空。  
  
## 练习17.9

> 解释下列每个bitset 对象所包含的位模式：
```cpp
(a) bitset<64> bitvec(32);
(b) bitset<32> bv(1010101);
(c) string bstr; cin >> bstr; bitset<8> bv(bstr);
```

（a）用unsigned值初始化：0000000000000000000000000000000000000000000000000000000000100000；  
（b）用unsigned值初始化：00000000000011110110100110110101；  
（c）用string初始化：取决于cin。  
  
## 练习17.10

> 使用序列1、2、3、5、8、13、21初始化一个bitset，将这些位置置位。对另一个bitset进行默认初始化，并编写一小段程序将其恰当的位置位。

```cpp
#include <bitset>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vi = {1, 2, 3, 5, 8, 13, 21};
	std::bitset<32> bset;
	for(auto const i : vi)
	{
		bset.set(i);
	}
	std::cout << bset << std::endl;

	return 0;
}
```

## 练习17.11

> 定义一个数据结构，包含一个整型对象，记录一个包含10个问题的真/假测验的解答。如果测验包含100道题，你需要对数据结构做出什么改变（如果需要的话）？

```cpp
#include <bitset>

template <unsigned N>
class quiz
{
public:
	quiz(std::string &s) : bset(s) {}
	
private:
	std::bitset<N> bset;
};

int main()
{
	std::string s1("0101010101");
	std::string s2("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101");
	quiz<10> q1(s1);
	quiz<100> q2(s2);

	return 0;
}
```
  
## 练习17.12

> 使用前一题中的数据结构，编写一个函数，它接受一个问题编号和一个表示真/假解答的值，函数根据这两个参数更新测验的解答。

```cpp
#include <bitset>
#include <iostream>

template <unsigned N>
class quiz
{
template <unsigned M>
friend std::ostream &operator<<(std::ostream&, const quiz<M>&);
public:
	quiz(std::string &s) : bset(s) {}
	void update(size_t n, bool b)
	{
		bset[n] = b;
	}
	
private:
	std::bitset<N> bset;
};

template <unsigned M>
std::ostream &operator<<(std::ostream &os, const quiz<M> &q)
{
	os << q.bset;
	return os;
}

int main()
{
	std::string s1("0101010101");
	std::string s2("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101");
	quiz<10> q1(s1);
	quiz<100> q2(s2);

	q1.update(1,true);
	std::cout << q1 << std::endl;

	return 0;
}
```
  
## 练习17.13

> 编写一个整型对象，包含真/假测验的正确答案。使用它来为前两题中的数据结构生成测验成绩。

```cpp
#include <bitset>
#include <iostream>

template <unsigned N>
class quiz
{
template <unsigned M>
friend std::ostream &operator<<(std::ostream&, const quiz<M>&);

template <unsigned M>
friend size_t grade(const quiz<M>&, const quiz<M>&);
public:
	quiz(std::string &s) : bset(s) {}
	void update(size_t n, bool b)
	{
		bset[n] = b;
	}
	
private:
	std::bitset<N> bset;
};

template <unsigned M>
std::ostream &operator<<(std::ostream &os, const quiz<M> &q)
{
	os << q.bset;
	return os;
}

template <unsigned M>
size_t grade(const quiz<M> &lhsQ, const quiz<M> &rhsQ)
{
	return (lhsQ.bset ^ rhsQ.bset).flip().count();
}

int main()
{
	std::string s1("0101010101");
	std::string s2("0101010100");

	quiz<10> q1(s1);
	quiz<10> q2(s2);

	std::cout << grade(q1, q2) << std::endl;

	return 0;
}
```
  
## 练习17.14

> 编写几个正则表达式，分别触发不同错误。运行你的程序，观察编译器对每个错误的输出。

```cpp
#include <iostream>
#include <regex>
int main()
{
	try
	{
		std::regex r1("[[:anum:]]+\\.(cpp|cxx|cc)$", std::regex::icase);
	}catch(std::regex_error e)
	{
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}

	try
	{
		std::regex r1("[[:alnum:]+\\.(cpp|cxx|cc)$", std::regex::icase);
	}catch(std::regex_error e)
	{
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}	

	try
	{
		std::regex r1("[[:alnum:]]+\\.cpp|cxx|cc)$", std::regex::icase);
	}catch(std::regex_error e)
	{
		std::cout << e.what() << "\ncode: " << e.code() << std::endl;
	}

	return 0;
}
```
  
## 练习17.15

> 编写程序，使用模式查找违反“i在e之前，除非在c之后”规则的单词。你的程序应该提示用户输入一个单词，然后指出此单词是否符号要求。用一些违反和未违反规则的单词测试你的程序。

gcc version 4.8.4 对regex支持有问题，请使用4.9及以上版本。  
```cpp
#include <iostream>
#include <regex>
#include <string>

int main()
{
	/*https://en.wikipedia.org/wiki/I_before_E_except_after_C
	**ie in believe, fierce, collie, die, friend
	**ei after c in receive, ceiling, receipt, ceilidh
	*/
	// std::string pattern("[[:alpha:]]*(cei|[^c]ie)[[:alpha:]]*");
	std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::regex r(pattern);
	std::smatch results;
	std::cout << "input a word: ";

	std::string s;
	while(std::cin >> s)
	{
		if(std::regex_search(s, results, r))
			std::cout << s <<  ": error" << std::endl;
		else
			std::cout << s <<  ": correct" << std::endl;
	}

	return 0;
}
```
```sh
$ ./ex15 
believe
believe: correct
freind
freind: error
receipt
receipt: correct
theif
theif: error
receive
receive: correct
```

  
## 练习17.16

> 如果前一题程序中的regex对象用"[^c]ei"进行初始化，将会发生什么？用此模式测试你的程序，检查你的答案是否正确。
这样只匹配3个字符，（非c）和ei这3个字符，匹配成功后result中只有3个字符。  
这里就按照题意写规则。  
```cpp
#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string pattern("[^c]ei");
	std::regex r(pattern);
	std::smatch results;

	std::string s;
	while(std::cin >> s)
	{
		if(std::regex_search(s, results, r))
		{
			std::cout << s <<  ": correct" << std::endl;
			for (size_t i = 0; i < results.size(); ++i) 
				std::cout << i << ": " << results[i] << '\n';
		}
		else
		{
			std::cout << s <<  ": error" << std::endl;
		}
	}

	return 0;
}
```
```sh
$ ./ex16 
freind
freind: correct
1: rei 
```

## 练习17.17

> 更新你的程序，令它查找输入序列中所有违反"ei"语法规则的单词。

```cpp
#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	std::regex r(pattern, std::regex::icase);
	std::smatch results;
	std::string s("freind receipt theif receive");

	for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
	{
		std::cout << it->str() << std::endl;
	}

	return 0;
}
```
```sh
$ ./ex17 
freind
theif
```
  
## 练习17.18

> 修改你的程序，忽略包含“ei”但并非拼写错误的单词，如“albeit”和“neighbor”。

```cpp
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string pattern("([[:alpha:]]*[^c]ei[[:alpha:]]*)");
	std::regex r(pattern, std::regex::icase);
	std::smatch results;
	std::string s("freind receipt theif receive albeit neighbor");
	std::vector<std::string> vec{"neighbor","albeit","beige","feint","heir","reign","their",
            "counterfeit","foreign","inveigh","rein","veil","deign",
            "forfeit","inveigle","seize","veineiderdown","freight",
            "leisure","skein","weigheight","heifer","neigh","sleigh",
            "weighteither","height","neighbour","sleight","weirfeign",
            "heinous","neither","surfeit","weird"};

	for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
	{
		if (find(vec.begin(), vec.end(), it->str()) != vec.end())
			continue;
		std::cout << it->str() << std::endl;
	}

	return 0;
}
```
  
## 练习17.19

> 为什么可以不先检查m[4]是否匹配了就直接调用m[4].str()？

没有匹配则返回为空字符串，也是可以比较的。  
  
## 练习17.20

> 编写你自己版本的验证电话号码的程序。

```cpp
#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch &m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

//908.555.1500
int main()
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	std::regex r(phone);
	std::smatch m;
	std::string s;

	while(std::getline(std::cin, s))
	{
		for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
			if(valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
	}

	return 0;
}
```

## 练习17.26

> 重写你的电话号码程序，使之对多于一个电话号码的人只输出第二个和后续号码。

```cpp
#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch &m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[7].str();
}

//tx 908.555.1500 (908)5551500
int main()
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?([ ]*)?(\\d{3})([-. ]?)([ ]*)?(\\d{4})";
	std::regex r(phone);
	std::smatch m;
	std::string s;

	while(std::getline(std::cin, s))
	{
		std::vector<std::string> vs;
		for(std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
			if(valid(*it))
				vs.push_back(it->str());
		if (vs.size() == 0)
		{
			std::cout << "no matched number" << std::endl;
		}else if(vs.size() == 1)
		{
			std::cout << vs[0] << std::endl;
		}else if(vs.size() >1)
		{
			for(int i = 1; i < vs.size(); ++i)
				std::cout << vs[i] << " ";
			std::cout << std::endl;
		}
	}

	return 0;
}
```
  
## 练习17.27

> 编写程序，将九位数字邮政编码的格式转换为 ddddd-dddd。

```cpp
#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch &m)
{
	if(m[3].matched)
		return true;
	else
		return !m[2].matched;
}

//111112222
//11111-2222
//11111
//11111-
int main()
{
	std::string mail = "(\\d{5})([-])?(\\d{4})?";
	std::regex r(mail);
	std::smatch m;
	std::string s;
	std::string fmt = "$1-$3";

	while(std::getline(std::cin, s))
	{
		std::cout << std::regex_replace(s, r, fmt) << std::endl;
	}

	return 0;
}
```
  
## 练习17.28

> 编写函数，每次调用生成并返回一个均匀分布的随机unsigned int。

```cpp
#include <random>
#include <iostream>

unsigned random_func()
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

int main()
{
	
	std::cout << random_func() << std::endl;

	return 0;
}
```
  
## 练习17.29

> 修改上一题中编写的函数，允许用户提供一个种子作为可选参数。

```cpp
#include <random>
#include <iostream>

unsigned random_func()
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

unsigned random_func(unsigned i)
{
	static std::default_random_engine e(i);
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

int main()
{
	
	std::cout << random_func() << std::endl;	//default 1
	std::cout << random_func(2) << std::endl;

	return 0;
}
```
  
## 练习17.30

> 再次修改你的程序，此次增加两个参数，表示函数允许返回的最小值和最大值。

```cpp
#include <random>
#include <iostream>

unsigned random_func()
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

unsigned random_func(unsigned i)
{
	static std::default_random_engine e(i);
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

unsigned random_func(unsigned i, unsigned min, unsigned max)
{
	static std::default_random_engine e(i);
	static std::uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}

int main()
{
	
	std::cout << random_func() << std::endl;	//default 1
	std::cout << random_func(2) << std::endl;
	for(int i = 0; i < 10; ++i)
		std::cout << random_func(1, 0, 10) << std::endl;

	return 0;
}
```