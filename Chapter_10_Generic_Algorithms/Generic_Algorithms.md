## [练习10.1](10.1.cpp)

> 头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入vector中，打印有多少个元素的值等于给定值。

## [练习10.2](10.2.cpp)

> 重做上一题，但读取 string 序列存入 list 中。

## [练习10.3](10.3.cpp)

> 用 accumulate求一个 vector<int> 中元素之和。

## [练习10.4](10.4.cpp)

> 假定 v 是一个vector<double>，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）？

结果会是 int 类型。

## 练习10.5

> 在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

C风格字符串是用指向字符的指针表示的，因此会比较两个指针的值（地址），而不会比较这两个字符串的内容。

## [练习10.6](10.6.cpp)

> 编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。

## 练习10.7

> 下面程序是否有错误？如果有，请改正：
```cpp
(a) vector<int> vec; list<int> lst; int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());
(b) vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
```

* (a) 应该加一条语句 `vec.resize(lst.size())` 。copy 时必须保证目标目的序列至少要包含与输入序列一样多的元素。
* (b) 从语句上来说没错误，这段代码没有任何结果。但是从逻辑上来说，应该将 `vec.reserve(10)` 改为 `vec.resize(10)` 。

## 练习10.8

> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？

`back_inserter` 是插入迭代器，在 `iterator.h` 头文件中，不是标准库的算法。

## [练习10.9](10.9.cpp)

> 实现你自己的 elimDups。分别在读取输入后、调用 unique后以及调用erase后打印vector的内容。

##　练习10.10

> 你认为算法不改变容器大小的原因是什么？

算法的接口是迭代器，而迭代器用来改变容器。这样的设计使得算法具有通用性。
