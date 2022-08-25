
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

给定两个整数 $N$ 和 $D$，如果 $N$ 是一个质数，并且将 $N$ 转化为 $D$ 进制表示后，再进行反转，得到的新数字转化为十进制表示后如果也是一个质数，则称 $N$ 在 $D$ 进制系统中，是一个可逆质数。

例如，$N = 73,D = 10$，则 $73$ 是质数，其十进制表示反转后为 $37$ 也是质数，所以 $73$ 在十进制系统中是一个可逆质数。

$N = 23,D = 2$，则 $23$ 是质数，其二进制表示为 $10111$，反转后得到 $11101$，转化为十进制后为 $29$，这也是一个质数，所以 $23$ 在二进制系统中是一个可逆质数。

现在，请你判断所给 $N$ 在 $D$ 进制系统中是否是一个可逆质数。

<h4>输入格式</h4>

<p>输入包含多组测试数据。</p>

每组数据共一行，包含两个整数 $N$ 和 $D$。

<p>当输入一行为一个负数时，表示输入停止。</p>

<h4>输出格式</h4>

<p>对于每组数据，输出一个结果，占一行。</p>

如果所给 $N$ 在 $D$ 进制系统中是一个可逆质数，则输出 <code>Yes</code>，否则输出 <code>No</code>。

<h4>数据范围</h4>

- $1 \le N < 10^5$
- $1 < D \le 10$

<h4>输入样例：</h4>

<pre><code>
73 10
23 2
23 10
-2
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Yes
Yes
No
</code></pre>

#### 1015 Reversible Primes (20 point(s))
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers $N (<10 
^5)$ and $D (1<D≤10)$, you are supposed to tell if N is a reversible prime with radix D.

#### Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

#### Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool is_prime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i ++ )
    {
        if (x % i == 0) return false;
    }
    return true;
}

bool check(int n, int r)
{
    if (!is_prime(n)) return false;
    
    int a = 0;
    while (n)
    {
        a = a * r + n % r;
        n = n / r;
    }
    
    if (is_prime(a)) return true;
    return false;
}

int main()
{
    int n, r;
    while (cin >> n >> r, n > 0)
    {
        if (check(n, r)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
```

### 火星颜色 1027 Colors in Mars (20 point(s))

<p>火星人以与地球人相似的方式在计算机中表示颜色。 </p>

也就是说，颜色由 $6$ 位数字表示，其中前 $2$ 位数字代表红色($R$)，中 $2$ 位数字代表绿色($G$)，后 $2$ 位数字代表蓝色($B$)。

与我们的区别在于，他们使用 $13$ 进制（$0 \sim 9$ 和 $A \sim C$）来表示颜色值。

现在给定三个用来表示颜色值的十进制数字（数字范围在 $[0,168]$ 之间），请你输出他们的火星 $RGB$ 颜色值。

<h4>输入格式</h4>

<p>包含三个十进制整数，分别表示十进制下的 R、G、B 颜色值。</p>

<h4>输出格式</h4>

共一行，先输出一个 `#`，然后输出一个 $6$ 位数字表示火星 RGB 颜色值。

如果某一种颜色的数值换算为 $13$ 进制后，不足 $2$ 位，则在前面补 $0$，凑足 $2$ 位。

<h4>输入样例：</h4>

<pre><code>
15 43 71
</code></pre>

<h4>输出样例：</h4>

<pre><code>
#123456
</code></pre>

<h4>样例解释</h4>

给定的三个数字 $15,43,71$ 在 $13$ 进制下的表示分别是 $12,34,56$。

<p>所以将它们组合起来，答案即为 <code>#123456</code>。</p>

#### 1027 Colors in Mars (20 point(s))
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

#### Input Specification:
Each input file contains one test case which occupies a line containing the three decimal color values.

#### Output Specification:
For each test case you should output the Mars RGB value in the following format: first output #, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a 0 to its left.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char get(int x)
{
    if (x <= 9) return x + '0';
    else return x - 10 + 'A';
}

string convert(int x)
{
    string s;
    while (x)
    {
        s = get(x % 13) + s;
        x /= 13;
    }
    if (s.size() == 1) s = '0' + s;
    if (s.size() == 0) s = "00";
    return s;
}

int main()
{
    cout << "#";
    for (int i = 0; i < 3; ++ i)
    {
        int x;
        cin >> x;
        cout << convert(x);
    }
}
```

### 火星数字 1100 Mars Numbers (20 point(s))

 火星人用 $13$ 进制来计数：

- <code>zero</code>（零）在火星读作 <code>tret</code>。
- 地球上的数字 $1 \sim 12$ 在火星读作：<code>jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec</code>。
- 对于进位后的 $12$ 个更高位数字，在火星读作：<code>tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou</code>。

例如，地球上的 $29$ 在火星读作 <code>hel mar</code>，而火星数字 <code>elo nov</code> 表示的是地球上的数字 $115$。

<p>为了帮助两个星球上的人民之间相互交流，请你编写一个程序，能够实现地球和火星数字之间的相互翻译。</p>

<h4>输入格式</h4>

第一行包含一个整数 $N$，表示要翻译的数字个数。

接下来 $N$ 行，每行包含一个在 $[0,169)$ 范围内的数字，可能以地球形式给出，也可能以火星形式给出。

<h4>输出格式</h4>

共 $N$ 行，对于每个输入数字，用另一种语言在一行中输出对应的数字。

<h4>数据范围</h4>

$1 \le N \le 100$

<h4>输入样例：</h4>

<pre><code>
5
29
5
13
elo nov
tam
</code></pre>

<h4>输出样例：</h4>

<pre><code>
hel mar
may
tam
115
13
</code></pre>

#### 1100 Mars Numbers (20 point(s))
People on Mars count their numbers with base 13:
- Zero on Earth is called "tret" on Mars.
- The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
- For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.

For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<100). Then N lines follow, each contains a number in `[0, 169)`, given either in the form of an Earth number, or that of Mars.

#### Output Specification:
For each number, print in a line the corresponding number in the other language.

```cpp
#include <iostream>
#include <sstream>
using namespace std;

char names[][5] = {
    "tret",  // 0
    "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",  // 1  - 12
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"   // 13 - 24
};

int get(string word)
{
    for (int i = 0; i <= 24; ++ i)
        if (names[i] == word)
        {
            if (i <= 12) return i;
            else return (i - 12) * 13;
        }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    getchar();  // 下面要用 getline ，因此要用 getchar 把之前 cin 遗留的 \n 干掉
    
    while (n -- )
    {
        string line;
        getline(cin, line);
        
        stringstream ssin(line);  // 用 sstream 中的 stringstream 处理一行字符串
        if (line[0] <= '9')  // 如果是数字转火星文
        {
            int v;
            ssin >> v;  // 如此使用 stringstream 实例
            if (v < 13) cout << names[v] << endl;
            else
            {
                cout << names[12 + v / 13];
                if (v % 13 == 0) cout << endl;
                else cout << " " << names[v % 13] << endl;
            }
        }
        else  // 如果是火星文转数字
        {
            int res = 0;
            string word;
            while (ssin >> word) res += get(word);
            cout << res << endl;
        }
    }
}
```

**经验：**
- `cin >> n; getchar(); getline(cin, line); stringstream ssin(line); ssin >> word;`
  - 下面要用 `getline` ，因此要用 `getchar` 把之前 `cin` 遗留的 `\n` 干掉
  - 用 `sstream` 中的 `stringstream` 处理一行字符串
