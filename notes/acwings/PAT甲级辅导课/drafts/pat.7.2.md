
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [卡住的键盘 1112 Stucked Keyboard (20 point(s))](#卡住的键盘-1112-stucked-keyboard-20-points)
- [C 语言竞赛 1116 Come on! Let's C (20 point(s))](#c-语言竞赛-1116-come-on-lets-c-20-points)
- [谷歌的招聘 1152 Google Recruitment (20 point(s))](#谷歌的招聘-1152-google-recruitment-20-points)

<!-- /code_chunk_output -->

### 卡住的键盘 1112 Stucked Keyboard (20 point(s))

<p>在一个损坏的键盘上，某些键总是被卡住。</p>

因此，当你用该键盘输入一些句子时，与这些键相对应的字符将在屏幕上重复出现 $k$ 次。

现在，给定 $k$ 以及最终屏幕显示的结果字符串，请你找出所有可能坏掉的按键，并给出原始字符串。

<p>注意，有些字符可能被重复键入。</p>

每当卡住的按键被按下时，其对应的字符将固定被输出 $k$ 次。

例如，当 $k=3$ 时，从字符串 <code>thiiis iiisss a teeeeeest</code>，我们可以推断出 <code>i</code> 和 <code>e</code> 可能被卡住了，但是 <code>s</code> 并没有被卡住，尽管它也重复出现过。

<p>所以，原始字符串可能是 <code>this isss a teest</code>。</p>

<h4>输入格式</h4>

第一行包含整数 $k$。

<p>第二行包含屏幕中显示的结果字符串，字符串中只包含 <code>{a-z}, {0-9}, _</code>。</p>

<h4>输出格式</h4>

<p>按照检测顺序在一行中输出所有可能卡住的按键，每个按键只需输出一次。</p>

<p>第二行输出原始字符串。</p>

<h4>数据范围</h4>

- $2 \le k \le 100$,
- 输入字符串非空且长度不超过 $1000$,
- 至少包含一个卡住的按键。

<h4>输入样例：</h4>

<pre><code>
3
caseee1__thiiis_iiisss_a_teeeeeest
</code></pre>

<h4>输出样例：</h4>

<pre><code>
ei
case1__this_isss_a_teest
</code></pre>

#### 1112 Stucked Keyboard (20 point(s))
On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string thiiis iiisss a teeeeeest we know that the keys i and e might be stucked, but s is not even though it appears repeatedly sometimes. The original string could be this isss a teest.

#### Input Specification:
Each input file contains one test case. For each case, the 1st line gives a positive integer $k (1<k≤100)$ which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from `{a-z}`, `{0-9}` and `_`. It is guaranteed that the string is non-empty.

#### Output Specification:
For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200;

int st[N];

int main()
{
    int k;
    string str;
    cin >> k >> str;

    for (int i = 0; i < str.size(); i ++ )
    {
        int j = i + 1;
        while (j < str.size() && str[j] == str[i]) j ++ ;
        int len = j - i;
        if (len % k) st[str[i]] = 1;  // 1 表示 str[i] 不可能是坏的
        i = j - 1;
    }

    string res;
    for (int i = 0; i < str.size(); i ++ )
    {
        if (!st[str[i]]) cout << str[i], st[str[i]] = 2;  // 2表示可能是坏的，且已经被输出

        if (st[str[i]] == 1) res += str[i];
        else
        {
            res += str[i];
            i += k - 1;  // 坏的，为什么跳 k-1 ？因为后面又 i ++
        }
    }

    cout << endl << res << endl;

    return 0;
}
```

### C 语言竞赛 1116 Come on! Let's C (20 point(s))

<p>C 语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：</p>

- 0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
- 1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
- 2、其他人将得到巧克力。

<p>给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。</p>

<h4>输入格式</h4>

第一行包含整数 $N$，表示参赛者人数。

随后 $N$ 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（$4$ 位数字组成）。

然后一行给出 $K$，表示查询人数。

接下来 $K$ 行，每行给出一个需要查询的 ID。

<h4>输出格式</h4>

<p>对每个要查询的 ID，在一行中输出 <code>ID: 奖品</code>，其中奖品或者是 <code>Mystery Award</code>（神秘大奖）、或者是 <code>Minion</code>（小黄人）、或者是 <code>Chocolate</code>（巧克力）。</p>

<p>如果所查 ID 根本不在排名里，打印 <code>Are you kidding?</code>（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 <code>ID: Checked</code>（不能多吃多占）。</p>

<h4>数据范围</h4>

$1 \le N,K \le 10^4$,

<h4>输入样例：</h4>

<pre><code>
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
</code></pre>

<h4>输出样例：</h4>

<pre><code>
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
</code></pre>

#### 1116 Come on! Let's C (20 point(s))
"Let's C" is a popular and fun programming contest hosted by the College of Computer Science and Technology, Zhejiang University. Since the idea of the contest is for fun, the award rules are funny as the following:

- 0、 The Champion will receive a "Mystery Award" (such as a BIG collection of students' research papers...).
- 1、 Those who ranked as a prime number will receive the best award -- the Minions (小黄人)!
- 2、 Everyone else will receive chocolates.

Given the final ranklist and a sequence of contestant ID's, you are supposed to tell the corresponding awards.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (≤10^4)$, the total number of contestants. Then N lines of the ranklist follow, each in order gives a contestant's ID (a 4-digit number). After the ranklist, there is a positive integer K followed by K query ID's.

#### Output Specification:
For each query, print in a line ID: award where the award is Mystery Award, or Minion, or Chocolate. If the ID is not in the ranklist, print Are you kidding? instead. If the ID has been checked before, print ID: Checked.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010;

int Rank[N];
int st[N];

void init()  // 筛法求质数
{
    for (int i = 2; i < N; i ++ )
        if (!st[i])  // 有没有被筛过
        {
            st[i] = 1;
            for (int j = i * 2; j < N; j += i)  // 把其倍数筛掉
                st[j] = 2;
        }
}

int main()
{
    init();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int id;
        cin >> id;
        Rank[id] = i;
    }

    int k;
    cin >> k;
    while (k -- )
    {
        int id;
        cin >> id;

        printf("%04d: ", id);
        if (!Rank[id]) puts("Are you kidding?");
        else if (Rank[id] == -1) puts("Checked");
        else
        {
            int t = st[Rank[id]];
            if (t == 0) puts("Mystery Award");  // 1 的话 st[1] 是 0
            else if (t == 1) puts("Minion");  // 素数
            else puts("Chocolate");

            Rank[id] = -1;  // 别忘了标记
        }
    }

    return 0;
}
```

### 谷歌的招聘 1152 Google Recruitment (20 point(s))

$2004$ 年 $7$ 月，谷歌在硅谷的 $101$ 号公路边竖立了一块巨大的广告牌（如下图）用于招聘。

内容超级简单，就是一个以 <code>.com</code> 结尾的网址，而前面的网址是一个 $10$ 位素数，这个素数是自然常数 $e$ 中最早出现的 $10$ 位连续数字。

<p>能找出这个素数的人，就可以通过访问谷歌的这个网站进入招聘流程的下一步。</p>

![](./images/2021082802.jpg)

自然常数 $e$ 是一个著名的超越数，前面若干位写出来是这样的：
- e = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642<strong>7427466391</strong>932003059921...
- 其中粗体标出的 $10$ 位数就是答案。

本题要求你编程解决一个更通用的问题：从任一给定的长度为 $L$ 的数字中，找出最早出现的 $K$ 位连续数字所组成的素数。

<h4>输入格式</h4>

输入在第一行给出 $2$ 个正整数，分别是 $L$ 和 $K$。

接下来一行给出一个长度为 $L$ 的正整数 $N$。

<h4>输出格式</h4>

在一行中输出 $N$ 中最早出现的 $K$ 位连续数字所组成的素数。

如果这样的素数不存在，则输出 $404$。

<p>注意，原始数字中的前导零也计算在位数之内。</p>

例如在 $200236$ 中找 $4$ 位素数，$0023$ 算是解；但第一位 $2$ 不能被当成 $0002$ 输出，因为在原始数字中不存在这个 $2$ 的前导零。

<h4>数据范围</h4>

- $1 \le L \le 1000$,
- $1 \le K < 10$

<h4>输入样例1：</h4>

<pre><code>
20 5
23654987725541023819
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
49877
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
10 3
2468024680
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
404
</code></pre>

#### 1152 Google Recruitment (20 point(s))
In July 2004, Google posted on a giant billboard along Highway 101 in Silicon Valley (shown in the picture below) for recruitment. The content is super-simple, a URL consisting of the first 10-digit prime found in consecutive digits of the natural constant e. The person who could find this prime number could go to the next step in Google's hiring process by visiting this website.

![prime.jpg](./images/2021082802.jpg)

The natural constant e is a well known transcendental number（超越数）. The first several digits are: e = 2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642<strong>7427466391</strong>932003059921...where the 10 digits in bold are the answer to Google's question.

Now you are asked to solve a more general problem: find the first K-digit prime in consecutive digits of any given L-digit number.

#### Input Specification:
Each input file contains one test case. Each case first gives in a line two positive integers: L (≤ 1,000) and K (< 10), which are the numbers of digits of the given number and the prime to be found, respectively. Then the L-digit number N is given in the next line.

#### Output Specification:
For each test case, print in a line the first K-digit prime in consecutive digits of N. If such a number does not exist, output 404 instead. Note: the leading zeroes must also be counted as part of the K digits. For example, to find the 4-digit prime in 200236, 0023 is a solution. However the first digit 2 must not be treated as a solution 0002 since the leading zeroes are not in the original number.


```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 40000;

int n, k;
bool st[M];
int primes[M], cnt;

void init()
{
    for (int i = 2; i < M; i ++ )
        if (!st[i])
        {
            primes[cnt ++ ] = i;  // 筛法求素数
            for (int j = i * 2; j < M; j += i)
                st[j] = true;
        }
}

bool check(int x)
{
    for (int i = 0; primes[i] <= x / primes[i]; i ++ )
        if (x % primes[i] == 0)  // 是任何一个小于等于sqrt(x)的素数的倍数，则不是素数
            return false;
    return true;
}

int main()
{
    init();

    string str;
    cin >> n >> k >> str;

    for (int i = 0; i + k <= n; i ++ )
    {
        int t = stoi(str.substr(i, k));  // 遍历每个数
        if (check(t))
        {
            cout << str.substr(i, k) << endl;
            return 0;
        }
    }

    puts("404");

    return 0;
}
```
