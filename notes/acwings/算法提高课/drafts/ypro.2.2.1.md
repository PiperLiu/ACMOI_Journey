
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [DFS中的连通性](#dfs中的连通性)
  - [迷宫](#迷宫)
  - [红与黑](#红与黑)
- [DFS中的搜索顺序](#dfs中的搜索顺序)

<!-- /code_chunk_output -->

### DFS中的连通性

注意 bfs 可能有爆栈风险，一般来讲，系统为我们维护的栈上限为 1 MB。

#### 迷宫

一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由 $n * n$ 的格点组成，每个格点只有2种状态，<code>.</code>和<code>#</code>，前者表示可以通行后者表示不能通行。

<p>同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。</p>
<p>如果起点或者终点有一个不能通行(为#)，则看成无法办到。</p>

<p><strong>注意</strong>：A、B不一定是两个不同的点。</p>

<h4>输入格式</h4>

第1行是测试数据的组数 $k$，后面跟着 $k$ 组输入。

每组测试数据的第1行是一个正整数 $n$，表示迷宫的规模是 $n * n$ 的。

接下来是一个 $n * n$ 的矩阵，矩阵中的元素为<code>.</code>或者<code>#</code>。

再接下来一行是 4 个整数 $h_a, l_a, h_b, l_b$，描述 $A$ 处在第 $h_a$ 行, 第 $l_a$ 列，$B$ 处在第 $h_b$ 行, 第 $l_b$ 列。

注意到 $h_a, l_a, h_b, l_b$ 全部是从 0 开始计数的。

<h4>输出格式</h4>

<p>k行，每行输出对应一个输入。</p>

<p>能办到则输出“YES”，否则输出“NO”。</p>

<h4>数据范围</h4>

- $1 \le n \le 100$

<h4>输入样例：</h4>

<pre><code>
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
</code></pre>

<h4>输出样例:</h4>

<pre><code>
YES
NO
</code></pre>

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
char g[N][N];
int xa, ya, xb, yb;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool st[N][N];

bool dfs(int x, int y)
{
    if (g[x][y] == '#') return false;
    if (x == xb && y == yb) return true;

    st[x][y] = true;

    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;
        if (dfs(a, b)) return true;
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

        memset(st, 0, sizeof st);
        if (dfs(xa, ya)) puts("YES");
        else puts("NO");
    }

    return 0;
}
```

#### 红与黑

<p>有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。</p>

<p>你站在其中一块黑色的瓷砖上，只能向相邻（上下左右四个方向）的黑色瓷砖移动。</p>

<p>请写一个程序，计算你总共能够到达多少块黑色的瓷砖。</p>

<h4>输入格式</h4>

<p>输入包括多个数据集合。</p>

每个数据集合的第一行是两个整数 $W$ 和 $H$，分别表示 $x$ 方向和 $y$ 方向瓷砖的数量。

在接下来的 $H$ 行中，每行包括 $W$ 个字符。每个字符表示一块瓷砖的颜色，规则如下

- 1）‘.’：黑色的瓷砖；
- 2）‘#’：红色的瓷砖；
- 3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。

<p>当在一行中读入的是两个零时，表示输入结束。</p>

<h4>输出格式</h4>

<p>对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。</p>

<h4>数据范围</h4>

- $1 \le W,H \le 20$

<h4>输入样例：</h4>

<pre><code>
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
</code></pre>

<h4>输出样例：</h4>

<pre><code>
45
</code></pre>

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25;

int n, m;
char g[N][N];
bool st[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
    int cnt = 1;

    st[x][y] = true;
    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (g[a][b] != '.') continue;
        if (st[a][b]) continue;

        cnt += dfs(a, b);
    }

    return cnt;
}

int main()
{
    // 这题里 n 是行， m 是列
    while (cin >> m >> n, n || m)
    {
        for (int i = 0; i < n; i ++ ) cin >> g[i];

        int x, y;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == '@')
                {
                    x = i;
                    y = j;
                }

        memset(st, 0, sizeof st);
        cout << dfs(x, y) << endl;
    }

    return 0;
}
```

### DFS中的搜索顺序

