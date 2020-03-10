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