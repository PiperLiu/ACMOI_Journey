# y总算法基础课
[https://www.acwing.com/activity/content/11/](https://www.acwing.com/activity/content/11/)

购买于2021年5月2日。

<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [错题本](#错题本)
- [第一章 基础算法（一）](#第一章-基础算法一)
- [第一章 基础算法（二）](#第一章-基础算法二)
- [第一章 基础算法（三）](#第一章-基础算法三)
- [第二章 数据结构（一）](#第二章-数据结构一)
- [第二章 数据结构（二）](#第二章-数据结构二)
- [第二章 数据结构（三）](#第二章-数据结构三)
- [第三章 搜索与图论（一）](#第三章-搜索与图论一)

<!-- /code_chunk_output -->
### 错题本
- [./errorbook/20210505分治_取中值_递归死循环_l_r_i_j.md](./errorbook/20210505分治_取中值_递归死循环_l_r_i_j.md)

### 第一章 基础算法（一）
[./ybase01.md](./ybase01.md)

- [快速排序（基于分治）](./ybase01.md/#快速排序基于分治)
  - [快排模板](./ybase01.md/#快排模板)
- [快速选择](./ybase01.md/#快速选择)
  - [快选模板](./ybase01.md/#快选模板)
- [归并排序（从中心分治）](./ybase01.md/#归并排序从中心分治)
  - [归并模板](./ybase01.md/#归并模板)
- [逆序对的数量](./ybase01.md/#逆序对的数量)
  - [逆序对的数量模板](./ybase01.md/#逆序对的数量模板)
- [整数二分（很多边界问题）](./ybase01.md/#整数二分很多边界问题)
  - [整数二分模板](./ybase01.md/#整数二分模板)
  - [整数二分模板挑选心得](./ybase01.md/#整数二分模板挑选心得)
- [浮点数二分](./ybase01.md/#浮点数二分)
  - [浮点数二分模板](./ybase01.md/#浮点数二分模板)

### 第一章 基础算法（二）
[./ybase02.md](./ybase02.md)

- [高精度](./ybase02.md#高精度)
  - [高精度加法与模板](./ybase02.md#高精度加法与模板)
  - [高精度减法与模板](./ybase02.md#高精度减法与模板)
  - [高精度乘法与模板](./ybase02.md#高精度乘法与模板)
  - [高精度除法与模板](./ybase02.md#高精度除法与模板)
- [前缀和](./ybase02.md#前缀和)
  - [前缀和思想（模板）](./ybase02.md#前缀和思想模板)
  - [前缀和（一维求s[i]）](./ybase02.md#前缀和一维求si)
  - [子矩阵的和（二维求s[i][j]）](./ybase02.md#子矩阵的和二维求sij)
- [差分（与前缀和互为逆运算）](./ybase02.md#差分与前缀和互为逆运算)
  - [差分（对连续区间加上同一个数）](./ybase02.md#差分对连续区间加上同一个数)
  - [差分矩阵（二维的）](./ybase02.md#差分矩阵二维的)

### 第一章 基础算法（三）
[./ybase03.md](./ybase03.md)

- [双指针算法](./ybase03.md#双指针算法)
  - [最长连续不重复子序列](./ybase03.md#最长连续不重复子序列)
  - [数组元素的目标和](./ybase03.md#数组元素的目标和)
  - [判断子序列](./ybase03.md#判断子序列)
- [位运算](./ybase03.md#位运算)
  - [n的二进制中第k位是几（k从0计）](./ybase03.md#n的二进制中第k位是几k从0计)
  - [lowbit(x)返回x的最右一位1开头的数](./ybase03.md#lowbitx返回x的最右一位1开头的数)
  - [二进制中1的个数](./ybase03.md#二进制中1的个数)
- [离散化](./ybase03.md#离散化)
  - [离散化模板](./ybase03.md#离散化模板)
  - [区间和（细节狂魔）](./ybase03.md#区间和细节狂魔)
  - [unique的自己实现](./ybase03.md#unique的自己实现)
- [区间合并](./ybase03.md#区间合并)
  - [区间和并模板](./ybase03.md#区间和并模板)

### 第二章 数据结构（一）
[./ybase04.md](./ybase04.md)

- [链表](./ybase04.md#链表)
  - [数组模拟单链表（邻接表）](./ybase04.md#数组模拟单链表邻接表)
  - [数组模拟双链表](./ybase04.md#数组模拟双链表)
- [栈](./ybase04.md#栈)
  - [数组实现栈模板](./ybase04.md#数组实现栈模板)
  - [表达式求值模板](./ybase04.md#表达式求值模板)
- [队列](./ybase04.md#队列)
  - [数组实现队列模板](./ybase04.md#数组实现队列模板)
- [单调栈](./ybase04.md#单调栈)
  - [寻找左边最近的比自己小的数](./ybase04.md#寻找左边最近的比自己小的数)
- [单调队列](./ybase04.md#单调队列)
  - [滑动窗口](./ybase04.md#滑动窗口)
- [KMP：字符串匹配](./ybase04.md#kmp字符串匹配)

### 第二章 数据结构（二）
[./ybase05.md](./ybase05.md)

- [字典树Tire树](./ybase05.md#字典树tire树)
  - [模板：Trie字符串统计](./ybase05.md#模板trie字符串统计)
  - [模板：最大异或对](./ybase05.md#模板最大异或对)
- [并查集](./ybase05.md#并查集)
  - [模板：合并集合](./ybase05.md#模板合并集合)
  - [动态维护集合大小信息：连通块中点的数量](./ybase05.md#动态维护集合大小信息连通块中点的数量)
  - [另一道例题：食物链](./ybase05.md#另一道例题食物链)
- [堆](./ybase05.md#堆)
  - [以小根堆为例](./ybase05.md#以小根堆为例)
  - [堆排序模板](./ybase05.md#堆排序模板)

### 第二章 数据结构（三）
[./ybase06.md](./ybase06.md)

- [哈希表](./ybase06.md#哈希表)
  - [模拟散列表模板](./ybase06.md#模拟散列表模板)
  - [拉链法](./ybase06.md#拉链法)
  - [开放寻址法](./ybase06.md#开放寻址法)
- [字符串哈希](./ybase06.md#字符串哈希)
  - [字符串前缀哈希法](./ybase06.md#字符串前缀哈希法)
  - [字符串哈希模板](./ybase06.md#字符串哈希模板)
- [Cpp的STL](./ybase06.md#cpp的stl)
  - [vector, 变长数组，倍增的思想](./ybase06.md#vector-变长数组倍增的思想)
  - [pair<int, int>](./ybase06.md#pairint-int)
  - [string，字符串](./ybase06.md#string字符串)
  - [queue, 队列](./ybase06.md#queue-队列)
  - [priority_queue, 优先队列，默认是大根堆](./ybase06.md#priority_queue-优先队列默认是大根堆)
  - [stack, 栈](./ybase06.md#stack-栈)
  - [deque, 双端队列](./ybase06.md#deque-双端队列)
  - [set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列](./ybase06.md#set-map-multiset-multimap-基于平衡二叉树红黑树动态维护有序序列)
  - [set/multiset](./ybase06.md#setmultiset)
  - [map/multimap](./ybase06.md#mapmultimap)
  - [unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表](./ybase06.md#unordered_set-unordered_map-unordered_multiset-unordered_multimap-哈希表)
  - [bitset, 圧位](./ybase06.md#bitset-圧位)

### 第三章 搜索与图论（一）
[./ybase07.md](./ybase07.md)

