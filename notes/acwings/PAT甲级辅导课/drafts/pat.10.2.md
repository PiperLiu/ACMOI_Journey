
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [社会集群 1107 Social Clusters (30 point(s))](#社会集群-1107-social-clusters-30-points)

<!-- /code_chunk_output -->

### 社会集群 1107 Social Clusters (30 point(s))

<p>在一些社交网络平台上注册账号时，平台总是会要求你填写自己的兴趣爱好，以便找到一些具有相同兴趣爱好的潜在朋友。 </p>

<p>社会集群是指一群有共同爱好的人。</p>

<p>给定社交网络中所有人的兴趣爱好，请你找到所有社会群集。</p>

<h4>输入格式</h4>

第一行包含一个正整数 $N$，表示社交网络的人数。

所有人的编号为 $1 \sim N$。

接下来 $N$ 行，每行包含一个人的爱好信息，格式如下：

$K_i:$ $h_i[1]$ $h_i[2]$ ... $h_i[K_i]$

$K_i$ 表示爱好数量，$h_i[j]$ 表示第 $j$ 个爱好的编号。

<h4>输出格式</h4>

<p>第一行输出总集群数量。</p>

<p>第二行按非递增顺序输出每个集群的人数。</p>

<p>数字之间空格隔开，行尾不得有多余空格。</p>

<h4>数据范围</h4>

- $1 \le N \le 1000$,
- $K_i &gt; 0$,
- 爱好种类最多 $1000$ 种，编号范围 $[1,1000]$。

<h4>输入样例：</h4>

<pre><code>
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3
4 3 1
</code></pre>

<h4>样例解释</h4>

共 $3$ 个集群：
- $4$ 人集群 $\lbrace 2,4,6,8 \rbrace$，他们都有共同的爱好 $4$。
- $3$ 人集群 $\lbrace 3,5,7 \rbrace$，其中 $3$ 和 $5$ 有共同的爱好 $3$，$3$ 和 $7$ 有共同的爱好 $5$。
- $1$ 人集群 $\lbrace 1 \rbrace$。

#### 1107 Social Clusters (30 point(s))
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A social cluster is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

#### Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

$K_i:$ $h_i[1]$ $h_i[2]$ ... $h_i[K_i]$

where $K_i (>0)$ is the number of hobbies, and $h_i$ [j] is the index of the j-th hobby, which is an integer in [1, 1000].

#### Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

```cpp

```