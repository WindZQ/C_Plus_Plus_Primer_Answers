## 练习14.1

> 在什么情况下重载的运算符与内置运算符有所区别？在什么情况下重载的运算符又与内置运算符一样？

我们可以直接调用重载运算符函数。重置运算符与内置运算符有一样的优先级与结合性。

## 练习14.2 ： [hpp](14.2.h) | [cpp](14.2.cpp)

> 为 Sales_data 编写重载的输入、输出、加法和复合赋值运算符。

## 练习14.3

> string 和 vector 都定义了重载的==以比较各自的对象，假设 svec1 和 svec2 是存放 string 的 vector，确定在下面的表达式中分别使用了哪个版本的==？
```cpp
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) "svec1[0] == "stone"
``` 

* (a) 都不是。
* (b) string 
* (c) vector 
* (d) string

## 练习14.4

> 如何确定下列运算符是否应该是类的成员？
```cpp
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
```

* (a) 不需要是成员。
* (b) 是成员。
* (c) 是成员。
* (d) 必须是成员。
* (e) 不需要是成员。
* (f) 不需要是成员。
* (g) 不需要是成员。
* (h) 必须是成员。

## 练习14.5

> 在7.5.1节中的练习7.40中，编写了下列类中某一个的框架，请问在这个类中应该定义重载的运算符吗？如果是，请写出来。
```cpp
(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree
``` 	

`Book`

[hpp](14.5.h) | [cpp](14.5.cpp) | [test](14.5.main.cpp)

## 练习14.6

> 为你的 Sales_data 类定义输出运算符。

## 练习14.7

> 你在13.5节的练习中曾经编写了一个String类，为它定义一个输出运算符。

[hpp](14.7.h) | [cpp](14.7.cpp) | [test](14.7.main.cpp)

## 练习14.8

> 你在7.5.1节中的练习中曾经选择并编写了一个类，为它定义一个输出运算符。

## 练习14.9

> 为你的 Sales_data 类定义输入运算符。

## 练习14.10

> 对于 Sales_data 的输入运算符来说如果给定了下面的输入将发生什么情况？
```cpp
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9
```

* (a) 格式正确。
* (b) 不合法的输入。因为程序试图将 `0-210-99999-9` 转换为 `float`。

## 练习14.11

> 下面的 Sales_data 输入运算符存在错误吗？如果有，请指出来。对于这个输入运算符如果仍然给定上个练习的输入将会发生什么情况？
```cpp
istream& operator>>(istream& in, Sales_data& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	s.revence = s.units_sold >> price;
	return in;
}
```

没有输入检查，什么也不会发生。

## 练习14.12

> 你在7.5.1节的练习中曾经选择并编写了一个类，为它定义一个输入运算符并确保该运算符可以处理输入错误。

## 练习14.13

> 你认为 Sales_data 类还应该支持哪些其他算术运算符？如果有的话，请给出它们的定义。

没有其他了。

## 练习14.14

> 你觉得为什么调用 operator+= 来定义operator+ 比其他方法更有效？

因为用 `operator+=` 会避免使用一个临时对象，而使得更有效。

## 练习14.15

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有其他算术运算符吗？如果是，请实现它们；如果不是，解释原因。

[hpp](14.15.h) | [cpp](14.15.cpp) | [test](14.15.main.cpp)


## 练习14.16

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义相等运算符和不相等运算符。

- `StrBlob` & `StrBlobPtr`: [hpp](14.16.StrBlob.h) | [cpp](14.16.StrBlob.cpp) | [Test](14.16.StrBlobTest.cpp)
- `StrVec`: [hpp](14.16.StrVec.h) | [cpp](14.16.StrVec.cpp) | [Test](14.16.StrVecMain.cpp)
- `String`: [hpp](14.16.String.h) | [cpp](14.16.String.cpp) | [Test](14.16.StringMain.cpp)- `StrBlob` & `StrBlobPtr`: [hpp](14.16.StrBlob.h) | [cpp](14.16.StrBlob.cpp) | [Test](14.16.StrBlobTest.cpp)
- `StrVec`: [hpp](14.16.StrVec.h) | [cpp](14.16.StrVec.cpp) | [Test](14.16.StrVecMain.cpp)
- `String`: [hpp](14.16.String.h) | [cpp](14.16.String.cpp) | [Test](14.16.StringMain.cpp)

