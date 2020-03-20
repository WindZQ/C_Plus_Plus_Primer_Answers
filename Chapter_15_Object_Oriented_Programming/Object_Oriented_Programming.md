## 练习15.1

> 什么是虚成员？

对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数。

## 练习15.2

> protected 访问说明符与 private 有何区别？

* protected ： 基类和和其派生类还有友元可以访问。
* private ： 只有基类本身和友元可以访问。

## 练习15.3

> 定义你自己的 Quote 类和 print_total 函数。

[Quote](15.3.h) | [main.cpp](15.3.cpp)

## 练习15.4

> 下面哪条声明语句是不正确的？请解释原因。
```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

* (a) 不正确。类不能派生自身。
* (b) 不正确。这是定义而非声明。
* (c) 不正确。派生列表不能出现在这。

## [练习15.5](exercise15_5.h)

> 定义你自己的 Bulk_quote 类。
