- [多项式 A + B 1002 A+B for Polynomials (25 point(s))](#多项式-a-b-1002-ab-for-polynomials-25-points)
- [多项式乘积 1009 Product of Polynomials (25 point(s))](#多项式乘积-1009-product-of-polynomials-25-points)
- [趣味数字 1023 Have Fun with Numbers (20 point(s))](#趣味数字-1023-have-fun-with-numbers-20-points)
- [回文数 1024 Palindromic Number (25 point(s))](#回文数-1024-palindromic-number-25-points)

### 多项式 A + B 1002 A+B for Polynomials (25 point(s))

给定两个多项式 $A$ 和 $B$，计算 $A+B$ 的结果。

<h4>输入格式</h4>

<p>共两行，每行包含一个多项式的信息，格式如下：</p>

$K\ N_1\ a_{N_1}\ N_2\ a_{N_2}\ ... \ N_K\ a_{N_K}$

其中，$K$ 表示多项式中非零项的数量，$N_i$ 和 $a_{N_i}$ 分别表示其中一个非零项的指数和系数。

<h4>输出格式</h4>

按照与输入相同的格式，输出 $A+B$ 的结果。</p>
<p>结果中的各项的系数均<strong>保留一位小数</strong>。

<h4>数据范围</h4>

- $K$ 为整数，$1 \le K \le 10$。
- $N_i$ 为整数，$0 \le N_K < \cdots < N_2 < N_1 \le 1000$。
- $a_{N_i}$ 为浮点数，$-100 \le a_{N_i} \le 100$。

<h4>输入样例：</h4>

<pre><code>
2 1 2.4 0 3.2
2 2 1.5 1 0.5
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3 2 1.5 1 2.9 0 3.2
</code></pre>

#### 1002 A+B for Polynomials (25 point(s))
This time, you are supposed to find A+B where A and B are two polynomials.

#### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

$K\ N_1\ a_{N_1}\ N_2\ a_{N_2}\ ... \ N_K\ a_{N_K}$

where K is the number of nonzero terms in the polynomial, $N_i$ and $a_{N_i} (i=1,2,⋯,K)$ are the exponents and coefficients, respectively. It is given that $0 \le N_K < \cdots < N_2 < N_1 \le 1000$.

#### Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 1010;

double a[N], b[N], c[N];

int main()
{
    int k;

    cin >> k;
    for (int i = 0; i < k; ++ i)
    {
        int n;
        double p;
        cin >> n >> p;
        a[n] = p;
    }
    
    cin >> k;
    for (int i = 0; i < k; ++ i)
    {
        int n;
        double p;
        cin >> n >> p;
        b[n] = p;
    }
    
    for (int i = 0; i < N; ++ i) c[i] = a[i] + b[i];
    
    k = 0;
    for (int i = 0; i < N; ++ i)
    {
        if (c[i]) k++;
    }
    
    cout << k;
    for (int i = N - 1; i >= 0; -- i)
    {
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
    }
    
    puts("");
}
```

### 多项式乘积 1009 Product of Polynomials (25 point(s))

给定两个多项式 $A$ 和 $B$，计算 $A \times B$ 的结果。

<h4>输入格式</h4>

<p>共两行，每行包含一个多项式的信息，格式如下：</p>

$K\ N_1\ a_{N_1}\ N_2\ a_{N_2}\ ...\ N_K\ a_{N_K}$

其中，$K$ 表示多项式中非零项的数量，$N_i$ 和 $a_{N_i}$ 分别表示其中一个非零项的指数和系数。

<h4>输出格式</h4>

<p>按照与输入相同的格式，输出 $A \times B$ 的结果。</p>

<p>结果中的各项的系数均<strong>保留一位小数</strong>。</p>

<h4>数据范围</h4>

- $K$ 为整数，$1 \le K \le 10$。
- $N_i$ 为整数，$0 \le N_K < \cdots < N_2 < N_1 \le 1000$。
- $a_{N_i}$ 为浮点数，$-100 \le a_{N_i} \le 100$。

<h4>输入样例：</h4>

<pre><code>
2 1 2.4 0 3.2
2 2 1.5 1 0.5
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3 3 3.6 2 6.0 1 1.6
</code></pre>

#### 1009 Product of Polynomials (25 point(s))
This time, you are supposed to find A×B where A and B are two polynomials.

#### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: $K\ N_1\ a_{N_1}\ N_2\ a_{N_2}\ ...\ N_K\ a_{N_K}$, where K is the number of nonzero terms in the polynomial, $N_i$ and $a_{N_i} (i=1,2,⋯,K)$ are the exponents and coefficients, respectively. It is given that $1 \le K \le 10$, $0 \le N_K < \cdots < N_2 < N_1 \le 1000$.

#### Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 1010;

double a[N], b[N], c[N];

int main()
{
    int k;

    cin >> k;
    for (int i = 0; i < k; ++ i)
    {
        int n;
        double p;
        cin >> n >> p;
        a[n] = p;
    }
    
    cin >> k;
    for (int i = 0; i < k; ++ i)
    {
        int n;
        double p;
        cin >> n >> p;
        b[n] = p;
    }
    
    for (int i = 0; i < N; ++ i) c[i] = a[i] + b[i];
    
    k = 0;
    for (int i = 0; i < N; ++ i)
    {
        if (c[i]) k++;
    }
    
    cout << k;
    for (int i = N - 1; i >= 0; -- i)
    {
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
    }
    
    puts("");
}
```

### 趣味数字 1023 Have Fun with Numbers (20 point(s))

请注意，数字 $123456789$ 是一个 $9$ 位数字，完全由 $1$ 到 $9$ 组成，没有重复。

将其加倍，我们将获得 $246913578$，它恰好是另一个 $9$ 位数字，恰好由 $1$ 到 $9$ 组成，只是排列不同。

现在，给定你一个 $k$ 位的数字，请你判断将其加倍以后得到的数字是否可以由原数字的各数位重新排列得到。

<h4>输入格式</h4>

<p>共一行，包含一个整数。</p>

<h4>输出格式</h4>

<p>输出共两行</p>

<p>如果原数字的各数位重新排列可以得到加倍后的数字，则在第一行输出 <code>Yes</code>，否则输出 <code>No</code>。</p>

<p>第二行，输出加倍后得到的数字。</p>

<h4>数据范围</h4>

输入数字不超过 $20$ 位。

<h4>输入样例：</h4>

<pre><code>
1234567899
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Yes
2469135798
</code></pre>

#### 1023 Have Fun with Numbers (20 point(s))
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

#### Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

#### Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string A;
    vector<int> a;
    
    cin >> A;
    
    for (int i = A.size() - 1; i >= 0; -- i)
        a.push_back(A[i] - '0');
        
    vector<int> b;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        int s = a[i] + a[i] + t;
        b.push_back(s % 10);
        t = s / 10;
    }
    if (t) b.push_back(t);
    
    vector<int> c = b;  // 备份 b
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    
    if (a == c) cout << "Yes" << endl;
    else cout << "No" << endl;

    for (int i = b.size() - 1; i >= 0; -- i)
        cout << b[i];
}
```

**经验：**
- C++ 中 `vector` 两个可以直接比较，因为 `vector` 重载了 `==` 运算符

### 回文数 1024 Palindromic Number (25 point(s))

<p>如果一个数字从前往后读和从后往前读都一样，那么这个数字就是回文数字。</p>

<p>所有一位数字都是回文数字。</p>

<p>非回文数字可以通过一系列的操作与回文数字配对。</p>

<p>首先，将非回文数字反转，让反转后的数字与原数字相加，得到一个新的数字。</p>

<p>如果新的数字不是回文数字，那么就重复此操作，直到得到回文数字为止。</p>

例如，我们从 $67$ 开始，经过两次操作可以得到一个回文数字：$67 + 76 = 143$，$143 + 341 = 484$。

对于给定的任意正整数 $N$，请你找到它的配对回文数并输出得到该回文数需要的操作次数。

<h4>输入格式</h4>

共一行，包含两个整数 $N$ 和 $K$，分别表示给定整数以及最大操作次数。

<h4>输出格式</h4>

<p>共两行，第一行输出配对回文数。</p>

<p>第二行输出得到配对回文数所需要的操作次数。</p>

如果经过 $K$ 次操作后，仍然无法得到回文数字。

那么，第一行输出 $K$ 次操作后得到的数字。

第二行输出 $K$。

<h4>数据范围</h4>

- $1 \le N \le 10^{10}$
- $1 \le K \le 100$

<h4>输入样例1：</h4>

<pre><code>
67 3
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
484
2
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
69 3
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
1353
3
</code></pre>

#### 1024 Palindromic Number (25 point(s))
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

#### Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where $N (≤10^{10})$ is the initial numer and $K (≤100)$ is the maximum number of steps. The numbers are separated by a space.

#### Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool check(const vector<int>& a)
{
    for (int i = 0, j = a.size() - 1; i < j; ++ i, -- j)
    {
        if (a[i] != a[j]) return false;
    }
    return true;
}

vector<int> add(const vector<int>& a, const vector<int>& b)
{
    vector<int> c;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; ++ i)
    {
        int s = 0;
        if (i < a.size()) s += a[i];
        if (i < b.size()) s += b[i];
        s += t;
        c.push_back(s % 10);
        t = s / 10;
    }
    return c;
}

int main()
{
    string A;
    int k;
    cin >> A >> k;
    
    vector<int> a;
    for (int i = A.size() - 1; i >= 0; -- i) a.push_back(A[i] - '0');
    
    int cnt = 0;
    if (!check(a))
    {
        while (cnt < k)
        {
            cnt ++;
            vector<int> b(a.rbegin(), a.rend());
            a = add(a, b);
            if (check(a)) break;
        }
    }
    
    for (int i = a.size() - 1; i >= 0; -- i) cout << a[i];
    cout << endl;
    cout << cnt << endl;
}
```

**经验：**
- C++ 中 `vector` 翻转使用反向迭代器：`vector<int> b(a.rbegin(), a.rend());`
