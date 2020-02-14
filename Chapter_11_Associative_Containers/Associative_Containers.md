## 练习11.1

> 描述map 和 vector 的不同。

`map` 是关联容器， `vector` 是顺序容器。

## 练习11.2

> 分别给出最适合使用 list、vector、deque、map以及set的例子。

* `list`：双向链表，适合频繁插入删除元素的场景。
* `vector`：适合频繁访问元素的场景。
* `deque`：双端队列，适合频繁在头尾插入删除元素的场景。
* `map`：字典。
* `set`：适合有序不重复的元素的场景。

## [练习11.3](11.3.cpp)

> 编写你自己的单词计数程序。

## [练习11.4](11.4.cpp)

> 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。

## 练习11.5

> 解释map和set的区别。你如何选择使用哪个？

map 是键值对，而 set 只有键没有值。当我需要存储键值对的时候使用 map，而只需要键的时候使用 set。

## 练习11.6

> 解释set和list 的区别。你如何选择使用哪个？

set 是有序不重复集合，底层实现是红黑树，而 list 是无序可重复集合，底层实现是链表。

## 练习11.7

> 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

```cpp
	map<string, vector<string>> m;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            m[ln].push_back(cn);
```

## [练习11.8](11.8.cpp)

> 编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？

set 的优点是集合本身的元素就是不重复。

## 练习11.9

> 定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。

```cpp
std::map<std::string, std::list<std::size_t>> m;
```

## 练习11.10

> 可以定义一个vector<int>::iterator 到 int 的map吗？list<int>::iterator 到 int 的map呢？对于两种情况，如果不能，解释为什么。

可以定义 `vector<int>::iterator` 到 `int` 的map，但是不能定义 `list<int>::iterator` 到 `int` 的map。因为map的键必须实现 `<` 操作，list 的迭代器不支持比较运算。


## 练习11.11

> 不使用decltype 重新定义 bookstore。

```cpp
using Less = bool (*)(Sales_data const&, Sales_data const&);
std::multiset<Sales_data, Less> bookstore(less);
```

## [练习11.12](11.12.cpp)

> 编写程序，读入string和int的序列，将每个string和int存入一个pair 中，pair保存在一个vector中。

## 练习11.13

> 在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？

```cpp
vec.push_back(std::make_pair(str, i));
vec.push_back({ str, i });
vec.push_back(std::pair<string, int>(str, i)); 
```
使用花括号的初始化器最易于理解和编写。

## [练习11.14](11.14.cpp)

> 扩展你在11.2.1节练习中编写的孩子姓达到名的map，添加一个pair的vector，保存孩子的名和生日。

## 练习11.15

> 对一个int到vector<int>的map，其mapped_type、key_type和 value_type分别是什么？

* mapped_type : vector<int>
* key_type : int
* value_type : std::pair<const int,vector >