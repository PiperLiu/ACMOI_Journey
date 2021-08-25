
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [战争中的城市 1013 Battle Over Cities (25 point(s))](#战争中的城市-1013-battle-over-cities-25-points)
- [家产 1114 Family Property (25 point(s))](#家产-1114-family-property-25-points)
- [森林里的鸟 1118 Birds in Forest (25 point(s))](#森林里的鸟-1118-birds-in-forest-25-points)

<!-- /code_chunk_output -->

### 战争中的城市 1013 Battle Over Cities (25 point(s))

<p>在战争中，所有城市都必须通过高速公路连接起来，这一点至关重要。</p>

<p>如果一个城市被敌人占领，则从该城市/往该城市的所有高速公路都将关闭。</p>

<p>此时，我们必须立即判断是否需要维修其他高速公路以保持其余城市的连通性。</p>

给定城市与道路分布地图以及一个重点关注城市列表，请你判断，当列表中的某个城市被攻陷时，至少要维修多少条高速公路才能保持其余城市的连通性。

例如，共有 $3$ 座城市，由 $2$ 条高速公路将它们连通，一条连接城市 $1$ 和城市 $2$，一条连接城市 $1$ 和城市 $3$。

当城市 $1$ 被敌人占领时，我们需要在城市 $2$ 和城市 $3$ 之间维修一条高速公路，以保持这两座城市的连通。

<h4>输入格式</h4>

第一行包含三个整数 $N,M,K$，分别表示城市总数，高速公路总数，重点关注城市数量。

接下来 $M$ 行，每行包含两个整数 $a,b$，表示城市 $a$ 和城市 $b$ 之间存在一条高速公路。

所有城市编号从 $1$ 到 $N$。

最后一行，包含 $K$ 个整数，表示重点关注的城市编号。

<h4>输出格式</h4>

共 $K$ 行，每行输出一个重点关注城市被占领时，为了保持其余城市连通性，需要维修的最少高速公路条数。

<h4>数据范围</h4>

- $2 \le N \le 1000$,
- $1 \le M \le \frac{N(N-1)}{2}$,
- $1 \le a,b \le N$,
- $1 \le K \le N$,
- $KM \le 3500000$,
- 数据保证最开始所有城市保持连通。

<h4>输入样例:</h4>

<pre><code>
3 2 3
1 2
1 3
1 2 3
</code></pre>

<h4>输出样例：</h4>

<pre><code>
1
0
0
</code></pre>

#### 1013 Battle Over Cities (25 point(s))
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting $city_1-city_2$ and $city_1-city_3$. Then if $city_1$ is occupied by the enemy, we must have 1 highway repaired, that is the highway $city_2-city_3$.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

### 家产 1114 Family Property (25 point(s))

### 森林里的鸟 1118 Birds in Forest (25 point(s))

