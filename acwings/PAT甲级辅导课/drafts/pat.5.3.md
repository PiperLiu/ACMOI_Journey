
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [等重路径 1053 Path of Equal Weight (30 point(s))](#等重路径-1053-path-of-equal-weight-30-points)
- [最大的一代 1094 The Largest Generation (25 point(s))](#最大的一代-1094-the-largest-generation-25-points)

<!-- /code_chunk_output -->

### 等重路径 1053 Path of Equal Weight (30 point(s))

给定一个非空的树，树根为 $R$。

树中每个节点 $T_i$ 的权重为 $W_i$。

从 $R$ 到 $L$ 的路径权重定义为从<strong>根节点</strong> $R$ 到任何<strong>叶节点</strong> $L$ 的路径中包含的所有节点的权重之和。

<p>现在给定一个加权树以及一个给定权重数字，请你找出树中所有的权重等于该数字的路径（必须从根节点到叶节点）。</p>

<p>例如，我们考虑下图的树，对于每个节点，上方的数字是节点 <code>ID</code>，它是两位数字，而下方的数字是该节点的权重。 </p>

假设给定数为 $24$，则存在 $4$ 个具有相同给定权重的不同路径：<code>{10 5 2 7}，{10 4 10}，{10 3 3 6 2}，{10 3 3 6 2}</code>， 已经在图中用红色标出。

![](./images/2021081901.jpg)

<h4>输入格式</h4>

第一行包含三个整数 $N,M,S$，分别表示树的总节点数量，非叶子节点数量，给定权重数字。

第二行包含 $N$ 个整数 $W_i$，表示每个节点的权重。

接下来 $M$ 行，每行的格式为：

<pre><code>
ID K ID[1] ID[2] ... ID[K]
</code></pre>

$ID$ 是一个两位数字，表示一个非叶子结点编号，$K$ 是一个整数，表示它的子结点数，接下来的 $K$ 个 $ID[i]$ 也是两位数字，表示一个子结点的编号。

出于方便考虑，根节点固定为 $00$，且树中所有节点的编号为 $00 \sim N - 1$。

<h4>输出格式</h4>

<p>以<strong>单调递减</strong>的顺序输出所有权重为S的路径。</p>

<p>每个路径占一行，从根节点到叶节点按顺序输出每个节点的权重。</p>

注意：我们称 $A$ 序列 $\lbrace A_1,A_2,...,A_n \rbrace$ 大于 $B$ 序列 $\lbrace B_1,B_2,...,B_m \rbrace$，当且仅当存在一个整数 $k$，$1 \le k < min(n,m)$，对于所有 $1 \le i \le k$，$A_i = B_i$ 成立，并且 $A_{k+1} > B_{k+1}$。

<h4>数据范围</h4>

- $1 \le N \le 100$,
- $0 \le M < N$,
- $0 < S < 2^{30}$,
- $0 < W_i < 1000$

<h4>输入样例：</h4>

<pre><code>
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
</code></pre>

<h4>输出样例：</h4>

<pre><code>
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
</code></pre>

#### 1053 Path of Equal Weight (30 point(s))
Given a non-empty tree with root R, and with weight $W_i$ assigned to each tree node $T_i$. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: `{10 5 2 7}`, `{10 4 10}`, `{10 3 3 6 2}` and `{10 3 3 6 2}`, which correspond to the red edges in the figure.

#### Input Specification:
Each input file contains one test case. Each case starts with a line containing $0<N≤100$, the number of nodes in a tree, $M (<N)$, the number of non-leaf nodes, and $0<S<2^{30}$, the given weight number. The next line contains N positive numbers where $W_i (<1000)$ corresponds to the tree node $T_i$. Then M lines follow, each in the format:
```
ID K ID[1] ID[2] ... ID[K]
```

where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be `00`.

![](./images/2021081901.jpg)

#### Output Specification:
For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence $\lbrace A_1,A_2,...,A_n \rbrace$ is said to be greater than sequence $\lbrace B_1,B_2,...,B_m \rbrace$ if there exists $1 \le k < min(n,m)$ such that $A_i = B_i$ for $1 \le i \le k$, and $A_{k+1} > B_{k+1}$ 。

```cpp
// 暴搜，长度等于目标路径的存下来
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m, S;
int w[N];
bool g[N][N];
vector<vector<int>> ans;

void dfs(int u, int s, vector<int> &path)
{
    // 是不是叶子节点
    bool is_leaf = true;
    for (int i = 0; i < n; i ++ )
        if (g[u][i])
        {
            is_leaf = false;
            break;
        }

    if (is_leaf)
    {
        if (s == S) ans.push_back(path);
    }
    else
    {
        for (int i = 0; i < n; i ++ )
            if (g[u][i])
            {
                path.push_back(w[i]);
                dfs(i, s + w[i], path);
                path.pop_back();  // 恢复现场
            }
    }
}

int main()
{
    cin >> n >> m >> S;
    for (int i = 0; i < n; i ++ ) cin >> w[i];

    while (m -- )
    {
        int id, k;
        cin >> id >> k;
        while (k -- )
        {
            int son;
            cin >> son;
            g[id][son] = true;  // 用邻接表建树
        }
    }

    vector<int> path({w[0]});
    dfs(0, w[0], path);

    sort(ans.begin(), ans.end(), greater<vector<int>>());  // vector 重载了 < ，按照元素字典序

    for (auto p : ans)
    {
        cout << p[0];
        for (int i = 1; i < p.size(); i ++ ) cout << ' ' << p[i];
        cout << endl;
    }

    return 0;
}
```

### 最大的一代 1094 The Largest Generation (25 point(s))

<p>家庭关系可以用家谱树来表示，同一层上的所有结点都属于同一代人。</p>

<p>请你找出人数最多的一代。</p>

<h4>输入格式</h4>

第一行包含一个整数 $N$ 表示树中结点总数以及一个整数 $M$ 表示非叶子结点数。

接下来 $M$ 行，每行的格式为：

<pre><code>
ID K ID[1] ID[2] ... ID[K]
</code></pre>

$ID$ 是一个两位数字，表示一个非叶子结点编号，$K$ 是一个整数，表示它的子结点数，接下来的 $K$ 个 $ID[i]$ 也是两位数字，表示一个子结点的编号。

为了简单起见，我们将根结点固定设为 $01$。

所有结点的编号即为 $01,02,03,…,31,32,33,…,N$。

<h4>输出格式</h4>

<p>输出结点数量最多的一层的结点数量以及层级。</p>

<p>保证答案唯一。</p>

<p>根结点定义为第一层。</p>

<h4>数据范围</h4>

$0 < N < 100$

<h4>输入样例：</h4>

<pre><code>
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
</code></pre>

<h4>输出样例：</h4>

<pre><code>
9 4
</code></pre>

#### 1094 The Largest Generation (25 point(s))
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

#### Input Specification:
Each input file contains one test case. Each case starts with two positive integers $N (<100)$ which is the total number of family members in the tree (and hence assume that all the members are numbered from `01` to N), and $M (<N)$ which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

```
ID K ID[1] ID[2] ... ID[K]
```

where ID is a two-digit number representing a family member, $K (>0)$ is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be `01`. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

```cpp
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110;

int n, m;
bool g[N][N];
vector<int> level[N];

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int id, k;
        cin >> id >> k;
        while (k -- )
        {
            int son;
            cin >> son;
            g[id][son] = true;
        }
    }

    level[1].push_back(1);
    int l = 1;

    while (level[l].size())
    {
        for (auto ver : level[l])
            for (int j = 1; j <= n; j ++ )
                if (g[ver][j])
                    level[l + 1].push_back(j);
        l ++ ;
    }

    int k = 1;  // 一共 1 .. l-1 层
    for(int i = 1; i < l; i ++ )
        if (level[i].size() > level[k].size())
            k = i;

    cout << level[k].size() << ' ' << k << endl;

    return 0;
}
```
