<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [质数](#质数)
  - [质数的判定——试除法](#质数的判定试除法)
  - [分解质因数——试除法](#分解质因数试除法)
  - [筛质数](#筛质数)
  - [朴素法筛质数（埃氏筛法）](#朴素法筛质数埃氏筛法)
  - [线性筛法](#线性筛法)
- [约数](#约数)
  - [试除法求约数](#试除法求约数)
  - [约数个数与约数之和](#约数个数与约数之和)
  - [约数个数例题](#约数个数例题)
  - [约数之和例题](#约数之和例题)
  - [欧几里得算法（辗转相除法）](#欧几里得算法辗转相除法)
  - [题目：最大公约数（很优雅gcd）](#题目最大公约数很优雅gcd)

<!-- /code_chunk_output -->

### 质数
在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。也叫素数。

#### 质数的判定——试除法

- 给定 $n$ 个正整数 $a_i$，判定每个数是否是质数。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个正整数 $a_i$。

输出格式
- 共 $n$ 行，其中第 $i$ 行输出第 $i$ 个正整数 $a_i$ 是否为质数，是则输出 `Yes`，否则输出 `No`。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool is_prime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i <= x / i; i ++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    int n ;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        if (is_prime(x)) puts("Yes");
        else puts("No");
    }
    return 0;
}
```

时间复杂度 $O(\sqrt{n})$

**经验：**
- 循环判定条件 `for (int i = 2; i <= x / i; i ++)` 比 `for (int i = 2; i <= sqrt(x); i ++)` 或 `for (int i = 2; i * i <= x; i ++)` 效率更高

#### 分解质因数——试除法

- 给定 $n$ 个正整数 $a_i$，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个正整数 ai。

输出格式
- 对于每个正整数 $a_i$，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。
- 每个正整数的质因数全部输出完毕后，输出一个空行。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            printf("%d %d\n", i, s);
        }
    }
    if (x > 1) printf("%d 1\n", x);
    printf("\n");
}

int main()
{
    int n ;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
}
```

时间复杂度 $O(\log{n})$ ~ $O(\sqrt{n})$

#### 筛质数

- 给定一个正整数 $n$，请你求出 $1∼n$ 中质数的个数。

输入格式
- 共一行，包含整数 $n$。

输出格式
- 共一行，包含一个整数，表示 $1∼n$ 中质数的个数。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];  // true 不是质数

int get_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = i + i; j <= n; j += i) st[j] = true;  // 把 i 的所有倍数删去
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << get_primes(n);

    return 0;
}
```

原理是：
- 对于数 `p` ，如果其最终被保存下来，那么说明 `2~p-1` 中没有其因数

时间复杂度：
- 删除倍数过程求和 $\frac{n}{2} + \frac{n}{3} + ... \frac{n}{n}$
  - 调和级数：$\lim_{n \to \infty}(\frac{1}{2} + \frac{1}{3} + ... \frac{1}{n}) = \ln{n} + c \approx \ln{n} + 0.57$
- 因此，$\frac{n}{2} + \frac{n}{3} + ... \frac{n}{n} = n(\frac{1}{2} + \frac{1}{3} + ... \frac{1}{n})$ 可看成 $n \ln{n}$

#### 朴素法筛质数（埃氏筛法）
埃拉托斯特尼筛法。

如果是质数，才删去所有其倍数，不是的话，没必要，因为其倍数肯定已经被之前的质数删去了。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];  // true 不是质数

int get_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i])
        {
            if (st[i]) continue;
            primes[cnt ++] = n;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << get_primes(n);

    return 0;
}
```

时间复杂度：
- 数学定理（质数定理）：$1\sim n$中有$\frac{n}{\ln{n}}$个质数
- 所以就有 $\frac{n}{2} + \frac{n}{3} + ... \frac{n}{n} = n(\frac{1}{2} + \frac{1}{3} + ... \frac{1}{n})$ 基础上除以 $n$ 乘上 $\frac{n}{\ln{n}}$ 约等于 $n$
- 而实际上，其严格时间复杂度是 $O(n\log{n}\log{n})$

#### 线性筛法

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];  // true 不是质数

int get_primes(int n)
{
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++)
        {
            st[primes[j] * i] = true;  // primes[j] <= n / i 了，所以 primes[j] * i 不会爆 int
            if (i % primes[j] == 0) break;  // primes[j] 是 i 的最小质因子，从而 j 不会 primes 越界
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << get_primes(n);

    return 0;
}
```

时间复杂度 $O(n)$ 。

$n$ 只会被最小的质因子筛掉：
- `i % primes[j] == 0` 时，因为是从小到大循环，则 `primes[j]` 一定是 `primes[j] * i` 的最小质因子
- `i % primes[j] != 0` 时，因为是从小到大循环，则 `primes[j]` 一定也是 `primes[j] * i` 的最小质因子

对于一个合数 $x$ ，当 `i` 枚举到 `x / primes[j]` 时，其总是会被其最小质因子 `primes[j]` 筛掉。

### 约数

如果 $d$ 整除 $n$ （$d|n$），那么 $\frac{n}{d}|n$ （$\frac{n}{d}$也能整除 $n$）。因此约数是成对出现的，只需要枚举较小的约数就可以了，枚举到 $\sqrt{n}$ 就可可以。

#### 试除法求约数

- 给定 $n$ 个正整数 $a_i$，对于每个整数 $a_i$，请你按照从小到大的顺序输出它的所有约数。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个整数 $a_i$。

输出格式
- 输出共 $n$ 行，其中第 $i$ 行输出第 $i$ 个整数 $a_i$ 的所有约数。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        auto res = get_divisors(x);
        
        for (auto r : res) printf("%d ", r);
        puts("");
    }
    return 0;
}
```

#### 约数个数与约数之和

对于数字 $N$ ，可以因式分解如下：
$$N = p_1^{\alpha_1} p_2^{\alpha_2} ... p_k^{\alpha_k}$$

其约数总可以唯一地分解为：
$$d = p_1^{\beta_1} p_2^{\beta_2} ... p_k^{\beta_k}$$

且 $0 \le \beta_i \le \alpha_i$

因此，对于每一个 $\beta_i$ ，其取值范围为 $[0, \alpha_i]$ 共 $\alpha_i + 1$ 个。

$N$ 的约数个数为 $(\alpha_1 + 1)(\alpha_2 + 1)...(\alpha_k + 1)$ 。

$N$ 的约数之和为 $(p_1^0 + p_1^1 + ... + p_1^{\alpha_1})...(p_k^0 + p_k^1 + ... + p_k^{\alpha_k})$ 。把公式展开，其意自现。

#### 约数个数例题

- 给定 $n$ 个正整数 $a_i$，请你输出这些数的乘积的约数个数，答案对 $10_9 +7$ 取模。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个整数 $a_i$。

输出格式
- 输出一个整数，表示所给正整数的乘积的约数个数，答案需对 $10_9 +7$ 取模。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7; 

typedef long long LL;

int main()
{
    int n ;
    scanf("%d", &n);
    
    unordered_map<int, int> primes;
    
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        
        for (int i = 2; i <= x / i; i ++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }
        }
        if (x > 1) primes[x] ++ ;
    }
    
    LL res = 1;
    for (auto p: primes) res = res * (p.second + 1) % mod;
    cout << res;
    return 0;
}
```

**经验：**
- 初始化 `unordered_map<int, int> a_map` 后，`a_map[0]` 默认值都是 0
- 可以用 `auto a : a_map` 遍历赋过值的元素
- 对于累乘结果取模，不必最后乘完了再取模，可以乘一个，取一次模（可以把 $A \times B \mod C$ 中 $A$ 拆成 $A = ((A / C \times C + A \mod C) \times B \mod C)$）

#### 约数之和例题

- 给定 $n$ 个正整数 $a_i$，请你输出这些数的乘积的约数之和，答案对 $10_9 +7$ 取模。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个整数 $a_i$。

输出格式
- 输出一个整数，表示所给正整数的乘积的约数之和，答案需对 $10_9+7$ 取模。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int main()
{
    int n;
    scanf("%d", &n);
    
    unordered_map<int, int> primes;
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= x / i; i ++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }
        }
        if (x > 1) primes[x] ++ ;
    }
    
    // 现在求 (p_1^0 + ... + p_1^a1)...(p_n^0 + ... + p_n^an)
    LL res = 1;
    for (auto p : primes)
    {
        // (p_k^0 + ... + p_k^ak)
        LL a = p.first, b = p.second;  // a is p_k, b is ak
        LL t = 1;
        // (a^0 + a^1 + ... + a^b) = (1 + (1 + (1 + a) * a) * a) ...
        while (b -- ) t = (1 + t * a) % mod;
        res = t * res % mod;
    }
    printf("%d", res);
    return 0;
}
```

**经验：**
- 等比数列求和 $(a^0 + a^1 + ... + a^b) = (1 + (1 + (1 + a) * a) * a) ...$ 可以表示为 `LL t = 1; while (b -- ) t = (1 + t * a);`

#### 欧几里得算法（辗转相除法）

已知：$d|a$，$d|b$，那么一定有$d|ax+by$。其中所有符号都代表整数。

有定理：$a$和$b$的最大公约数$(a,b)$，一定等于 $b$ 和 $a \mod b$ 的最大公约数 $(b, a \mod b)$ 。

证明：
- $a \mod b = a - \lfloor \frac{a}{b} \rfloor \cdot b$
- 整数 $\lfloor \frac{a}{b} \rfloor$ 记为 $c$
- 用上面的证明可得， $(a, b) = (b, a - c \cdot b) = (b, a \mod b)$

#### 题目：最大公约数（很优雅gcd）

- 给定 $n$ 对正整数 $a_i , b_i$，请你求出每对数的最大公约数。

输入格式
- 第一行包含整数 $n$。
- 接下来 $n$ 行，每行包含一个整数对 $a_i , b_i$。

输出格式
- 输出共 $n$ 行，每行输出一个整数对的最大公约数。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
    // 分析： b 是 0 的话，输出 a
    // a % b 总是小于 a 的，这保证了最终 gcd 的第二个参数小于第一个参数
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = gcd(a, b);
        printf("%d\n", res);
    }

    return 0;
}
```
