
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [定长数组](#定长数组)
  - [数组](#数组)
- [变长数组](#变长数组)
  - [vector](#vector)
- [哈希表](#哈希表)
  - [有序字典](#有序字典)
- [优先队列](#优先队列)
  - [优先队列重载](#优先队列重载)
- [排序](#排序)
  - [排序返回索引](#排序返回索引)

<!-- /code_chunk_output -->

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

### 排序

要求：
- 重载排序规则
- 排序返回索引

```cpp
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
