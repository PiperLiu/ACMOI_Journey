## 要求
一般来讲， `C++` 的版本要在 11 及以上； `Python` 应至少为 3.6 版本以上。

## 索引
- [哈希映射](#哈希映射)：[C++](#C++哈希映射) [Python](#Python哈希映射)
- [字符串](#字符串)：[C](#C字符串) [C++](#C++字符串)

### 哈希映射
#### C++哈希映射
以下二者操作相同，但是底层实现不同：
- unordered_map `#include <unordered_map>` 基于哈希映射 `unordered_map<string, int> m = {{"I", 1}, {"V": 5}}`
- map `#include <map>` 基于红黑树

unordered_map
```cpp
// 参考 https://blog.csdn.net/BillCYJ/article/details/78985895
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;
int main()
{
    //注意：C++11才开始支持括号初始化
    unordered_map<int, string> myMap={{ 5, "张大" },{ 6, "李五" }};  //使用{}赋值
    myMap[2] = "李四";  //使用[ ]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
    myMap.insert(pair<int, string>(3, "陈二"));//使用insert和pair插入

    //遍历输出+迭代器的使用
    auto iter = myMap.begin();  //auto自动识别为迭代器类型unordered_map<int,string>::iterator
    while (iter != myMap.end())
    {  
        cout << iter->first << "," << iter->second << endl;
        ++iter;
    }  

    //查找元素并输出+迭代器的使用
    auto iterator = myMap.find(2);  //find()返回一个指向2的迭代器
    if (iterator != myMap.end())
        cout << endl << iterator->first << "," << iterator->second << endl;
    system("pause");
    return 0;
}
```

使用 unordered_map 输出：
```
3,陈二
2,李四
6,李五
5,张大

2,李四
```

若使用 map 则输出：
```
2,李四
3,陈二
5,张大
6,李五

2,李四
```

```cpp
unordered_map<char, char> pairs = {
    {')', '('},
    {']', '['},
    {'}', '{'}
};

// count 检查是否为键值
if (pairs.count(')')) return true;
```

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

#### Python哈希映射
dict `str2int = {'a': 1, 'b': 2}`
- 不需要定义键与值的泛型

```python
a = {"a": 2}
b = {"b": 3}
c = dict()

# 获取
a.keys()  # dict_keys(["a"])

# 赋值、插入
a.setdefault("a", 3)  # a = {"a": 2}
b.setdefault("z", 4)  # b = {"b": 3, "z": 4}
a["x"] = 5
a.update({1: 2})  # {'a': 2, 'x': 5, 1: 2}

# 删除（键）
a.pop("a")  # {'x': 5, 1: 2}
a.popitem()
print(a)  # {'x': 5}
a.popitem()
print(a)  # {}

# 此外还有 clear()
```

### 字符串
#### C字符串
chars
```c
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greeting[] = "Hello";
```

在标准库 `string.h` 中存有 6 个常见的方法。

```c
// 参考 https://www.runoob.com/cprogramming/c-strings.html
#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len ;

   /* 复制 str1 到 str3 */
   strcpy(str3, str1);
   printf("strcpy(str3, str1):  %s\n", str3 );

   /* 连接 str1 和 str2 */
   strcat(str1, str2);
   printf("strcat(str1, str2):   %s\n", str1 );

   /* 连接后，str1 的总长度 */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );

   return 0;
}
```

输出为：
```
strcpy(str3, str1):  Hello
strcat(str1, str2):   HelloWorld
strlen(str1) :  10
```

#### C++字符串
string `#include <string> using namespace std;`
- 可以使用 `+, +=`
- 可以直接赋值 `string s = "Hello";`
- `.size()` 返回长度
- 也可以用 `[]` 访问索引对应元素 **但注意返回的是 char ，而非 string！与 substr() 不同！**
- 此外还有如下方法
```cpp
// 参考：https://www.runoob.com/cplusplus/cpp-strings.html
// 声明
string s1();  // si = ""
string s2("Hello");  // s2 = "Hello"
string s3(4, 'K');  // s3 = "KKKK"
string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串

// 合并
string s1("123"), s2("abc");
s1.append(s2);  // s1 = "123abc"

// 比较
string s1("hello"), s2("hello, world");
int n = s1.compare(s2);
n = s1.compare(1, 2, s2, 0, 3);  //比较s1的子串 (1,2) 和s2的子串 (0,3)

// 子串
string s1 = "this is ok";
string s2 = s1.substr(2, 4);  // s2 = "is i"
s2 = s1.substr(2);  // s2 = "is is ok"

// 交换
string s1("West"), s2("East");
s1.swap(s2);  // s1 = "East"，s2 = "West"
```

下面是一个使用 `[]` 访问的示例。 **但注意返回的是 char ，而非 string！与 substr() 不同！**
```cpp
#include <string>
#include <iostream>
#include <typeinfo>

int main(int argc, char const *argv[])
{
    std::string s = "abc";
    std::cout << typeid(s).name() << std::endl;
    std::cout << typeid(s[0]).name() << std::endl;
    std::cout << typeid(s.substr(0, 1)).name() << std::endl;
    return 0;
}
```

输出如下。
```
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
c
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
```
