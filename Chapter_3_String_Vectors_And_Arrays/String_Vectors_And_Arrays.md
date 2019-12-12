## 练习3.1

> 使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。

* [**1.4.1**](3.1.a.cpp)
* [**2.6.2**](3.1.b.cpp)

## 练习3.2

> 编写一段程序从标准输入中一次读入一行，然后修改该程序使其一次读入一个词。

* [**一次读入一行**](3.2.a.cpp)
* [**一次读入一个词**](3.2.b.cpp)

## 练习3.3 

> 请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

* 类似 is >> s 的读取，string对象会忽略开头的空白并从第一个真正的字符开始，直到遇见下一空白为止。
* 类似 getline(is, s) 的读取，string对象会从输入流中读取字符，直到遇见换行符为止。

## 练习3.4

> 编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

* [**比较大的**](3.4.a.cpp)
* [**长度大的**](3.4.b.cpp)

## 练习3.5

> 编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。

* [**未隔开的**](3.5.a.cpp)
* [**隔开的**](3.5.b.cpp)

## [练习3.6](3.6.cpp) 

> 编写一段程序，使用范围for语句将字符串内所有字符用X代替。

## [练习3.7](3.7.cpp)

> 就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？先估计一下结果，然后实际编程进行验证。

如果设置为char，那么原来的字符串不会发生改变。

## [练习3.8](3.8.cpp)

> 分别用while循环和传统for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？

范围for语句更好，不直接操作索引，更简洁。

## 练习3.9

> 下面的程序有何作用？它合法吗？如果不合法？为什么？
```cpp
string s;
cout << s[0] << endl;
```

不合法。使用下标访问空字符串是非法的行为。

## [练习3.10](3.10.cpp)

> 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

## 练习3.11

> 下面的范围for语句合法吗？如果合法，c的类型是什么？
```cpp
const string s = "Keep out!";
for(auto &c : s){ /* ... */ }
```

要根据for循环中的代码来看是否合法，c是string 对象中字符的引用，s是常量。因此如果for循环中的代码重新给c赋值就会非法，如果不改变c的值，那么合法。

## 练习3.12

> 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。
```cpp
vector<vector<int>> ivec;         // 在C++11当中合法
vector<string> svec = ivec;       // 不合法，类型不一样
vector<string> svec(10, "null");  // 合法
```

## 练习3.13

> 下列的vector对象各包含多少个元素？这些元素的值分别是多少？
```cpp
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{ 10 };     // size:1,  value:10
vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
vector<string> v6{ 10 };  // size:10, value:""
vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
```

## [练习3.14](3.14.cpp)

> 编写一段程序，用cin读入一组整数并把它们存入一个vector对象。

## [练习3.15](3.15.cpp)

> 改写上题程序，不过这次读入的是字符串。

## [练习3.16](3.16.cpp)

> 编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来

## [练习3.17](3.17.cpp)

> 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。输出改变后的结果，每个词占一行。

## 练习3.18

> 下面的程序合法吗？如果不合法，你准备如何修改？
```cpp
vector<int> ivec;
ivec[0] = 42;
```

不合法。应改为：
```cpp
ivec.push_back(42);
```

## 练习3.19

> 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请例举三种不同的实现方法，哪种方式更好呢？

如下三种：
```cpp
vector<int> ivec1(10, 42);
vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
vector<int> ivec3;
for (int i = 0; i < 10; ++i)
	ivec3.push_back(42);
```
第一种方式最好。

## [练习3.20](3.20.cpp)

> 读入一组整数并把他们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，接着输入第二个和倒数第二个元素的和，以此类推。

## [练习3.21](3.21.cpp)

> 请使用迭代器重做3.3.3节的第一个练习。

## [练习3.22](3.22.cpp)

> 修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后输出它。

## [练习3.23](3.23.cpp)

> 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

## [练习3.24](3.24.cpp)

> 请使用迭代器重做3.3.3节的最后一个练习。

## [练习3.25](3.25.cpp)

> 3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。

## 练习3.26

> 在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?

因为迭代器支持的运算只有 ` - ` ，而没有 ` + ` 。` end - beg ` 意思是相距若干个元素，将之除以2然后与beg相加，表示将beg移动到一半的位置。

## 练习3.27

> 假设txt_size 是一个无参函数，它的返回值是int。请回答下列哪个定义是非法的，为什么？
```cpp
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```

* (a) 非法。纬度必须是一个常量表达式。
* (b) 合法。
* (c) 非法。txt_size() 的值必须要到运行时才能得到。
* (d) 非法。数组的大小应该是12。

## 练习3.28

> 下列数组中元素的值是什么？
```cpp
string sa[10];
int ia[10];
int main() {
	string sa2[10];
	int ia2[10];
}
```

数组的元素会被默认初始化。sa 的元素值全部为空字符串，ia 的元素值全部为0。sa2 的元素值全部为空字符串，ia2 的元素值全部未定义。

## 练习3.29

> 相比于vector 来说，数组有哪些缺点，请例举一些。

* 数组的大小是确定的。
* 不能随意增加元素
* 不允许拷贝和赋值

## 练习3.30

> 指出下面代码中的索引错误。
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
	ia[ix] = ix;
```

当 ix 增长到 10 的时候，ia[ix] 的下标越界。