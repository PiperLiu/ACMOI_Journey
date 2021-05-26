<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [最小生成树](#最小生成树)
- [Prim](#prim)
  - [Prim模板](#prim模板)
- [Kruskal](#kruskal)
  - [Kruskal模板：Kruskal算法求最小生成树](#kruskal模板kruskal算法求最小生成树)
- [二分图](#二分图)

<!-- /code_chunk_output -->

### 最小生成树
![](./images/20210526最小生成树.png)

一般来讲，稠密图用朴素Prim（$O(n^2)$），稀疏图用Kruskal（$O(m \log m)$）；堆优化的Prim（$O(m\log n)$）不常用。

### Prim
![](./images/20210526最小生成树Prim.png)

算法示例如下。

![](./images/20210526最小生成树Prim2.png)

#### Prim模板
- 给定一个 $n$ 个点 $m$ 条边的无向图，图中可能存在重边和自环，边权可能为负数。
- 求最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。
- 给定一张边带权的无向图 $G=(V,E)$，其中 $V$ 表示图中点的集合，$E$ 表示图中边的集合，$n=|V|$，$m=|E|$。
- 由 $V$ 中的全部 $n$ 个顶点和 $E$ 中 $n−1$ 条边构成的无向连通子图被称为 $G$ 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 $G$ 的最小生成树。

输入格式
- 第一行包含两个整数 $n$ 和 $m$。
- 接下来 $m$ 行，每行包含三个整数 $u,v,w$，表示点 $u$ 和点 $v$ 之间存在一条权值为 $w$ 的边。

输出格式
- 共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible` 。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;
    for (int i = 0; i < n; i ++)  // 循环 n 次
    {
        int t = -1;
        for (int j = 1; j <= n; j ++)  // 检测每个点
            if (!st[j] && (t == -1 || dist[j] < dist[t]))  // t 是技巧，把第一个拿出来和别的点比较
                t = j;
        
        if (i && dist[t] == INF)  // 不是第一次循环，新增到树的点d是最小的，然而值却是 -1
            return INF;
        
        st[t] = true;
        if (i) res += dist[t];  // 先把 res += dist[t] ，防止自环产生影响
        
        for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);  // 更新到集合的最小距离
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if (t == INF) puts("impossible");
    else printf("%d", t);
    return 0;
}
```

**注意：**
- 使用 `if(i)` 检测是不是第一个循环，第一个循环只是任取一个点加到集合，不更新 `res`

### Kruskal

![](./images/20210526最小生成树Kruskal.png)

第二步是 $O(m)$ 的。

#### Kruskal模板：Kruskal算法求最小生成树
- 给定一个 $n$ 个点 $m$ 条边的无向图，图中可能存在重边和自环，边权可能为负数。
- 求最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。
- 给定一张边带权的无向图 $G=(V,E)$，其中 $V$ 表示图中点的集合，$E$ 表示图中边的集合，$n=|V|$，$m=|E|$。
- 由 $V$ 中的全部 $n$ 个顶点和 $E$ 中 $n−1$ 条边构成的无向连通子图被称为 $G$ 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 $G$ 的最小生成树。

输入格式
- 第一行包含两个整数 $n$ 和 $m$。
- 接下来 $m$ 行，每行包含三个整数 $u,v,w$，表示点 $u$ 和点 $v$ 之间存在一条权值为 $w$ 的边。

输出格式
- 共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int p[N];  // 并查集指针

struct Edge {
    int a, b, w;
    
    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
} edges[M];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++) p[i] = i;
    
    int res = 0, cnt = 1;  // 默认树里已经有 1 个点了
    for (int i = 0; i < m; i ++)  // 这里不能是 Edge e : edges ，因为 edges 默认开了 N
    {
        Edge e = edges[i];
        int a = e.a, b = e.b, w = e.w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            cnt ++ ;
            res += w;
        }
    }
    
    if (cnt != n) return 0x3f3f3f3f;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = { a, b, c };
    }
    
    int t = kruskal();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else printf("%d", t);
    
    return 0;
}
```

**经验：**
- 重载了结构体的运算符，用于 `sort`

### 二分图
![](./images/20210526二分图.png)

染色法（$O(n + m)$）判断是否为为二分图，匈牙利法（$O(mn)$，实际运行时间一般远小于$O(mn)$）最大匹配。

> 学到 54:47
