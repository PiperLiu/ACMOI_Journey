<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [由数据范围反推算法复杂度以及算法内容](#由数据范围反推算法复杂度以及算法内容)
- [如何判断时间复杂度？](#如何判断时间复杂度)
- [空间分析？](#空间分析)

<!-- /code_chunk_output -->

### 由数据范围反推算法复杂度以及算法内容

来自 [y总ACWING](https://www.acwing.com/) 。

一般ACM或者笔试题的时间限制是1秒或2秒。

在这种情况下，C++代码中的操作次数控制在 $10^7 \sim 10^8$ 为最佳。

下面给出在不同数据范围下，代码的时间复杂度和算法该如何选择：

- $n \le 30$, 指数级别, dfs+剪枝，状态压缩dp
- $n \le 100$ => $O(n^3)$，floyd，dp，高斯消元
- $n \le 1000$ => $O(n^2)$，$O(n^2logn)$，dp，二分，朴素版Dijkstra、朴素版Prim、Bellman-Ford
- $n \le 10000$ => $O(n * \sqrt n)$，块状链表、分块、莫队
- $n \le 100000$ => $O(nlogn)$ => 各种sort，线段树、树状数组、set/map、heap、拓扑排序、dijkstra+heap、prim+heap、spfa、求凸包、求半平面交、二分、CDQ分治、整体二分
- $n \le 1000000$ => $O(n)$, 以及常数较小的 $O(nlogn)$ 算法 => 单调队列、 hash、双指针扫描、并查集，kmp、AC自动机，常数比较小的 $O(nlogn)$ 的做法：sort、树状数组、heap、dijkstra、spfa
- $n \le 10000000$ => $O(n)$，双指针扫描、kmp、AC自动机、线性筛素数
- $n \le 10^9$ => $O(\sqrt n)$，判断质数
- $n \le 10^{18}$ => $O(logn)$，最大公约数，快速幂
- $n \le 10^{1000}$ => $O((logn)^2)$，高精度加减乘除
- $n \le 10^{100000}$ => $O(logk \times loglogk)，k表示位数$，高精度加减、FFT/NTT

### 如何判断时间复杂度？

类别一：看循环。

类别二：递归，涉及算法分析中的[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)。

类别三：双指针，看似两层循环，实则内存循环只加不减，$O(n)$。包括单调栈、单调队列、KMP。

类别四：特殊的。比如并查集经过优化，由$n$变为$log(n)$。

### 空间分析？

- `1 Byte = 8 bit`
- `1 KB = 1024 Byte`
- `1 MB = 1024 * 1024 Byte`
- `1 GB = 1024 * 1024 * 1024 Byte`

对于 C++ ：
- `int 4 Byte`
- `char 1 Byte`
- `double, long long 4 Byte`

流量是兆字节、网速是兆位。

可以用 `sizeof` 看字节。

```cpp
// 看多少兆
cout << (sizeof v + sizeof w + sizeof f) / 1024 / 1024 << endl;
```

一般地，操作系统会有优化，只开不用，不会占内存。
