
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [紧急情况 1003 Emergency (25 point(s))](#紧急情况-1003-emergency-25-points)
- [旅行计划 1030 Travel Plan (30 point(s))](#旅行计划-1030-travel-plan-30-points)

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

```