
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [坏掉的键盘 1084 Broken Keyboard (20 point(s))](#坏掉的键盘-1084-broken-keyboard-20-points)
- [求平均值 1108 Finding Average (20 point(s))](#求平均值-1108-finding-average-20-points)
- [微博转发抽奖 1124 Raffle for Weibo Followers (20 point(s))](#微博转发抽奖-1124-raffle-for-weibo-followers-20-points)
- [PAT单位排行 1141 PAT Ranking of Institutions (25 point(s))](#pat单位排行-1141-pat-ranking-of-institutions-25-points)
- [解码PAT准考证 1153 Decode Registration Card of PAT (25 point(s))](#解码pat准考证-1153-decode-registration-card-of-pat-25-points)

<!-- /code_chunk_output -->

### 坏掉的键盘 1084 Broken Keyboard (20 point(s))

<p>键盘上有些按键已经损坏了。</p>

<p>当你输入一些句子时，与坏掉的按键相对应的字符将不会出现在屏幕上。</p>

<p>现在给定你应该键入的字符串以及你实际键入的字符串，请找出哪些按键坏了。</p>

<h4>输入格式</h4>

<p>第一行包含应该键入的字符串。</p>

<p>第二行包含实际键入的字符串。</p>

<p>两个字符串中都只包含大小写英文字母，数字以及 <code>_</code>（表示空格）。</p>

<h4>输出格式</h4>

<p>共一行，按检测到的顺序，输出所有损坏的按键。</p>

<p>英文字母必须大写，每个损坏的按键只需要输出一次。</p>

<h4>数据范围</h4>

给定字符串的长度均不超过 $80$。

保证至少有一个按键损坏。</p>

<h4>输入样例：</h4>

<pre><code>
7_This_is_a_test
_hs_s_a_es
</code></pre>

<h4>输出样例：</h4>

<pre><code>
7TI
</code></pre>

#### 1084 Broken Keyboard (20 point(s))
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

#### Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.

#### Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

```cpp
// 我写的
#include <iostream>
#include <unordered_set>

using namespace std;

char big(char a)
{
    if (a <= 'z' && a >= 'a')
        return a + 'A' - 'a';
    return a;
}

char small(char a)
{
    if (a <= 'Z' && a >= 'A')
        return a + 'a' - 'A';
    return a;
}

int main()
{
    unordered_set<char> S, printed;
    string a, b;
    cin >> a >> b;
    for (auto s: b)
    {
        S.insert(s);
        S.insert(big(s));
        S.insert(small(s));
    }
    for (auto s: a)
    {
        if (!S.count(s))
        {
            if (!printed.count(s))
            {
                printed.insert(s);
                printed.insert(big(s));
                printed.insert(small(s));
                cout << big(s);
            }
        }
    }
}
```

下面是 y 总的。

```cpp
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    bool st[200] = {0};
    b += '#';
    for (int i = 0, j = 0; i < a.size(); i ++ )
    {
        char x = toupper(a[i]), y = toupper(b[j]);
        if (x == y) j ++ ;
        else
        {
            if (!st[x]) cout << x, st[x] = true;
        }
    }

    return 0;
}
```

**经验：**
- C++ 中 `toupper` 是把字符串都转化为大写；相对应的有 `tolower`

### 求平均值 1108 Finding Average (20 point(s))

基本任务非常简单：给定 $N$ 个实数，请你计算它们的平均值。

<p>但是令事情变得复杂的是，某些输入数字可能不合法。</p>

合法输入数字指 $[−1000,1000]$ 范围内的精确到<strong>不超过</strong> $2$ 个小数位的实数。

<p>在计算平均值时，不得将这些非法数字计算在内。</p>

<h4>输入格式</h4>

第一行包含整数 $N$。

第二行包含 $N$ 个输入数字，数字之间用空格隔开。

<h4>输出格式</h4>

<p>按照输入的顺序，对于每个输入的非法数字，在一行中输出 <code>ERROR: X is not a legal number</code>，其中 <code>X</code> 是非法输入。</p>

<p>最后一行，输出 <code>The average of K numbers is Y</code>，其中 <code>K</code> 是合法输入的数量，<code>Y</code> 是它们的平均值，注意保留两位小数。</p>

<p>如果平均值无法计算，则将 <code>Y</code> 替换为 <code>Undefined</code>。</p>

如果 <code>K</code> 仅为 $1$，则输出 <code>The average of 1 number is Y</code>。

<h4>数据范围</h4>

$1 \le N \le 1000$

<h4>输入样例1：</h4>

<pre><code>
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
2
aaa -9999
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
</code></pre>

#### 1108 Finding Average (20 point(s))
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A legal input is a real number in [−1000,1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then N numbers are given in the next line, separated by one space.

#### Output Specification:
For each illegal input number, print in a line ERROR: X is not a legal number where X is the input. Then finally print in a line the result: The average of K numbers is Y where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output Undefined instead of Y. In case K is only 1, output The average of 1 number is Y instead.

```cpp
```

### 微博转发抽奖 1124 Raffle for Weibo Followers (20 point(s))

约翰 PAT 考了满分，高兴之余决定发起微博转发抽奖活动，从转发的网友中按顺序每隔 $N$ 个人就发出一个红包。

<p>请你编写程序帮助他确定中奖名单。</p>

<h4>输入格式</h4>

输入第一行给出三个正整数 $M,N,S$，分别是转发的总量、小明决定的中奖间隔、以及第一位中奖者的序号（编号从 $1$ 开始）。

随后 $M$ 行，顺序给出转发微博的网友的昵称（不超过 $20$ 个字符、不包含空格回车的非空字符串）。

<p>注意：可能有人转发多次，但不能中奖多次。</p>

<p>所以如果处于当前中奖位置的网友已经中过奖，则跳过他顺次取下一位。</p>

<h4>输出格式</h4>

<p>按照输入的顺序输出中奖名单，每个昵称占一行。</p>

如果没有人中奖，则输出 <code>Keep going...</code>。
<h4>数据范围</h4>

$1 \le M \le 1000$

<h4>输入样例1：</h4>

<pre><code>
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
PickMe
Imgonnawin!
TryAgainAgain
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
2 3 5
Imgonnawin!
PickMe
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
Keep going...
</code></pre>

#### 1124 Raffle for Weibo Followers (20 point(s))
John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers M (≤ 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.

Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

#### Output Specification:
For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print Keep going... instead.

```cpp
```

### PAT单位排行 1141 PAT Ranking of Institutions (25 point(s))

<p>每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。</p>

<p>本题就请你实现这个功能。</p>

<h4>输入格式</h4>

输入第一行给出一个正整数 $N$，即考生人数。

随后 $N$ 行，每行按下列格式给出一个考生的信息：

<pre><code>
准考证号 得分 学校
</code></pre>

其中 <code>准考证号</code> 是由 $6$ 个字符组成的字符串，其首字母表示考试的级别：<code>B</code> 代表乙级，<code>A</code> 代表甲级，<code>T</code> 代表顶级；<code>得分</code> 是 $[0, 100]$ 区间内的整数；学校是由不超过 $6$ 个英文字母组成的单位码（大小写无关）。

<p>注意：题目保证每个考生的准考证号是不同的。</p>

<h4>输出格式</h4>

<p>首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：</p>

<pre><code>
排名 学校 加权总分 考生人数
</code></pre>

其中 <code>排名</code> 是该单位的排名（从 $1$ 开始）；<code>学校</code> 是<strong>全部按小写字母</strong>输出的单位码；<code>加权总分</code> 定义为 <code>乙级总分/1.5 + 甲级总分 + 顶级总分*1.5</code> 的<strong>整数部分</strong>；<code>考生人数</code> 是该属于单位的考生的总人数。

<p>学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序从小到大输出。</p>

<h4>数据范围</h4>

$1 \le N \le 10^5$

<h4>输入样例：</h4>

<pre><code>
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu
</code></pre>

<h4>输出样例：</h4>

<pre><code>
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
</code></pre>

#### 1141 PAT Ranking of Institutions (25 point(s))
After each PAT, the PAT Center will announce the ranking of institutions based on their students' performances. Now you are asked to generate the ranklist.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (≤10^5)$, which is the number of testees. Then N lines follow, each gives the information of a testee in the following format:
```
ID Score School
```

where ID is a string of 6 characters with the first one representing the test level: B stands for the basic level, A the advanced level and T the top level; Score is an integer in [0, 100]; and School is the institution code which is a string of no more than 6 English letters (case insensitive). Note: it is guaranteed that ID is unique for each testee.

#### Output Specification:
For each case, first print in a line the total number of institutions. Then output the ranklist of institutions in nondecreasing order of their ranks in the following format:
```
Rank School TWS Ns
```

where Rank is the rank (start from 1) of the institution; School is the institution code (all in lower case); ; TWS is the total weighted score which is defined to be the integer part of ScoreB/1.5 + ScoreA + ScoreT*1.5, where ScoreX is the total score of the testees belong to this institution on level X; and Ns is the total number of testees who belong to this institution.

The institutions are ranked according to their TWS. If there is a tie, the institutions are supposed to have the same rank, and they shall be printed in ascending order of Ns. If there is still a tie, they shall be printed in alphabetical order of their codes.

### 解码PAT准考证 1153 Decode Registration Card of PAT (25 point(s))

PAT 准考证号由 $4$ 部分组成：

- 第 $1$ 位是级别，即 <code>T</code> 代表顶级；<code>A</code> 代表甲级；<code>B</code> 代表乙级；
- 第 $2 \sim 4$ 位是考场编号，范围从 $101$ 到 $999$；
- 第 $5 \sim 10$ 位是考试日期，格式为年、月、日顺次各占 $2$ 位；
- 最后 $11 \sim 13$ 位是考生编号，范围从 $000$ 到 $999$。

现给定一系列考生的准考证号和他们的成绩，请你按照要求输出各种统计信息。

<h4>输入格式</h4>

输入首先在一行中给出两个正整数 $N$ 和 $M$，分别为考生人数和统计要求的个数。

接下来 $N$ 行，每行给出一个考生的准考证号和其分数（在区间 $[0,100]$ 内的整数），其间以空格分隔。

考生信息之后，再给出 $M$ 行，每行给出一个统计要求，格式为：<code>类型 指令</code>，其中

- <code>类型</code> 为 $1$ 表示要求按分数非升序输出某个指定级别的考生的成绩，对应的 <code>指令</code> 则给出代表指定级别的字母；
- <code>类型</code> 为 $2$ 表示要求将某指定考场的考生人数和总分统计输出，对应的 <code>指令</code> 则给出指定考场的编号；
- <code>类型</code> 为 $3$ 表示要求将某指定日期的考生人数分考场统计输出，对应的 <code>指令</code> 则给出指定日期，格式与准考证上日期相同。

<h4>输出格式</h4>

对每项统计要求，首先在一行中输出 <code>Case #: 要求</code>，其中 <code>#</code> 是该项要求的编号，从 $1$ 开始；<code>要求</code> 即复制输入给出的要求。随后输出相应的统计结果：

- <code>类型</code> 为 1 的指令，输出格式与输入的考生信息格式相同，即 <code>准考证号 成绩</code>。对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）；
- <code>类型</code> 为 2 的指令，按 <code>人数 总分</code> 的格式输出；
- <code>类型</code> 为 3 的指令，输出按人数非递增顺序，格式为 <code>考场编号 总人数</code>。若人数并列则按考场编号递增顺序输出。
<p>如果查询结果为空，则输出 <code>NA</code>。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^4$,
- $1 \le M \le 100$

<h4>输入样例：</h4>

<pre><code>
8 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
1 A
2 107
3 180908
2 999
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Case 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
Case 2: 2 107
3 260
Case 3: 3 180908
107 2
123 2
102 1
Case 4: 2 999
NA
</code></pre>

#### 1153 Decode Registration Card of PAT (25 point(s))
A registration card number of PAT consists of 4 parts:

- the 1st letter represents the test level, namely, T for the top level, A for advance and B for basic;
- the 2nd - 4th digits are the test site number, ranged from 101 to 999;
- the 5th - 10th digits give the test date, in the form of yymmdd;
- finally the 11th - 13th digits are the testee's number, ranged from 000 to 999.

Now given a set of registration card numbers and the scores of the card owners, you are supposed to output the various statistics according to the given queries.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N $(≤10^4)$ and M (≤100), the numbers of cards and the queries, respectively.

Then N lines follow, each gives a card number and the owner's score (integer in [0,100]), separated by a space.

After the info of testees, there are M lines, each gives a query in the format Type Term, where

- Type being 1 means to output all the testees on a given level, in non-increasing order of their scores. The corresponding Term will be the letter which specifies the level;
- Type being 2 means to output the total number of testees together with their total scores in a given site. The corresponding Term will then be the site number;
- Type being 3 means to output the total number of testees of every site for a given test date. The corresponding Term will then be the date, given in the same format as in the registration card.

#### Output Specification:
For each query, first print in a line Case #: input, where # is the index of the query case, starting from 1; and input is a copy of the corresponding input query. Then output as requested:

- for a type 1 query, the output format is the same as in input, that is, CardNumber Score. If there is a tie of the scores, output in increasing alphabetical order of their card numbers (uniqueness of the card numbers is guaranteed);
- for a type 2 query, output in the format Nt Ns where Nt is the total number of testees and Ns is their total score;
- for a type 3 query, output in the format Site Nt where Site is the site number and Nt is the total number of testees at Site. The output must be in non-increasing order of Nt's, or in increasing order of site numbers if there is a tie of Nt.

If the result of a query is empty, simply print NA.

```cpp

```
