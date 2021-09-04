
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [急性中风 1091 Acute Stroke (30 point(s))](#急性中风-1091-acute-stroke-30-points)
- [狼人杀-简单版 1148 Werewolf - Simple Version (20 point(s))](#狼人杀-简单版-1148-werewolf-simple-version-20-points)
- [弹出序列 1051 Pop Sequence (25 point(s))](#弹出序列-1051-pop-sequence-25-points)
- [世界首富 1055 The World's Richest (25 point(s))](#世界首富-1055-the-worlds-richest-25-points)
- [栈 1057 Stack (30 point(s))](#栈-1057-stack-30-points)
- [爱丁顿数 1117 Eddington Number (25 point(s))](#爱丁顿数-1117-eddington-number-25-points)
- [火星购物 1044 Shopping in Mars (25 point(s))](#火星购物-1044-shopping-in-mars-25-points)
- [最长回文子串 1040 Longest Symmetric String (25 point(s))](#最长回文子串-1040-longest-symmetric-string-25-points)

<!-- /code_chunk_output -->

### 急性中风 1091 Acute Stroke (30 point(s))

<p>识别急性中风的重要因素之一是中风区域的体积。</p>

现在将脑部区域看作是一个 $M \times N \times L$ 的立方体，通过仪器检测，我们可以得到每个单位体积的脑部区域是否中风。

已知，当一片<strong>连通</strong>的中风区域的体积不小于 $T$ 时，才会对人体产生威胁，属于危险中风区域。

<p>每个单位区域只与其上下左右前后六个方向直接相连的单位区域算作直接连通。</p>

现在，给定脑部整体中风状况分析，请你计算危险中风区域的总体积，即统计所有的体积不小于 $T$ 的连通中风区域，计算它们的体积和。

<h4>输入格式</h4>

第一行包含四个整数 $M,N,L,T$，其中 $M,N,L$ 分别表示脑部区域的长、宽、高。$T$ 是一个整数阈值，当某一连通中风区域的体积小于 $T$ 时，直接忽略不予考虑。

<p>接下来由高到底，按层介绍每层的脑部区域的情况。</p>

共 $L$ 层脑部区域，每层脑部区域都由一个 $M \times N$ 的 $01$ 矩阵表示，其中 $0$ 表示正常区域，$1$ 表示中风区域。

<h4>输出格式</h4>

<p>输出危险中风区域的总体积。</p>

<h4>数据范围</h4>

- $1 \le M \le 1286$,
- $1 \le N \le 128$,
- $1 \le L \le 60$

<h4>输入样例：</h4>

<pre><code>
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
</code></pre>

<h4>输出样例：</h4>

<pre><code>
26
</code></pre>

#### 1091 Acute Stroke (30 point(s))
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M×N matrix, and the maximum resolution is 1286 by 128); L (≤60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M×N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.

![Figure 1](./images/2021090403.jpg)

#### Output Specification:
For each case, output in a line the total volume of the stroke core.

```cpp
```

### 狼人杀-简单版 1148 Werewolf - Simple Version (20 point(s))

<p>“狼人杀”游戏分为狼人、好人两大阵营。</p>

<p>在一局“狼人杀”游戏中：</p>

- 1 号玩家说：“2 号是狼人”；
- 2 号玩家说：“3 号是好人”；
- 3 号玩家说：“4 号是狼人”；
- 4 号玩家说：“5 号是好人”；
- 5 号玩家说：“4 号是好人”。

已知这 $5$ 名玩家中有 $2$ 人扮演狼人角色，有 $2$ 人说的不是实话，有且只有一只狼在说谎。

<p>扮演狼人角色的是哪两号玩家？</p>

<p>本题是这个问题的升级版：</p>

已知 $N$ 名玩家中有 $2$ 人扮演狼人角色，有 $2$ 人说的不是实话，有且只有一只狼在说谎。

<p>要求你找出扮演狼人角色的是哪几号玩家？</p>

<h4>输入格式</h4>

输入在第一行中给出一个正整数 $N$。

随后 $N$ 行，第 $i$ 行给出第 $i$ 号玩家说的话（$1≤i≤N$），即一个玩家编号，用正号表示好人，负号表示狼人。

<h4>输出格式</h4>

如果有解，在一行中按递增顺序输出 $2$ 个狼人的编号，其间以空格分隔，行首尾不得有多余空格。

如果解不唯一，则输出最小序列解 —— 即对于两个序列 $A=a[1],...,a[M]$ 和 $B=b[1],...,b[M]$，若存在 $0≤k<M$ 使得 $a[i]=b[i] （i≤k）$，且 $a[k+1]<b[k+1]$，则称序列 $A$ 小于序列 $B$。

<p>若无解则输出 <code>No Solution</code>。</p>

<h4>数据范围</h4>

$5 \le N \le 100$

<h4>输入样例1：</h4>

<pre><code>
5
-2
+3
-4
+5
+4
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
1 4
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
6
+6
+3
+1
-5
-2
+4
</code></pre>

<h4>输出样例2（解不唯一）：</h4>

<pre><code>
1 5
</code></pre>

<h4>输入样例3：</h4>

<pre><code>
5
-2
-3
-4
-5
-1
</code></pre>

<h4>输出样例3：</h4>

<pre><code>
No Solution
</code></pre>

#### 1148 Werewolf - Simple Version (20 point(s))
Werewolf（狼人杀） is a game in which the players are partitioned into two parties: the werewolves and the human beings. Suppose that in a game,

- player #1 said: "Player #2 is a werewolf.";
- player #2 said: "Player #3 is a human.";
- player #3 said: "Player #4 is a werewolf.";
- player #4 said: "Player #5 is a human."; and
- player #5 said: "Player #4 is a human.".

Given that there were 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. Can you point out the werewolves?

Now you are asked to solve a harder version of this problem: given that there were N players, with 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. You are supposed to point out the werewolves.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (5≤N≤100)$. Then N lines follow and the i-th line gives the statement of the i-th player $(1≤i≤N)$, which is represented by the index of the player with a positive sign for a human and a negative sign for a werewolf.

#### Output Specification:
If a solution exists, print in a line in ascending order the indices of the two werewolves. The numbers must be separated by exactly one space with no extra spaces at the beginning or the end of the line. If there are more than one solution, you must output the smallest solution sequence -- that is, for two sequences `A=a[1],...,a[M]` and `B=b[1],...,b[M]`, if there exists $0≤k<M$ such that `a[i]=b[i] (i≤k)` and `a[k+1]<b[k+1]`, then A is said to be smaller than B. In case there is no solution, simply print No Solution.

```cpp
```

### 弹出序列 1051 Pop Sequence (25 point(s))

给定一个最多能存 $M$ 个数字的栈，将 $1 \sim N$ 按顺序压入栈中，过程中可随机弹出栈顶元素。

当 $N$ 个数字都经历过入栈和出栈后，我们按照元素出栈的顺序，可以得到一个弹出序列。

现在给定一系列 $1 \sim N$ 的随机排列序列，请你判断哪些序列可能是该栈的弹出序列。

例如，当 $N = 7,M=5$ 时，<code>1, 2, 3, 4, 5, 6, 7</code>可能是该栈的弹出序列，而 <code>3, 2, 1, 7, 5, 6, 4</code> 不可能是该栈的弹出序列。

<h4>输入格式</h4>

第一行包含三个整数 $M,N,K$，分别表示栈的容量，数字个数，需要判断的序列个数。

接下来 $K$ 行，每行包含一个 $1 \sim N$ 的排列。

<h4>输出格式</h4>

<p>对于每个序列，如果可能是该栈的弹出序列，则输出一行 <code>YES</code>，否则输出一行 <code>NO</code>。</p>

<h4>数据范围</h4>

$1 \le M,N,K \le 1000$

<h4>输入样例：</h4>

<pre><code>
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
</code></pre>

<h4>输出样例：</h4>

<pre><code>
YES
NO
NO
YES
NO
</code></pre>

#### 1051 Pop Sequence (25 point(s))
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

#### Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

```cpp

```

### 世界首富 1055 The World's Richest (25 point(s))

<p>《福布斯》杂志每年都会根据世界上最富有的人群的年度排名发布其亿万富翁名单。 </p>

<p>现在，你需要模拟这项工作，但你只需要统计特定年龄段的富有人群。 </p>

也就是说，给定 $N$ 个人的净资产，你必须找到在给定年龄范围内的 $M$ 个最富有的人。

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $K$，分别表示总人数以及询问次数。

接下来 $N$ 行，每行包含一个人的姓名（长度不超过 $8$ 且不包含空格的字符串），年龄（范围在 $(0,200]$ 的整数），净资产（范围在 $[-10^6,10^6]$ 的整数）。

接下来 $K$ 行，每行表示一个询问，包含三个整数：$M$，最大输出人数，以及 $A_{min},A_{max}$，表示年龄范围在 $[A_{min},A_{max}]$。

<h4>输出格式</h4>

对于每个询问，首先输出一行形如 <code>Case #X:</code>，其中 $x$ 是询问编号，从 $1$ 开始。

接下来输出给定年龄段内最富有的 $M$ 个人的信息，格式为：

<pre><code>
Name Age Net_Worth
</code></pre>

<p>输出必须按照净资产的非递增顺序排列，如果净资产相同，则按照年龄不降序排列，如果年龄也相同，则按照字典序不降序排列。</p>

<p>数据保证不会出现三个信息完全相同的人。</p>

不够 $M$ 个人，有多少输出多少。

如果找不到任何人，则输出 <code>None</code>。

<h4>数据范围</h4>

- $1 \le N \le 10^5$,
- $1 \le K \le 10^3$,
- $1 \le M \le 100$

<h4>输入样例：</h4>

<pre><code>
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
</code></pre>

#### 1055 The World's Richest (25 point(s))
Forbes magazine publishes every year its list of billionaires based on the annual ranking of the world's wealthiest people. Now you are supposed to simulate this job, but concentrate only on the people in a certain range of ages. That is, given the net worths of N people, you must find the M richest people in a given range of their ages.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: $N (≤10^5)$ - the total number of people, and $K (≤10^3)$ - the number of queries. Then N lines follow, each contains the name (string of no more than 8 characters without space), age (integer in $(0, 200]$), and the net worth (integer in $[−10^6,10^6]$) of a person. Finally there are K lines of queries, each contains three positive integers: M (≤100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages. All the numbers in a line are separated by a space.

#### Output Specification:
For each query, first print in a line Case #X: where X is the query number starting from 1. Then output the M richest people with their ages in the range [Amin, Amax]. Each person's information occupies a line, in the format
```
Name Age Net_Worth
```
The outputs must be in non-increasing order of the net worths. In case there are equal worths, it must be in non-decreasing order of the ages. If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names. It is guaranteed that there is no two persons share all the same of the three pieces of information. In case no one is found, output None.

```cpp

```

### 栈 1057 Stack (30 point(s))

<p>栈是最基本的数据结构之一，它基于后进先出（LIFO）的原理。 </p>

<p>基本操作包括“入栈”（将元素插入到顶部位置）和“出栈”（删除顶部元素）。 </p>

<p>现在，你需要实现一个栈，该栈要具有一个额外的操作：PeekMedian-返回栈中所有元素的中值。 </p>

对于 $N$ 个元素，如果 $N$ 为偶数，则中值定义<strong>从小到大</strong>第 $\frac{N}{2}$ 个元素；如果 $N$ 为奇数，则中值定义为<strong>从小到大</strong>第 $\frac{N+1}{2}$ 个元素。

<h4>输入格式</h4>

第一行包含整数 $N$，表示命令数。

接下来 $N$ 行，每行包含以下三种命令中的一种：

<pre><code>
Push key
Pop
PeekMedian
</code></pre>

<p>其中 <code>key</code> 是一个不超过 $10^5$ 的正整数。</p>

<h4>输出格式</h4>

<p>对于每个 <code>Push</code> 操作，在顶部插入一个 <code>key</code> 值，不输出任何内容。</p>
<p>对于每个 <code>Pop</code> 或 <code>PeekMedian</code> 命令，在一行中输出相应的返回值。 </p>

如果命令无效，则输出 <code>Invalid</code>。

<h4>数据范围</h4>

$1 \le N \le 10^5$

<h4>输入样例：</h4>

<pre><code>
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
</code></pre>

#### 1057 Stack (30 point(s))
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the $(N/2)$-th smallest element if N is even, or $((N+1)/2)$-th if N is odd.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer $N (≤10^5)$. Then N lines follow, each contains a command in one of the following 3 formats:
```
Push key
Pop
PeekMedian
```

where key is a positive integer no more than $10^5$.

#### Output Specification:
For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print Invalid instead.

### 爱丁顿数 1117 Eddington Number (25 point(s))

<p>英国天文学家爱丁顿很喜欢骑车。</p>

据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” $E$ ，即满足有 $E$ 天骑车<strong>超过</strong> $E$ 英里的最大整数 $E$。

据说爱丁顿自己的 $E$ 等于 $87$。

现给定某人 $N$ 天的骑车距离，请你算出对应的爱丁顿数 $E$（$≤N$）。

<h4>输入格式</h4>

输入第一行给出一个正整数 $N$ ，即连续骑车的天数；

第二行给出 $N$ 个非负整数，代表每天的骑车距离。

<h4>输出格式</h4>

在一行中给出 $N$ 天的爱丁顿数。

<h4>数据范围</h4>

- $1 \le N \le 10^5$,
- 所给非负整数均不超过 $10^9$。

<h4>输入样例：</h4>

<pre><code>
10
6 7 6 9 3 10 8 2 7 8
</code></pre>

<h4>输出样例：</h4>

<pre><code>
6
</code></pre>

#### 1117 Eddington Number (25 point(s))
British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.

Now given everyday's distances that one rides for N days, you are supposed to find the corresponding $E (≤N)$.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (≤10^5)$, the days of continuous riding. Then N non-negative integers are given in the next line, being the riding distances of everyday.

#### Output Specification:
For each case, print in a line the Eddington number for these N days.

```cpp

```

### 火星购物 1044 Shopping in Mars (25 point(s))

<p>在火星购物是一个完全不同的体验。</p>

<p>火星人用被链子连在一起的钻石付款，每颗钻石都有一定的价值。</p>

<p>付款时，只能在链条的某一位置上切割一次，然后一些钻石就会一个接着一个的从链条上脱落。</p>

<p>一旦钻石脱离链条，就不能在穿回去。</p>

例如，如果我们有一个钻石链条，上面有 $8$ 颗钻石，价值分别为 $3, 2, 1, 5, 4, 6, 8, 7$ 元，而我们需要支付的价格为 $15$ 元。

<p>我们有三种选择：</p>

- 在 $4$ 和 $6$ 之间剪断链条，然后取走前 $5$ 颗钻石，价值为 $3+2+1+5+4=15$。
- 在 $5$ 之前或 $6$ 之后剪断链条，然后取走第 $4 \sim 6$ 颗钻石，价值为 $5+4+6=15$。
- 在 $8$ 之前剪断链条，然后取走后 $2$ 颗钻石，价值为 $8+7=15$。

<p>现在给定钻石链条上钻石的价值以及顾客需要支付的价钱，请你帮助顾客确定他有多少种选择方案。</p>

<p>如果无法恰好凑出顾客需要支付的确切金额，那就凑出足够支付的情况下的最少金额，从而避免钻石浪费。</p>

<h4>输入格式</h4>

第一行包含两个整数 $N$ 和 $M$，分别表示链条上的钻石数量以及顾客需要支付的金额。

第二行包含 $N$ 个整数，$D_1,D_2,...,D_N$，表示钻石的价值。

<h4>输出格式</h4>

每行输出一种可行方案，具体格式为 <code>i-j</code>，表示 $D_i+...+D_j = M$。

如果方案不唯一，则按照 $i$ 递增的顺序输出所有方案。

如果无法准确凑出 $M$，仍然输出 <code>i-j</code>，表示 $D_i+...+D_j > M$ 并且 $D_i+...+D_j-M$ 的值最小。

如果方案不唯一，则按照 $i$ 递增的顺序输出所有方案。

<h4>数据范围</h4>

- $1 \le N \le 10^5$,,
- $1 \le M \le 10^8$,,
- $1 \le D_i \le 10^3$,
- $\sum D_i \ge M$

<h4>输入样例1：</h4>

<pre><code>
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
1-5
4-6
7-8
11-11
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
5 13
2 4 5 7 9
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
2-4
4-5
</code></pre>

#### 1044 Shopping in Mars (25 point(s))
Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M\$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M\$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M\$15. We may have 3 options:
- Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
- Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
- Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).

Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.

If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: $N (≤10^5)$, the total number of diamonds on the chain, and $M (≤10^8)$, the amount that the customer has to pay. Then the next line contains N positive numbers $D_1,D_2,...,D_N ≤10^3$ for all $i=1,⋯,N$) which are the values of the diamonds. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print i-j in a line for each pair of i ≤ j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.

If there is no solution, output i-j for pairs of i ≤ j such that `Di + ... + Dj >M` with `(Di + ... + Dj −M)` minimized. Again all the solutions must be printed in increasing order of i.

It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

```cpp

```

### 最长回文子串 1040 Longest Symmetric String (25 point(s))

<p>给定一个字符串，请你求出其中的最长回文子串的长度。</p>

例如，给定字符串 <code>Is PAT&TAP symmetric?</code>，最长回文子串为 <code>s PAT&TAP s</code>，其长度是 $11$。

<h4>输入格式</h4>

<p>包含一个非空字符串。</p>

<h4>输出格式</h4>

<p>输出一个整数，表示给定字符串的最长回文子串的长度。</p>

<h4>数据范围</h4>

给定字符串的长度不超过 $1000$。

<h4>输入样例：</h4>

<pre><code>
Is PAT&TAP symmetric?
</code></pre>

<h4>输出样例：</h4>

<pre><code>
11
</code></pre>

#### 1040 Longest Symmetric String (25 point(s))
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.

#### Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.

#### Output Specification:
For each test case, simply print the maximum length in a line.

```cpp

```
