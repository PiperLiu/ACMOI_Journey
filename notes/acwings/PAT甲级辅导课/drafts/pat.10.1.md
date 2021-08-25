
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

#### Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

#### Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

```cpp

```

### 家产 1114 Family Property (25 point(s))

<p>这次，需要你帮我们整理关于家庭财产方面的数据。</p>

<p>给定每个人的家庭成员以及他/她自己名字下的不动产（地产）信息，我们需要知道每个家庭的成员数，以及人均不动产面积和人均房产套数。</p>

<h4>输入格式</h4>

第一行包含整数 $N$。

接下来 $N$ 行，每行包含一个拥有房产的人员的信息，格式如下：

<pre><code>
ID Father Mother k Child_1 ... child_k M_estate Area
</code></pre>

其中 <code>ID</code> 是每个人的独一无二的 $4$ 位数标识号，<code>Father</code> 和 <code>Mother</code> 是这个人的父母的 <code>ID</code> 号（父母去世则用 <code>-1</code> 代替），$k$ 是孩子数量，<code>Child_i</code> 是孩子的 <code>ID</code>，<code>M_estate</code> 是其名下房产数量，<code>Area</code> 是其名下房产的总面积。

<h4>输出格式</h4>

<p>每行输出一个家庭的相关房产信息，格式如下：</p>

<pre><code>
ID M AVG_sets AVG_area
</code></pre>

<p>其中 <code>ID</code> 是家庭成员中编号最小的成员编号，<code>M</code> 是家庭成员数，<code>AVG_sets</code> 是人均房产套数，<code>AVG_area</code> 是人均房产面积。</p>

<p>两个平均数都要保留三位小数。</p>

<p>按人均房产面积降序顺序输出所有家庭信息。</p>

<p>当存在人均房产面积相同的情况时，按 <code>ID</code> 升序顺序排序。</p>

<h4>数据范围</h4>

- $1 \le N \le 1000$,
- $0 \le k \le 5$
- 每个人名下房产不超过 $100$ 套，
- 每个人名下房产总面积不超过 $50000$。

<h4>输入样例1：</h4>

<pre><code>
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
</code></pre>

#### 1114 Family Property (25 point(s))
This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:

`ID` `Father` `Mother` $k \; Child_1 \; ⋯ \; Child_k \; M_{estate}$ `Area`

where `ID` is a unique 4-digit identification number for each person; `Father` and `Mother` are the `ID`'s of this person's parents (if a parent has passed away, -1 will be given instead); k (0≤k≤5) is the number of children of this person; $Child_i$'s are the ID's of his/her children; $M_{estate}$ is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate.

#### Output Specification:
For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:

`ID` `M` $AVG_{sets}$ $AVG_{area}$

where ID is the smallest ID in the family; M is the total number of family members; $AVG_{sets} is the average number of sets of their real estate; and $AVG_{area}$ is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.

```cpp

```

### 森林里的鸟 1118 Birds in Forest (25 point(s))

<p>一些科学家为森林中成千上万的鸟类拍照。 </p>

<p>假设所有出现在同一张照片中的鸟都属于同一棵树。 </p>

<p>请你帮助科学家计算森林中树木的最大数量，对于任何一对鸟类，请判断它们是否在同一棵树上。</p>

<h4>输入格式</h4>

第一行包含整数 $N$ 表示照片数量。

接下来 $N$ 行，每行描述一张照片，格式如下：

$K$ $B_1$ $B_2$ ... $B_K$

$K$ 表示照片中的鸟的数量，$B_i$ 是鸟的具体编号。

保证所有照片中的鸟被连续编号为 $1$ 到某个不超过 $10^4$ 的整数。

再一行包含整数 $Q$。

接下来 $Q$ 行，每行包含两个鸟的编号，表示一组询问。

<h4>输出格式</h4>

<p>第一行输出最大可能的树的数量以及鸟的数量。</p>

<p>接下来对于每个询问，如果被询问的两个鸟在同一棵树上，则在一行中输出 <code>Yes</code>，否则输出 <code>No</code>。</p>

<h4>数据范围</h4>

- $1 \le N \le 10^4$,
- $1 \le K \le 10$,
- $1 \le Q \le 10^4$

<h4>输入样例：</h4>

<pre><code>
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
</code></pre>

<h4>输出样例：</h4>

<pre><code>
2 10
Yes
No
</code></pre>

#### 1118 Birds in Forest (25 point(s))

Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number $N (≤10^4)$ which is the number of pictures. Then N lines follow, each describes a picture in the format:

$K$ $B_1$ $B_2$ ... $B_K$

where K is the number of birds in this picture, and $B_i$'s are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than $10^4$.

After the pictures there is a positive number $Q (≤10^4)$ which is the number of queries. Then Q lines follow, each contains the indices of two birds.

#### Output Specification:
For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line Yes if the two birds belong to the same tree, or No if not.

```cpp

```
