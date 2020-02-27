## 练习13.1

> 拷贝构造函数是什么？什么时候使用它？

如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数。当使用**拷贝初始化**时，我们会用到拷贝构造函数。

## 练习13.2

> 解释为什么下面的声明是非法的：
```cpp
Sales_data::Sales_data(Sales_data rhs);
```

参数类型应该是引用类型。

## 练习13.3

> 当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

当我们拷贝 StrBlob时，会使 `shared_ptr` 的引用计数加1。当我们拷贝 StrBlobPtr 时，引用计数不会变化。

## 练习13.4

> 假定 Point 是一个类类型，它有一个public的拷贝构造函数，指出下面程序片段中哪些地方使用了拷贝构造函数：
```cpp
Point global;
Point foo_bar(Point arg) // 1
{
	Point local = arg, *heap = new Point(global); // 2: Point local = arg,  3: Point *heap = new Point(global) 
	*heap = local; 
	Point pa[4] = { local, *heap }; // 4, 5
	return *heap;  // 6
}
```

上面有6处地方使用了拷贝构造函数。


## [练习13.5](13.5.h)

> 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。你的构造函数应该动态分配一个新的string，并将对象拷贝到ps所指向的位置，而不是拷贝ps本身：
```cpp
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()):
		ps(new std::string(s)), i(0) { }
private:
	std::string *ps;
	int i;
}
```