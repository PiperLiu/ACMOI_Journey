
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [数位DP](#数位dp)
  - [度的数量](#度的数量)
  - [数字游戏](#数字游戏)
  - [Windy数](#windy数)

<!-- /code_chunk_output -->

### 数位DP

**技巧1：**

把 `f(x, y)` 转换为 `f(x)` ，比如遇到了 `[X, Y]` 可以思考能否转换为 `f(y) - f(x - 1)`

**技巧2:**

尽量用树的形式考虑。

#### 度的数量

求给定区间 $[X,Y]$ 中满足下列条件的整数个数：这个数恰好等于 $K$ 个互不相等的 $B$ 的整数次幂之和。

例如，设 $X = 15, Y = 20, K = 2, B = 2$，则有且仅有下列三个数满足题意：

- $17 = 2^4 + 2^0$
- $18 = 2^4 + 2^1$
- $20 = 2^4 + 2^2$

<h4>输入格式</h4>

第一行包含两个整数 $X$ 和 $Y$，接下来两行包含整数 $K$ 和 $B$。

<h4>输出格式</h4>

只包含一个整数，表示满足条件的数的个数。

<h4>数据范围</h4>

- $1 \le X \le Y \le 2^{31}-1$,
- $1 \le K \le 20$,
- $2 \le B \le 10$

<h4>输入样例：</h4>

```
15 20
2
2
```

<h4>输出样例：</h4>

```
3
```

分析：

这道题可以先求 $0~N$ 的数字数量。

![](./images/2021100601.png)

![](./images/2021100602.png)

组合数求和：$C_a^b = C_{a-1}^{b-1} + C_{a-1}^b$

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;  // 转为 B 进制后可能有 31 位

int K, B;
int f[N][N];

void init()
{   // 预处理 C_a^b
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) f[i][j] = 1;
            else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
}

int dp(int n)
{
    if (!n) return 0;

    vector<int> nums;
    while (n) nums.push_back(n % B), n /= B;  // 转为 B 进制

    int res = 0;
    int last = 0;  // 已经有多少 1 被分配
    for (int i = nums.size() - 1; i >= 0; i -- )
    {   // 从高位开始，对应咱们上面画的树
        int x = nums[i];
        if (x)  // 求左边分支中的数的个数（只有当 i 位不是 0 时才有必要枚举）
        {
            res += f[i][K - last];  // 第 i 位不是1是0时，比 i 低的位（共 i 位）随便填，共 K - last 个 1 
            if (x > 1)  // 只要当 i 位大于 1 时才有必要枚举
            {   // 第 i 位放 1 ，剩下的位随便填，共 K - last - 1 个 1 
                if (K - last - 1 >= 0) res += f[i][K - last - 1];
                break;  // 如果第 i 位放 1 ，则与上图不同，本题没必要继续枚举了，因为每位上只能0/1
            }
            else
            {
                last ++ ;  // 表示进入右边的分支，且这个分支表示 i 位为 1
                if (last > K) break;
            }
        }

        if (!i && last == K) res ++ ;   // 最右侧分支上的方案（最下面的，只有当 i == 0 且 所有 1 都用掉才合法）
    }

    return res;
}

int main()
{
    init();

    int l, r;
    cin >> l >> r >> K >> B;

    cout << dp(r) - dp(l - 1) << endl;

    return 0;
}
```

#### 数字游戏

科协里最近很流行数字游戏。

某人命名了一种不降数，这种数字必须满足从左到右各位数字呈非下降关系，如 $123$，$446$。

现在大家决定玩一个游戏，指定一个整数闭区间 $[a,b]$，问这个区间内有多少个不降数。

<h4>输入格式</h4>

输入包含多组测试数据。

每组数据占一行，包含两个整数 $a$ 和 $b$。

<h4>输出格式</h4>

每行给出一组测试数据的答案，即 $[a,b]$ 之间有多少不降数。

<h4>数据范围</h4>

$1 \le a \le b \le 2^{31}-1$

<h4>输入样例：</h4>

```
1 9
1 19
```

<h4>输出样例：</h4>

```
9
18
```

![](./images/2021100603.png)

![](./images/2021100604.png)

和上一题思路基本一样。但是用递推而非组合数求左侧叶子节点。

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 15;

int f[N][N];    // f[i, j]表示一共有i位，且最高位填j的数的个数

void init()
{
    for (int i = 0; i <= 9; i ++ ) f[1][i] = 1;

    for (int i = 2; i < N; i ++ )
        for (int j = 0; j <= 9; j ++ )
            for (int k = j; k <= 9; k ++ )
                f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (!n) return 1;  // 0 要特判

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0;
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];  // 从高位开始
        for (int j = last; j < x; j ++ )  // 最高位不能填 x 剩下情况都行
            res += f[i + 1][j];  // 因为如果填 x 则可能比 n 大

        if (x < last) break;  // 如果 x 比上一位还小，则枚举 0~i 位的情况已经被上面的循环涵盖
        last = x;  // 否则， x 大于等于 last ，则接下来枚举第 i+1 位是 last ，第 0~i 位的情况

        if (!i) res ++ ;  // 能抵达最后，说明之前的数都是合法的
    }

    return res;
}

int main()
{
    init();

    int l, r;
    while (cin >> l >> r) cout << dp(r) - dp(l - 1) << endl;

    return 0;
}
```

#### Windy数

Windy 定义了一种 Windy 数：不含前导零且相邻两个数字之差至少为 $2$ 的正整数被称为 Windy 数。

Windy 想知道，在 $A$ 和 $B$ 之间，包括 $A$ 和 $B$，总共有多少个 Windy 数？

<h4>输入格式</h4>

共一行，包含两个整数 $A$ 和 $B$。

<h4>输出格式</h4>

输出一个整数，表示答案。

<h4>数据范围</h4>

$1 \le A \le B \le 2 \times 10^9$

<h4>输入样例1：</h4>

```
1 10
```

<h4>输出样例1：</h4>

```
9
```

<h4>输入样例2：</h4>

```
25 50
```

<h4>输出样例2：</h4>

```
20
```

![](./images/2021100605.png)

如上，还是和上题差不多。

```cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11;

int f[N][10];

void init()
{
    for (int i = 0; i <= 9; i ++ ) f[1][i] = 1;

    for (int i = 2; i < N; i ++ )
        for (int j = 0; j <= 9; j ++ )
            for (int k = 0; k <= 9; k ++ )
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (!n) return 0;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = -2;  // last 初始值是一个和 0~9 距离大于等于 2 的数就好
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];
        for (int j = i == nums.size() - 1; j < x; j ++ )  // 如果 i 是最高位，枚举 [1, x) 否则 [0, x)
            if (abs(j - last) >= 2)
                res += f[i + 1][j];

        if (abs(x - last) >= 2) last = x;
        else break;  // i 位定为 x 的情况都被 i + 1 位时枚举了， break

        if (!i) res ++ ;
    }

    // 特殊处理有前导零的数
    for (int i = 1; i < nums.size(); i ++ )
        for (int j = 1; j <= 9; j ++ )
            res += f[i][j];

    return res;
}

int main()
{
    init();

    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;

    return 0;
}
```
