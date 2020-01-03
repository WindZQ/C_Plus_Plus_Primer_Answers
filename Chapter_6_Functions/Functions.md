## 练习6.1

> 实参和形参的区别的什么？

实参是函数调用的实际值，是形参的初始值。

## 练习6.2

> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```cpp
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x; 
```

应该改为下面这样：
```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

## [练习6.3](6.3.cpp)

> 编写你自己的fact函数，上机检查是否正确。

## [练习6.4](6.4.cpp)

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

## 练习6.5

> 编写一个函数输出其实参的绝对值。

```cpp
#include <iostream>

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
    return 0;
}
```

## 练习6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。

**形参**定义在函数形参列表里面；**局部变量**定义在代码块里面；**局部静态变量**在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁。
```cpp
// 例子
int count_add(int n)       // n是形参
{
    static int ctr = 0;    // ctr 是局部静态变量
    ctr += n;
    return ctr;
}

int main()
{
    for (int i = 0; i != 10; ++i)  // i 是局部变量
      cout << count_add(i) << endl;

    return 0;
}
```

## 练习6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```cpp
int generate()
{
    static int ctr = 0;
    return ctr++;
}
```

## [练习6.8](6.h)

> 编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。

## 练习6.9 : [fact.cc](fact.cpp) | [factMain.cc](factMain.cpp)

> 编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

## [练习6.10](6.10.cpp)

> 编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

## [练习6.11](6.11.cpp)

> 编写并验证你自己的reset函数，使其作用于引用类型的参数。

## [练习6.12](6.12.cpp)

> 改写6.2.1节练习中的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？

很明显引用更好。

## 练习6.13

> 假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。

* `void f(T)` 的参数通过值传递，在函数中 T 是实参的副本，改变T不会影响到原来的实参。
* `void f(&T)` 的参数通过引用传递，在函数中的T是实参的引用，T的改变也就是实参的改变。

## 练习6.14

> 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

例如交换两个整数的函数，形参应该是引用
```cpp
void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
```
当实参的值是右值时，形参不能为引用类型
```cpp
int add(int a, int b)
{
	return a + b;
}

int main()
{
	int i = add(1,2);
	return 0;
}
```

## 练习6.15

> 说明find_char 函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

* 因为字符串可能很长，因此使用引用避免拷贝；而在函数中我们不希望改变 s 的内容，所以令 s 为常量。
* occurs 是要传到函数外部的变量，所以使用引用，occurs 的值会改变，所以是普通引用。
* 因为我们只需要 c 的值，这个实参可能是右值(右值实参无法用于引用形参)，所以 c 不能用引用类型。
* 如果 s 是普通引用，也可能会意外改变原来字符串的内容。
* occurs 如果是常量引用，那么意味着不能改变它的值，那也就失去意义了。

## 练习6.16

> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
```cpp
bool is_empty(string& s) { return s.empty(); }
```

局限性在于**常量字符串**和**字符串字面值**无法作为该函数的实参，如果下面这样调用是非法的：
```cpp
const string str;
bool flag = is_empty(str); //非法
bool flag = is_empty("hello"); //非法
```
所以要将这个函数的形参定义为常量引用：
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

## [练习6.17](6.17.cpp)

> 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

两个函数的形参不一样。第一个函数使用常量引用，第二个函数使用普通引用。

## 练习6.18

> 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
* (a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。 
* (b) 名为 change_val 的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。

```cpp
(a) bool compare(matrix &m1, matrix &m2);
(b) vector<int>::iterator change_val(int, vector<int>::iterator);
```

## 练习6.19

> 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```

* (a) 不合法。calc只有一个参数。
* (b) 合法。
* (c) 合法。
* (d) 合法。

## 练习6.20

> 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

应该尽量将引用形参设为常量引用，除非有明确的目的是为了**改变**这个引用变量。如果形参应该是常量引用，而我们将其设为了普通引用，那么常量实参将无法作用于普通引用形参。

## [练习6.21](6.21.cpp)

> 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

应该是 `const int *` 类型。

## [练习6.22](6.22.cpp)

> 编写一个函数，令其交换两个int指针。

## [练习6.23](6.23.cpp)

> 参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:
```cpp
int i = 0, j[2] = { 0, 1 };
```

## 练习6.24

> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
```cpp
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

当数组作为实参的时候，会被自动转换为指向首元素的指针。因此函数形参接受的是一个指针。如果要让这个代码成功运行，可以将实参改为数组的引用。
```cpp
void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

## [练习6.25](6.25.cpp)

> 编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。


## [练习6.26](6.25.cpp)

> 编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。

## [练习6.27](6.27.cpp)

> 编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。

## 练习6.28

> 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？

`elem` 是 `const string &` 类型。

## 练习6.29

> 在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

应该使用**常量引用**类型。`initializer_list` 对象中的元素都是常量，我们无法修改`initializer_list` 对象中的元素的值。

## [练习6.30](6.30.cpp)

> 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

## 练习6.31

> 什么情况下返回的引用无效？什么情况下返回常量的引用无效？

当返回的引用的对象是局部变量时，返回的引用无效；当我们希望返回的对象被修改时，返回常量的引用无效。

## 练习6.32

> 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
```cpp
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

合法。get 函数根据索引取得数组中的元素的引用。

## [练习6.33](6.33.cpp)

> 编写一个递归函数，输出vector对象的内容。

## 练习6.34

> 如果factorial 函数的停止条件如下所示，将发生什么？
```cpp
if (val != 0)
```

如果val为正数，从结果上来说没有区别（多乘了个 1）; 如果val为负数，那么递归永远不会结束。

## 练习6.35

> 在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？

如果传入的值是 val--，那么将会永远传入相同的值来调用该函数，递归将永远不会结束。

## 练习6.36

> 编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名。

```cpp
string (&fun())[10];
```

## 练习6.37

> 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？

```cpp
typedef string str_arr[10];
str_arr& fun();

auto fun()->string(&)[10];

string s[10];
decltype(s)& fun();
```
我觉得尾置返回类型最好。

## 练习6.38

> 修改arrPtr函数，使其返回数组的引用。

```cpp
decltype(odd)& arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
```

## 练习6.39

> 说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
```cpp
(a) int calc(int, int);
	int calc(const int, const int);
(b) int get();
	double get();
(c) int *reset(int *);
	double *reset(double *);
```

* (a) 非法。因为顶层const 不影响传入函数的对象，所以第二个声明无法与第一个声明区分开来。
* (b) 非法。对于重载的函数来说，它们应该只有形参的数量和形参的类型不同。返回值与重载无关。
* (c) 合法。

## 练习6.40

> 下面的哪个声明是错误的？为什么？
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);		
```

* (a) 正确。
* (b) 错误。因为一旦某个形参被赋予了默认值，那么它之后的形参都必须要有默认值。