
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [普通回文数 1019 General Palindromic Number (20 point(s))](#普通回文数-1019-general-palindromic-number-20-points)

<!-- /code_chunk_output -->

### 普通回文数 1019 General Palindromic Number (20 point(s))

<p>一个数字如果从前往后读和从后往前读都完全一样，那么这个数就是回文数。</p>

例如，$1234321$ 就是一个回文数。

<p>所有的一位数字都是回文数。</p>

<p>我们一般都是在十进制下考虑回文，但是回文这一概念也可以应用于其他进制下的数字中。</p>

一个整数 $N$，在 $b$ 进制下，共有 $k+1$ 位，其中第 $i$ 位的数字为 $a_i,(0 \le i \le k)$，那么 $N = \sum_{i=0}^k(a_ib^i)$。

一般来说，$0 \le a_i < b$，并且 $a_k \neq 0$。

如果对于任意 $i$，满足 $a_i = a_{k-i}$，那么 $N$ 在 $b$ 进制下就是一个回文数。

$0$ 在任何进制下都表示为 $0$，且都视为是一个回文数。

现在给定一个整数 $N$，请你判断它在 $b$ 进制的表示下，是否是一个回文数。

<h4>输入格式</h4>

共一行包含两个整数 $N$ 和 $b$。

<h4>输出格式</h4>

<p>输出共两行。</p>

如果 $N$ 在 $b$ 进制下是回文数，则第一行输出 <code>Yes</code>，否则输出 <code>No</code>。

第二行，输出 $N$ 在 $b$ 进制下的表示，包含 $k+1$ 个整数，要求按顺序输出 $a_k,a_{k-1},...,a_0$，整数之间用空格隔开。

<h4>数据范围</h4>

- $0 \le N \le 10^9$,
- $2 \le b \le 10^9$

<h4>输入样例1：</h4>

<pre><code>
27 2
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
Yes
1 1 0 1 1
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
121 5
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
No
4 4 1
</code></pre>

#### 1019 General Palindromic Number (20 point(s))
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N>0 in base b≥2, where it is written in standard notation with k+1 digits $a_i$ as $N = \sum_{i=0}^k(a_ib^i). Here, as usual, $0≤a_i < b$ for all i and $a_k$ is non-zero. Then N is palindromic if and only if $a_i = a_{k−i} for all i. Zero is written 0 in any base and is also palindromic by definition.

Given any positive decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

#### Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and b, where $0<N≤10^9$ is the decimal number and $2≤b≤10^9$ is the base. The numbers are separated by a space.

#### Output Specification:
For each test case, first print in one line `Yes` if N is a palindromic number in base `b`, or `No` if not. Then in the next line, print N as the number in base b in the form $a_k,a_{k-1},...,a_0$. Notice that there must be no extra space at the end of output.

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

bool check()
{
    for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- )
        if (nums[i] != nums[j])
            return false;

    return true;
}

int main()
{
    int n, b;
    cin >> n >> b;

    if (!n) nums.push_back(0);  // 是 0 的话直接返回 0
    while (n) nums.push_back(n % b), n /= b;

    if (check()) puts("Yes");
    else puts("No");

    cout << nums.back();  // 题目要求倒着输出
    for (int i = nums.size() - 2; i >= 0; i -- ) cout << ' ' << nums[i];

    return 0;
}
```
