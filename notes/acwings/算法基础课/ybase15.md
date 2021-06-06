<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [线性动态规划](#线性动态规划)
  - [基础例题：数字三角形](#基础例题数字三角形)
  - [例题：最长上升子序列](#例题最长上升子序列)
  - [例题：最长上升子序列II（优化）](#例题最长上升子序列ii优化)

<!-- /code_chunk_output -->

### 线性动态规划

递推犹如一条线。

#### 基础例题：数字三角形

给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

```
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
```

输入格式
- 第一行包含整数 n，表示数字三角形的层数。
- 接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
- 输出一个整数，表示最大的路径数字和。

数据范围
- $1≤n≤500$
- $−10000≤三角形中的整数≤10000$

![](./images/20210606dp1.png)

动态规划的时间复杂度一般是`状态 * 转移`。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
const int INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            scanf("%d", &a[i][j]);
    
    // 因为求最短路径，把无效路径设为 -INF
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= i + 1; j ++)  // 最右边的点的右上没有数，但可能被遍历到，因此取 i + 1
            f[i][j] = - INF;
    
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
    
    int res = -INF;
    for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
    
    printf("%d", res);
    return 0;
}
```

#### 例题：最长上升子序列

- 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
- 第一行包含整数 N。
- 第二行包含 N 个整数，表示完整序列。

输出格式
- 输出一个整数，表示最大长度。

数据范围
- $1≤N≤1000$
- $−10^9≤数列中的数≤10^9$

**分析：** （参考[VictorWu](https://www.acwing.com/solution/content/4807/)）
- 状态表示：`f[i]`表示从第一个数字开始算，以`a[i]`结尾的最大的上升序列。(以`a[i]`结尾的所有上升序列中属性为最大值的那一个)
- 状态计算（集合划分）：`j∈(0,1,2,..,i-1)` 在`a[i] > a[j]`时，`f[i] = max(f[i], f[j] + 1)`。
- 有一个边界，若前面没有比`i`小的，`f[i]`为`1`（自己为结尾，且元素只有自己）。
- 最后再找`f[i]`的最大值。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int f[N];
int a[N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for (int j = 1; j <= i - 1; j ++)
        {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);
    
    printf("%d", res);
    return 0;
}
```

时间复杂度 `O(n^2)` 。

#### 例题：最长上升子序列II（优化）

- 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
- 第一行包含整数 N。
- 第二行包含 N 个整数，表示完整序列。

输出格式
- 输出一个整数，表示最大长度。

数据范围
- $1≤N≤100000$
- $−10^9≤数列中的数≤10^9$

**分析：**
- 之前的做法存在信息冗余
- 对于序列 `3 1 2 3 1` ，我们的 `f[1]` 和 `f[2]` 都是 `1` （以第一个元素 `3` 结尾的最长上升子序列是 `3` ，长度为 1 ；以第二个元素 1 结尾的最长上升子序列是 `1` ，长度也为 1）
- 那么，此时就可用抛弃 `f[1]` 这个信息，没有用了，因为 `1` 比 `3` 要小，适配性大于等于 `3` ，且两个子序列长度相等
- 所以我们维护一个列表 `q[]` ，表示目前最优的长度为 `k` 的最大上升子序列其对应的结尾元素是谁，记录在 `q[k]` 里 
- 我们可以知道 `q[]` 里面的元素是单调递增的（反证法可以证明，如果`q[k+1]`小于`q[k]`，那么必有`q[k+1]`对应的序列倒数第二个元素值也小于`q[k]`，那此时`q[k]`对应的长度为k的子序列就不是最优的了（适配性还不如`q[k+1]`对应的子序列中的长度为`k`的序列呢））
- 所以我们每次向后纳入一个元素`a[i]`，把`a[i]`对接到`q[]`中比其小的数的最大值，如果对接的是`q[]`的最后一个元素，说明找到了现有更长的子序列，`q[]`新增元素`length + 1`，且对应值为`q[length + 1] = a[i]`
- `q[]` 单调，则可以用二分法，状态转移数量从 `O(n)` 变为 `O(logn)`

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    
    int len = 0;
    for (int i = 1; i <= n; i ++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            // 找到比 a[i] 小的最大值，所以取 mid 右边，即向上取整
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);  // 最终 l = r = mid， r + 1 等价于 mid ，但是 mid 不一定被赋值
        q[r + 1] = a[i];
    }
    
    printf("%d", len);
    return 0;
}
```

> 学到 56