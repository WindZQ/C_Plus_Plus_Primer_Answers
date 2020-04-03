## 练习16.1

> 给出实例化的定义。

当编译器实例化一个模版时，它使用实际的模版参数代替对应的模版参数来创建出模版的一个新“实例”。

## 练习16.2

> 编写并测试你自己版本的 compare 函数。

```cpp
template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}
```

## 练习16.3

> 对两个 Sales_data 对象调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。

`error: no match for 'operator<' `

## 练习16.4

> 编写行为类似标准库 find 算法的模版。函数需要两个模版类型参数，一个表示函数的迭代器参数，另一个表示值的类型。使用你的函数在一个 vector<int> 和一个list<string>中查找给定值。

```cpp
template<typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value& v)
{
	for ( ; first != last && *first != value; ++first);
	return first;
}
```

## 练习16.5

> 为6.2.4节中的print函数编写模版版本，它接受一个数组的引用，能处理任意大小、任意元素类型的数组。

```cpp
template<typename Array>
void print(const Array& arr)
{
	for (const auto& elem : arr)
		std::cout << elem << std::endl;
}
```

## 练习16.6

> 你认为接受一个数组实参的标准库函数 begin 和 end 是如何工作的？定义你自己版本的 begin 和 end。

```cpp
template<typename T, unsigned N>
T* begin(const T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T* end(const T (&arr)[N])
{
	return arr + N;
}
```

## 练习16.7

> 编写一个 constexpr 模版，返回给定数组的大小。

```cpp
template<typename T, typename N> constexpr
unsigned size(const T (&arr)[N])
{
	return N;
}
```

## 练习16.8

> 在第97页的“关键概念”中，我们注意到，C++程序员喜欢使用 != 而不喜欢 < 。解释这个习惯的原因。

因为大多数类只定义了 != 操作而没有定义 < 操作，使用 != 可以降低对要处理的类型的要求。

## 练习16.9

> 什么是函数模版，什么是类模版？

一个函数模版就是一个公式，可用来生成针对特定类型的函数版本。类模版是用来生成类的蓝图的，与函数模版的不同之处是，编译器不能为类模版推断模版参数类型。如果我们已经多次看到，为了使用类模版，我们必须在模版名后的尖括号中提供额外信息。

## 练习16.10

> 当一个类模版被实例化时，会发生什么？

一个类模版的每个实例都形成一个独立的类。

## 练习16.11

> 下面 List 的定义是错误的。应如何修改它？
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem *ptr, elemType value);
private:
	ListItem *front, *end;
};
```

模版需要模版参数，应该修改为如下：
```cpp
template <typename elemType> class ListItem;  
template <typename elemType> class List{  
public:  
  	List<elemType>();  
  	List<elemType>(const List<elemType> &);  
  	List<elemType>& operator=(const List<elemType> &);  
  	~List();  
  	void insert(ListItem<elemType> *ptr, elemType value);  
private:  
  	ListItem<elemType> *front, *end;  
};
```	

## 练习16.12

> 编写你自己版本的 Blob 和 BlobPtr 模版，包含书中未定义的多个const成员。

[Blob](blob.h) | [BlobPtr](blobptr.h)

## 练习16.13

> 解释你为 BlobPtr 的相等和关系运算符选择哪种类型的友好关系？

这里需要与类型一一对应，所以就选择一对一友好关系。

## 练习16.14

> 编写 Screen 类模版，用非类型参数定义 Screen 的高和宽。

[Screen](screen.h)

## 练习16.15

> 为你的 Screen 模版实现输入和输出运算符。Screen 类需要哪些友元（如果需要的话）来令输入和输出运算符正确工作？解释每个友元声明（如果有的话）为什么是必要的。

类的 operator<< 和 operator>> 应该是类的友元。

## 练习16.16

> 将 StrVec 类重写为模版，命名为 Vec。

[Vec](vec.h)

## 练习16.17

> 声明为 typename 的类型参数和声明为 class 的类型参数有什么不同（如果有的话）？什么时候必须使用typename？

没有什么不同。当我们希望通知编译器一个名字表示类型时，必须使用关键字 typename，而不能使用 class。

## 练习16.18

> 解释下面每个函数模版声明并指出它们是否非法。更正你发现的每个错误。
```cpp
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int *);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
	template <typename Ctype> Ctype f5(Ctype a);
```

* (a) 非法。应该为 `template <typename T, typename U, typename V> void f1(T, U, V);`。
* (b) 非法。应该为 `template <typename T> T f2(int &t);`
* (c) 非法。应该为 `template <typename T> inline T foo(T, unsigned int*);`
* (d) 非法。应该为 `template <typename T> T f4(T, T);`
* (e) 非法。Ctype 被隐藏了。

## 练习16.19

> 编写函数，接受一个容器的引用，打印容器中的元素。使用容器的 size_type 和 size成员来控制打印元素的循环。

```cpp
template<typename Container>
void print(const Container& c)
{
	for (typename Container::size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
}
```

## 练习16.20

> 重写上一题的函数，使用begin 和 end 返回的迭代器来控制循环。

```cpp
template<typename Container>
void print(const Container& c)
{
	for (auto it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
}
```

## 练习16.21

> 编写你自己的 DebugDelete 版本。

[DebugDelete](debugDelete.h)

## 练习16.22

> 修改12.3节中你的 TextQuery 程序，令 shared_ptr 成员使用 DebugDelete 作为它们的删除器。

## 练习16.23

> 预测在你的查询主程序中何时会执行调用运算符。如果你的预测和实际不符，确认你理解了原因。

## 练习16.24

> 为你的 Blob 模版添加一个构造函数，它接受两个迭代器。

```cpp
template<typename T>    //for class
template<typename It>   //for this member
Blob<T>::Blob(It b, It e) :
    data(std::make_shared<std::vector<T>>(b, e))
{ }
```

## 练习16.25

> 解释下面这些声明的含义。
```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

前者是模版声明，后者是实例化定义。

## 练习16.26

> 假设 NoDefault 是一个没有默认构造函数的类，我们可以显式实例化 vector<NoDefualt>吗？如果不可以，解释为什么。

不可以。如
```cpp
std::vector<NoDefault> vec(10);
```
会使用 NoDefault 的默认构造函数，而 NoDefault 没有默认构造函数，因此是不可以的。

## 练习16.27

> 对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。如果一个模版被实例化，解释为什么;如果未实例化，解释为什么没有。
```cpp
template <typename T> class Stack {	};
void f1(Stack<char>); 		//(a)
class Exercise {
	Stack<double> &rds;		//(b)
	Stack<int> si;			//(c)
};
int main() {
	Stack<char> *sc;		//(d)
	f1(*sc);				//(e)
	int iObj = sizeof(Stack<string>);	//(f)
}
```

(a)、(b)、(c)、(f) 都发生了实例化，(d)、(e) 没有实例化。

## 练习16.28

> 编写你自己版本的 shared_ptr 和 unique_ptr。

[shared_ptr](shared_ptr.h) | [unique_ptr](unique_ptr.h)

## 练习16.29

> 修改你的 Blob 类，用你自己的 shared_ptr 代替标准库中的版本。

## 练习16.30

> 重新运行你的一些程序，验证你的 shared_ptr 类和修改后的 Blob 类。（注意：实现 weak_ptr 类型超出了本书范围，因此你不能将BlobPtr类与你修改后的Blob一起使用。）
