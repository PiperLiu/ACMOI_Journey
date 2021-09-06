
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [中位数 1029 Median (25 point(s))](#中位数-1029-median-25-points)
- [最短距离 1046 Shortest Distance (20 point(s))](#最短距离-1046-shortest-distance-20-points)
- [完美序列 1085 Perfect Sequence (25 point(s))](#完美序列-1085-perfect-sequence-25-points)

<!-- /code_chunk_output -->

### 中位数 1029 Median (25 point(s))

给定一个 $N$ 个整数构成的递增序列，中位数是中间位置的数字。

<p>如果一共有奇数个数，则中位数是最中间的数；如果一共有偶数个数，则中位数是中间偏左的数。</p>

例如 $S_1 = \lbrace 11,12,13,14 \rbrace$ 的中位数是 $12$，$S_2 = \lbrace 9, 10, 15, 16, 17 \rbrace$ 的中位数是 $15$。

<p>两个序列的中位数定义为包含两个序列的所有元素的非递减序列的中位数。</p>

例如，$S_1$ 和 $S_2$ 的中位数为 $13$。

<p>给定两个递增序列，请你找出它们的中位数。</p>

<h4>输入格式</h4>

<p>共两行，每行包含一个递增序列。</p>

每行首先包含一个整数 $N$，表示序列长度，接下来包含 $N$ 个整数，表示完整序列。

<h4>输出格式</h4>

<p>输出一个整数，表示两个序列的中位数。</p>

<h4>数据范围</h4>

$1 \le N \le 2 \times 10^5$,

序列中的整数都在 <strong>int</strong> 范围内。

<h4>输入样例：</h4>

<pre><code>
4 11 12 13 14
5 9 10 15 16 17
</code></pre>

<h4>输出样例：</h4>

<pre><code>
13
</code></pre>

#### 1029 Median (25 point(s))
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of `S1 = { 11, 12, 13, 14 }` is 12, and the median of `S2 = { 9, 10, 15, 16, 17 }` is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

#### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer $N (≤2×10^5)$ is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

#### Output Specification:
For each test case you should output the median of the two given sequences in a line.

```cpp
// 合并两个有序序列，然后取中位数
// 归并排序中经典的 二路归并
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int n, m;
int a[N], b[N], c[N * 2];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

    int k = 0, i = 0, j = 0;  // k 是新数组的下标
    while (i < n && j < m)
        if (a[i] <= b[j]) c[k ++ ] = a[i ++ ];
        else c[k ++ ] = b[j ++ ];
    while (i < n) c[k ++ ] = a[i ++ ];
    while (j < m) c[k ++ ] = b[j ++ ];

    printf("%d\n", c[(n + m - 1) / 2]);

    return 0;
}
```

### 最短距离 1046 Shortest Distance (20 point(s))

一个环形高速公路上有 $N$ 个出口，共有 $M$ 次询问，每次询问你需要回答其中两个出口之间的最短距离是多少。

<h4>输入格式</h4>

第一行首先包含一个整数 $N$，接下来包含 $N$ 个整数 $D_1,D_2,...,D_N$，其中 $D_i$ 是第 $i$ 个出口与第 $i+1$ 个出口之间的距离，$D_N$ 是第 $N$ 个出口与第 $1$ 个出口之间的距离。

第二行包含一个整数 $M$，表示询问次数。

接下来 $M$ 行，每行包含两个整数，表示询问两个出口之间的最短距离。

<h4>输出格式</h4>

共 $M$ 行，每行输出一个查询的答案。

<h4>数据范围</h4>

- $3 \le N \le 10^5$,
- $1 \le M \le 10^4$,
- 高速公路总长度不超过 $10^7$。

<h4>输入样例：</h4>

<pre><code>
5 1 2 4 14 9
3
1 3
2 5
4 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3
10
7
</code></pre>

#### 1046 Shortest Distance (20 point(s))
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in $[3,10^5]$), followed by N integer distances $D_1,D_2,...,D_N$, where $D_i$ is the distance between the i-th and the (i+1)-st exits, and $D_N$ is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer $M (≤10^4)$, with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than $10^7$.

#### Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

```cpp
// 累计距离用前缀和
// 环形则斩成一条链
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    scanf("%d", &m);
    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        printf("%d\n", min(s[r - 1] - s[l - 1], s[n] - s[r - 1] + s[l - 1]));  // 正向和反向
    }

    return 0;
}
```

### 完美序列 1085 Perfect Sequence (25 point(s))

给定一个正整数序列和一个正整数 $p$。

如果 $M \le m \times p$ 成立，则该序列被称为完美序列，其中 $M$ 和 $m$ 分别是序列中的最大和最小数。

现在给定一个序列和一个参数 $p$，你应该从序列中找到尽可能多的数字以构成一个完美的子序列。

<h4>输入格式</h4>

- 第一行包含两个整数 $N$ 和 $p$。
- 第二行包含 $N$ 个正整数，表示给定序列。

<h4>输出格式</h4>

<p>输出最多可以选择多少个数，构成一个完美子序列。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^5$,
- $1 \le p \le 10^9$,
- 序列中的元素均不超过 $10^9$。

<h4>输入样例：</h4>

<pre><code>
10 8
2 3 20 4 5 1 6 7 8 9
</code></pre>

<h4>输出样例：</h4>

<pre><code>
8
</code></pre>

#### 1085 Perfect Sequence (25 point(s))
Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if $M≤m×p$ where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N $(≤10^5)$ is the number of integers in the sequence, and p $(≤10^9)$ is the parameter. In the second line there are N positive integers, each is no greater than $10^9$.

#### Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

```cpp
// 本来有 2^n 个情况要枚举
// 但是，我们可以把这题转换为排序后取区间，情况变为 n^2 / 2
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, p;
int a[N];

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    sort(a, a + n);

    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        while ((long long)a[j] * p < a[i]) j ++ ;  // M 定了，找最小的 m
        res = max(res, i - j + 1);
    }

    printf("%d\n", res);
    return 0;
}
```
