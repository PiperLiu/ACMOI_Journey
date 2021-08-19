
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [紧急情况 1003 Emergency (25 point(s))](#紧急情况-1003-emergency-25-points)
- [旅行计划 1030 Travel Plan (30 point(s))](#旅行计划-1030-travel-plan-30-points)
- [团伙头目 1034 Head of a Gang (30 point(s))](#团伙头目-1034-head-of-a-gang-30-points)
- [条条大路通罗马 1087 All Roads Lead to Rome (30 point(s))](#条条大路通罗马-1087-all-roads-lead-to-rome-30-points)
- [在线地图 1111 Online Map (30 point(s))](#在线地图-1111-online-map-30-points)
- [哈密顿回路 1122 Hamiltonian Cycle (25 point(s))](#哈密顿回路-1122-hamiltonian-cycle-25-points)

<!-- /code_chunk_output -->

### 紧急情况 1003 Emergency (25 point(s))

<p>作为城市的紧急救援团队负责人，你将获得一张你所在国家的特殊地图。</p>

<p>该地图显示了一些通过道路连接的分散城市，<strong>道路是双向的</strong>。</p>

<p>地图上标出了每个城市的救援队数量以及每对城市之间的每条道路的长度。</p>

<p>当其他城市发出紧急求援信息时，你的工作是尽快带领你的士兵前往该地点，同时，在途中尽可能多地调动救援帮手。</p>

<h4>输入格式</h4>

第一行包含四个整数 $N$，表示城市数量（城市编号从 $0$ 到 $N-1$），$M$ 表示道路数量，$C_1$ 表示你当前所在的城市编号，$C_2$ 表示发出紧急求援信息的城市编号。

第二行包含 $N$ 个整数，其中第 $i$ 个整数表示城市 $i$ 的救援队数量。

接下来 $M$ 行，每行包含三个整数 $c_1,c_2,L_i$，表示城市 $c_1$ 和城市 $c_2$ 之间存在一条道路相连，道路长度为 $L_i$。

数据保证 $C_1$ 和 $C_2$ 之间至少存在一条路径相连。

<h4>输出格式</h4>

共一行，两个整数，第一个整数表示 $C_1$ 和 $C_2$ 之间最短路的数量，第二个整数表示走最短路的情况下，能聚集到的救援队最大数量。

<h4>数据范围</h4>

- $2 \le N \le 500$,
- $1 \le M \le 600$,
- $1 \le L_i \le 200$,
- 每个城市包含的救援人员数量不超过 $200$。

<h4>输入样例：</h4>

<pre><code>
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
2 4
</code></pre>

#### 1003 Emergency (25 point(s))
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

#### Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, $C_1$ and $C_2$ - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers $c_1$, $c_2$ and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from $C_1 to $C_2$.

#### Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between $C_1$ and $C_2$, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

```cpp
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;

int n, m, S, T;
int w[N], d[N][N];
int dist[N], cnt[N], sum[N];  // dist 最短路 cnt 分支数量 sum 途径救援队
bool st[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0, cnt[S] = 1, sum[S] = w[S];

    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        for (int j = 0; j < n; j ++ )
            if (dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cnt[j] = cnt[t];
                sum[j] = sum[t] + w[j];
            }
            else if (dist[j] == dist[t] + d[t][j])
            {
                cnt[j] += cnt[t];
                sum[j] = max(sum[j], sum[t] + w[j]);
            }
    }
}

int main()
{
    cin >> n >> m >> S >> T;

    for (int i = 0; i < n; i ++ ) cin >> w[i];

    memset(d, 0x3f, sizeof d);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(d[a][b], c);
    }

    dijkstra();

    cout << cnt[T] << ' ' << sum[T] << endl;

    return 0;
}
```

### 旅行计划 1030 Travel Plan (30 point(s))

给定一张地图，包含 $N$ 个城市，$M$ 条高速公路。

<p>城市之间都能相互连通。</p>

<p>每条高速公路的长度和走该条公路的花费都是已知的，高速公路都是<strong>双向</strong>的。</p>

<p>现在要从地图中的某个城市前往另一个城市。</p>

<p>请你确定最短路径，当最短路径不唯一时，请你选取花费最小的路径（保证唯一）。</p>

<h4>输入格式</h4>

第一行包含四个整数 $N,M,S,D$，分别表示城市数量，公路数量，起点城市编号，终点城市编号。

城市编号从 $0$ 到 $N-1$。

接下来 $M$ 行，每行包含四个整数 $a,b,c,d$，表示城市 $a$ 和城市 $b$ 之间存在一条公路，长度为 $c$，花费为 $d$。

<h4>输出格式</h4>

<p>共一行，首先输出从起点城市到终点城市的最短路径（花费最少的）经过的所有城市，然后输出最短路径的距离以及最小的花费。</p>

<h4>数据范围</h4>

- $1 \le N \le 500$,
- $1 \le M \le 600$,
- $1 \le c,d \le 500$

<h4>输入样例：</h4>

<pre><code>
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
</code></pre>

<h4>输出样例：</h4>

<pre><code>
0 2 3 3 40
</code></pre>

#### 1030 Travel Plan (30 point(s))
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

#### Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (≤500) is the number of cities (and hence the cities are numbered from 0 to N−1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

```
City1 City2 Distance Cost
```

where the numbers are all integers no more than 500, and are separated by a space.

#### Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

```cpp
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 510;

int n, m, S, T;
int d[N][N], c[N][N];
int dist[N], cost[N], pre[N];
bool st[N];

void dijkstra()  // 典型的 dijkstra
{
    memset(dist, 0x3f, sizeof dist);
    memset(cost, 0x3f, sizeof cost);

    dist[S] = 0, cost[S] = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        for (int j = 0; j < n; j ++ )
            if (dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cost[j] = cost[t] + c[t][j];
                pre[j] = t;
            }
            else if (dist[j] == dist[t] + d[t][j] && cost[j] > cost[t] + c[t][j])
            {
                cost[j] = cost[t] + c[t][j];
                pre[j] = t;
            }
    }
}

int main()
{
    cin >> n >> m >> S >> T;
    memset(d, 0x3f, sizeof d);
    memset(c, 0x3f, sizeof c);

    while (m -- )
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x < d[a][b])
        {
            d[a][b] = d[b][a] = x;
            c[a][b] = c[b][a] = y;
        }
        else if (x == d[a][b] && y < c[a][b])
        {
            c[a][b] = c[b][a] = y;
        }
    }

    dijkstra();

    vector<int> path;
    for (int i = T; i != S; i = pre[i]) path.push_back(i);

    cout << S;
    for (int i = path.size() - 1; i >= 0; i -- ) cout << ' ' << path[i];
    cout << ' ' << dist[T] << ' ' << cost[T] << endl;

    return 0;
}
```

### 团伙头目 1034 Head of a Gang (30 point(s))

<p>警察找到团伙头目的一种方法是检查人们的通话。</p>

如果 $A$ 和 $B$ 之间有通话，我们就说 $A$ 和 $B$ 是相关的。并且关联具有传递性，即如果 $A$ 与 $B$ 关联，$B$ 与 $C$ 关联，那么 $A$ 与 $C$ 也是关联的。

<p>关联权重定义为两人之间所有通话的总时间长度。</p>

一个“帮派”是一个由<strong>至少3个</strong>相互关联的人组成的群体，并且其总关联权重大于给定的阈值 $K$。

<p>在每个帮派中，总权重最大的就是头目，数据保证每个帮派中总权重最大的人是唯一的。</p>

<p>你需要确定各个帮派以及帮派头目。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $K$，表示通话数量以及权重阈值。

接下来 $N$ 行，每行采用如下形式描述通话：

<pre><code>
Name1 Name2 Time
</code></pre>

<p><code>Name1</code> 和 <code>Name2</code> 是通话的两人的名字，<code>Time</code> 是通话时间。</p>

名字的长度固定为 $3$，且只包含大写字母。

时间是一个不超过 $1000$ 的正整数。

<h4>输出格式</h4>

<p>第一行输出帮派数量。</p>

<p>接下来每行输出一个帮派的信息，包括帮派头目名字以及帮派人数。</p>

<p>帮派信息按头目名字字典序输出。</p>

<h4>数据范围</h4>

$1 \le N,K \le 1000$

<h4>输入样例1：</h4>

<pre><code>
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
2
AAA 3
GGG 3
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
0
</code></pre>

#### 1034 Head of a Gang (30 point(s))
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:
```
Name1 Name2 Time
```

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

#### Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

```cpp
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;
unordered_map<string, vector<pair<string, int>>> g;  // 邻接表
unordered_map<string, int> total;  // 每个人打电话时长
unordered_map<string, bool> st;  // 是否被遍历（用于检查连通性）

int dfs(string ver, vector<string> &nodes)
{
    st[ver] = true;
    nodes.push_back(ver);

    int sum = 0;
    for (auto edge : g[ver])
    {
        sum += edge.second;  // A->B 是会记录一次时间；B->A时还会记录一次时间；因此main 里 sum / 2
        string cur = edge.first;
        if (!st[cur]) sum += dfs(cur, nodes);
        // 可不可以是 if (!st[cur]) sum += edge.second, sum += dfs(cur, nodes); 这样呢
        // 不可以，因为这样加入顺序是 A->B->C 的探索顺序的话， A->C 的边权就无法计入 sum
    }

    return sum;
}

int main()
{
    cin >> n >> k;
    while (n -- )
    {
        string a, b;
        int t;
        cin >> a >> b >> t;
        g[a].push_back({b, t});  // 双向图
        g[b].push_back({a, t});
        total[a] += t;
        total[b] += t;
    }

    vector<pair<string, int>> res;
    for (auto item : total)
    {
        // cout << item.first << " " << item.second << endl; 经验： auto t: unordered_map 输出 pair<键, 值>
        string ver = item.first;
        // 对于每个节点 ver ，看看其是否是新的连通区域
        vector<string> nodes;
        int sum = dfs(ver, nodes) / 2;  // 这里除以 2 注意

        if (nodes.size() > 2 && sum > k)
        {
            string boss = nodes[0];
            for (string node : nodes)
                if (total[boss] < total[node])
                    boss = node;
            res.push_back({boss, (int)nodes.size()});
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (auto item : res) cout << item.first << ' ' << item.second << endl;

    return 0;
}
```

**经验**：
- `auto t: unordered_map` 输出 `pair<键, 值>`

### 条条大路通罗马 1087 All Roads Lead to Rome (30 point(s))

<p>从我们的城市到达罗马有许多不同的旅游路线。</p>

<p>请你在成本最低的旅游路线之中，找到使得游客幸福感最强的路线。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $K$，分别表示总城市数量，城市之间道路数量，还包含一个城市名字，表示初始城市。

接下来 $N-1$ 行，每行包含一个城市名和一个整数，表示到达该城市（初始城市除外）可以获得的幸福感。

接下来 $K$ 行，每行包含一个道路的信息，格式为 <code>City1 City2 Cost</code>，表示两个城市之间的道路行走的花费，<strong>道路是双向的</strong>。

<p>城市都是由三个大写字母构成的字符串。</p>

<p>我们的目的地始终都是罗马 <code>ROM</code>。</p>

<h4>输出格式</h4>

<p>我们应该找到成本最低的路线。</p>

<p>如果这样的路线不是唯一的，那么选取使人们获得最大幸福感的路线。</p>

<p>如果这样的路线仍然不是唯一的，那么我们选择平均幸福感最大的路线，数据保证这种路线唯一。</p>

<p>平均幸福感 = 总幸福感 / 经过的城市数量（初始城市不算）</p>

<p>第一行输出四个整数，最小成本的路线数量，最小成本，幸福感，平均幸福感（只取整数部分）。</p>

<p>第二行，按照 <code>City1->City2->...->ROM</code> 的格式输出路线。</p>

<h4>数据范围</h4>

- $2 \le N \le 200$,
- $1 \le K \le 250$,
- 每个城市的幸福感范围在 $[0,100]$，
- 每条路线最大成本不超过 $1000$

<h4>输入样例：</h4>

<pre><code>
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3 3 195 97
HZH->PRS->ROM
</code></pre>

#### 1087 All Roads Lead to Rome (30 point(s))
Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.

#### Output Specification:
For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format `City1->City2->...->ROM`.

```cpp
// 在更新中凸显优先级
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 210;

int n, m;
int w[N];
int d[N][N];
int dist[N], cnt[N], cost[N], sum[N], pre[N];
// 最短距离，最短路数量，最大点权，最小点数, 最短路径的前一个点
bool st[N];

string city[N];
unordered_map<string, int> mp;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0, cnt[1] = 1;

    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        for (int j = 1; j <= n; j ++ )
            if (dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cnt[j] = cnt[t];
                cost[j] = cost[t] + w[j];
                sum[j] = sum[t] + 1;
                pre[j] = t;
            }
            else if (dist[j] == dist[t] + d[t][j])
            {
                cnt[j] += cnt[t];
                if (cost[j] < cost[t] + w[j])  // 点权取大的
                {
                    cost[j] = cost[t] + w[j];
                    sum[j] = sum[t] + 1;
                    pre[j] = t;
                }
                else if (cost[j] == cost[t] + w[j])
                {
                    if (sum[j] > sum[t] + 1)
                    {
                        sum[j] = sum[t] + 1;
                        pre[j] = t;
                    }
                }
            }
    }
}

int main()
{
    cin >> n >> m >> city[1];
    mp[city[1]] = 1;

    for (int i = 2; i <= n; i ++ )
    {
        cin >> city[i] >> w[i];
        mp[city[i]] = i;
    }

    memset(d, 0x3f, sizeof d);
    while (m -- )
    {
        string x, y;
        int c;
        cin >> x >> y >> c;
        int a = mp[x], b = mp[y];
        d[a][b] = d[b][a] = min(d[a][b], c);
    }

    dijkstra();

    int T = mp["ROM"];
    cout << cnt[T] << ' ' << dist[T] << ' ' << cost[T] << ' ' << cost[T] / sum[T] << endl;

    vector<int> path;
    for (int i = T; i != 1; i = pre[i]) path.push_back(i);

    cout << city[1];
    for (int i = path.size() - 1; i >= 0; i -- )
        cout << "->" << city[path[i]];
    cout << endl;

    return 0;
}
```

### 在线地图 1111 Online Map (30 point(s))

<p>输入我们的当前位置和目的地，在线地图就可以推荐一些行进路线。 </p>

<p>现在你的工作是向用户推荐两条路线：一条是最短路线，另一条是最快路线。</p>

<p>保证任何询问的两地之间都存在至少一条路线。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $M$，表示地图中共有 $N$ 个路口（编号 $0 \sim N-1$）和 $M$ 个街道。

接下来 $M$ 行，每行描述一条街道，格式如下：

<pre><code>
V1 V2 one-way length time
</code></pre>


<code>V1</code> 和 <code>V2</code> 是两个路口的编号，表示这两个路口之间存在一条街道，<code>one-way</code> 如果为 $1$ 则表示这条街道是单行道，只能从 <code>V1</code> 前往 <code>V2</code>。如果为 $0$ 表示是双行道，可随意通行。 <code>length</code> 是街道的长度，<code>time</code> 是通过这条街道花费的时间。

<p>最后一行，将给出起点和终点路口的编号。</p>

<h4>输出格式</h4>

第一行输出路程最短的路线，并输出最短路程 $D$，格式如下：

<pre><code>
Distance = D: source -> v1 -> ... -> destination
</code></pre>

<p>第二行输出用时最快的路线，并输出最短用时 $T$，格式如下：</p>

<pre><code>
Time = T: source -> w1 -> ... -> destination
</code></pre>

<p>如果最短路线不唯一，则输出用时最短的那条路线（保证唯一）。</p>

<p>如果最快路线不唯一，则输出经过路口最少的那条路线（保证唯一）。</p>

<p>如果最短路线和最快路线经过的路口序列完全相同，则以如下格式将两个信息输出在一行：</p>

<pre><code>
Distance = D; Time = T: source -> u1 -> ... -> destination
</code></pre>

<h4>数据范围</h4>

- $2 \le N \le 500$,
- $1 \le M \le \frac{N(N-1)}{2}$,
- 每条道路的长度和用时都不超过 $1000$。
- 任意两个路口之间可能出现重复街道。（这一点和官网不同）

<h4>输入样例1:</h4>

<pre><code>
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
</code></pre>

#### 1111 Online Map (30 point(s))
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers $N (2≤N≤500)$, and $M$, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:
```
V1 V2 one-way length time
```

where V1 and V2 are the indices (from 0 to N−1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

#### Output Specification:
For each case, first print the shortest path from the source to the destination with distance D in the format:
```
Distance = D: source -> v1 -> ... -> destination
```

Then in the next line print the fastest path with total time T:
```
Time = T: source -> w1 -> ... -> destination
```

In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:
```
Distance = D; Time = T: source -> u1 -> ... -> destination
```

```cpp
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 510, M = N * N;

int n, m, S, T;
int h[N], e[M], w1[M], w2[M], ne[M], idx;
int dist1[N], dist2[N], pre[N];
bool st[N];

void add(int a, int b, int c, int d)
{
    e[idx] = b, w1[idx] = c, w2[idx] = d, ne[idx] = h[a], h[a] = idx ++ ;
}

pair<int, string> dijkstra(int w1[], int w2[], int type)  // pair<总长, 答案路径>
{
    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);
    memset(st, 0, sizeof st);
    dist1[S] = dist2[S] = 0;

    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist1[t] > dist1[j]))
                t = j;
        st[t] = true;
        for (int u = h[t]; ~u; u = ne[u])
        {
            int j = e[u];
            int cost;
            if (type == 0) cost = w2[u];
            else cost = 1;  // 如果最快路线不唯一，则输出经过路口最少的那条路线

            if (dist1[j] > dist1[t] + w1[u])
            {
                dist1[j] = dist1[t] + w1[u];
                dist2[j] = dist2[t] + cost;
                pre[j] = t;
            }
            else if (dist1[j] == dist1[t] + w1[u])
            {
                if (dist2[j] > dist2[t] + cost)
                {
                    dist2[j] = dist2[t] + cost;
                    pre[j] = t;
                }
            }
        }
    }

    vector<int> path;
    for (int i = T; i != S; i = pre[i]) path.push_back(i);

    pair<int, string> res;
    res.first = dist1[T];
    res.second = to_string(S);
    for (int i = path.size() - 1; i >= 0; i -- )
        res.second += " -> " + to_string(path[i]);
    return res;
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, t, c, d;
        cin >> a >> b >> t >> c >> d;
        add(a, b, c, d);
        if (!t) add(b, a, c, d);
    }

    cin >> S >> T;

    auto A = dijkstra(w1, w2, 0);
    auto B = dijkstra(w2, w1, 1);

    if (A.second != B.second)
    {
        printf("Distance = %d: %s\n", A.first, A.second.c_str());
        printf("Time = %d: %s\n", B.first, B.second.c_str());
    }
    else
    {
        printf("Distance = %d; Time = %d: %s\n", A.first, B.first, A.second.c_str());
    }

    return 0;
}
```

### 哈密顿回路 1122 Hamiltonian Cycle (25 point(s))

<p>哈密顿回路问题是找到一个包含图中每个顶点的简单回路。 </p>

<p>这样的回路称为“哈密顿回路”。</p>

<p>在本题中，你需要做的是判断给定路径是否为哈密顿回路。</p>

<h4>输入格式</h4>

第一行包含一个整数 $N$ 表示顶点数，一个整数 $M$ 表示给定<strong>无向图</strong>中的边数。

接下来 $M$ 行，每行包含两个整数 $a,b$，表示点 $a$ 和 $b$ 之间存在一条边。

所有顶点编号从 $1$ 到 $N$。

再一行给出整数 $K$，表示询问次数。

接下来 $K$ 行，每行包含一个询问，格式如下：

$n$ $V_1$ $V_2$ ... $V_n$

$n$ 表示给定路径经过的点的数目，$V_i$ 是路径中经过的点。

<h4>输出格式</h4>

<p>对于每个询问，如果是哈密顿回路则在一行输出 <code>YES</code>，否则输出 <code>NO</code>。</p>

<h4>数据范围</h4>

- $2 < N \le 200$,
- $N-1 \le M \le \frac{N(N-1)}{2}$,
- $1 \le K \le 1000$,
- $1 \le n \le 410$

<h4>输入样例：</h4>

<pre><code>
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
YES
NO
NO
NO
YES
NO
</code></pre>

#### 1122 Hamiltonian Cycle (25 point(s))
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers $N (2<N≤200)$, the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format Vertex1 Vertex2, where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:

$n$ $V_1$ $V_2$ ... $V_n$

where n is the number of vertices in the list, and $V_i$'s are the vertices on a path.

#### Output Specification:
For each query, print in a line `YES` if the path does form a Hamiltonian cycle, or `NO` if not.

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;

int n, m;
bool g[N][N], st[N];
int nodes[N * 2];

// 检查路径是否满足 4 个条件即可
// 起点与终点相同
// 点数量 n+1 （是否包含每个节点）
// 每一步都有边
// 所有点均走到
bool check(int cnt)
{
    if (nodes[0] != nodes[cnt - 1] || cnt != n + 1) return false;

    memset(st, 0, sizeof st);
    for (int i = 0; i < cnt - 1; i ++ )
    {
        st[nodes[i]] = true;
        if (!g[nodes[i]][nodes[i + 1]])
            return false;
    }

    for (int i = 1; i <= n; i ++ )
        if (!st[i])
            return false;

    return true;
}

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    int k;
    cin >> k;
    while (k -- )
    {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i ++ ) cin >> nodes[i];

        if (check(cnt)) puts("YES");
        else puts("NO");
    }

    return 0;
}
```
