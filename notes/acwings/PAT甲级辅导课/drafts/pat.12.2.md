
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [月饼 1070 Mooncake (25 point(s))](#月饼-1070-mooncake-25-points)
- [整数集合划分 1113 Integer Set Partition (25 point(s))](#整数集合划分-1113-integer-set-partition-25-points)
- [结绳 1125 Chain the Ropes (25 point(s))](#结绳-1125-chain-the-ropes-25-points)
- [是否加满油 1033 To Fill or Not to Fill (25 point(s))](#是否加满油-1033-to-fill-or-not-to-fill-25-points)

<!-- /code_chunk_output -->

### 月饼 1070 Mooncake (25 point(s))

月饼是中国的一种烘焙食品，是在中秋节期间食用的传统美食。

月饼的种类多种多样，不同的月饼可能会有不同的表皮和馅料。 

现在，考虑到各种月饼的库存量和价格，以及市场对月饼的总需求量，请你计算出可以赚到的最大利润。

例如，共有 $3$ 种月饼，存量分别为 $180,150,100$（单位：千吨），总价值分别为 $7.5,7.2,4.5$ （单位：十亿元），市场总需求量为 $200$，那么最佳销售方案是出售第二种月饼 $150$，第三种月饼 $50$，这样可获最大利润：$7.2 + 4.5/2 = 9.45$。

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $D$，分别表示月饼种类以及月饼总需求量。

第二行包含 $N$ 个正数，表示每种月饼的存量。

第三行包含 $N$ 个正数，表示每种月饼的总价值。

<h4>输出格式</h4>

<p>输出一个数，表示最大利润，保留两位小数。</p>

<h4>数据范围</h4>

- $1 \le N \le 1000$,
- $1 \le D \le 500$,
- 每种月饼的存量不超过 $200$, 总价值不超过 $2000$。

<h4>输入样例：</h4>

<pre><code>
3 200
180 150 100
7.5 7.2 4.5
</code></pre>

<h4>输出样例：</h4>

<pre><code>
9.45
</code></pre>

#### 1070 Mooncake (25 point(s))
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (≤1000), the number of different kinds of mooncakes, and D (≤500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

```cpp

```

### 整数集合划分 1113 Integer Set Partition (25 point(s))

给定一个包含 $N$ 个正整数的集合，请你将它划分为两个集合 $A_1$ 和 $A_2$，其中 $A_1$ 包含 $n_1$ 个元素，$A_2$ 包含 $n_2$ 个元素。

<p>集合中可以包含相同元素。</p>

用 $S_1$ 表示集合 $A_1$ 内所有元素之和，$S_2$ 表示集合 $A_2$ 内所有元素之和。

请你妥善划分，使得 $|n_1-n_2|$ 尽可能小，并在此基础上 $|S_1-S_2|$ 尽可能大。

<h4>输入格式</h4>

第一行包含整数 $N$。

第二行包含 $N$ 个正整数。

<h4>输出格式</h4>

在一行中输出 $|n_1-n_2|$ 和 $|S_1-S_2|$，两数之间空格隔开。

<h4>数据范围</h4>

- $2 \le N \le 10^5$,
- 保证集合中各元素以及所有元素之和小于 $2^{31}$。

<h4>输入样例1：</h4>

<pre><code>
10
23 8 10 99 46 2333 46 1 666 555
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
0 3611
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
1 9359
</code></pre>

#### 1113 Integer Set Partition (25 point(s))
Given a set of N (>1) positive integers, you are supposed to partition them into two disjoint sets $A_1$ and $A_2$ of $n_1$ and $n_2$ numbers, respectively. Let $S_1$ and $S_2$ denote the sums of all the numbers in $A_1$ and $A_2$, respectively. You are supposed to make the partition so that $∣n_1 - n_2∣$ is minimized first, and then $|S_1 - S_2| is maximized.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives an integer $N (2≤N≤10^5)$, and then N positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than $2^{31}$.

#### Output Specification:
For each case, print in a line two numbers: $∣n_1 − n_2∣$ and $|S_1 − S_2|$, separated by exactly one space.

```cpp

```

### 结绳 1125 Chain the Ropes (25 point(s))

<p>给定一段一段的绳子，你需要把它们串成一条绳。</p>
<p>每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。</p>
<p>这样得到的绳子又被当成是另一段绳子，可以再次对折去跟另一段绳子串连。</p>
<p>每次串连后，原来两段绳子的长度就会减半。</p>

![](./images/2021090401.jpg)

给定 $N$ 段绳子的长度，你需要找出它们能串成的绳子的最大长度。

<h4>输入格式</h4>

第 $1$ 行给出正整数 N；

第 $2$ 行给出 $N$ 个正整数，即原始绳段的长度，数字间以空格分隔。

<h4>输出格式</h4>

<p>在一行中输出能够串成的绳子的最大长度。</p>
<p>结果向下取整，即取为不超过最大长度的最近整数。</p>

<h4>数据范围</h4>

- $2 \le N \le 10^4$,
- 所有原始绳段的长度都不超过 $10^4$。

<h4>输入样例：</h4>

<pre><code>
8
10 15 12 3 4 13 1 15
</code></pre>

<h4>输出样例：</h4>

<pre><code>
14
</code></pre>

#### 1125 Chain the Ropes (25 point(s))
Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each chaining, the lengths of the original two segments will be halved.

![rope.jpg](./images/2021090401.jpg)

Your job is to make the longest possible rope out of N given segments.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (2≤N≤10^4)$. Then N positive integer lengths of the segments are given in the next line, separated by spaces. All the integers are no more than $10^4$.

#### Output Specification:
For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded to the nearest integer that is no greater than the maximum length.

```cpp

```

### 是否加满油 1033 To Fill or Not to Fill (25 point(s))

<p>有了高速公路以后，从杭州开车到其他城市变得非常容易。 </p>
<p>但是由于汽车的油箱容量有限，我们只能不时的寻找加油站去加油。 </p>
<p>不同的加油站的油价可能不同。 </p>
<p>你需要计算，到达目的地所花费的最少油钱是多少。</p>

<h4>输入格式</h4>

第一行包含四个正整数，$C_{max}$，油箱的最大容量，$D$，杭州到目的地城市的距离，$D_{avg}$，每单位汽油可供汽车行驶距离，$N$，加油站总数。

接下来 $N$ 行，每行包含一对非负数描述一个加油站的相关信息，$P_i$，每单位汽油价格，$D_i$，该加油站与杭州的距离。

<h4>输出格式</h4>

<p>输出到达目的地的最小花费，保留两位小数。</p>

假设最开始油箱是空的，如果无法到达目的地，则输出 <code>The maximum travel distance = X</code>，其中 $X$ 是可以行驶的最大距离，保留两位小数。

<h4>数据范围</h4>

- $1 \le C_{max} \le 100$
- $1 \le D \le 30000$
- $1 \le D_{avg} \le 20$
- $1 \le N \le 500$
- $1 \le P_i \le 100$
- $0 \le D_i \le D$

<h4>输入样例1：</h4>

<pre><code>
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
749.17
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
50 1300 12 2
7.10 0
7.00 600
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
The maximum travel distance = 1200.00
</code></pre>

#### 1033 To Fill or Not to Fill (25 point(s))
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: $C_{max}$ (≤ 100), the maximum capacity of the tank; D (≤30000), the distance between Hangzhou and the destination city; $D_{avg}$ (≤20), the average distance per unit gas that the car can run; and N (≤ 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: $P_i$, the unit gas price, and $D_i$ (≤D), the distance between this station and Hangzhou, for $i=1,⋯,N$. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print The maximum travel distance = X where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

```cpp

```
