## 练习12.1

> 在此代码的结尾，b1 和 b2 各包含多少个元素？
```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```

它们实际操作的是同一个vector，都包含4个元素。在代码的结尾，b2 被析构了，不影响 b1 的元素。

## 练习12.2 : [头文件](12.2.h) | [主函数](12.2.cpp)

> 编写你自己的StrBlob 类，包含const 版本的 front 和 back。

## 练习12.3

> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要。

不需要。`push_back` 和 `pop_back` 会改变对象的内容。而 const 对象是只读的，因此不需要。

## 练习12.4

> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

因为 size_type 是一个无符号整型，当传递给 check 的参数小于 0 的时候，参数值会转换成一个正整数。

## 练习12.5

> 我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。

构造函数不是 explicit 的，意味着可以从 initializer_list 隐式转换为 StrBlob。在 StrBlob 对象中，只有一个数据成员 data，而 StrBlob 对象本身的含义，也是一个**管理字符串的序列**。因此，从 initializer_list 到 StrBlob 的转换，在逻辑上是可行的。而这个设计策略的缺点，可能在某些地方我们确实需要 initializer_list，而编译器仍会将之转换为 StrBlob。

## [练习12.6](12.6.cpp)

> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

## [练习12.7](12.7.cpp)

> 重做上一题，这次使用 shared_ptr 而不是内置指针。

## 练习12.8

> 下面的函数是否有错误？如果有，解释错误原因。
```cpp
bool b() {
	int* p = new int;
	// ...
	return p;
}
```

有错误。没有释放指针 p 。

## 练习12.9

> 解释下面代码执行的结果。
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

r 和 q 指向 42，而之前 r 指向的 100 的内存空间并没有被释放，因此会发生内存泄漏。r2 和 q2 都是智能指针，当对象空间不被引用的时候会自动释放。

## 练习12.10

> 下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

正确。`shared_ptr<int>(p)` 会创建一个临时的智能指针，这个智能指针与 p 引用同一个对象，此时引用计数为 2。当表达式结束时，临时的智能指针被销毁，此时引用计数为 1。