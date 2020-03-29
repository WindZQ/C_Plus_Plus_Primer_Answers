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

