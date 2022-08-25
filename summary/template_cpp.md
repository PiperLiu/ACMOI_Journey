
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [小结](#小结)
- [算法API](#算法api)
  - [数与字符串转换](#数与字符串转换)
  - [排序](#排序)
    - [重载排序规则](#重载排序规则)
    - [排序返回索引](#排序返回索引)
- [数据结构](#数据结构)
  - [自定义结构体](#自定义结构体)
  - [定长数组](#定长数组)
    - [数组](#数组)
  - [变长数组](#变长数组)
    - [vector](#vector)
  - [哈希表](#哈希表)
    - [有序字典](#有序字典)
  - [优先队列](#优先队列)
    - [优先队列重载](#优先队列重载)
  - [集合](#集合)
    - [有序集合与二分查找](#有序集合与二分查找)

<!-- /code_chunk_output -->

## 小结

`C++ STL` 牛逼，我于 2021 年 11 月 14 日做完 [leetcode 双周赛 65 T4](../leetcode_double/drafts/65.md#你可以安排的最多任务数目二分套二分贪心) 决定以后能有 STL 则用 STL ，不再手写二分。有这么两点需要理解记忆：一是 `s.find()` 返回一个 `iterator` ；二是 `*s.rbegin()` 取最后一个数，而非 `end()` 因为 `end()` 是最后一个数指针 `+ 1`  。

## 算法API
### 数与字符串转换

要求：
- 数字到字符（ASCII码）
- 数字到字符串（表面值）
- 字符到数字（ASCII码）
- 字符串到数字（表面值）

数字到字符（ASCII码）：
```cpp
// 强制转换，根据 ASCII 码
int tmp = 97;
char ac = tmp;
cout << ac << endl;  // 输出 a
```

数字到字符串（表面值）：
```cpp
int tmp = 97;
string as = to_string(tmp);
cout << as << endl;  // 输出 97
```

字符到数字（ASCII码）：
```cpp
char a;
cin >> a;
int num1 = a - '0';
int num2 = a - 'A';
int num3 = a - 'a';
```


字符串到数字（表面值）：
```cpp
string b;
cin >> b;
int          num4 = stoi(b);
float        num5 = stof(b);
double       num6 = stod(b);
long double  num7 = stold(b);
```

### 排序

要求：
- 重载排序规则
- 排序返回索引

#### 重载排序规则

```cpp
// 重载函数
bool cmp1(Person p1, Person p2)
{
    if (p1.time != p2.time) return p1.time < p2.time;
    return p1.id < p2.id;
}

// lambda
auto cmp2 = [&](Person p1, Person p2) -> bool
{
    if (p1.time != p2.time) return p1.time < p2.time;
    return p1.id < p2.id;
}

vector<int> ans;
sort(ans.begin(), ans.end());  // 默认从小到大

vector<pair<int, int>> res;
sort(res.begin(), res.begin());  // 默认比较第一个元素
```

#### 排序返回索引

```cpp
vector<int> data = {5, 16, 4, 7};   
vector<int> index(data.size(), 0);
for (int i = 0 ; i != index.size() ; i++) {
    index[i] = i;
}
sort(index.begin(), index.end(),
    [&](const int& a, const int& b) {
        return (data[a] < data[b]);
    }
);
for (int i = 0 ; i != index.size() ; i++) {
    cout << index[i] << endl;
}
// 版权声明：本文为CSDN博主「liangbaqiang」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/qq_36523492/article/details/114122256
```

## 数据结构

### 自定义结构体

要求：
- 自定义包含变量
- 重载比较函数

```cpp
struct Player
{
    int arrive_time, serve_time;
    int start_time, waiting_time;
    
    // 给 sort 排
    const bool operator< (const Player& t) const
    {
        if (start_time != t.start_time) return start_time < t.start_time;
        return arrive_time < t.arrive_time;
    }
    
    // 给 priority_queue 最大堆排（最大堆用<less>）
    const bool operator> (const Player& t) const
    {
        return arrive_time > t.arrive_time;
    }
};
```

### 定长数组

要求：
- 声明与取数

#### 数组

```cpp
int dx[4] = {0, 1, 0, -1};
int a[N];

dx[0];
```

### 变长数组

要求：
- 取值：取头取尾取索引
- 追加
- 掐头去尾

#### vector

```cpp
vector<int> ans(n);  // 初始长度 n ，默认值为 0

// 取值：取头取尾取索引
ans.front();
ans.back();
ans[i] += 1;

// 追加
// 为什么 std::vector 不支持 push_front？ - Milo Yip的回答 - 知乎
// https://www.zhihu.com/question/51555037/answer/126373709
ans.push_back(5);  // O(1)

// 去尾
ans.pop_back();
```

### 哈希表

要求：
- 键值已存在
- 有序字典

```cpp
map<int, int> S;
// 键值已存在
if (S.count(5))
    // S[5] 被定义过
else
    // S[5] 未被定义过
```

#### 有序字典

- `map` 有序，基于红黑树
- `unordered_map` 无序，基于映射，效率可能更高

### 优先队列

要求：
- 空尺看存弹
- 重载存储对象
- 重载比较函数

```cpp
// 默认是大根堆
priority_queue<int> heap;

// 改为小根堆
priority_queue<int, vetor<int>, greater<int> > min_heap;

// 空尺看存弹
heap.empty();
heap.size();
heap.top();
heap.push(5);
heap.pop();
```

#### 优先队列重载

首选是用 `greater<>` （小根堆） 或者 `less<>` （大根堆）：

```cpp
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>
```

此外，重载 struct 比较函数也行：

```cpp
// 重载比较函数
struct cmp {
    template<typename T, typename U>
    bool operator()(T const& left, U const &right) {
        if (left.second < right.second) return true;
        return false;
    }
};

int main() {
    unordered_map<int, int> mp;
    mp[3] = 4;
    mp[2] = 44;
    mp[12] = 432;
    // 重载存储对象 pair<int, int>
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>  pq(mp.begin(), mp.end());  //完成pq的初始化
}

// 版权声明：本文为CSDN博主「leagalhigh」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/u014257954/article/details/78623215
```

### 集合

要求：
- 初尺看存弹
- 有序集合与二分查找

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};
    // 初
    set<int> s(a.begin(), a.end());
    // 尺
    s.size();
    // 看
    auto it = s.find(2);
    if (it == s.end()) printf("not in\n"); else printf("in\n");
    // 存
    s.insert(4);
    // 弹
    s.erase(s.find(2));
}
```

#### 有序集合与二分查找

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};
    // 初
    multiset<int> s(a.begin(), a.end());
    // 尺
    s.size();
    // 看
    auto it = s.find(2);
    if (it == s.end()) printf("not in\n"); else printf("in\n");
    int last = *s.rbegin();
    auto it2 = s.lower_bound(2);
    auto it3 = s.upper_bound(1);
    // 存
    s.insert(4);
    // 弹
    s.erase(s.find(2));
}
```
