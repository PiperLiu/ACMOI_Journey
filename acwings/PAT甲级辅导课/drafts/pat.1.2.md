
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [约会 1061 Dating (20 point(s))](#约会-1061-dating-20-points)
- [电话账单 1016 Phone Bills (25 point(s))](#电话账单-1016-phone-bills-25-points)
- [银行排队 1017 Queueing at Bank (25 point(s))](#银行排队-1017-queueing-at-bank-25-points)
- [乒乓球 1026 Table Tennis (30 point(s))](#乒乓球-1026-table-tennis-30-points)

<!-- /code_chunk_output -->

### 约会 1061 Dating (20 point(s))

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

    k ++ ;  // 注意：“位于代表日期的字符后面的，第一对相同的”
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

### 电话账单 1016 Phone Bills (25 point(s))

<p>长途电话公司按以下规则向客户收费：</p>

<p>拨打长途电话每分钟要花费一定的费用，具体收费取决于拨打电话的时间。 </p>

<p>客户开始拨打长途电话的时间将被记录，客户挂断电话的时间也将被记录。 </p>

<p>每个月都要给客户发送一次话费账单，账单中应包含每次通话记录以及相关收费等信息。 </p>

<p>给定一组电话记录，你的工作是为客户准备帐单。</p>

<h4>输入格式</h4>

<p>输入包含两部分：费率结构和电话记录。</p>

<p>费率结构由一行组成，该行包含24个非负整数，分别表示从 <code>00:00-01:00</code> 的收费（分/分钟），从 <code>01:00-02:00</code> 的收费，以此类推...</p>

下一行包含一个正整数 $N$。

接下来 $N$ 行，每行包含一条记录。

每个记录由客户名称（最多 $20$ 个字符的字符串，不带空格），时间和日期（<code>mm:dd:hh:mm</code>）以及单词 <code>on-line</code> 或 <code>off-line</code> 组成。

<p>所有日期都在同一个月内，每个 <code>on-line</code> 记录都与<strong>按时间顺序排列</strong>的同一位客户的下一条记录配对，但<strong>前提</strong>是这条记录是 <code>off-line</code>。</p>

<p>所有未与 <code>off-line</code> 记录配对的 <code>on-line</code> 记录以及未与 <code>on-line</code> 记录配对的 <code>off-line</code> 记录都必须忽略。</p>

<p>输入中至少包含一个成功的配对。</p>

<p>同一客户在同一时间不会有两个或以上的电话记录。</p>

使用 $24$ 小时制记录时间。

<h4>输出格式</h4>

<p>你需要为每个客户打印电话费。</p>

<p>账单必须按照客户姓名的字母顺序（按ASCII码顺序，大写字母在前，小写字母在后）打印。</p>

<p>对于每个客户，首先以示例显示的格式在一行中打印客户名称和帐单月份。</p>

<p>然后，对于每个通话时间段，在一行中分别打印开始和结束时间和日期（<code>dd:hh:mm</code>），持续时间（以分钟为单位）和通话费用。</p>

<p>通话必须按时间顺序列出。</p>

<p>最后，以示例显示的格式打印该月的总费用。</p>

<p>注意，没有任何有效通话记录的客户直接忽略，不予打印账单。</p>

<h4>数据范围</h4>

$1 \le N \le 1000$

<h4>输入样例：</h4>

<pre><code>
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
</code></pre>

<h4>输出样例：</h4>

<pre><code>
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
</code></pre>

#### 1016 Phone Bills (25 point(s))

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

#### Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (MM:dd:HH:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

#### Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:HH:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int N = 1010;
const int M = 31 * 1440 + 10;

int n;
int cost[24];
double sum[M];  // 费用前缀和，以分钟为单位

struct Record
{
    int minutes;  // 本月第几分钟
    string state;  // on-line 还是 off-line
    string format_time;  // 输入的时间
    
    bool operator< (const Record& t) const
    {
        return minutes < t.minutes;
    }
};

// 用 map 是为了按照键值字典序
map<string, vector<Record>> persons;

int main()
{
    for (int i = 0; i < 24; i ++ ) cin >> cost[i];
    // 注意下面是 i - 1 比如打电话从 6:00 到 7:00 ，计入费用是 6:00 - 6:59
    for (int i = 1; i <= M; ++ i) sum[i] = cost[(i - 1) % 1440 / 60] / 100.0 + sum[i - 1];
    
    cin >> n;
    char name[25], state[10], format_time[20];
    int month, day, hour, minute;
    for (int i = 0; i < n; i ++ )
    {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);
        
        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        persons[name].push_back({minutes, state, format_time});
    }
    
    for (auto &person: persons)
    {
        auto name = person.first;
        auto records = person.second;
        sort(records.begin(), records.end());
        
        double total = 0;
        for (int i = 0; i + 1 < records.size(); ++ i)
        {
            auto a = records[i], b = records[i + 1];
            if (a.state == "on-line" && b.state == "off-line")
            {
                if (!total) printf("%s %02d\n", name.c_str(), month);
                cout << a.format_time << " " << b.format_time;
                
                double c = sum[b.minutes] - sum[a.minutes];
                total += c;
                printf(" %d $%.2lf\n", b.minutes - a.minutes, c);
            }
        }
        if (total) printf("Total amount: $%.2lf\n", total);
    }
}
```

**经验：**
- `sprintf` 将格式化的数据写入字符串
- `string` 数组的 `c_str()` 返回一个指向正规 `char` 字符串的指针常量，内容与本 `string` 相同， `printf("%s %02d\n", name.c_str(), month)`

### 银行排队 1017 Queueing at Bank (25 point(s))

假设一家银行有 $K$ 个服务窗口。 
<p>窗户前面有一条黄线，将等候区分为两部分。 </p>
<p>所有客户都必须在黄线后面排队等候，直到轮到他/她服务并且有可用的窗口为止。 </p>

假定一个窗口<strong>不能被单个客户占用超过 $1$ 小时，即如果某位顾客的业务已经办理了一小时，则立即终止此项业务。</strong>

现在给定每个客户的到达时间 $T$ 和业务办理时间 $P$，请计算所有客户的平均等待时间。

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $K$，分别表示客户数量以及窗口数量。

接下来 $N$ 行，每行包含两个时间，分别是一个客户的到达时间，用 <code>HH:MM:SS</code> 表示，以及一个客户的业务办理时间 $P$（单位：分钟）。

<code>HH</code> 在 $[00,23]$ 范围内，<code>MM</code> 和 <code>SS</code> 都在 $[00,59]$ 范围内。

<p>所有客户的到达时间均不相同。</p>

<p>请注意，银行的营业时间为 <code>08:00</code> 至 <code>17:00</code>。</p>

<p>任何人提前到达都必须排队等候至 <code>08:00</code>，而任何人来得太晚（在 <code>17:00:01</code> 或之后到达）都将不被服务也无需计入平均值。</p>

<p><strong>注意只要客户在<code>17:00</code>之前排上队，则即使办理业务时超过<code>17:00</code>，也会被服务。</strong></p>

<h4>输出格式</h4>

<p>输出平均等待时间（单位：分钟），结果保留一位小数。</p>

<p>注意，从到达银行至开始办理业务这一期间视为等待期间。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^4$,
- $1 \le K \le 100$

<h4>输入样例：</h4>

<pre><code>
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
</code></pre>

<h4>输出样例：</h4>

<pre><code>
8.2
</code></pre>

#### 1017 Queueing at Bank (25 point(s))

Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: $N (≤10^4)$ - the total number of customers, and K (≤100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

#### Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4 + 10, M = 1e2 + 10;

struct Person
{
    int arrive_time;
    int service_time;
    
    bool operator< (const Person& t) const
    {
        return arrive_time < t.arrive_time;
    }
} persons[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
    {
        int hour, minute, second, service_time;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &service_time);
        service_time = min(service_time, 60);
        
        persons[i] = {hour * 3600 + minute * 60 + second, service_time * 60};
    }
    
    // 小根堆，首先保存 m 个值，表示多少时候可服务
    priority_queue<int, vector<int>, greater<int>> windows;
    // m 个窗口早 8 点开始可服务
    for (int i = 0; i < m; i ++ ) windows.push(8 * 3600);
    
    sort(persons, persons + n);
    
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; ++ i)
    {
        auto person = persons[i];
        if (person.arrive_time > 17 * 3600) break;

        int w = windows.top();
        windows.pop();
        
        int start_time = max(person.arrive_time, w);
        sum += start_time - person.arrive_time;
        cnt ++;
        
        windows.push(start_time + person.service_time);
    }

    printf("%.1lf\n", (double) sum / cnt / 60);
}
```

### 乒乓球 1026 Table Tennis (30 point(s))

一个乒乓球俱乐部共有 $K$ 张乒乓球台，编号为 $1 \sim K$。

<p>对于任意一对球员，当他们到达时如果有多个球台可用，那么他们就会被安排到编号较小的那个球台上打球。</p>
<p>如果所有球台都被占用了，他们就只能排队等待了。</p>
<p>假设每对球员<strong>最多只允许打两小时球</strong>。</p>

<p>你需要计算每个排队等候的人的等待时间以及每个球台当天有多少对球员在上面打球。</p>

<p>另外，让这个事情变得复杂的是，俱乐部为 VIP 球员保留了一些球台。</p>

<p>当一个 VIP 球台空出时，等待队伍中的第一对 VIP 球员将优先使用这个球台。</p>

<p>如果此时等待队伍中没有 VIP，则排在等待队伍的第一对球员可以使用这个球台。</p>

<p>另一方面，当轮到一对 VIP 球员打球时，如果没有 VIP 球台可用，那么他们将被视作普通球员处理。</p>

<h4>补充：</h4>

- 1、当等待队伍中有 VIP 球员并且有空闲 VIP 球台时，必须优先分配 VIP 球员，并且必须分配他们 VIP 球台（优先分配编号较小的），直至 VIP 用户或 VIP 球台分配完为止。
- 2、期望打球时间超过两小时的，只能允许打两小时。
- 3、当多对球员的开始打球时间相同时，<strong>先输出到达时间早</strong>的球员的信息。
- 4、当等待球员中没有 VIP 时，VIP 球台视作普通球台处理，当可用球台中没有 VIP 球台时，VIP 球员视作普通球员处理。

<h4>输入格式</h4>

第一行包含整数 $N$，表示共有 $N$ 对球员。

接下来 $N$ 行，每行包含两个时间以及一个 VIP 标识，<code>HH:MM:SS</code>----到达时间，<code>p</code>----打球时间（单位：分钟），<code>tag</code>----如果是 $1$，说明这是一对 VIP，如果是 $0$，说明不是 VIP。

<p>保证到达时间在 <code>08:00:00</code> 至 <code>21:00:00</code> 之间，这是俱乐部的营业时间。</p>

<p>保证每对球员的到达时间都不相同。</p>

再一行包含两个整数 $K$ 和 $M$，表示球台数量以及 VIP 球台数量。

最后一行包含 $M$ 个整数，表示 VIP 球台的编号。

<h4>输出格式</h4>

<p>首先输出每对球员的到达时间，开始打球时间，等待时间。</p>

<p>每对球员的信息占一行，按开始打球时间从早到晚的顺序依次输出。</p>

<p>等待时间必须四舍五入为整数分钟。</p>

<p>如果一对球员在 <code>21:00:00</code> 之前(不包括 <code>21:00:00</code>）不能得到一张球台，那么无需输出他们的信息。</p>

再输出一行，$K$ 个整数，表示每个球台服务的球员对数。

<h4>数据范围</h4>

- $1 \le N \le 10000$,
- $1 \le K \le 100$,
- $0 \le M \le K$

<h4>输入样例：</h4>

<pre><code>
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
</code></pre>

<h4>输出样例：</h4>

<pre><code>
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
</code></pre>

#### 1026 Table Tennis (30 point(s))
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the privilege to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (≤10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: `HH:MM:SS` - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (≤100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.

#### Output Specification:
For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1e4 + 10, M = 1e2 + 10, INF = 2e9;
int n, k, m;

struct Player
{
    int arrive_time, serve_time;
    int start_time, waiting_time;
    
    // 给 sort 排
    const bool operator< (const Player& t) const
    {
        if (start_time != t.start_time) return start_time < t.start_time;
        return arrive_time < t.arrive_time;
    }
    
    // 给 priority_queue 排
    const bool operator> (const Player& t) const
    {
        return arrive_time > t.arrive_time;
    }
};

struct Table
{
    int id;
    int end_time;

    // 细节注意！！
    const bool operator> (const Table& t) const
    {
        if (end_time != t.end_time) return end_time > t.end_time;
        return id > t.id;
    }
};

bool is_vip_table[M];
int table_count[M];

// 最终输出的玩家及顺序
vector<Player> players;

// 注意 `&` 很重要
void assign(priority_queue<Player, vector<Player>, greater<Player>>& ps,
            priority_queue<Table, vector<Table>, greater<Table>>& ts)
{
    auto p = ps.top();
    ps.pop();
    auto t = ts.top();
    ts.pop();
    int start_time = t.end_time;
    int end_time = start_time + p.serve_time;
    ts.push({t.id, end_time});
    table_count[t.id] ++;
    p.start_time = start_time;
    p.waiting_time = round((start_time - p.arrive_time) / 60.0);
    players.push_back(p);
}

string time_to_string(int sec)
{
    char str[20];
    sprintf(str, "%02d:%02d:%02d", sec / 3600, sec % 3600 / 60, sec % 60);
    return str;
}

int main()
{
    // 输入玩家
    priority_queue<Player, vector<Player>, greater<Player>> normal_players;
    priority_queue<Player, vector<Player>, greater<Player>> vip_players;
    
    normal_players.push({INF});
    vip_players.push({INF});

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int hour, minute, sec;
        int serve_time, is_vip;
        scanf("%d:%d:%d %d %d", &hour, &minute, &sec, &serve_time, &is_vip);
        sec = hour * 3600 + minute * 60 + sec;
        serve_time = min(serve_time * 60, 7200);
        if (is_vip) vip_players.push({sec, serve_time});
        else normal_players.push({sec, serve_time});
    }
    
    // 输入桌子
    priority_queue<Table, vector<Table>, greater<Table>> normal_tables;
    priority_queue<Table, vector<Table>, greater<Table>> vip_tables;
    
    normal_tables.push({-1, INF});
    vip_tables.push({-1, INF});
    
    cin >> k >> m;
    for (int i = 0; i < m; ++ i)
    {
        int id;
        cin >> id;
        is_vip_table[id] = true;
    }
    
    for (int i = 1; i <= k; i ++ )
    {
        if (is_vip_table[i]) vip_tables.push({i, 8 * 3600});
        else normal_tables.push({i, 8 * 3600});
    }
    
    // 开始分配
    while (normal_players.size() > 1 || vip_players.size() > 1)
    {
        auto np = normal_players.top();
        auto vp = vip_players.top();
        
        int cur_time = min(np.arrive_time, vp.arrive_time);
        
        while (normal_tables.top().end_time < cur_time)
        {
            auto t = normal_tables.top();
            normal_tables.pop();
            t.end_time = cur_time;
            normal_tables.push(t);
        }
        
        while (vip_tables.top().end_time < cur_time)
        {
            auto t = vip_tables.top();
            vip_tables.pop();
            t.end_time = cur_time;
            vip_tables.push(t);
        }
        
        auto nt = normal_tables.top();
        auto vt = vip_tables.top();
        int end_time = min(nt.end_time, vt.end_time);

        if (end_time >= 21 * 3600) break;

        if (vp.arrive_time <= end_time && vt.end_time == end_time) assign(vip_players, vip_tables);
        else if (np.arrive_time < vp.arrive_time)
        {
            if (nt > vt) assign(normal_players, vip_tables);
            else assign(normal_players, normal_tables);
        }
        else
        {
            if (nt > vt) assign(vip_players, vip_tables);
            else assign(vip_players, normal_tables);
        }
    }
    
    sort(players.begin(), players.end());
    
    for (auto p: players)
    {
        cout << time_to_string(p.arrive_time) << " " << time_to_string(p.start_time) << " " << p.waiting_time << endl;
    }

    for (int i = 1; i <= k; i ++ )
    {
        cout << table_count[i];
        if (i + 1 <= k) cout << " ";
        else cout << endl;
    }
}
```

**经验：**
- 为了防止判断堆是不是空的，可以加入 `INF` 之类永远都不会被出堆的元素（叫做`哨兵`）
- 对于 Struct ，重写 `sort` 用 `operator<` ，重写 `priority_queue` 则重写 `operator>`
