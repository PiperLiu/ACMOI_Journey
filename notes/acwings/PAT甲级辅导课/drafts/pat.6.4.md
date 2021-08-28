
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [微博转发 1076 Forwards on Weibo (30 point(s))](#微博转发-1076-forwards-on-weibo-30-points)

<!-- /code_chunk_output -->

### 微博转发 1076 Forwards on Weibo (30 point(s))

<p>微博被称为中文版的 Twitter。 </p>

<p>微博上的用户既可能有很多关注者，也可能关注很多其他用户。 </p>

<p>因此，形成了一种基于这些关注关系的社交网络。 </p>

<p>当用户在微博上发布帖子时，他/她的所有关注者都可以查看并转发他/她的帖子，然后这些人的关注者可以对内容再次转发&hellip;</p>

现在给定一个社交网络，假设只考虑 $L$ 层关注者，请你计算某些用户的帖子的最大可能转发量。

<h4>补充</h4>

如果 $B$ 是 $A$ 的关注者，$C$ 是 $B$ 的关注者，那么 $A$ 的第一层关注者是 $B$，第二层关注者是 $C$。

<h4>输入格式</h4>

第一行包含两个整数，$N$ 表示用户数量，$L$ 表示需要考虑的关注者的层数。

假设，所有的用户的编号为 $1 \sim N$。

接下来 $N$ 行，每行包含一个用户的关注信息，格式如下：

<pre><code>
M[i] user_list[i]
</code></pre>

<code>M[i]</code> 是第 $i$ 名用户关注的总人数，<code>user_list[i]</code> 是第 $i$ 名用户关注的 <code>M[i]</code> 个用户的编号列表。

最后一行首先包含一个整数 $K$，表示询问次数，然后包含 $K$ 个用户编号，表示询问这些人的帖子的最大可能转发量。

<h4>输出格式</h4>

<p>按顺序，每行输出一个被询问人的帖子最大可能转发量。</p>

假设每名用户初次看到帖子时，都会转发帖子，只考虑 $L$ 层关注者。

<h4>数据范围</h4>

- $1 \le N \le 1000$,
- $1 \le L \le 6$,
- $1 \le M[i] \le 100$,
- $1 \le K \le N$

<h4>输入样例：</h4>

<pre><code>
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
</code></pre>

<h4>输出样例：</h4>

<pre><code>
4
5
</code></pre>

#### 1076 Forwards on Weibo (30 point(s))
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤1000), the number of users; and L (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
```
M[i] user_list[i]
```
where M[i] (≤100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

#### Output Specification:
For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

```cpp
```