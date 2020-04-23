## 练习19.1

> 使用 malloc 编写你自己的 operator new(sizt_t)函数，使用 free 编写operator delete(void *)函数。

```cpp
#include <cstdlib>
#include <new>

void *operator new(size_t size)
{
	if(void *mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept { free(mem); }

int main()
{
	return 0;
}
```
  
## 练习19.2

> 默认情况下，allocator 类使用 operator new 获取存储空间，然后使用 operator delete 释放它。利用上一题中的两个函数重新编译并运行你的 StrVec 程序。

```cpp
#ifndef STRVEC_H_
#define STRVEC_H_

#include <string>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>

void *operator new(size_t size)
{
	std::cout << "void *operator new(size_t size)" << std::endl;
	if(void *mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem) noexcept
{
	std::cout << "void operator delete(void *mem) noexcept" << std::endl;
	free(mem);
}

class StrVec
{
friend bool operator==(StrVec &lhs, StrVec &rhs);
friend bool operator!=(StrVec &lhs, StrVec &rhs);
friend bool operator<(StrVec &lhs, StrVec &rhs);
friend bool operator>(StrVec &lhs, StrVec &rhs);
friend bool operator<=(StrVec &lhs, StrVec &rhs);
friend bool operator>=(StrVec &lhs, StrVec &rhs);
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec(StrVec &&s) noexcept : alloc(std::move(s.alloc)), elements(std::move(s.elements)), first_free(std::move(s.first_free)), cap(std::move(s.cap)) { s.elements = s.first_free = s.cap = nullptr; }
	template <typename... Args>
	void emplace_back(Args&&... args);
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec&&) noexcept;
	std::string& operator[](std::size_t n) { return elements[n]; }
	const std::string& operator[](std::size_t n) const { return elements[n]; }
	~StrVec();
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const std::string &s);
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc() { if(size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename... Args>
inline void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if(elements)
	{
		std::for_each(elements, first_free, [this](std::string &p){ alloc.destroy(&p); });
		// for(auto p = first_free; p != elements; )
		// 	alloc.destroy(--p);
		alloc.deallocate(elements, cap-elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::reserve(size_t n)
{
	if(n > capacity()) return;
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void StrVec::resize(size_t n)
{
	resize(n,std::string());
}

void StrVec::resize(size_t n, const std::string &s)
{
	if(n < size())
	{
		while(n < size())
			alloc.destroy(--first_free);
	}else if(n > size())
	{
		while(n > size())
			push_back(s);
			// alloc.construct(first_free, s);
	}
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
	if(this != &rhs)
	{
		free();
		alloc = std::move(rhs.alloc);
		elements = std::move(rhs.elements);
		first_free = std::move(rhs.first_free);
		cap = std::move(rhs.cap);
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

bool operator==(StrVec &lhs, StrVec &rhs)
{
	return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(StrVec &lhs, StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(StrVec &lhs, StrVec &rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(StrVec &lhs, StrVec &rhs)
{
	return rhs < lhs;
}

bool operator<=(StrVec &lhs, StrVec &rhs)
{
	return !(rhs < lhs);
}

bool operator>=(StrVec &lhs, StrVec &rhs)
{
	return !(lhs < rhs);
}

#endif
```
  
## 练习19.3

> 已知存在如下的类继承体系，其中每个类分别定义了一个公有的默认构造函数和一个析构函数：
```cpp
class A { /* ... */};
class B : public A { /* ... */};
class C : public B { /* ... */};
class D : public B, public A { /* ... */};
```
下面哪个 dynamic_cast 将失败？
```cpp
(a) A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
(b) B *pb = new B;
	C *pc = dynamic_cast<C*>(pb);
(c) A *pa = new D;
	B *pb = dynamic_cast<B*>(pa);
```

（a）成功；  
（b）失败，pb是指向B的指针，不能转换为指向C的指针；  
（c）失败，A *pa = new D具有二义性。  
  
## 练习19.4

> 使用上一个练习定义的类改写下面的代码，将表达式*pa 转换成类型C&：
```cpp
if (C *pc = dynamic_cast<C*>(pa))
{
	//使用C的成员
} else {
	//使用A的成员
}
```

```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

class D : public B, public A
{};

int main(int argc, char const *argv[])
{
	// A *pa = new C;
	// B *pb = dynamic_cast<B*>(pa);
	// if(pb) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	// B *pb = new B;
	// C *pc = dynamic_cast<C*>(pb);
	// if(pc) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	// A *pa = new D;
	// B *pb = dynamic_cast<B*>(pa);
	// if(pb) std::cout << "success" << std::endl;
	// else std::cout << "fail" << std::endl;

	A *pa = new C;
	try{
		const C &c = dynamic_cast<const C&>(*pa);
	}catch(std::bad_cast &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
```
  
## 练习19.5

> 在什么情况下你应该用 dynamic_cast 替代虚函数？

我们想使用基类对象的指针或引用执行某个派生类操作并且该操作不是虚函数，则可以使用RTTI运算符（该类类型应该含有虚函数）。  

  
## 练习19.6

> 编写一条表达式将 Query_base 指针动态转换为 AndQuery 指针。分别使用 AndQuery 的对象以及其他类型的对象测试转换是否有效。打印一条表示类型转换是否成功的信息，确保实际输出的结果与期望的一致。

