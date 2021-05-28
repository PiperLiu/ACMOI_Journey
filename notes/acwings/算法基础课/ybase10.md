<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [质数](#质数)
  - [质数的判定——试除法](#质数的判定试除法)
  - [分解质因数——试除法](#分解质因数试除法)
  - [筛质数](#筛质数)
  - [朴素法筛质数（埃氏筛法）](#朴素法筛质数埃氏筛法)
  - [线性筛法](#线性筛法)

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
  - 调和级数：$\lim_{n \to \infty}(\frac{n}{2} + \frac{n}{3} + ... \frac{n}{n}) = \ln{n} + c \approx \ln{n} + 0.57$
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
- 数学定理（质数定理）：$1~n$中有$\frac{n}{\ln{n}}$个质数
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

> 学到 40:00