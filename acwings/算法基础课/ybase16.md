<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [数位统计动态规划](#数位统计动态规划)
  - [例题：计数问题](#例题计数问题)
- [状态压缩动态规划](#状态压缩动态规划)
  - [例题：蒙德里安的梦想](#例题蒙德里安的梦想)
  - [例题：最短Hamilton路径](#例题最短hamilton路径)
- [树形动态规划](#树形动态规划)
  - [例题：没有上司的舞会](#例题没有上司的舞会)
- [记忆化搜索](#记忆化搜索)
  - [例题：滑雪](#例题滑雪)

<!-- /code_chunk_output -->

### 数位统计动态规划

#### 例题：计数问题

- 给定两个整数 a 和 b，求 a 和 b 之间的所有数字中 0∼9 的出现次数。
- 例如，a=1024，b=1032，则 a 和 b 之间共有 9 个数如下：
  - `1024 1025 1026 1027 1028 1029 1030 1031 1032`
- 其中 0 出现 10 次，1 出现 10 次，2 出现 7 次，3 出现 3 次等等…

输入格式
- 输入包含多组测试数据。
- 每组测试数据占一行，包含两个整数 a 和 b。
- 当读入一行为 `0 0` 时，表示输入终止，且该行不作处理。

输出格式
- 每组数据输出一个结果，每个结果占一行。
每个结果包含十个用空格隔开的数字，第一个数字表示 0 出现- 的次数，第二个数字表示 1 出现的次数，以此类推。

数据范围
- $0<a,b<100000000$

参考：[aleihentai](https://www.acwing.com/solution/content/4934/)：

（说实在的这位朋友写的有点乱，不如直接看我代码）

![](./images/20210608dp1.jpg)
![](./images/20210608dp2.jpg)
![](./images/20210608dp3.jpg)
![](./images/20210608dp4.jpg)
![](./images/20210608dp5.jpg)

这题 y 总奋战了很久。最后还是在直播课把 bug 干没了。很牛逼。很牛逼的临场分析和 debug 技巧。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int get(vector<int> num, int l, int r)
{
    /*
    * 数字 12345
    *       ^ ^
    *       3 1
    *       l r
    * 取出 234
    */
    int  res = 0;
    for (int i = l; i >= r; i --) res = res * 10 + num[i];
    return res;
}

int power10(int x)
{
    // 10^x
    int res = 1;
    while (x -- ) res *= 10;
    return res;
}

int count(int n, int x)
{
    // 本题中 a > 0，因此如果传入 0 ，则不算范围内
    if (!n) return 0;
    
    // 12345 存入 num = {5, 4, 3, 2, 1}
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    
    int res = 0;
    // x非0，则 i 从最高位开始；否则从最高位-1开始
    for (int i = n - 1 - !x; i >= 0; i --)
    {
        // 如果不是最高位
        if (i < n - 1)
        {
            // abcxyyy
            //    ^    现在求 x 在第 i 位出现的次数
            //    i    000~abc-1 yyy = 000 ~ 999
            res += get(num, n - 1, i + 1) * power10(i);
            // 如果 x 为 0 ，因为 abc=000 时，x=0，0yyy 不算个数，因此减去 1yyy
            if (!x) res -= power10(i);
        }
        
        // abcdefg
        // abcxyyy
        //    ^
        //    i
        // 刚才做了 前缀=000~abc-1 ，现在做 前缀=abc
        // 如果 x == d，则有 0 ~ efg 种方案
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        // 如果 x < d，则 yyy 取 000 ~ 999 都在 abcdefg 范围内
        else if (num[i] > x) res += power10(i);
    }
    
    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a)
    {
        // b 更大一点
        if (a > b) swap(a, b);
        
        for (int i = 0; i <= 9; i ++)
            // 可以视作集合的减法，注意 a~b 的数包含 a ，因此减去 count(a-1, i)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}
```

**经验：**
- `while (cin >> a >> b , a)` 可以应对`输入包含多组测试数据`且`a`不会是`0`这种情况，最后放`a`还是别的变量来判断是否还有数据输入，视情况而定
- 强类型转换`i = n - 1 - !x;`省去了繁杂的判断`if (x) i = n - 1; else i = n - 2`

```go
package main

import (
    "fmt"
    "strconv"
    "bufio"
    "os"
)

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    
    out := bufio.NewWriter(os.Stdout)
    defer out.Flush()
    
    readInt := func () int {
        sc.Scan()
        x, _ := strconv.Atoi(sc.Text())
        return x
    }
    
    for {
        x, y := readInt(), readInt()
        if x == 0 {
            break
        }
        if x < y {
            x, y = y, x
        }
        for i := 0; i < 10; i ++ {
            fmt.Fprint(out, count(x, i) - count(y - 1, i))
            if i == 9 {
                fmt.Fprint(out, "\n")
            } else {
                fmt.Fprint(out, " ")
            }
        }
    }
}

func count(n, x int) int {  // x 数字在 [1, 2, ..., n] 中出现了多少次
    if n == 0 {
        return 0
    }
    nums := []int{}
    for tmp := n; tmp > 0; tmp /= 10 {
        nums = append(nums, tmp % 10)
    }
    
    le := len(nums)
    i := le - 1
    if x == 0 {
        i --
    }
    res := 0
    for ; i >= 0; i -- {
        if i < le - 1 {
            prefix := get(nums, le - 1, i + 1)
            subfix := power10(i)
            res += prefix * subfix
            if x == 0 {
                res -= power10(i)
            }
        }
        if nums[i] == x {
            res += get(nums, i - 1, 0) + 1
        } else if nums[i] > x {
            res += power10(i)
        }
    }
    return res
}

func get(nums []int, r, l int) int {
    res := 0
    for i := r; i >= l; i -- {
        res *= 10
        res += nums[i]
    }
    return res
}

func power10(x int) int {
    res := 1
    for i := 0; i < x; i ++ {
        res *= 10
    }
    return res
}
```

### 状态压缩动态规划

#### 例题：蒙德里安的梦想

- 求把 $N×M$ 的棋盘分割成若干个 $1×2$ 的的长方形，有多少种方案。
- 例如当 N=2，M=4 时，共有 5 种方案。当 N=2，M=3 时，共有 3 种方案。
- 如下图所示：

![](./images/20210608dp6.jpg)

输入格式
- 输入包含多组测试用例。
- 每组测试用例占一行，包含两个整数 N 和 M。
- 当输入用例 $N=0$，$M=0$ 时，表示输入终止，且该用例无需处理。

输出格式
- 每个测试用例输出一个结果，每个结果占一行。

数据范围
- $1≤N,M≤11$

**分析：**
- $1≤N,M≤11$ 提示了我们可能用状态压缩来做
- 核心：先放横着的、再放竖着的
  - 总方案数，等于只放横着的小方块的合法方案数。
  - 如何判断，当前方案是否合法？
    - （合法：所有剩余位置能否填充慢竖着的小方块）
    - 可以按列来看，每一列内部所有连续的空着的小方块，需要偶数个

![](./images/20210610dp1.png)

之后，考虑用动态规划做：
- 状态表示：`f[i, j]`表示已将前`i-1`列摆好，且从第`i-1`列，伸出到第`i`列（且第`i`列状态为`j`）的所有方案和
- 状态计算：前`i-2`列摆好，伸出到第`i-1`列，如下图，`f[i-1, k]`的`k`表示第`i-1`列中哪些位置由`i-2`探出头来，而这个`k`不应该与`j`矛盾，否则`f[i, j]`不能由`f[i-1, k]`转移而来

![](./images/20210610dp2.png)

如何判断`j`与`k`是否相容呢？
- 首先，二者不能同时为1：`(j & k) == 0`
- 其次，对于`j`与`k`这类列，所有连续空着的位置的长度必须是偶数

下标从 0 开始，因此最终答案是 `f[m, 0]` 。

时间复杂度：`第一维度×第二维度×状态转移`，即`11×2^{11}×2^{11}`

不加优化：
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 12, M = 1 << N;

LL f[N][M];
int m, n;
bool st[M];  // 保存所有伸出来的状态是否合法

int main()
{
    while (cin >> n >> m, n || m)
    {
        // 把列的所有状态遍历一遍
        for (int i = 0; i < 1 << n; i ++)
        {
            // 对于本状态 i
            st[i] = true;
            int cnt = 0;  // 记录连续 0 的数量
            // 从第一行的格子开始
            for (int j = 0; j < n; j ++)
            {
                if (i >> j & 1)  // 如果第 j 个格子对应数是 1
                {
                    // 连续 0 的数量是奇数
                    if (cnt & 1)
                    {
                        st[i] = false;
                        break;
                    }
                }
                else cnt ++;
            }
            if (cnt & 1) st[i] = false;
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1;  // 对于第 0 列，只有 1 种情况00...000，方案也只有 1 种
        for (int i = 1; i <= m; i ++)
            for (int j = 0; j < 1 << n; j ++)
                for (int k = 0; k < 1 << n; k ++)
                    if ((j & k) == 0 && st[j | k])  // j 和 k 没有冲突，且 j 和 k 状态合法
                        f[i][j] += f[i - 1][k];
        
        cout << f[m][0] << endl;
    }
    return 0;
}
```

```go
package main

import (
    "fmt"
    "strconv"
    "bufio"
    "os"
)

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    
    out := bufio.NewWriter(os.Stdout)
    defer out.Flush()
    
    readInt := func () int {
        sc.Scan()
        x, _ := strconv.Atoi(sc.Text())
        return x
    }
    
    for {
        x, y := readInt(), readInt()
        if x == 0 {
            break
        }
        fmt.Fprint(out, foo(x, y), "\n")
    }
}

func foo(n, m int) int {
    f := make([][]int, m + 1)
    for i := range f {
        f[i] = make([]int, 1 << n)
    }

    st := make([]bool, 1 << n)  // 各个状态是否合法
    for i := 0; i < 1 << n; i ++ {
        st[i] = true
        cnt := 0
        for j := 0; j < n; j ++ {
            if i >> j & 1 > 0 {
                if cnt % 2 == 1 {
                    st[i] = false
                    break
                }
            } else {
                cnt ++
            }
        }
        if cnt % 2 == 1 {
            st[i] = false
        }
    }

    f[0][0] = 1  // 第一列所有有意义状态 f[1][*] 都将来自 f[0][0]
    for i := 1; i <= m; i ++ {
        for j := 0; j < 1 << n; j ++ {
            for k := 0; k < 1 << n; k ++ {  // 上一列的状态
                if (j & k) == 0 && st[j | k] {
                    f[i][j] += f[i - 1][k]
                }
            }
        }
    }
    
    return f[m][0]
}
```

加优化（把对于状态`j`来说，其对应的合法`k`保存起来）：
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 12, M = 1 << N;

LL f[N][M];
int m, n;
bool st[M];  // 保存所有伸出来的状态是否合法
vector<int> state[M];  // 保存各个合法状态对应的合法前置状态

int main()
{
    while (cin >> n >> m, n || m)
    {
        // 把列的所有状态遍历一遍
        for (int i = 0; i < 1 << n; i ++)
        {
            // 对于本状态 i
            st[i] = true;
            int cnt = 0;  // 记录连续 0 的数量
            // 从第一行的格子开始
            for (int j = 0; j < n; j ++)
            {
                if (i >> j & 1)  // 如果第 j 个格子对应数是 1
                {
                    // 连续 0 的数量是奇数
                    if (cnt & 1)
                    {
                        st[i] = false;
                        break;
                    }
                }
                else cnt ++;
            }
            if (cnt & 1) st[i] = false;
        }
        
        for (int i = 0; i < 1 << n; i ++)
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j ++)
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1;  // 对于第 1 列，只有 1 种情况00...000，方案也只有 1 种
        for (int i = 1; i <= m; i ++)
            for (int j = 0; j < 1 << n; j ++)
                for (auto k: state[j])
                        f[i][j] += f[i - 1][k];
        
        cout << f[m][0] << endl;
    }
    return 0;
}
```


|提交时间|	状态|	运行时间|	语言|	模式|
|---|---|---|---|---|
|53秒前|	Accepted|	211 ms|	C++|	普通|
|7分钟前|	Accepted|	876 ms|	C++|	普通|

#### 例题：最短Hamilton路径

- 给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。
- Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

输入格式
- 第一行输入整数 n。
- 接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 `a[i,j]`）。
- 对于任意的 `x,y,z`，数据保证 `a[x,x]=0`，`a[x,y]=a[y,x]` 并且 `a[x,y]+a[y,z]≥a[x,z]`。

输出格式
- 输出一个整数，表示最短 Hamilton 路径的长度。

数据范围
- $1≤n≤20$
- $0≤a[i,j]≤10^7$

![](./images/20210610dp3.png)

**分析：**
- 状态表示：`f[i, j]` 表示所有从 `0` 走到 `j` ，经过了 `i` 这些点的路径中，最短的路径长度（举例子：`n = 5, i = 0b01010`表示经过1、3点，计数从0开始）
- 状态计算：对于当前状态 `i, j` ，其上一个所在点是 `k` ，则经过的路径是 `i - {j}` （因为还没到达 `j` 点）比如`j = 3, k = 1`，则当前状态 `i = 0b01010` ，而上一步状态 `i - {j} = 0b00010` ，运算是 `i - 1 << j`

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            scanf("%d", &w[i][j]);
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;  // 路径里只有第 0 点，且状态是 000...001

    for (int i = 0; i < 1 << n; i ++)
        for (int j = 0; j < n; j ++)
            if (i >> j & 1)  // 如果路径 i 里有第 j 点
                for (int k = 0; k < n; k ++)
                    if (i >> k & 1)  // 如果路径 i 里有第 k 点
                        f[i][j] = min(f[i - (1 << j)][k] + w[k][j], f[i][j]);
    
    printf("%d", f[(1 << n) - 1][n - 1]);

    return 0;
}
```

**经验：**
- 想得到 `n` 个 `1111` 可以 `(1 << n) - 1`

```go
package main

import (
    "fmt"
    "strconv"
    "bufio"
    "os"
)

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    
    readInt := func () int {
        sc.Scan()
        x, _ := strconv.Atoi(sc.Text())
        return x
    }
    
    n := readInt()
    w := make([][]int, n)
    for i := range w {
        w[i] = make([]int, n)
        for j := range w[i] {
            w[i][j] = readInt()
        }
    }

    f := make([][]int, 1 << n)
    for i := range f {
        f[i] = make([]int, n)
        for j := range f[i] {
            f[i][j] = int(2e9)
        }
    }
    
    f[1][0] = 0  // 路径为 0...01 ，且目前在 0 节点

    for i := 0; i < 1 << n; i ++ {
        for dst := 0; dst < n; dst ++ {
            if i >> dst & 1 == 0 {
                continue
            }
            for src := 0; src < n; src ++ {
                if i >> src & 1 == 0 || dst == src {
                    continue
                }
                f[i][dst] = min(f[i][dst], f[i - (1 << dst)][src] + w[src][dst])
            }
        }
    }
    
    fmt.Println(f[(1 << n) - 1][n - 1])
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```

### 树形动态规划

#### 例题：没有上司的舞会

- Ural 大学有 N 名职员，编号为 1∼N。
- 他们的关系就像一棵以校长为根的树，父节点就是子节点的直接上司。
- 每个职员有一个快乐指数，用整数 $H_i$ 给出，其中 $1≤i≤N$。
- 现在要召开一场周年庆宴会，不过，没有职员愿意和直接上司一起参会。
- 在满足这个条件的前提下，主办方希望邀请一部分职员参会，使得所有参会职员的快乐指数总和最大，求这个最大值。

输入格式
- 第一行一个整数 N。
- 接下来 N 行，第 i 行表示 i 号职员的快乐指数 Hi。
- 接下来 N−1 行，每行输入一对整数 L,K，表示 K 是 L 的直接上司。

输出格式
- 输出最大的快乐指数。

数据范围
- $1≤N≤6000$
- $−128≤H_i≤127$

**分析参考[Jayfeather](https://www.acwing.com/solution/content/4757/)：**

![](./images/20210610dp4.png)
![](./images/20210610dp5.png)
![](./images/20210610dp6.png)

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010;

int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    // 以 u 为根节点，1 代表方案里有 u ，0 代表没有
    f[u][1] = happy[u];
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);  // 更新子节点为根节点时的值，下面是回溯加回来
        
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main()
{
    scanf("%d", &n);
    
    // 注意这里从 1 开始计数，否则与树的输入不想对应
    for (int i = 1; i <= n; i ++) scanf("%d", &happy[i]);
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
        has_fa[a] = true;
    }
    
    int root = 1;
    while (has_fa[root]) root ++ ;  // 找到根节点
    
    dfs(root);
    
    printf("%d", max(f[root][0], f[root][1]));
    return 0;
}
```

```go
package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

type Node struct {
    Idx int
    Val int
    Children []*Node
}

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)
    
    readInt := func () int {
        sc.Scan()
        x, _ := strconv.Atoi(sc.Text())
        return x
    }
    
    n := readInt()
    idx2Node := map[int]*Node{}
    HasFa := map[int]bool{}
    for i := 1; i <= n; i ++ {
        val := readInt()
        idx2Node[i] = &Node {
            Idx: i,
            Val: val,
        }
    }
    for i := 0; i < n - 1; i ++ {
        x, y := readInt(), readInt()
        idx2Node[y].Children = append(idx2Node[y].Children, idx2Node[x])
        HasFa[x] = true
    }
    
    var root *Node
    for i := range idx2Node {
        if !HasFa[i] {
            root = idx2Node[i]
            break
        }
    }

    f := make([][2]int, n + 1)
    dfs(root, f)
    fmt.Println(max(f[root.Idx][0], f[root.Idx][1]))
}

func dfs(u *Node, f [][2]int){
    f[u.Idx][1] = u.Val
    for _, child := range u.Children {
        dfs(child, f)
        f[u.Idx][1] += f[child.Idx][0]
        f[u.Idx][0] += max(f[child.Idx][0], f[child.Idx][1])
    }
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```

### 记忆化搜索

#### 例题：滑雪

- 给定一个 R 行 C 列的矩阵，表示一个矩形网格滑雪场。
- 矩阵中第 i 行第 j 列的点表示滑雪场的第 i 行第 j 列区域的高度。
- 一个人从滑雪场中的某个区域内出发，每次可以向上下左右任意一个方向滑动一个单位距离。
- 当然，一个人能够滑动到某相邻区域的前提是该区域的高度低于自己目前所在区域的高度。
- 下面给出一个矩阵作为例子：

```
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9
```

- 在给定矩阵中，一条可行的滑行轨迹为 `24−17−2−1`。
- 在给定矩阵中，最长的滑行轨迹为 `25−24−23−…−3−2−1`，沿途共经过 25 个区域。
- 现在给定你一个二维矩阵表示滑雪场各区域的高度，请你找出在该滑雪场中能够完成的最长滑雪轨迹，并输出其长度(可经过最大区域数)。

输入格式
- 第一行包含两个整数 R 和 C。
- 接下来 R 行，每行包含 C 个整数，表示完整的二维矩阵。

输出格式
- 输出一个整数，表示可完成的最长滑雪长度。

数据范围
- $1≤R,C≤300$
- $0≤矩阵中整数≤10000$

**分析：**

![](./images/20210610dp7.png)

如上图：
- 状态表示中，集合为所有从`(i, j)`开始滑的路径，属性为路径的 `Max`
- 状态计算为 `f(i, j) = f(上下左右) + 1` ，前提是，要是行动应该是合法的
  - 不能撞墙
  - 不能走到更高或等高的坡上
- 本题可以用记忆化搜索是因为没有环形状态转移，因为`不能走到更高或等高的坡上`导致无法形成环

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n, m;
int g[N][N];  // 地图
int f[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y)
{
    int &v = f[x][y];  // v 就是 f[x][y]
    if (v != -1) return v;  // v 已经被“记忆”过
    
    // OK，从 v 开始，我最远可以到达？
    v = 1;
    for (int i = 0; i < 4; i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && g[x][y] > g[a][b])  // 合法的移动
            v = max(v, dp(a, b) + 1);
    }
    
    return v;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &g[i][j]);
    
    memset(f, -1, sizeof f);
    
    int res = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            res = max(res, dp(i, j));  // 遍历起点 i, j
    
    printf("%d", res);
    
    return 0;
}
```

**经验：**
- 用 `&v = f[i][j]` 表示 `f[i][j]` 的值，我的理解是，`&v = f[i][j]` 表示 `v` 的地址也是 `f[i][j]` 的地址

```go
package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

func main() {
    sc := bufio.NewScanner(os.Stdin)
    sc.Split(bufio.ScanWords)

    readInt := func () int {
        sc.Scan()
        x, _ := strconv.Atoi(sc.Text())
        return x
    }

    n, m := readInt(), readInt()
    f := make([][]int, n)
    g := make([][]int, n)
    for i := range f {
        f[i] = make([]int, m)
        g[i] = make([]int, m)
        for j := range g[i] {
            g[i][j] = readInt()
        }
    }

    ans := -1
    for i := range f {
        for j := range f[i] {
            ans = max(dfs(i, j, n, m, f, g), ans)
        }
    }
    
    fmt.Println(ans)
}

func dfs(x, y, n, m int, f, g [][]int) int {
    if f[x][y] != 0 {
        return f[x][y]
    }

    f[x][y] = 1
    dx := [4]int{0, 1, 0, -1}
    dy := [4]int{1, 0, -1, 0}
    for i := range dx {
        xx, yy := x + dx[i], y + dy[i]
        if xx < 0 || xx >= n || yy < 0 || yy >= m || g[xx][yy] >= g[x][y] {
            continue
        }
        f[x][y] = max(f[x][y], dfs(xx, yy, n, m, f, g) + 1)
    }
    
    return f[x][y]
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}
```