## 练习14.17

> 你在7.5.1节中的练习7.40中曾经选择并编写了一个类，你认为它应该含有相等运算符吗？如果是，请实现它；如果不是，解释原因。

## 练习14.18

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类分别定义关系运算符。

## 练习14.19

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有关系运算符吗？如果是，请实现它；如果不是，解释原因。

## 练习14.20

> 为你的 Sales_data 类定义加法和复合赋值运算符。


## 练习14.21

> 编写 Sales_data 类的+ 和+= 运算符，使得 + 执行实际的加法操作而 += 调用+。相比14.3节和14.4节对这两个运算符的定义，本题的定义有何缺点？试讨论之。

缺点：使用了一个 `Sales_data` 的临时对象，但它并不是必须的。

## 练习14.22

> 定义赋值运算符的一个新版本，使得我们能把一个表示 ISBN 的 string 赋给一个 Sales_data 对象。

[hpp](14.22.h) | [cpp](14.22.cpp) | [test](14.22.main.cpp)

## 练习14.23

> 为你的StrVec 类定义一个 initializer_list 赋值运算符。

[hpp](14.23.h) | [cpp](14.23.cpp) | [test](14.23.main.cpp)

## 练习14.24

> 你在7.5.1节的练习7.40中曾经选择并编写了一个类，你认为它应该含有拷贝赋值和移动赋值运算符吗？如果是，请实现它们。

[hpp](14.24.h) | [cpp](14.24.cpp) | [test](14.24.main.cpp)

## 练习14.25

> 上题的这个类还需要定义其他赋值运算符吗？如果是，请实现它们；同时说明运算对象应该是什么类型并解释原因。

是。如上题。

## 练习14.26

> 为你的 StrBlob 类、StrBlobPtr 类、StrVec 类和 String 类定义下标运算符。

## 练习14.27

> 为你的 StrBlobPtr 类添加递增和递减运算符。

## 练习14.28

> 为你的 StrBlobPtr 类添加加法和减法运算符，使其可以实现指针的算术运算。

## 练习14.29

> 为什么不定义const 版本的递增和递减运算符？

因为递增和递减会改变对象本身，所以定义 const 版本的毫无意义。

## 练习14.30

> 为你的 StrBlobPtr 类和在12.1.6节练习12.22中定义的 ConstStrBlobPtr 的类分别添加解引用运算符和箭头运算符。注意：因为 ConstStrBlobPtr 的数据成员指向const vector，所以ConstStrBlobPtr 中的运算符必须返回常量引用。

## 练习14.31

> 我们的 StrBlobPtr 类没有定义拷贝构造函数、赋值运算符以及析构函数，为什么？

因为使用合成的足够了。

## 练习14.32

> 定义一个类令其含有指向 StrBlobPtr 对象的指针，为这个类定义重载的箭头运算符。

```cpp
class StrBlobPtr;

class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) { }

    StrBlobPtr& operator *();
    StrBlobPtr* operator->();

private:
    StrBlobPtr* pointer = nullptr;
};
```

## 练习14.33

> 一个重载的函数调用运算符应该接受几个运算对象？

一个重载的函数调用运算符接受的运算对象应该和该运算符拥有的操作数一样多。

## 练习14.34

> 定义一个函数对象类，令其执行if-then-else 的操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参值；如果不成功返回第三个形参的值。

```cpp
struct Test 
{
    int operator()(bool b, int iA, int iB) 
    {
        return b ? iA : iB;
    }
};
```

## [练习14.35](14.35.cpp)

> 编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，然后返回一个表示我们所读内容的string。如果读取失败，返回空string。

## [练习14.36](14.36.cpp)

> 使用前一个练习定义的类读取标准输入，将每一行保存为 vector 的一个元素。

## [练习14.37](14.37.cpp)

> 编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。

## [练习14.38](14.38.cpp)

> 编写一个类令其检查某个给定的 string 对象的长度是否与一个阈值相等。使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个，长度为2的单词有多少个、......、长度为10的单词有多少个。

## [练习14.39](14.38.cpp)

> 修改上一题的程序令其报告长度在1到9之间的单词有多少个、长度在10以上的单词有多少个。

## [练习14.40](14.40.cpp)

> 重新编写10.3.2节的biggies 函数，使用函数对象替换其中的 lambda 表达式。
