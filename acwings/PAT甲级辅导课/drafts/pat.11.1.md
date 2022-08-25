
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [电梯 1008 Elevator (20 point(s))](#电梯-1008-elevator-20-points)
- [世界杯投注 1011 World Cup Betting (20 point(s))](#世界杯投注-1011-world-cup-betting-20-points)
- [排队等候 1014 Waiting in Line (30 point(s))](#排队等候-1014-waiting-in-line-30-points)
- [U 形 Hello World 1031 Hello World for U (20 point(s))](#u-形-hello-world-1031-hello-world-for-u-20-points)
- [独一无二 1041 Be Unique (20 point(s))](#独一无二-1041-be-unique-20-points)
- [洗牌机 1042 Shuffling Machine (20 point(s))](#洗牌机-1042-shuffling-machine-20-points)
- [课程学生列表 1047 Student List for Course (25 point(s))](#课程学生列表-1047-student-list-for-course-25-points)
- [主导颜色 1054 The Dominant Color (20 point(s))](#主导颜色-1054-the-dominant-color-20-points)

<!-- /code_chunk_output -->

### 电梯 1008 Elevator (20 point(s))

<p>我们城市的最高建筑上只有一部电梯。</p>

给定一个由 $N$ 个整数组成的请求列表。

我们要按照列表指定的顺序，将电梯依次停到各个楼层。

已知，电梯上行一层需要 $6$ 秒，下行一层需要 $4$ 秒，每个停留楼层每次停留 $5$ 秒。

<p>请你求出，将列表给出的所有楼层都按指定顺序完成停留共需多少秒。</p>

电梯开始时位于第 $0$ 层，所有楼层均停留完毕后，电梯不用回归原位置。

<h4>补充</h4>

<p>可能存在连续在同一楼层停留多次的情况，此时每停留一次就要等待5秒钟。</p>

<h4>输入格式</h4>

共一行，首先包含一个整数 $N$，然后包含 $N$ 个正数。

<h4>输出格式</h4>

<p>输出一个整数，表示所花费的总时间。</p>

<h4>数据范围</h4>

- $1 \le N \le 100$,
- 列表中的数字不会超过 $100$。

<h4>输入样例：</h4>

<pre><code>
3 2 3 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
41
</code></pre>

#### 1008 Elevator (20 point(s))
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

#### Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

#### Output Specification:
For each test case, print the total time on a single line.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    int last = 0;
    while (n -- )
    {
        int cur;
        cin >> cur;

        if (last < cur) res += (cur - last) * 6;
        else res += (last - cur) * 4;
        res += 5;

        last = cur;
    }

    cout << res << endl;

    return 0;
}
```

### 世界杯投注 1011 World Cup Betting (20 point(s))

随着 $2010$ 年FIFA世界杯的举办，世界各地的足球迷变得越来越兴奋，因为来自各个顶级队伍的顶级球员们正在为南非的世界杯奖杯而战。

<p>同样，足球投注迷们也拿出了大把的金钱，投入到了各种形式的世界杯投注之中。</p>

<p>中国足球彩票提供了一种叫做“三连胜”的游戏。</p>

获胜的规则很简单：首先选择其中三场比赛。 然后，对于每个选定的比赛，下注三个可能的结果之一----$W$ 代表胜利，$T$ 代表平局，$L$ 代表失败。 每个结果都有一个赔率。 获胜者（三场都压中结果）的赔率将是三个下注结果的赔率的乘积乘以 $65\%$ 以后得到的值。

<p>例如，以下是三场比赛的赔率：</p>

<pre><code>
 W    T    L
1.1  2.5  1.7
1.2  3.1  1.6
4.1  1.2  1.1
</code></pre>

<p>为了获得最大的利润，我们需要在前两场买平局，第三场买胜利。</p>

如果投注 $2$ 元，那么最大利润将是 $(4.1×3.1×2.5×65\%−1)×2 = 39.31$元（最多 $2$ 位小数）。

<h4>输入格式</h4>

输入共三行，每行包含三个浮点数，分别表示一场比赛的胜利($W$)，平局($T$)，失败($L$)的赔率。

<h4>输出格式</h4>

输出共一行，先输出可获得最大利润的投注方式，即三场比赛分别投注什么结果（用字母表示），再输出可获得的最大利润（在投注 $2$ 元的情况下），注意结果保留两位小数。

<h4>数据范围</h4>

- 每场比赛每个结果的赔率都是正数，且不会超过 $5$。
- 同一场比赛的三个结果的赔率不可能相同。

<h4>输入样例：</h4>

<pre><code>
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
T T W 39.31
</code></pre>

#### 1011 World Cup Betting (20 point(s))
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:
```
 W    T    L
1.1  2.5  1.7
1.2  3.1  1.6
4.1  1.2  1.1
```
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be $(4.1×3.1×2.5×65\%−1)×2 = 39.31$ yuans (accurate up to 2 decimal places).

#### Input Specification:
Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

#### Output Specification:
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

```cpp
// 就是个阅读理解

#include <iostream>

using namespace std;

int main()
{
    double res = 1;
    for (int i = 0; i < 3; i ++ )
    {
        double w, t, l;
        cin >> w >> t >> l;
        double x = max(w, max(t, l));
        if (x == w) cout << "W ";  // 用这种方式判断最大
        else if (x == t) cout << "T ";
        else cout << "L ";
        res *= x;
    }

    printf("%.2lf\n", (res * 0.65 - 1) * 2);

    return 0;
}
```

### 排队等候 1014 Waiting in Line (30 point(s))

假设一家银行有 $N$ 个服务窗口。

<p>窗户前面有一条黄线，将等候区分为两部分。</p>

<p>客户排队等候的规则是：</p>

- 在黄线以内的区域，每个窗口前都可以排一队人，每队最多可以排 $M$ 个人，当 $N$ 个窗口前的队伍都排满时，第 $NM+1$ 个顾客以及以后的顾客只能在黄线以外的区域等候。黄线外的所有客户统一排成一个长队。
- 每当客户进入黄线以内时，他会选择到当前排队人数最少的窗口处排队等待办理业务。当多个窗口前排队人数最少时，客户会选择窗口编号更小的窗口处排队等待办理业务。
- 第 $i$ 名客户的办理业务时长为 $T_i$。
- 最开始的 $N$ 名客户将于早上 <code>08:00</code> 被受理业务。

<p>现在，给定所有客户办理业务所需的时间，并对你进行若干次询问，每次询问一名客户办理完自身业务时的确切时间。</p>

例如，假设银行共有 $2$ 个服务窗口，每个窗口内可以有两名客户排在黄线以内。

现在共有 $5$ 名客户等待办理业务，他们的业务时长分别为 $1,2,6,4,3$ 分钟。

早上 <code>08:00</code> 时，客户 $1$ 在窗口 $1$ 接受服务，客户 $2$ 在窗口 $2$ 接受服务，客户 $3$ 在窗口 $1$ 前等待，客户 $4$ 在窗口 $2$ 前等待，客户 $5$ 在黄线以外等待。

在 <code>08:01</code>，客户 $1$ 办完业务，客户 $5$ 进入黄线以内，并于窗口 $1$ 前等待。

客户 $2$ 将于 <code>08:02</code> 办完业务，客户 $4$ 将于 <code>08:06</code> 办完业务，客户 $3$ 将于 <code>08:07</code> 办完业务，客户 $5$ 将于 <code>08:10</code> 办完业务。

<h4>输入格式</h4>

第一行包含 $4$ 个整数，$N,M,K,Q$，分别表示窗口总数，黄线内每个队伍的最大长度，客户总数，询问次数。

第二行包含 $K$ 个整数，表示每个客户办理业务的所需时长（单位：分钟）。

第三行包含 $Q$ 个整数，表示询问的所有客户的编号。

客户编号从 $1$ 到 $K$。

<h4>输出格式</h4>

<p>对于每个询问的客户，输出其办理完业务的确切时间，格式为 <code>HH:MM</code>。</p>

<p>注意，银行 <code>17:00</code> 就会停止受理新的业务，所以对于<strong>不能在 17:00 之前（即最晚可以开始服务的时间是16:59）</strong>开始办理业务的客户，要输出 <code>Sorry</code>。</p>

<h4>数据范围</h4>

- $1 \le N \le 20$,
- $1 \le M \le 10$,
- $1 \le K \le 1000$,
- $1 \le Q \le K$

<h4>输入样例：</h4>

<pre><code>
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
</code></pre>

<h4>输出样例：</h4>

<pre><code>
08:07
08:06
08:10
17:00
Sorry
</code></pre>

#### 1014 Waiting in Line (30 point(s))
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

- The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
- Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
- $Customer_i$ will take $T_i$ minutes to have his/her transaction processed.
- The first N customers are assumed to be served at 8:00am.

Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, $customer_1$ is served at $window_1$ while $customer_2$ is served at $window_2$. $Customer_3$ will wait in front of $window_1$ and $customer_4$ will wait in front of $window_2$. $Customer_5$ will wait behind the yellow line.

At 08:01, $customer_1$ is done and $customer_5$ enters the line in front of $window_1$ since that line seems shorter now. $Customer_2$ will leave at 08:02, $customer_4$ at 08:06, $customer_3$ at 08:07, and finally $customer_5$ at 08:10.

#### Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line), K (≤1000, number of customers), and Q (≤1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

#### Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

```cpp
#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 20;

int n, m, k, Q;
int sum[N];
queue<int> q[N];  // N 个窗口对应 N 个队列，保存完成时间

int main()
{
    cin >> n >> m >> k >> Q;

    unordered_map<int, int> hash;
    for (int i = 1; i <= k; i ++ )
    {
        int s;
        cin >> s;

        int t = 0;
        for (int j = 0; j < n; j ++ )  // 找最短的窗口
            if (i <= n * m)  // 如果顾客可以直接进入黄线内
            {
                if (q[j].size() < q[t].size()) t = j;  // 把最短的队伍找到
            }
            else  // 否则如果黄线内都满了
            {
                if (q[j].front() < q[t].front()) t = j;  // 把最快结束的窗口找到
            }

        sum[t] += s;  // 当前窗口服务时间 + s
        if (i > n * m) q[t].pop();  // 对于 i > n * m ，其能入队，一定是因为有人已经服务完了（有人出队）
        q[t].push(sum[t]);  // 这个队伍加入当前这人的完成时间

        if (sum[t] - s < 540) hash[i] = sum[t];  // 是否在 540 之前开始服务
    }

    while (Q -- )
    {
        int id;
        cin >> id;
        if (hash.count(id)) printf("%02d:%02d\n", hash[id] / 60 + 8, hash[id] % 60);
        else puts("Sorry");
    }

    return 0;
}
```

### U 形 Hello World 1031 Hello World for U (20 point(s))

给定一个长度为 $N$ 的字符串，请你将它以 $U$ 形输出。

<p>例如，<code>helloworld</code> 可以输出为：</p>

<pre><code>
h  d
e  l
l  r
lowo
</code></pre>

也就是说，必须按照原始顺序输出字符，左垂直线自上而下共有 $n_1$ 个字符，底部行从左到右共有 $n_2$ 个字符，右垂直线自下而上共有 $n_3$ 个字符。

另外，必须满足 $n_1 = n_3 = max \lbrace k | k \le n_2 对于所有 3 \le n_2 \le N \rbrace$ 以及 $n_1+n_2+n_3-2=N$。

对于 <code>helloworld</code>，$n_1 = n_2 = n_3 = 4$。

<h4>输入格式</h4>

包含一个长度不少于 $5$ 且不超过 $80$ 的字符串，字符串内不含空格。

<h4>输出格式</h4>

输出转化为 $U$ 形后的图案。

<h4>输入样例：</h4>

<pre><code>
helloworld!
</code></pre>

<h4>输出样例：</h4>

<pre><code>
h   !
e   d
l   l
lowor
</code></pre>

#### 1031 Hello World for U (20 point(s))
Given any string of N (≥5) characters, you are asked to form the characters into the shape of U. For example, helloworld can be printed as:
```
h  d
e  l
l  r
lowo
```
That is, the characters must be printed in the original order, starting top-down from the left vertical line with $n_1$ characters, then left to right along the bottom line with $n_2$ characters, and finally bottom-up along the vertical line with $n_3$ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that $n_1 = n_3 = max \lbrace k | k \le n_2 \; for \; all \; 3 \le n_2 \le N \rbrace$ with $n_1+n_2+n_3-2=N$.

#### Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

#### Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

```cpp
// n1 小于等于 n2
// 2n1 + n2 - 2 ≤ N
// 所以有 3n1 - 2 ≤ 2n1 + n2 - 2 ≤ N
// 所以 n1 = (N + 2) / 3
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

char g[N][N];

int main()
{
    string str;
    cin >> str;

    int n = str.size();
    int n1 = (n + 2) / 3;
    int n2 = n + 2 - n1 * 2;

    int k = 0;
    for (int i = 0; i < n1; i ++ ) g[i][0] = str[k ++ ];
    for (int i = 1; i < n2; i ++ ) g[n1 - 1][i] = str[k ++ ];
    for (int i = n1 - 2; i >= 0; i -- ) g[i][n2 - 1] = str[k ++ ];

    for (int i = 0; i < n1; i ++ )
    {
        for (int j = 0; j < n2; j ++ )
            if (g[i][j]) cout << g[i][j];
            else cout << ' ';
        cout << endl;
    }

    return 0;
}
```

### 独一无二 1041 Be Unique (20 point(s))

<p>对于火星人来说，保持独一无二非常的重要。</p>

<p>以至于他们的彩票都是以独特的方式设计的。</p>

中奖规则十分简单，每一个买彩票的人选中一个范围在 $[1,10^4]$ 的数字，将所有数字按购买顺序排成一排。

数列中，只出现过一次且排位最靠前的那个数字就是中奖号码。

例如，$7$ 个人购买了彩票，所买数字依次是 <code>5 31 5 88 67 88 17</code>，则第二个数字 <code>31</code> 为中奖号码。

<h4>输入格式</h4>

共一行，首先包含一个整数 $N$，表示共有 $N$ 个投注号码，然后跟随 $N$ 个数字，表示投注号码。

<p>数字之间用空格隔开。</p>

<h4>输出格式</h4>

<p>输出中奖号码。</p>

<p>如果没人中奖，则输出 <code>None</code>。</p>

<h4>数据范围</h4>

$1 \le N \le 10^5$

<h4>输入样例1：</h4>

<pre><code>
7 5 31 5 88 67 88 17
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
31
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
5 888 666 666 888 888
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
None
</code></pre>

#### 1041 Be Unique (20 point(s))
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from $[1,10^4]$. The first one who bets on a unique number wins. For example, if there are 7 people betting on `{ 5 31 5 88 67 88 17 }`, then the second one who bets on 31 wins.

#### Input Specification:
Each input file contains one test case. Each case contains a line which begins with a positive integer $N (≤10^5)$ and then followed by N bets. The numbers are separated by a space.

#### Output Specification:
For each test case, print the winning number in a line. If there is no winner, print None instead.

```cpp
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], c[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> a[i];
        c[a[i]] ++ ;
    }

    for (int i = 0; i < n; i ++ )
        if (c[a[i]] == 1)
        {
            cout << a[i] << endl;
            return 0;
        }

    puts("None");
    return 0;
}
```

### 洗牌机 1042 Shuffling Machine (20 point(s))

<p>洗牌就是将一副牌的顺序打乱。</p>

<p>为了防止员工洗牌不够彻底或者员工串通赌徒出老千，许多娱乐场都用自动洗牌机来洗牌。</p>

洗牌机会根据一套随机产生的打乱顺序，将一套牌（$54$ 张）进行若干次的洗牌操作。

<p>假设一副牌的<strong>最开始</strong>时按如下顺序排列：</p>

<pre><code>
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
</code></pre>

其中，$S$ 表示黑桃，$H$ 表示红桃，$C$ 表示草花，$D$ 表示方块，$J$ 表示小丑。

给定一个 $1 \sim 54$ 的排列表示打乱顺序，如果第 $i$ 个位置的数字是 $j$，则意味着现在处于位置 $i$ 的卡牌在洗牌结束后要出现在位置 $j$。

假设我们一共只有 $5$ 张卡牌，<code>S3, H5, C1, D13, J2</code>，给定的打乱顺序为 <code>{4, 2, 5, 3, 1}</code>。

洗牌一次后，卡牌顺序变为 <code>J2, H5, D13, S3, C1</code>，再洗一次，卡牌顺序变为 <code>C1, H5, S3, J2, D13</code>。

<h4>输入格式</h4>

第一行包含整数 $K$，表示洗牌次数。

第二行包含一个 $1 \sim 54$ 的排列，表示打乱顺序。

<h4>输出格式</h4>

<p>输出洗牌完成后的最终卡牌顺序。</p>

<p>占一行。</p>

<h4>数据范围</h4>

$K \le 20$

<h4>输入样例：</h4>

<pre><code>
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
</code></pre>

<h4>输出样例：</h4>

<pre><code>
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
</code></pre>

#### 1042 Shuffling Machine (20 point(s))
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:
```
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
```

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer K (≤20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 60;

int k;
int q[N], p[N], w[N];

void print(int x)
{
    if (x <= 13) cout << 'S' << x;
    else if (x <= 26) cout << 'H' << x - 13;
    else if (x <= 39) cout << 'C' << x - 26;
    else if (x <= 52) cout << 'D' << x - 39;
    else cout << 'J' << x - 52;
}

int main()
{
    cin >> k;
    for (int i = 1; i <= 54; i ++ ) cin >> q[i];
    for (int i = 1; i <= 54; i ++ ) p[i] = i;

    while (k -- )
    {
        memcpy(w, p, sizeof w);  // 把现有排列 p 记录下来为 w
        for (int i = 1; i <= 54; i ++ ) p[q[i]] = w[i];  // 根据 q 更新 p
    }

    for (int i = 1; i <= 54; i ++ )
    {
        print(p[i]);
        if (i != 54) cout << ' ';
    }

    return 0;
}
```

### 课程学生列表 1047 Student List for Course (25 point(s))

浙江大学有 $40000$ 名学生，提供 $2500$ 门课程。

<p>现在给定每个学生的选课列表。</p>

<p>请你统计，每门课程的学生报名情况。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $K$，分别表示学生总数和课程总数。

接下来 $N$ 行，每行包含一个学生的选课列表，首先包含学生姓名（三个大写字母加一位数字），然后包含一个整数 $C$，表示该学生报课总数，接下来包含 $C$ 个整数，表示所报课程编号。

所有课程编号为 $1 \sim K$。

<h4>输出格式</h4>

<p>按照课程编号升序的顺序输出每一门课的报名情况。</p>

<p>每门课输出信息时，第一行包含两个整数，分别表示课程编号以及报名人数。</p>

<p>接下来若干行，按字典序输出报名的具体人员姓名，每个姓名占一行。</p>

<h4>数据范围</h4>

- $1 \le N \le 40000$,
- $1 \le K \le 2500$,
- $1 \le C \le 20$,

<h4>输入样例：</h4>

<pre><code>
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
</code></pre>

<h4>输出样例：</h4>

<pre><code>
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
</code></pre>

#### 1047 Student List for Course (25 point(s))
Zhejiang University has 40,000 students and provides 2,500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤40,000), the total number of students, and K (≤2,500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (≤20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

#### Output Specification:
For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2510;

int n, k;
vector<string> lesson[N];  // 相当于哈希映射

int main()
{
    scanf("%d%d", &n, &k);

    char str[5];
    while (n -- )
    {
        int cnt;
        scanf("%s %d", str, &cnt);
        while (cnt -- )
        {
            int l;
            scanf("%d", &l);
            lesson[l].push_back(str);
        }
    }

    for (int i = 1; i <= k; i ++ )
    {
        printf("%d %d\n", i, lesson[i].size());
        sort(lesson[i].begin(), lesson[i].end());
        for (auto id : lesson[i])
            printf("%s\n", id.c_str());
    }

    return 0;
}
```

### 主导颜色 1054 The Dominant Color (20 point(s))

给定一个分辨率为 $M \times N$ 的屏幕，每个像素都有一个颜色，如果超过一半的像素都显示同一种颜色，则这个颜色就称之为主导颜色。

<p>现在，请你确定屏幕的主导颜色。</p>

<h4>输入格式</h4>

第一行包含两个整数 $M$ 和 $N$。

接下来 $N$ 行，每行包含 $M$ 个数字，每个数字表示一种颜色。

<h4>输出格式</h4>

<p>输出一个整数，表示主导颜色的编号。</p>

<h4>数据范围</h4>

- $1 \le M \le 800$,
- $1 \le N \le 600$,
- 颜色编号取值在 $[0,2^{24})$ 范围内，
- 数据保证主导颜色一定存在。

<h4>输入样例：</h4>

<pre><code>
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
</code></pre>

<h4>输出样例：</h4>

<pre><code>
24
</code></pre>

#### 1054 The Dominant Color (20 point(s))
Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range $[0,2^24)$. It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, simply print the dominant color in a line.

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    unordered_map<int, int> cnt;
    for (int i = 0; i < n * m; i ++ )
    {
        int x;
        scanf("%d", &x);
        if ( ++ cnt[x] > n * m / 2)
        {
            // 在线就判断了
            printf("%d\n", x);
            break;
        }
    }

    return 0;
}
```
