
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [进制 1010 Radix (25 point(s))](#进制-1010-radix-25-points)
- [可逆质数 1015 Reversible Primes (20 point(s))](#可逆质数-1015-reversible-primes-20-points)
- [火星颜色 1027 Colors in Mars (20 point(s))](#火星颜色-1027-colors-in-mars-20-points)
- [火星数字 1100 Mars Numbers (20 point(s))](#火星数字-1100-mars-numbers-20-points)

<!-- /code_chunk_output -->

### 进制 1010 Radix (25 point(s))

给定一对正整数，例如 $6$ 和 $110$，此等式 $6 = 110$ 是否成立？

答案是可以成立，当 $6$ 是十进制数字，$110$ 是二进制数字时等式得到满足。

现在，给定一个正整数数对 $N_1,N_2$，并给出其中一个数字的进制，请你求出另一个数字在什么进制下，两数相等成立。

<h4>输入格式</h4>

<p>输入共一行，包含四个正整数，格式如下：</p>

<pre><code>
N1 N2 tag radix
</code></pre>

$N_1$ 和 $N_2$ 是两个不超过 $10$ 位的数字，<code>radix</code> 是其中一个数字的进制，如果 <code>tag</code> 为 $1$，则 <code>radix</code> 是 $N_1$ 的进制，如果 <code>tag</code> 为 $2$，则 <code>radix</code> 是 $N_2$ 的进制。

注意，一个数字的各个位上的数都不会超过它的进制，我们用 $0 \sim 9$ 表示数字 $0 \sim 9$，用 $a \sim z$ 表示 $10 \sim 35$。

<h4>输出格式</h4>

输出使得 $N_1 = N_2$ 成立的另一个数字的进制数。

<p>如果等式不可能成立，则输出 <code>Impossible</code>。</p>

<p>如果答案不唯一，则输出更小的进制数。</p>

<h4>数据范围</h4>

$2 \le radix \le 36$

<h4>输入样例1：</h4>

<pre><code>
6 110 1 10
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
2
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
1 ab 1 2
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
Impossible
</code></pre>

#### 1010 Radix (25 point(s))
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers $N_1$ and $N_2$, your task is to find the radix of one number while that of the other is given.

#### Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:`N1 N2 tag radix`.

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set `{ 0-9, a-z }` where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

#### Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// n1 最大值为 36^10 - 1 ≈ 3e15
// 可以用 LL 存（LL上限 9e18）
typedef long long LL;

int get(char c)
{
    if (c <= '9') return c - '0';
    return c - 'a' + 10;
}

// 注意，进制是 LL
LL calc(string n, LL radix)
{
    LL res = 0;
    for (auto c: n)
    {
        // 用 double 是因为 LL × LL 可能爆 LL
        // 超过 target 理论值，直接返回
        if ((double) res * radix + get(c) >= 1e16) return 1e18;
        res = res * radix + get(c);
    }
    return res;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int tag, radix;
    cin >> tag >> radix;
    
    if (tag == 2) swap(n1, n2);
    LL target = calc(n1, radix);
    
    // 假设 n2 为 10，则进制必须为 target 才能与 n1 值同
    // r 最少是 36ll
    LL l = 0, r = max(target, 36ll);
    for (auto c: n2) l = max(l, (LL)get(c) + 1);  // 进制下界为 n2 出现过的最大字符+1
    
    while (l < r)
    {
        LL mid = l + r >> 1;  // 注意 mid 是 LL
        if (calc(n2, mid) >= target) r = mid;
        else l = mid + 1;
    }
    
    if (calc(n2, r) != target) cout << "Impossible" << endl;
    else cout << r << endl;
}
```

**经验：**
- 用 `double` 是因为 `LL × LL` 可能爆 `LL`
- 对于 `LL l, r` ，其中 `mid` 也得是 `LL` 的

### 可逆质数 1015 Reversible Primes (20 point(s))

### 火星颜色 1027 Colors in Mars (20 point(s))

### 火星数字 1100 Mars Numbers (20 point(s))
