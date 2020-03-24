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


## [练习15.6](15.6.cpp)

> 将 Quote 和 Bulk_quote 的对象传给15.2.1节练习中的 print_total 函数，检查该函数是否正确。

## [练习15.7](15.7.h)

> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分将以原价销售。

## 练习15.8

> 给出静态类型和动态类型的定义。

表达式的静态类型在编译时总是已知的，它是变量声明时的类型或表达式生成的类型。动态类型则是变量或表达式表示的内存中的对象的类型。动态类型直到运行时才可知。

## 练习15.9

> 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

基类的指针或引用的静态类型可能与其动态类型不一致。

## 练习15.10

> 回忆我们在8.1节进行的讨论，解释第284页中将 ifstream 传递给 Sales_data 的read 函数的程序是如何工作的。

`std::ifstream` 是 `std::istream` 的派生基类，因此 read 函数能够正常工作。

## 练习15.11

> 为你的 Quote 类体系添加一个名为 debug 的虚函数，令其分别显示每个类的数据成员。

```cpp
void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
}
```

## 练习15.12

> 有必要将一个成员函数同时声明成 override 和 final 吗？为什么？

有必要。override 的含义是重写基类中相同名称的虚函数，final 是阻止它的派生类重写当前虚函数。

## 练习15.13

> 给定下面的类，解释每个 print 函数的机理：
```cpp
class base {
public:
	string name() { return basename;}
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};
class derived : public base {
public:
	void print(ostream &os) { print(os); os << " " << i; }
private:
	int i;
};
```
在上述代码中存在问题吗？如果有，你该如何修改它？

有问题。应该改为：
```cpp
	void print(ostream &os) override { base::print(os); os << " derived\n " << i; }
```

## 练习15.14

> 给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数：
```cpp
base bobj; 		base *bp1 = &bobj; 	base &br1 = bobj;
derived dobj; 	base *bp2 = &dobj; 	base &br2 = dobj;
(a) bobj.print();	(b)dobj.print();	(c)bp1->name();
(d)bp2->name();		(e)br1.print();		(f)br2.print();
```

* (a) 编译时。
* (b) 编译时。
* (c) 编译时。
* (d) 编译时。
* (e) 运行时。base::print()
* (f) 运行时。derived::print()

## 练习15.15

> 定义你自己的 Disc_quote 和 Bulk_quote。

[Disc_quote](Disc_quote.h) | [Bulk_quote](Bulk_quote.h)

## 练习15.16

> 改写你在15.2.2节练习中编写的数量受限的折扣策略，令其继承 Disc_quote。

[Limit_quote](Limit_quote.h)

## 练习15.17

> 尝试定义一个 Disc_quote 的对象，看看编译器给出的错误信息是什么？

`error: cannot declare variable 'd' to be of abstract type 'Disc_quote': Disc_quote d;`

## 练习15.18

> 假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：
```cpp
Base *p = &d1;  //d1 的类型是 Pub_Derv
p = &d2;		//d2 的类型是 Priv_Derv
p = &d3;		//d3 的类型是 Prot_Derv
p = &dd1;		//dd1 的类型是 Derived_from_Public	
p = &dd2;		//dd2 的类型是 Derived_from_Private
p = &dd3;		//dd3 的类型是 Derived_from_Protected
```

* Base *p = &d1; 合法
* p = &d2; 不合法
* p = &d3; 不合法
* p = &dd1; 合法
* p = &dd2; 不合法
* p = &dd3; 不合法

## 练习15.19

> 假设543页和544页的每个类都有如下形式的成员函数：
```cpp
void memfcn(Base &b) { b = *this; }
```
对于每个类，分别判断上面的函数是否合法。

合法：
* Pub_Derv
* Priv_Derv
* Prot_Derv
* Derived_from_Public
* Derived_from_Protected
不合法：
* Derived_from_Private

## [练习15.20](15.20.cpp)

> 编写代码检验你对前面两题的回答是否正确。

## 练习15.21

> 从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应的一组类型组织成一个继承体系：
```cpp
(a) 图形文件格式（如gif、tiff、jpeg、bmp）
(b) 图形基元（如方格、圆、球、圆锥）
(c) C++语言中的类型（如类、函数、成员函数）
```

## [练习15.22](15.20.cpp)

> 对于你在上一题中选择的类，为其添加函数的虚函数及公有成员和受保护的成员。

## [练习15.23](15.23.cpp)

> 假设第550页的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？如果你修改之后 fcn 匹配了 Base 中的定义，则该节的那些调用语句将如何解析？

移除 int 参数。

## 练习15.24

> 哪种类需要虚析构函数？虚析构函数必须执行什么样的操作？

基类通常应该定义一个虚析构函数。

## 练习15.25

> 我们为什么为 Disc_quote 定义一个默认构造函数？如果去掉该构造函数的话会对 Bulk_quote 的行为产生什么影响？

因为Disc_quote的默认构造函数会运行Quote的默认构造函数，而Quote默认构造函数会完成成员的初始化工作。
如果去除掉该构造函数的话，Bulk_quote的默认构造函数而无法完成Disc_quote的初始化工作。
