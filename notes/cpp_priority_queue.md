http://www.cplusplus.com/reference/queue/priority_queue/


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [注意](#注意)
  - [1. 默认是最大堆](#1-默认是最大堆)
  - [2. 重载比较方法](#2-重载比较方法)

<!-- /code_chunk_output -->


## 注意
### 1. 默认是最大堆
### 2. 重载比较方法
https://blog.csdn.net/lym940928/article/details/89635690

需要注意的是，如果使用less<int>和greater<int>，需要头文件：
```cpp
#include <functional>
```

https://www.cnblogs.com/huashanqingzhu/p/11040390.html

用自定义类型做优先队列元素的例子

```cpp
#include <iostream>
#include <queue>
using namespace std;

//方法1
struct tmp1 //运算符重载<
{
    int x;
    tmp1(int a) {x = a;}
    bool operator<(const tmp1& a) const
    {
        return x < a.x; //大顶堆
    }
};

//方法2
struct tmp2 //重写仿函数
{
    bool operator() (tmp1 a, tmp1 b)
    {
        return a.x < b.x; //大顶堆
    }
};

int main()
{
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty())
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(b);
    f.push(c);
    f.push(a);
    while (!f.empty())
    {
        cout << f.top().x << '\n';
        f.pop();
    }
}
```

```
3
2
1
 
3
2
1
请按任意键继续. . .
```
