
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [DFS之剪枝与优化](#dfs之剪枝与优化)
  - [小猫爬山](#小猫爬山)
  - [数独](#数独)
  - [木棒](#木棒)
  - [生日蛋糕](#生日蛋糕)

<!-- /code_chunk_output -->

### DFS之剪枝与优化

提前预知，哪个分支接下来的结点都不会是我们想要的。于是剪掉。

有如下4个优化参考：
- 优化搜索顺序（大部分情况下，我们应该搜索分支较少的节点）
- 排除等效冗余（不要搜索重复状态）
- 可行性剪枝（不可行就没必要接着探索了）
- 最优性剪枝（上限不如当前找到的最优）

![](./images/2021090801.png)

如上图，在枚举问题中，应该有限搜索分支较少的节点。

#### 小猫爬山

翰翰和达达饲养了 $N$ 只小猫，这天，小猫们要去爬山。

<p>经历了千辛万苦，小猫们终于爬上了山顶，但是疲倦的它们再也不想徒步走下山了（呜咕&gt;_&lt;）。</p>

翰翰和达达只好花钱让它们坐索道下山。

索道上的缆车最大承重量为 $W$，而 $N$ 只小猫的重量分别是 $C_1、C_2……C_N$。

当然，每辆缆车上的小猫的重量之和不能超过 $W$。

每租用一辆缆车，翰翰和达达就要付 $1$ 美元，所以他们想知道，最少需要付多少美元才能把这 $N$ 只小猫都运送下山？

<h4>输入格式</h4>

第 $1$ 行：包含两个用空格隔开的整数，$N$ 和 $W$。

第 $2..N+1$ 行：每行一个整数，其中第 $i+1$ 行的整数表示第 $i$ 只小猫的重量 $C_i$。

<h4>输出格式</h4>

<p>输出一个整数，表示最少需要多少美元，也就是最少需要多少辆缆车。</p>

<h4>数据范围</h4>

- $1 \le N \le 18$,
- $1 \le C_i \le W \le 10^8$

<h4>输入样例：</h4>

<pre><code>
5 1996
1
2
1994
12
29
</code></pre>

<h4>输出样例：</h4>

<pre><code>
2
</code></pre>

![](./images/2021090802.png)

```cpp
// 类似 leetcode 周赛256T3 状压DP
// 这里用 dfs ，优化的点在于：
//     一、优化搜索顺序，先放重的，这样分支少
//     二、可行性剪枝
//     三、最优性剪枝

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 18;

int n, m;
int w[N], sum[N];
int ans = N + 1;

void dfs(int u, int k)  // 分配第 u 只小猫，现有 k 量车，将其 dfs 将其放在那辆车上，或者新开一辆
{
    if (k >= ans) return ;  // 最优性剪枝
    if (u == n)
    {
        ans = k;
        return ;
    }

    for (int i = 0; i < k; ++ i)
    {
        if (sum[i] + w[u] <= m)  // 可行性剪枝
        {
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];  // 恢复现场
        }
    }
    
    // 或者新开一辆
    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;  // 恢复现场
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) cin >> w[i];

    // 优化搜索顺序
    sort(w, w + n);
    reverse(w, w + n);
    
    dfs(0, 0);  // 现有 0 辆车，第 0 只小猫开始分配
    
    cout << ans << endl;
}
```

#### 数独

数独是一种传统益智游戏，你需要把一个 $9 \times 9$ 的数独补充完整，使得图中每行、每列、每个 $3 \times 3$ 的九宫格内数字 $1 \sim 9$ 均恰好出现一次。

<p>请编写一个程序填写数独。</p>

<h4>输入格式</h4>

<p>输入包含多组测试用例。</p>

每个测试用例占一行，包含 $81$ 个字符，代表数独的 $81$ 个格内数据（顺序总体由上到下，同行由左到右）。

每个字符都是一个数字（$1-9$）或一个 <code>.</code>（表示尚未填充）。

<p>您可以假设输入中的每个谜题都只有一个解决方案。 </p>

<p>文件结尾处为包含单词 <code>end</code> 的单行，表示输入结束。</p>

<h4>输出格式</h4>

<p>每个测试用例，输出一行数据，代表填充完全后的数独。</p>

<h4>输入样例：</h4>

<pre><code>
4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
</code></pre>

<h4>输出样例：</h4>

<pre><code>
417369825632158947958724316825437169791586432346912758289643571573291684164875293
416837529982465371735129468571298643293746185864351297647913852359682714128574936
</code></pre>

![](./images/2021090803.png)

用到了优化搜索顺序与可行性剪枝，此外还用到了位运算：
- 用 `&` 进行交集
- 枚举可选方案用 `lowbit` 而非枚举 9 次

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

int ones[M], map[M];  // 用来优化打表
int row[N], col[N], cell[3][3];
char str[100];

void init()
{
    for (int i = 0; i < N; i ++ )
        row[i] = col[i] = (1 << N) - 1;  // 每行每列都没填，都是 1

    for (int i = 0; i < 3; i ++ )
        for (int j = 0; j < 3; j ++ )
            cell[i][j] = (1 << N) - 1;  // 每个 cell 都没填，都是 1
}

void draw(int x, int y, int t, bool is_set)  // is_set 填，否则是扣掉
{
    if (is_set) str[x * N + y] = '1' + t;  // t 取值 0 到 8
    else str[x * N + y] = '.';

    int v = 1 << t;  // 把相应的二级制状态处理了
    if (!is_set) v = -v;

    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

int lowbit(int x)
{
    return x & -x;
}

int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];  // x y 点能填哪些数
}

bool dfs(int cnt)
{
    if (!cnt) return true;  // 没空格了，返回

    int minv = 10;  // 找一个分支数量最小的空格
    int x, y;
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            if (str[i * N + j] == '.')  // 是空格
            {
                int state = get(i, j);
                if (ones[state] < minv)  // 当前这个点有多少个备选数（多少个分支）
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];  // lowbit 返回的是 2^k ，这里取 k
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }

    return false;
}

int main()
{
    for (int i = 0; i < N; i ++ ) map[1 << i] = i;  // map[i] 是 log_2{i}
    for (int i = 0; i < 1 << N; i ++ )
        for (int j = 0; j < N; j ++ )
            ones[i] += i >> j & 1;  // 每个数的二进制表示里有多少个 1

    while (cin >> str, str[0] != 'e')
    {
        init();

        int cnt = 0;
        for (int i = 0, k = 0; i < N; i ++ )
            for (int j = 0; j < N; j ++, k ++ )
                if (str[k] != '.')
                {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else cnt ++ ;  // 有多少个数需要填（还剩多少个空格）

        dfs(cnt);

        puts(str);
    }

    return 0;
}
```

#### 木棒

乔治拿来一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过 $50$ 个长度单位。

<p>然后他又想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。</p>

<p>请你设计一个程序，帮助乔治计算木棒的可能最小长度。</p>

<p>每一节木棍的长度都用大于零的整数表示。</p>

<h4>输入格式</h4>

<p>输入包含多组数据，每组数据包括两行。</p>

第一行是一个不超过 $64$ 的整数，表示砍断之后共有多少节木棍。

<p>第二行是截断以后，所得到的各节木棍的长度。</p>

<p>在最后一组数据之后，是一个零。</p>

<h4>输出格式</h4>

<p>为每组数据，分别输出原始木棒的可能最小长度，每组数据占一行。</p>

<h4>数据范围</h4>

数据保证每一节木棍的长度均不大于 $50$。

<h4>输入样例：</h4>

<pre><code>
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0
</code></pre>

<h4>输出样例：</h4>

<pre><code>
6
5
</code></pre>

DFS 首先考虑正确性：是否可以枚举到所有方案，然后再想着怎么优化。

先枚举木棒的可能长度，然后再看看木棒能不能拼接成该长度的若干根。

可以进行很多优化：
- 1 只枚举木棍长度的约数
- 2 优化搜索顺序（从大到小枚举木棒）
- 排除等效冗余
  - 3.1一个木棍内部按照组合数方式枚举（因为 `1+2+3` 和 `1+3+2` 等等是一样的），
  - 3.2 `3`和`4`两根木棍长度相同，`3`在某处枚举失败了，而`4`也会在该处枚举失败；如果当前木棍加到当前棒中失败了，则直接略过后面所有长度相等木棍（反证法）
  - 3.3 如果在新开某个木棒时，放入木棍失败了，则这个方案一定会失败的（反证法）
  - 3.4 如果该木棍是木棒的最后一段，放入失败了，则这个方案一定会失败（反证法）

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 70;

int n;
int w[N];
int sum, length;
bool st[N];

bool dfs(int u, int cur, int start)  // 已有 u 个大棍，当前大棍长度 cur ，小棍从 start 编号开始枚举
{
    if (u * length == sum) return true;  // 枚举 OK 了
    if (cur == length) return dfs(u + 1, 0, 0);  // 本大棍满了，进入下一大棍，注意 start 也从 0 开始

    // 剪枝3-1：i从start开始枚举（组合数）
    for (int i = start; i < n; i ++ )
    {
        if (st[i] || cur + w[i] > length) continue;  // 可行性剪枝：用过了或者超出当前大棍长度不行

        st[i] = true;
        if (dfs(u, cur + w[i], i + 1)) return true;  // 把小棍 i 放入当前大棍，接下来只考虑该小棍之后的棍棍填满本大棍（组合数）
        st[i] = false;
        
        // !cur 是剪枝 3-4 ，当前小棍是新开大棍的第一个，但是失败了
        if (!cur || cur + w[i] == length) return false;  // 当前小棍是新开大棍的最后一个，但是失败了
        
        // 当前长度 w[i] 枚举失败了，咱们找下一个长度
        int j = i;
        while (j < n && w[j] == w[i]) j ++ ;
        i = j - 1;
    }

    return false;
}

int main()
{
    while (cin >> n, n)
    {
        memset(st, 0, sizeof st);
        sum = 0;

        for (int i = 0; i < n; i ++ )
        {
            cin >> w[i];
            sum += w[i];
        }

        // 剪枝2：优化搜索顺序
        sort(w, w + n);
        reverse(w, w + n);

        length = 1;
        while (true)
        {
            // 剪枝1
            if (sum % length == 0 && dfs(0, 0, 0))
            {
                cout << length << endl;
                break;
            }
            length ++ ;
        }
    }

    return 0;
}
```

#### 生日蛋糕

$7$ 月 $17$ 日是 Mr.W 的生日，ACM-THU 为此要制作一个体积为 $Nπ$ 的 $M$ 层生日蛋糕，每层都是一个圆柱体。

设从下往上数第 $i$ 层蛋糕是半径为 $R_i$，高度为 $H_i$ 的圆柱。

当 $i < M$ 时，要求 $R_i > R_{i+1}$ 且 $H_i > H_{i+1}$。

由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积 $Q$ 最小。 

令 $Q = Sπ$ ，请编程对给出的 $N$ 和 $M$，找出蛋糕的制作方案（适当的 $R_i$ 和 $H_i$ 的值），使 $S$ 最小。

除 $Q$ 外，以上所有数据皆为正整数。

<h4>输入格式</h4>

输入包含两行，第一行为整数 $N$，表示待制作的蛋糕的体积为 $Nπ$。

第二行为整数 $M$，表示蛋糕的层数为 $M$。

<h4>输出格式</h4>

输出仅一行，是一个正整数 $S$（若无解则 $S = 0$）。

<h4>数据范围</h4>

- $1 \le N \le 10000$,
- $1 \le M \le 20$

<h4>输入样例：</h4>

<pre><code>
100
2
</code></pre>

<h4>输出样例：</h4>

<pre><code>
68
</code></pre>

![](./images/2021090804.png)

$$\pi R_m^2 + $$

$$2 \pi R_m h_m + 2 \pi R_{m-1} h_{m-1} + ... + 2 \pi R_1 h_1$$

题解转自[抽象带师](https://www.acwing.com/solution/content/31876/)：

记最底层为$m$，很容易观察得出，表面积的公式为：

$$S_总 = S_{m上} + \sum_{i=1}^{m}2\pi R_iH_i$$

而体积为

$$V_总= \sum_{i=1}^{m}\pi R_i^2H_i$$

有了两个公式，还有题目给出的每层最小高度和最小半径，就知道可以用剪枝+暴搜来做这个题

![](./images/2021090805.png)

**剪枝优化**

1.优化搜索顺序

- 层间：从下到上
- 层内：先枚举半径再枚举高（半径相对于高来说对体积的影响较大），半径由大到小，高度由大到小

2. 可行性剪枝

记总体积为`n`，当前层位`u`, 第`u`层的高度为$H_u$, 半径为$R_u$， 体积为$V_u$, 第$m$层到第u层体积的累计值$V$
- 对于`R`, 当前为第`u`层, 第`u`层的体积为$V_u$。R最小的取值应该是当前的层号`u` ，`R`的最大值应该由两部分决定：
    - `u+1`层的半径减`1`, 记$R_{u+1}-1$ （肯定比下一层的半径小）
    - 第`u`层体积的最大值刨去第`u`层高度的最小值`u`
- 这两者的最小值, 故有以下等式成立

$$ u \leq R_u \leq min \lbrace R_{u+1}-1, \sqrt{\frac{n-min\sum_{i=1}^{u-1}V_i - V}{u}} \rbrace$$

（大于等于 `u` 是怎么回事？因为对于第 `u` 层来说，接下来上面的层半径都得严格递减，因此你不能让上面的层没有减的空间）

- 对于第`u`层高度`h`的推导同理，高度`h`的取值的最小值应该大于等于层号`u`，高度的最小值由两部分决定
    - $H_{u+1}-1$
    - 第`u`层体积的最大值除第`u`层的底面积最小值
- 故同理可得出下列等式

$$ u \leq H_u \leq min \lbrace H_{u+1}-1, \frac {{n-min\sum_{i=1}^{u-1}V_i - V}}{R_u^2} \rbrace$$

考虑体积的剪枝：预处理前`u`层的体积最小值$min\sum_{i=1}^{u-1}V_i$, 会有$V + min\sum_{i=1}^{u-1}V_i \leq n$

推表面积公式和体积公式的关系：
- 第一层到第`u`层的表面积有（不考虑$\pi$）

$$S_{1-u} = 2\sum_{i=1}^{u}R_iH_i = \frac{2}{R_{u+1}} \sum_{i=1}^{u}R_{u+1}R_iH_i >  \frac{2}{R_{u+1}}\sum_{i=1}^{u}R_i^2H_i$$

- 第一层到第`u`层的体积有

$$n - V = \sum_{i=1}^{u}R_i^2H_i$$

- 所以惊奇地发现：

$$S_{1-u} >\frac{2(n-V)}{R_{u+1}}$$

因此如果有$S_{1-u} \leq \frac{2(n-V)}{R_{u+1}}$那么就可以剪枝掉。

3.最优性剪枝

记第$m$层到第`u`层表面积的累计值$S$, 第1到第$u-1$层表面积的最小值为 $min\sum_{i=1}^{u-1}S_i$
则应该有$S + min\sum_{i=1}^{u-1}S_i < res$

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 25, INF = 1e9;

int n, m;
int minv[N], mins[N];
int R[N], H[N];
int ans = INF;

void dfs(int u, int v, int s)
{   // u 是当前层， v 是已有体积， s 是已有表面积
    if (v + minv[u] > n) return;  // 可行性剪枝
    if (s + mins[u] >= ans) return;  // 最优化剪枝
    if (s + 2 * (n - v) / R[u + 1] >= ans) return;  // 递推式剪枝

    if (!u)
    {   // 如果 m~1 层都填满了，且 v == n ，则更新最优值
        if (v == n) ans = s;
        return;
    }

    // 先枚举本层 r 再枚举本层 h
    for (int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r -- )
        for (int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h -- )
        {
            int t = 0;
            if (u == m) t = r * r;  // 如果是最低层，别忘了加上 ΠR^2
            R[u] = r, H[u] = h;  // 更新本层 R H
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t);  // 往上走一层，已处理体积增加，已处理表面积增加
        }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i ++ )
    {   // 预处理每层 v s 最小值
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }

    R[m + 1] = H[m + 1] = INF;  // 不存在 m+1 层，这两个数是哨兵

    dfs(m, 0, 0);  // 从最下层开始搜索

    if (ans == INF) ans = 0;
    cout << ans << endl;

    return 0;
}
```
