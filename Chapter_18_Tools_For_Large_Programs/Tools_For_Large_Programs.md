## 练习18.1

> 在下列 throw 语句中异常对象的类型是什么？
```cpp
(a) range_error r("error");
	throw r;
(b) exception *p = &r;
	throw *p;
```

（a）range_error；  
（b）exception。  
throw p，此时抛出的为指向局部对象的指针，我们几乎可以肯定这是一种错误行为。  
  
## 练习18.2

> 当在指定的位置发生了异常时将出现什么情况？
```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	//此处发生异常
}
```

p的内存将不会被释放，会出现内存泄漏。  
  
## 练习18.3

> 要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方法并实现它们。

使用shared_ptr；自己写个类来实现。  
```cpp
std::shared_ptr<int> p(new int[v.size()], [](int *p) {delete p});
```
```cpp
struct P {
	int *p = nullptr;
	P(std::size_t n):p(new int[n]){}
	~P()
	{
		delete []p;
	}
};
```
  
## 练习18.4

> 查看图18.1所示的继承体系，说明下面的 try 块有何错误并修改它。
```cpp
try {
	// 使用 C++ 标准库
} catch (exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```

应该把继承链最底端的类放在前面，而将继承链最顶端的类放在后面。  
```cpp
try{
	//使用C++标准库
}catch(overflow_error eobj){
	//...
}catch(const runtime_error &re){
	//...
}catch(exception){
	//...
}
```
  
## 练习18.5

> 修改下面的main函数，使其能捕获图18.1所示的任何异常类型：
```cpp
int main(){
	// 使用 C++标准库
}
```
处理代码应该首先打印异常相关的错误信息，然后调用 abort 终止函数。

```cpp
#include <exception>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

using namespace std;

int main()
{
	try{
		//使用C++标准库
	}catch(bad_cast &r){
		cout << r.what();
		abort();
	}catch(range_error &r){
		cout << r.what();
		abort();
	}catch(underflow_error &r){
		cout << r.what();
		abort();
	}catch(overflow_error &r){
		cout << r.what();
		abort();
	}catch(runtime_error &r){
		cout << r.what();
		abort();
	}catch(length_error &r){
		cout << r.what();
		abort();
	}catch(out_of_range &r){
		cout << r.what();
		abort();
	}catch(invalid_argument &r){
		cout << r.what();
		abort();
	}catch(domain_error &r){
		cout << r.what();
		abort();
	}catch(logic_error &r){
		cout << r.what();
		abort();
	}catch(bad_alloc &r){
		cout << r.what();
		abort();
	}catch(exception &r){
		cout << r.what();
		abort();
	}

	return 0;
}
```