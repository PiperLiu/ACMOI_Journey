
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [约会](#约会)

<!-- /code_chunk_output -->

### 约会

<p>大侦探福尔摩斯接到一张奇怪的字条：<code>我们约会吧！3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm</code>。</p>

大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间<code>星期四 14:04</code>，因为前面两字符串中第 $1$ 对相同的大写英文字母（大小写有区分）是第 $4$ 个字母 D，代表星期四；第 $2$ 对相同的字符是 $E$ ，那是第 $5$ 个英文字母，代表一天里的第 $14$ 个钟头（于是一天的 $0$ 点到 $23$ 点由数字 $0$ 到 $9$、以及大写字母 $A$ 到 $N$ 表示）；后面两字符串第 $1$ 对相同的英文字母 $s$ 出现在第 $4$ 个位置（从 $0$ 开始计数）上，代表第 $4$ 分钟。

<p>现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。</p>

<h4>补充</h4>

- 1、一对字符相同，是指在两个字符相同且在字符串的位置也相同。
- 2、前两个字符串中第一对相同的大写英文字母，是指第一对能够<strong>正确代表日期</strong>的大写英文字母。
- 3、前两个字符串中第二对相同的字符，是指位于<strong>代表日期的字符后面</strong>的，<strong>第一对</strong>相同的，能够<strong>正确代表小时</strong>的字符。

<h4>输入格式</h4>

输入在 $4$ 行中分别给出 $4$ 个非空、不包含空格、且长度不超过 $60$ 的字符串。

<h4>输出格式</h4>

<p>在一行中输出约会的时间，格式为 <code>DAY HH:MM</code>，其中 <code>DAY</code> 是某星期的 $3$ 字符缩写，即 <code>MON</code> 表示星期一，<code>TUE</code> 表示星期二，<code>WED</code> 表示星期三，<code>THU</code> 表示星期四，<code>FRI</code> 表示星期五，<code>SAT</code> 表示星期六，<code>SUN</code> 表示星期日。</p>

<p>题目输入保证每个测试存在唯一解。</p>

<h4>输入样例：</h4>

<pre><code>
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
</code></pre>

<h4>输出样例：</h4>

<pre><code>
THU 14:04
</code></pre>

#### 1061 Dating (20 point(s))
Sherlock Holmes received a note with some strange strings: `Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`. It took him only a minute to figure out that those strange strings are actually referring to the coded time Thursday 14:04 -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D, representing the 4th day in a week; the second common character is the 5th capital letter E, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is s at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

#### Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

#### Output Specification:
For each test case, print the decoded time in one line, in the format DAY HH:MM, where DAY is a 3-character abbreviation for the days in a week -- that is, MON for Monday, TUE for Tuesday, WED for Wednesday, THU for Thursday, FRI for Friday, SAT for Saturday, and SUN for Sunday. It is guaranteed that the result is unique for each case.

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int k = 0;
    while (true)
    {
        if (a[k] == b[k] && a[k] >= 'A' && a[k] <= 'G') break;
        k ++ ;
    }

    char weekdays[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s ", weekdays[a[k] - 'A']);

    k ++ ;
    while (true)
    {
        if (a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N')) break;
        k ++ ;
    }

    printf("%02d:", a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10);

    for (int i = 0;; i ++ )
        if (c[i] == d[i] && (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z'))
        {
            printf("%02d\n", i);
            break;
        }

    return 0;
}
```
