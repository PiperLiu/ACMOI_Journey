
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [找硬币 1048 Find Coins (25 point(s))](#找硬币-1048-find-coins-25-points)
- [集合相似度 1063 Set Similarity (25 point(s))](#集合相似度-1063-set-similarity-25-points)
- [朋友数 1120 Friend Numbers (20 point(s))](#朋友数-1120-friend-numbers-20-points)
- [漏掉的数字 1144 The Missing Number (20 point(s))](#漏掉的数字-1144-the-missing-number-20-points)
- [危险品装箱 1149 Dangerous Goods Packaging (25 point(s))](#危险品装箱-1149-dangerous-goods-packaging-25-points)

<!-- /code_chunk_output -->

### 找硬币 1048 Find Coins (25 point(s))

<p>伊娃喜欢从整个宇宙中收集硬币。</p>

<p>有一天，她去了一家宇宙购物中心购物，结账时可以使用各种硬币付款。</p>

<p>但是，有一个特殊的付款要求：每张帐单，她只能使用<strong>恰好</strong>两个硬币来<strong>准确</strong>的支付消费金额。</p>

<p>给定她拥有的所有硬币的面额，请你帮她确定对于给定的金额，她是否可以找到两个硬币来支付。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $M$，分别表示硬币数量以及需要支付的金额。

第二行包含 $N$ 个整数，表示每个硬币的面额。

<h4>输出格式</h4>

输出一行，包含两个整数 $V_1,V_2$，表示所选的两个硬币的面额，使得 $V_1 \le V_2$ 并且 $V_1 + V_2 = M$。

如果答案不唯一，则输出 $V_1$ 最小的解。

如果无解，则输出 <code>No Solution</code>。

<h4>数据范围</h4>

- $1 \le N \le 10^5$,
- $1 \le M \le 1000$

<h4>输入样例1：</h4>

<pre><code>
8 15
1 2 8 7 2 4 11 15
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
4 11
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
7 14
1 8 7 2 4 11 15
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
No Solution
</code></pre>

#### 1048 Find Coins (25 point(s))
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as $10^5$ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤$10^5$, the total number of coins) and M (≤$10^3$, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print in one line the two face values $V_1$ and $V_2$ (separated by a space) such that $V_1 + V_2 = M$ and $V_1≤V_2$. If such a solution is not unique, output the one with the smallest $V_1$. If there is no solution, output No Solution instead.

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> S;

int main()
{
    int n, m;
    cin >> n >> m;
    int v1 = 1e9, v2 = 0;
    for (int i = 0; i < n; ++ i)
    {
        int x, y;
        cin >> x;
        y = m - x;
        if (S.count(y))
        {
            if (x > y) swap(x, y);
            if (x < v1) v1 = x, v2 = y;
        }
        S.insert(x);
    }
    
    if (v1 == 1e9) cout << "No Solution" << endl;
    else cout << v1 << " " << v2 << endl;
}
```

### 集合相似度 1063 Set Similarity (25 point(s))

给定两个整数集合，两个集合的相似度定义为 $N_c / N_t \times 100\%$，其中 $N_c$ 是两个集合中都存在的不同整数的数量，$N_t$ 是两个集合中不同整数的数量。

<p>现在，请你计算给定集合的相似度。</p>

<h4>输入格式</h4>

第一行包含整数 $N$，表示集合数量。

接下来 $N$ 行，每行包含一个集合的信息，首先包含一个整数 $M$，表示集合中的数的个数，然后包含 $M$ 个整数，表示集合中的每个元素。

再一行，包含整数 $K$，表示询问次数。

接下来 $K$ 行，每行包含一组询问，包括两个整数 $a$ 和 $b$，表示询问集合 $a$ 和集合 $b$ 的相似度。

所有集合的编号为 $1 \sim N$。

<h4>输出格式</h4>

<p>每行输出一个询问的结果，保留一位小数。</p>

<h4>数据范围</h4>

- $1 \le N \le 50$,
- $1 \le M \le 10000$,
- $1 \le K \le 2000$,
- 集合中的元素取值均在 $[0,10^9]$ 范围内。

<h4>输入样例：</h4>

<pre><code>
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
</code></pre>

<h4>输出样例：</h4>

<pre><code>
50.0%
33.3%
</code></pre>

#### 1063 Set Similarity (25 point(s))
Given two sets of integers, the similarity of the sets is defined to be $N_c / N_t \times 100\%$, where $N_c$ is the number of distinct common numbers shared by the two sets, and $N_t$ is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

#### Input Specification:
Each input file contains one test case. Each case first gives a positive integer N (≤50) which is the total number of sets. Then N lines follow, each gives a set with a positive M ($≤10^4$) and followed by M integers in the range $[0,10^9]$. After the input of sets, a positive integer K (≤2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

#### Output Specification:
For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 55;

int n, m, k;
unordered_set<int> S[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> m;
        for (int j = 0; j < m; ++ j)
        {
            int x;
            cin >> x;
            S[i].insert(x);
        }
    }
    
    cin >> k;
    while (k --)
    {
        int a, b;
        cin >> a >> b;
        int nc = 0, nt = 0;
        for (auto t: S[a]) nc += S[b].count(t);
        nt = S[a].size() + S[b].size() - nc;
        double res = (double) nc / nt * 100;
        printf("%.1lf%\n", res);
    }
    
}
```

### 朋友数 1120 Friend Numbers (20 point(s))

<p>如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。</p>

例如 $123$ 和 $51$ 就是朋友数，因为 $1+2+3 = 5+1 = 6$，而 $6$ 就是它们的朋友证号。

<p>给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。</p>

<h4>输入格式</h4>

输入第一行给出正整数 $N$。

随后一行给出 $N$ 个正整数，数字间以空格分隔。

<h4>输出格式</h4>

<p>首先第一行输出给定数字中不同的朋友证号的个数；</p>

<p>随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。</p>

<h4>数据范围</h4>

- $1 \le N \le 10000$,
- 给定正整数均不超过 $10000$。

<h4>输入样例：</h4>

<pre><code>
8
123 899 51 998 27 33 36 12
</code></pre>

<h4>输出样例：</h4>

<pre><code>
4
3 6 9 26
</code></pre>

#### 1120 Friend Numbers (20 point(s))
Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different friend ID's among them.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than $10^4$.

#### Output Specification:
For each case, print in the first line the number of different friend ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

```cpp
// 经验：set基于红黑树实现，红黑树具有自动排序的功能，
// 因此map内部所有的数据，在任何时候，都是有序的
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> S;
    while (n -- )
    {
        int x;
        cin >> x;
        int s = 0;
        while (x) s += x % 10, x /= 10;
        S.insert(s);
    }

    cout << S.size() << endl;

    bool is_first = true;
    for (auto x : S)
    {
        if (is_first) is_first = false;
        else cout << ' ';
        cout << x;
    }

    return 0;
}
```

**经验：**
- C++ 中 `set` 基于红黑树实现，红黑树具有自动排序的功能，因此map内部所有的数据，在任何时候，都是有序的

### 漏掉的数字 1144 The Missing Number (20 point(s))

给定 $N$ 个整数，请你找出最小的不在给定整数列表中的正整数。

<h4>输入格式</h4>

第一行包含整数 $N$。

第二行包含 $N$ 个整数，整数之间用空格隔开，所有数字都在 <strong>int</strong> 范围内。

<h4>输出格式</h4>

<p>输出不在给定整数列表中的最小正整数。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^5$

<h4>输入样例：</h4>

<pre><code>
10
5 -25 9 6 1 3 4 2 5 17
</code></pre>

<h4>输出样例：</h4>

<pre><code>
7
</code></pre>

#### 1144 The Missing Number (20 point(s))
Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (≤10^5)$. Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.

#### Output Specification:
Print in a line the smallest positive integer that is missing from the input list.

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<int> S;
    while (n -- )
    {
        int x;
        cin >> x;
        S.insert(x);
    }

    int res = 1;  // 暴搜
    while (S.count(res)) res ++ ;

    cout << res << endl;

    return 0;
}
```

### 危险品装箱 1149 Dangerous Goods Packaging (25 point(s))

<p>集装箱运输货物时，我们必须特别小心，不能把不相容的货物装在一只箱子里。</p>

<p>比如氧化剂绝对不能跟易燃液体同箱，否则很容易造成爆炸。</p>

<p>本题给定一张不相容物品的清单，需要你检查每一张集装箱货品清单，判断它们是否能装在同一只箱子里。</p>

<h4>输入格式</h4>

输入第一行给出两个正整数：$N$ 是成对的不相容物品的对数；$M$ 是集装箱货品清单的单数。

随后数据分两大块给出。第一块有 $N$ 行，每行给出一对不相容的物品。

第二块有 $M$ 行，每行给出一箱货物的清单，格式如下：

<pre><code>
K G[1] G[2] ... G[K]
</code></pre>

<p>其中 <code>K</code> 是物品件数，<code>G[i]</code> 是物品的编号。</p>

简单起见，每件物品用一个 $5$ 位数的编号代表。

<p>两个数字之间用空格分隔。</p>

<h4>输出格式</h4>

<p>对每箱货物清单，判断是否可以安全运输。</p>

<p>如果没有不相容物品，则在一行中输出 <code>Yes</code>，否则输出 <code>No</code>。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^4$,
- $1 \le M \le 100$,
- $1 \le K \le 1000$

<h4>输入样例：</h4>

<pre><code>
6 3
20001 20002
20003 20004
20005 20006
20003 20001
20005 20004
20004 20006
4 00001 20004 00002 20003
5 98823 20002 20003 20006 10010
3 12345 67890 23333
</code></pre>

<h4>输出样例：</h4>

<pre><code>
No
Yes
Yes
</code></pre>

#### 1149 Dangerous Goods Packaging (25 point(s))
When shipping goods with containers, we have to be careful not to pack some incompatible goods into the same container, or we might get ourselves in serious trouble. For example, oxidizing agent （氧化剂） must not be packed with flammable liquid （易燃液体）, or it can cause explosion.

Now you are given a long list of incompatible goods, and several lists of goods to be shipped. You are supposed to tell if all the goods in a list can be packed into the same container.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: $N (≤10^4)$, the number of pairs of incompatible goods, and M (≤100), the number of lists of goods to be shipped.

Then two blocks follow. The first block contains N pairs of incompatible goods, each pair occupies a line; and the second one contains M lists of goods to be shipped, each list occupies a line in the following format:
```
K G[1] G[2] ... G[K]
```

where $K (≤1,000)$ is the number of goods and G[i]'s are the IDs of the goods. To make it simple, each good is represented by a 5-digit ID number. All the numbers in a line are separated by spaces.

#### Output Specification:
For each shipping list, print in a line Yes if there are no incompatible goods in the list, or No if not.

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 10010;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &a[i], &b[i]);

    while (m -- )
    {
        int k;
        scanf("%d", &k);
        unordered_set<int> S;
        while (k -- )
        {
            int x;
            scanf("%d", &x);
            S.insert(x);
        }

        bool success = true;
        // 这里是检查每一对危险品
        for (int i = 0; i < n; i ++ )
            if (S.count(a[i]) && S.count(b[i]))
            {
                success = false;
                break;
            }

        if (success) puts("Yes");
        else puts("No");
    }

    return 0;
}
```