Query_base为抽象虚类，AndQuery的构造函数为private，暂时没想到方法来实现该题，目前使用19.3的继承体系来验证。  
```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

class D : public B, public A
{};

int main(int argc, char const *argv[])
{
	A *pa1 = new C;
    if(C *qc = dynamic_cast<C*>(pa1))
    {
        std::cout << "success" << std::endl;
    }else
    {
        std::cout << "fail" << std::endl;
    }

	A *pa2 = new C;
	try{
		const C &rc = dynamic_cast<const C&>(*pa2);
	}catch(std::bad_cast &e){
		std::cout << e.what() << std::endl;
	}

	C c = C();
	if(typeid(*pa1) == typeid(*pa2)) std::cout << "same type" << std::endl;
	if(typeid(*pa1) == typeid(c)) std::cout << "same type as C" << std::endl;
	if(typeid(*pa1) == typeid(C)) std::cout << "same type as C" << std::endl;

	return 0;
}
```
  
## 练习19.7

> 编写与上一个练习类似的转换，这一次将 Query_base 对象转换为 AndQuery 的引用。重复上面的测试过程，确保转换能正常工作。

详见１9.6。  
  
## 练习19.8

> 编写一条 typeid 表达式检查两个 Query_base 对象是否指向同一种类型。再检查该类型是否是 AndQuery。

详见１9.6。  
  
## 练习19.9

> 编写与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。如果你得到的输出结果与本书类似，尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。

```cpp
#include <iostream>
#include <typeinfo>

class Base
{
	friend bool operator==(const Base&, const Base&);
public:
	Base() = default;
	Base(int i_) : i(i_) { }
protected:
	virtual bool equal(const Base&) const;
private:
	int i;
};

class Derived : public Base
{
public:
	Derived() = default;
	Derived(std::string s_, int i_) : s(s_), Base(i_) { }
protected:
	bool equal(const Base&) const;
private:
	std::string s;
};

bool operator==(const Base &lhs, const Base &rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base &rhs) const
{
	return this->i == rhs.i;
}

bool Derived::equal(const Base &rhs) const
{
	auto r = dynamic_cast<const Derived&>(rhs);
	return (this->s == r.s) && this->Base::equal(rhs);
}

int main()
{
	Base *pb1 = new Derived();
	Base *pb2 = new Derived();
	Base *pb3 = new Derived("a", 1);
	Base *pb4 = new Base();

	std::cout << std::boolalpha << (*pb1 == *pb2) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb3) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb4) << std::endl;

	int arr[10];
	Derived d;

	std::cout << typeid(42).name() << ", "
			  << typeid(arr).name() << ", "
			  << typeid(d).name() << ", "
			  << typeid(std::string).name() << ", "
			  << typeid(pb1).name() << ", "
			  << typeid(*pb1).name() << ", "
			  << typeid(*pb3).name() << std::endl;

	return 0;
}
```
```sh
$ ./ex09 true
false
false
i, A10_i, 7Derived, Ss, P4Base, 7Derived, 7Derived
```
  
## 练习19.10

> 已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数和一个虚析构函数。下面的语句将打印哪些类型名字？
```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /*...*/ };
(a) A *pa = new C;
	cout << typeid(pa).name() << endl;
(b) C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;
(c) B *px = new B;
	A& ra = *px;
	cout << typeid(ra).name() << endl;
```

（a）P1A；  
（b）P1A；  
（c）1B。  
```cpp
#include <typeinfo>
#include <iostream>

class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

int main(int argc, char const *argv[])
{
	// A *pa = new C;
	// std::cout << typeid(pa).name() << std::endl;

	// C cobj;
	// A &ra = cobj;
	// std::cout << typeid(&ra).name() << std::endl;

	B *px = new B;
	A &ra = *px;
	std::cout << typeid(ra).name() << std::endl;

	return 0;
}
```
## 练习19.11

> 普通的数据指针和指向数据成员的指针有何区别？

普通的数据指针指向一个对象；类成员指针指向类的非静态成员。当初始化这样一个指针时，我们令其指向类的某个成员，但是不指定该成员所属的对象；直到使用成员指针时，才提供所属的对象。  
  
## 练习19.12

> 定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。通过该指针获得 Screen::cursor 的值。

```cpp
#include <string>
#include <iostream>

class Screen {
    public:
        using pos = std::string::size_type;

        static const std::string Screen::*data() { return &Screen::contents; }
        static const pos Screen::*pcursor() { return &Screen::cursor; }
        Screen() = default;
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ }

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
};

int main()
{
    // const std::string Screen::*pdata;
    // pdata = &Screen::contents;
    // auto pdata = &Screen::contents;  //contents is private

    const std::string Screen::*pdata = Screen::data();
    Screen myScreen(2, 2, 'c');
    auto s = myScreen.*pdata;
    std::cout << s << std::endl;

    const std::string::size_type Screen::*pcursor = Screen::pcursor();
    auto i = myScreen.*pcursor;
    std::cout << i << std::endl;

    return 0;
}
```
  
## 练习19.13

> 定义一个类型，使其可以表示指向 Sales_data 类的 bookNo 成员的指针。

```cpp
const std::string Sales_data::*pdata;
```
  
## 练习19.14

> 下面的代码合法吗？如果合法，代码的含义是什么？如果不合法，解释原因。
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

不合法，Screen中get_cursor函数返回的为pos类型，get函数返回的为char类型。  
  
## 练习19.15

> 普通函数指针和指向成员函数的指针有何区别？

和普通函数指针不同的是，在成员函数和指向该成员的指针之间不存在自动转换规则。  