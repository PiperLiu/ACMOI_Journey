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
- [第三章 搜索与图论（二）](#第三章-搜索与图论二)
- [第三章 搜索与图论（三）](#第三章-搜索与图论三)
- [第四章 数学知识（一）](#第四章-数学知识一)
- [第四章 数学知识（二）](#第四章-数学知识二)
- [第四章 数学知识（三）](#第四章-数学知识三)
- [第四章 数学知识（四）](#第四章-数学知识四)

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

- [DFS与BFS对比](./ybase07.md#dfs与bfs对比)
- [DFS](./ybase07.md#dfs)
  - [DFS最简单模板](./ybase07.md#dfs最简单模板)
  - [n皇后问题两种做法](./ybase07.md#n皇后问题两种做法)
- [BFS](./ybase07.md#bfs)
  - [走迷宫问题](./ybase07.md#走迷宫问题)
  - [八数码](./ybase07.md#八数码)
- [树与图的表示方法（有向图）](./ybase07.md#树与图的表示方法有向图)
- [树与图的深度优先遍历](./ybase07.md#树与图的深度优先遍历)
  - [树的重心](./ybase07.md#树的重心)
- [树与图的广度优先遍历](./ybase07.md#树与图的广度优先遍历)
  - [图中点的层次](./ybase07.md#图中点的层次)
  - [有向图的拓扑序列（图bfs基本应用）](./ybase07.md#有向图的拓扑序列图bfs基本应用)
  - [例题：有向图的拓扑序列](./ybase07.md#例题有向图的拓扑序列)

### 第三章 搜索与图论（二）
[./ybase08.md](./ybase08.md)

- [最短路](./ybase08.md#最短路)
- [朴素 Dijkstra 算法](./ybase08.md#朴素-dijkstra-算法)
  - [Dijkstra求最短路 I](./ybase08.md#dijkstra求最短路-i)
- [堆优化版的 Dijkstra 算法](./ybase08.md#堆优化版的-dijkstra-算法)
  - [Dijkstra求最短路 II](./ybase08.md#dijkstra求最短路-ii)
- [bellman-ford（负权）](./ybase08.md#bellman-ford负权)
  - [有边数限制的最短路](./ybase08.md#有边数限制的最短路)
- [SPFA](./ybase08.md#spfa)
  - [spfa求最短路模板](./ybase08.md#spfa求最短路模板)
  - [spfa判断负环模板](./ybase08.md#spfa判断负环模板)
- [Floyd求最短路](./ybase08.md#floyd求最短路)
  - [Floyd求最短路](./ybase08.md#floyd求最短路-1)

### 第三章 搜索与图论（三）
[./ybase09.md](./ybase09.md)

- [最小生成树](./ybase09.md#最小生成树)
- [Prim](./ybase09.md#prim)
  - [Prim模板](./ybase09.md#prim模板)
- [Kruskal](./ybase09.md#kruskal)
  - [Kruskal模板：Kruskal算法求最小生成树](./ybase09.md#kruskal模板kruskal算法求最小生成树)
- [二分图](./ybase09.md#二分图)
- [染色法判定二分图](./ybase09.md#染色法判定二分图)
  - [染色法判定二分图模板](./ybase09.md#染色法判定二分图模板)
- [匈牙利算法](./ybase09.md#匈牙利算法)
  - [例题：二分图的最大匹配](./ybase09.md#例题二分图的最大匹配)

### 第四章 数学知识（一）
[./ybase10.md](./ybase10.md)

- [质数](./ybase10.md#质数)
  - [质数的判定——试除法](./ybase10.md#质数的判定试除法)
  - [分解质因数——试除法](./ybase10.md#分解质因数试除法)
  - [筛质数](./ybase10.md#筛质数)
  - [朴素法筛质数（埃氏筛法）](./ybase10.md#朴素法筛质数埃氏筛法)
  - [线性筛法](./ybase10.md#线性筛法)
- [约数](./ybase10.md#约数)
  - [试除法求约数](./ybase10.md#试除法求约数)
  - [约数个数与约数之和](./ybase10.md#约数个数与约数之和)
  - [约数个数例题](./ybase10.md#约数个数例题)
  - [约数之和例题](./ybase10.md#约数之和例题)
  - [欧几里得算法（辗转相除法）](./ybase10.md#欧几里得算法辗转相除法)
  - [题目：最大公约数（很优雅gcd）](./ybase10.md#题目最大公约数很优雅gcd)

### 第四章 数学知识（二）
[./ybase11.md](./ybase11.md)

- [欧拉函数](./ybase11.md#欧拉函数)
  - [欧拉函数（定义法例题）](./ybase11.md#欧拉函数定义法例题)
  - [筛法求欧拉函数](./ybase11.md#筛法求欧拉函数)
- [欧拉定理、费马小定理](./ybase11.md#欧拉定理-费马小定理)
- [快速幂](./ybase11.md#快速幂)
  - [极简写法的快速幂](./ybase11.md#极简写法的快速幂)
  - [快速幂求逆元](./ybase11.md#快速幂求逆元)
- [扩展欧几里得算法](./ybase11.md#扩展欧几里得算法)
  - [裴属定理](./ybase11.md#裴属定理)
  - [扩展欧几里得算法例题](./ybase11.md#扩展欧几里得算法例题)
  - [线性同余方程](./ybase11.md#线性同余方程)
  - [线性同余方程例题](./ybase11.md#线性同余方程例题)
- [中国剩余定理（孙子定理）](./ybase11.md#中国剩余定理孙子定理)
  - [例题：表达整数的奇怪方式](./ybase11.md#例题表达整数的奇怪方式)

### 第四章 数学知识（三）
[./ybase12.md](./ybase12.md)

- [高斯消元](./ybase12.md#高斯消元)
  - [高斯消元解线性方程组](./ybase12.md#高斯消元解线性方程组)
  - [高斯消元解异或线性方程组](./ybase12.md#高斯消元解异或线性方程组)
- [求组合数](./ybase12.md#求组合数)
  - [组合数递推式（以及例题）](./ybase12.md#组合数递推式以及例题)
  - [组合数与逆元、快速幂（以及例题）](./ybase12.md#组合数与逆元-快速幂以及例题)
  - [组合数与卢卡斯定理（以及例题）](./ybase12.md#组合数与卢卡斯定理以及例题)
  - [组合数与高精度（不模）](./ybase12.md#组合数与高精度不模)
- [组合计数、卡特兰数](./ybase12.md#组合计数-卡特兰数)
  - [例题：满足条件的01序列](./ybase12.md#例题满足条件的01序列)

### 第四章 数学知识（四）
[./ybase13.md](./ybase13.md)

