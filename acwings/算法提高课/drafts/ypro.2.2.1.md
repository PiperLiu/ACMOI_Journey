
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [DFS中的连通性](#dfs中的连通性)
  - [迷宫](#迷宫)
  - [红与黑](#红与黑)
- [DFS中的搜索顺序](#dfs中的搜索顺序)
  - [马走日](#马走日)
  - [单词接龙](#单词接龙)
  - [分成互质组](#分成互质组)

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

#### 马走日

<p>马在中国象棋以日字形规则移动。</p>

请编写一段程序，给定 $n*m$ 大小的棋盘，以及马的初始位置 $(x，y)$，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。

<h4>输入格式</h4>

第一行为整数 $T$，表示测试数据组数。

每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标 $n,m,x,y$。

<h4>输出格式</h4>

<p>每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，若无法遍历棋盘上的所有点则输出 0。</p>

<h4>数据范围</h4>

- $1 \le T \le 9$
- $1 \le m,n \le 9$
- $0 \le x \le n-1$
- $0 \le y \le m-1$

<h4>输入样例：</h4>

<pre><code>
1
5 4 0 0
</code></pre>

<h4>输出样例：</h4>

<pre><code>
32
</code></pre>

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;
int ans, m, n;
bool st[N][N];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void dfs(int x, int y, int cnt)
{
    if (n * m == cnt)
    {
        ans ++;
        return;
    }
    
    st[x][y] = true;
    for (int i = 0; i < 8; ++ i)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b]) continue;
        dfs(a, b, cnt + 1);
    }
    st[x][y] = false;
    
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        memset(st, false, sizeof st);
        ans = 0;
        int x, y;
        cin >> n >> m >> x >> y;
        st[x][y] = true;
        dfs(x, y, 1);
        cout << ans << endl;
    }
}
```

#### 单词接龙

<p>单词接龙是一个与我们经常玩的成语接龙相类似的游戏。</p>

<p>现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”，每个单词最多被使用两次。</p>

<p>在两个单词相连时，其重合部分合为一部分，例如 beast 和 astonish ，如果接成一条龙则变为 beastonish。</p>

<p>我们可以任意选择重合部分的长度，但其长度必须大于等于1，且严格小于两个串的长度，例如 at 和 atide 间不能相连。</p>

<h4>输入格式</h4>

输入的第一行为一个单独的整数 $n$ 表示单词数，以下 $n$ 行每行有一个单词（只含有大写或小写字母，长度不超过20），输入的最后一行为一个单个字符，表示“龙”开头的字母。

<p>你可以假定以此字母开头的“龙”一定存在。</p>

<h4>输出格式</h4>

<p>只需输出以此字母开头的最长的“龙”的长度。</p>

<h4>数据范围</h4>

- $n \le 20$

<h4>输入样例：</h4>

<pre><code>
5
at
touch
cheat
choose
tact
a
</code></pre>

<h4>输出样例：</h4>

<pre><code>
23
</code></pre>

<h4>提示</h4>

<p>连成的“龙”为 atoucheatactactouchoose。</p>

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
int used[N];
int g[N][N];  // i 拼 j 最少重叠多少
string word[N];
int n;
int ans;

void dfs(string dragon, int last)
{
    ans = max((int) dragon.size(), ans);
    
    used[last] ++;
    for (int i = 0; i < n; ++ i)
    {
        if (g[last][i] && used[i] < 2)
            dfs(dragon + word[i].substr(g[last][i]), i);
    }
    used[last] --;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> word[i];
    char start;
    cin >> start;
    
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
        {
            string a = word[i], b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); ++ k)
            {
                if (a.substr(a.size() - k, k) == b.substr(0, k))
                {
                    g[i][j] = k;
                    break;
                }
            }
        }
    
    for (int i = 0; i < n; ++ i)
    {
        if (word[i][0] == start)
            dfs(word[i], i);
    }
    
    cout << ans;
}
```

#### 分成互质组

给定 $n$ 个正整数，将它们分组，使得每组中任意两个数互质。

<p>至少要分成多少个组？</p>

<h4>输入格式</h4>

第一行是一个正整数 $n$。

第二行是 $n$ 个不大于10000的正整数。

<h4>输出格式</h4>

<p>一个正整数，即最少需要的组数。</p>

<h4>数据范围</h4>

- $1 \le n \le 10$

<h4>输入样例：</h4>

<pre><code>
6
14 20 33 117 143 175
</code></pre>

<h4>输出样例：</h4>

<pre><code>
3
</code></pre>

这个问题其实挺复杂的，这里数据量小，咱们暴搜就行。加上一些优化。

```cpp
// 每层 dfs ，对于未分配的点：
// ①能否在当前组中；②不能的话新开一组
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 11;

int n;
int p[N];  // 存放数字
int group[N][N];
bool st[N];
int ans = N;

int gcd(int a, int b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}

// p[i] 进入组 group 是否合法
// gc 是 group 内元素数量
bool check(int group[], int gc, int i)
{
    for (int j = 0; j < gc; ++ j)
    {
        if (gcd(p[group[j]], p[i]) > 1)
            return false;
    }
    return true;
}

// 组号 g 组内元素数量 gc 一共元素数量 tc 第 start 个元素尝试进入
void dfs(int g, int gc, int tc, int start)
{
    if (g > ans) return ;
    if (tc == n) ans = g;
    
    bool flag = true;
    for (int i = start; i < n; ++ i)
    {
        if (!st[i] && check(group[g], gc, i))
        {
            st[i] = true;
            group[g][gc] = i;
            dfs(g, gc + 1, tc + 1, i + 1);
            st[i] = false;
            
            flag = false;
        }
    }
    
    // 没有数可以进入老组了，开新组
    if (flag) dfs(g + 1, 0, tc, 0);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> p[i];
    
    // 为了方便统计 ans ，组号从 1 而非 0 开始
    dfs(1, 0, 0, 0);
    
    cout << ans;
}
```
