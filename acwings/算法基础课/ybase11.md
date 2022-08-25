<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [ŷ������](#ŷ������)
  - [ŷ�����������巨���⣩](#ŷ���������巨����)
  - [ɸ����ŷ������](#ɸ����ŷ������)
- [ŷ����������С����](#ŷ������-����С����)
- [������](#������)
  - [����д���Ŀ�����](#����д���Ŀ�����)
  - [����������Ԫ](#����������Ԫ)
- [��չŷ������㷨](#��չŷ������㷨)
  - [��������](#��������)
  - [��չŷ������㷨����](#��չŷ������㷨����)
  - [����ͬ�෽��](#����ͬ�෽��)
  - [����ͬ�෽������](#����ͬ�෽������)
- [�й�ʣ�ඨ�����Ӷ���](#�й�ʣ�ඨ�����Ӷ���)
  - [���⣺�����������ַ�ʽ](#��������������ַ�ʽ)

<!-- /code_chunk_output -->

### ŷ������

$1 \sim N$����$N$���ʵ����ĸ�������Ϊŷ����������Ϊ$\phi(N)$��

���������Ļ��������У�$N=p_1^{a_1} p_2^{a_2} ... p_m^{a_m}$ ������

$$\phi(N) = N \times \frac{p_1 - 1}{p_1} \times \frac{p_2 - 1}{p_2} \times ... \times \frac{p_m - 1}{p_m}$$

�������Ӧ�����ݳ�ԭ��
- �� $N$ �У���ȥ���� $p_1$ �� $p_2$ ... $p_m$ �ı���
- �� $N$ �У���Ϊ�еı������ϸ������ظ������ˣ����� $p_1$ �� $p_2$ �ı��������� $p_1 p_2$ �ı�������� $p_1 p_2$ �ı����ͱ��������Σ������Լӻ��������� $p_1 p_2$ �� $p_2 p_3$ ... �ı���
- ...

�����У�
$$
\begin{aligned}
& & N & - \frac{N}{p_1} - \frac{N}{p_2} - ... - \frac{N}{p_m} \\
& & & + \frac{N}{p_1 p_2} + \frac{N}{p_2 p_3} + ... + \frac{N}{p_{m-1} p_m} \\
& & &  - \frac{N}{p_1 p_2 p_3} - \frac{N}{p_2 p_3 p_4} - ... - \frac{N}{p_{m-2} p_{m-1} p_m} \\
& & &  + \frac{N}{p_1 p_2 p_3 p_4} + \frac{N}{p_2 p_3 p_4 p_5} + ... + \frac{N}{p_{m-3} p_{m-2} p_{m-1} p_m} \\
& & & ...
\end{aligned}
$$

��ʽ�����������ı����������ˣ�Ҳ�� $\phi (N)$ ��չ����

#### ŷ�����������巨���⣩
- ���� n �������� $a_i$���������ÿ������ŷ��������

�����ʽ
- ��һ�а������� n��
- ������ n �У�ÿ�а���һ�������� $a_i$��

�����ʽ
- ����� n �У�ÿ�����һ�������� $a_i$ ��ŷ��������

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    while (n --)
    {
        int x;
        scanf("%d", &x);
        int res = x;
        for (int i = 2; i <= x / i; i ++)
        {
            if (x % i == 0)
            {
                res = res / i * (i - 1);  // �ȳ��ٳˣ��������Խ��
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) res = res / x * (x - 1);  // �ȳ��ٳ�
        printf("%d\n", res);
    }
    
    return 0;
}
```

**���飺**
- **�ȳ��ٳˣ�** һ�ǣ���ֹ�����˺� int
- ���ǣ� `7 * 11 / 2 == 38` ���� `7 / 2 * 11 == 33` ������ŷ����������ѧ��ʽ�������õڶ���

#### ɸ����ŷ������

- ����һ�������� n���� 1~n ��ÿ������ŷ������֮�͡�

�����ʽ
- ��һ�У�����һ������ n��

�����ʽ
- ��һ�У�����һ����������ʾ 1~n ��ÿ������ŷ������֮�͡�

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

typedef long long LL;

int primes[N], cnt;
int eulers[N];
bool st[N];

void get_eulers(int n)
{
    eulers[1] = 1;
    for (int i = 2; i <= n; i ++)
    {
        if (!st[i])
        {
            primes[cnt ++] = i;
            eulers[i] = i - 1;  // ����
        }
        
        for (int j = 0; primes[j] <= n / i; j ++)
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                eulers[t] = eulers[i] * primes[j];
                break;
            }
            else
            {
                eulers[t] = eulers[i] * (primes[j] - 1);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    get_eulers(n);
    
    LL res = 0;
    for (int i = 1; i <= n; i ++) res += eulers[i];
    printf("%lld", res);  // ע�⣬��� long long �� "%lld" ������ cout ������
    return 0;
}
```

**���飺**
- ע�⣬��� `long long` �� `"%lld"` ������ `cout` ������

��ϴ��룬����ɸ��˼·������[���ѽ�](https://www.acwing.com/user/myspace/index/6828/)��
- ���� `i` ��ŷ��������Ϊ `phi[i] = i - 1` �� $1 \sim i-1$ ���� $i$ ���ʣ��� $i-1$ ����
`phi[primes[j] * i]` ��Ϊ���������
  - `i % primes[j] == 0` ʱ�� `primes[j]` �� `i` ����С�����ӣ�Ҳ�� `primes[j] * i` ����С�����ӣ����`1 - 1 / primes[j]` ��һ���� `phi[i]` �м�����ˣ�ֻ�轫���� `N` ����Ϊ `primes[j]` �������ս��Ϊ `phi[i] * primes[j]` ��
  - `i % primes[j] != 0` �� `primes[j]` ���� `i` �������ӣ�ֻ�� `primes[j] * i` ����С�����ӣ���˲�����Ҫ������ `N` ����Ϊ `primes[j]` ��������Ҫ���� `1 - 1 / primes[j]` ��һ�������ս�� `phi[i] * (primes[j] - 1)` ��

### ŷ����������С����
ŷ�������� $a$ �� $n$ ���ʣ��� $a^{\phi(n)} \equiv 1 (\mod n)$ ��$a^{\phi(n)}$ ģ $n$ Ϊ 1�� ��

���磬$5$ �� $6$ ���ʣ��� $5^{\phi(6)} \mod 6 = 5^2 \mod 6 = 1$ ��

**֤��ŷ������**

�� $1\sim n$ �У��� $\phi(n)$ ���� $n$ ���ʵ�����$Z_n = \{ a_1, a_2, ... , a_{\phi(n)} \}$ ��

���ǽ���������г��� $a$ ���õ������� $\{a a_1, a a_2, ... , a a_{\phi(n)} \}$ ����������Ҫ֤���� $\{a a_1 \mod n, a a_2 \mod n, ... , a a_{\phi(n)} \mod n \}$ �������� $Z_n$ ������ҪӦ�� $\{a a_1, a a_2, ... , a a_{\phi(n)} \}$ ���������ʡ�

> ��һ��$i \neq j$ ���� $aa_i$ �� $aa_j$ ��ģ $n$ ͬ�ࡣ

�����÷�֤��֤�������

���� $aa_i$ �� $aa_j$ ģ $n$ ͬ�࣬��ô���� $a a_i  - a a_j = a(a_i - a_j) = n k$ ��$k$�ǳ�����������Ϊ $a$ �� $n$ ���ʣ�����Ϊ�Ⱥų�����ֻ���� $(a_i - a_j)$ �� $n$ �ı������� $a_i$ �� $a_j$ �ֱ����� $n$ ���ʵģ���ģ $n$ ��ͬ�࣬���ì���ˣ�$(a_i - a_j)$ �������� $n$ �ı�������

��˵���� $\phi(n)$ �� $\{ a a_i \mod n \}$ ����**Ψһ��Ԫ��**��

> �ڶ���$a a_i$ �� $n$ ���ʡ�

��Ϊ $a$ �� $n$ ���ʣ� $a_i$ �� $n$ ���ʣ����� $a a_i$ �� $n$ ���ʡ����ԣ�$a a_i \mod n \in \{a_1, a_2, ... , a_{\phi(n)} \}$ ������Ϊ $a a_i \mod n$ һ���� $\phi(n)$ ������ÿ������Ψһ�ģ��� $Z_n$ Ҳ��$\phi(n)$ ��Ԫ�� ����� $\{a a_1 \mod n, a a_2 \mod n, ... , a a_{\phi(n)} \mod n \}$ �������� $Z_n$ ��

������ϸ����һ�£�Ϊʲô $a a_i \mod n \in \{a_1, a_2, ... , a_{\phi(n)} \}$ ��

��Ϊ $a a_i \mod n$ һ����С�� $n$ �ģ����� $n$ ���ʡ�

С�� $n$ �ܺ���⣬�Ͼ�ȡ�� $n$ ��ģ�����ǣ�Ϊʲô $A$ �� $B$ ���ʣ���ô $A \mod B$ ���� $B$ �����أ����¡�

�� $C = A \mod B$ ���� $A + C = B k$ �� $C$ һ���� $B$ ���ʣ����� $C = B h$ ��$A = B(k - h)$ �� $k - h$ Ϊ������������ $A$ $B$ ���ʵļ���ì�ܡ�

�������￪ʼ����̫�Ͻ���δ���ɲο���[ǳ̸ŷ�������֤��](https://www.cnblogs.com/wangxiaodai/articles/9758242.html)��

���ˣ�֤���� $\{a a_1 \mod n, a a_2 \mod n, ... , a a_{\phi(n)} \mod n \}$ �������� $Z_n$ ��

���ǰ������۳ˣ����� $a^{\phi(n)} a_1 a_2 ... a_{\phi(n)} \equiv a_1 a_2 ... a_{\phi(n)} (\mod n)$ ������ģ $n$ ͬ�ࣩ��Լ������ $a^{\phi(n)} \equiv 1 (\mod n)$ ��

֤�ϡ�

> �� $n$ Ϊ���� $p$ ʱ������ $a^{\phi(p)} = a^{p-1} \equiv 1 (\mod p)$ ������Ƿ���С����

### ������

������ $a^k \mod p (1 \le a, p, k \le 10^9)$ ʱ����������Ϊ��
```cpp
LL res = 1;
for (int i = 1; i <= k; i ++)
    res = res * a % p;
```

ʱ�临�Ӷ�Ϊ $O(k)$ ��

����ʹ�ÿ����ݽ��併�͵� $O(\log k)$ ��

**������ԭ��**

���� $a^k \mod p$ ���������Ƚ��� $\log{k} + 1$ �μ��㣺
$$a^{2^0} \mod p = a^1 \mod p$$
$$a^{2^1} \mod p = a^{2^0 \cdot 2} \mod p$$
$$a^{2^2} \mod p = a^{2^1 \cdot 2} \mod p$$
$$ ... $$
$$a^{2^{\log{k}}} \mod p = (a^{2^{\log{k} - 1}})^2 \mod p$$

������Щ��$a^{...}$Ҳ�й��ɣ�**ÿ������������һ������ƽ��** ��

�����κ�һ�� $a^k$ �����Ƕ����Ի�Ϊ��
$$a^k = a^{2^{x_1}} \cdot a^{2^{x_2}} \cdot ... \cdot a^{2^{x_t}} = a^{2^{x_1} + 2^{x_2} + ... + 2^{x_t}}$$

������ $k$ ��Ϊ�����Ʊ�ʾ�� $k = 2^{x_1} + 2^{x_2} + ... + 2^{x_t}$ ��

��ˣ����������֮ǰ����� $a^{2^{\log{k}}} \mod p$ ��Щֵ�ˡ�

#### ����д���Ŀ�����

- ���� $n$ �� $a_i,b_i,p_i$������ÿ�����ݣ���� $a_i^{b_i} \mod p_i$ ��ֵ��

�����ʽ
- ��һ�а������� $n$��
- ������ n �У�ÿ�а����������� $a_i,b_i,p_i$��

�����ʽ
- ����ÿ�����ݣ����һ���������ʾ abiimodpi ��ֵ��
- ÿ�����ռһ�С�

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int n;
int a, b, p;

LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL) a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    
    while (n --)
    {
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }

    return 0;
}
```

**���飺**
- һ�ֺܺõ���ȡ���������λ�ط�����`while(b) ... b&1 ... b >>=1; `

#### ����������Ԫ

- ���� n �� $a_i,p_i$������ $p_i$ ���������� $a_i$ ģ $p_i$ �ĳ˷���Ԫ������Ԫ����������� `impossible`��
- ע�⣺�뷵���� $0\sim p-1$ ֮�����Ԫ��

> �˷���Ԫ�Ķ��壺������ b��m ���ʣ����Ҷ������������ a��������� b|a ��$a / b$ ���������������һ������ x��ʹ�� $a/b \equiv a \times x (\mod m)$����� x Ϊ b ��ģ m �˷���Ԫ����Ϊ $b^{-1}(\mod m)$��b ���ڳ˷���Ԫ�ĳ�Ҫ������ b ��ģ�� m ���ʡ���ģ�� m Ϊ����ʱ��$b^{m-2}$ ��Ϊ b �ĳ˷���Ԫ��

�����ʽ
- ��һ�а������� n��
- ������ n �У�ÿ�а���һ������ $a_i,p_i$�����ݱ�֤ $p_i$ ��������

�����ʽ
- ����� n �У�ÿ���������һ�������ÿ�����ռһ�С�
- �� $a_i$ ģ $p_i$ �ĳ˷���Ԫ���ڣ������һ����������ʾ��Ԫ��������� `impossible`��

**������**
- ����� $a$ ģ $p$ �ĳ˷���Ԫ����ʵ������ $a \cdot x \equiv 1 (\mod p)$ �У��ҷ�������ʽ�ӵ� $x$ ��
- ��Ϊ��Ŀ�������� $p$ Ϊ���������Ӧ�÷���С���� $a^{p-1} \equiv 1 (\mod p)$ �������� $a \cdot a^{p-2} \equiv 1 (\mod p)$���� $a^{p-2}$ ���� $a$ ģ $p$ �ĳ˷���Ԫ��
- ���Ա�����Ƿ���С����+������
- ���� $p$ �����������ֻ�е� $a$ �� $p$ �ı���ʱ�����߲��ǻ��ʣ���ʱ�޽�

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int n;
int a, p;

LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL) a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    
    while (n --)
    {
        scanf("%d%d", &a, &p);
        if (a % p == 0) puts("impossible");
        else printf("%lld\n", qmi(a, p-2, p));
    }

    return 0;
}
```

### ��չŷ������㷨

#### ��������

[�ٶȰٿ�](https://baike.baidu.com/item/%E8%A3%B4%E8%9C%80%E5%AE%9A%E7%90%86/5186593?fr=aladdin)��
- �������У���������һ���������Լ���������Լʽ���Ķ�������������ڷ�����ѧ�Ұ��ٰ�������
- ������˵���˶��κ����� a��b �����ǵ����Լ�� d ������δ֪�� x �Լ� y �����ԵĶ���ͼ���̣���Ϊ�����ʽ����

������a,b����������$gcd(a,b)=d$����ô�������������$x,y$��$ax+by$��һ����$d$�ı������ر�أ�һ����������$x,y$��ʹ$ax+by=d$������

֤���У�ʹ�ù��췽��������$ax+by=d$��ʹ����ŷ������㷨��

#### ��չŷ������㷨����

- ���� n �������� $a_i,b_i$������ÿ���������һ�� $x_i,y_i$��ʹ������ $a_i\times x_i+b_i\times y_i=gcd(a_i,b_i)$��

�����ʽ
- ��һ�а������� n��
- ������ n �У�ÿ�а����������� $a_i,b_i$��

�����ʽ
- ����� n �У�����ÿ�� $a_i,b_i$�����һ������������ $x_i,y_i$��ÿ����ռһ�С�
- ����𰸲�Ψһ������������������� $x_i,y_i$ ���ɡ�

**������** ���ο���[zeroAC](https://www.acwing.com/solution/content/1393/)��

������ⷽ�� $ax + by = \gcd(a,b)$ �Ľ�

�� $b=0$ ʱ�� $ax + by = a$ �ʶ� $x=1, y=0$

�� $b\neq 0$ ʱ��

��Ϊ

$$\gcd(a,b) = \gcd (b, a\%b)$$

��

$$bx' + (a\% b)y' = \gcd(b, a \% b)$$

$$b x' + (a - \lfloor a / b \rfloor \times b) y' = \gcd(b, a\% b)$$

$$ay' + b (x' - \lfloor a / b \rfloor \times y) = \gcd(b,a\% b) = \gcd (a,b)$$

�ʶ�

$$x=y', y=x' - \lfloor a / b \rfloor \times y'$$

��ˣ����Բ��õݹ飬�����һ��� $x', y'$ �ٴ��ر��㹫ʽ���ɡ�

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
    /*
    ����Ĵ��벻����⣬����дΪ
    int x1, y1;
    int d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
    */
}

int main()
{
    int n ;
    scanf("%d", &n);
    
    while (n -- )
    {
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}
```

#### ����ͬ�෽��

**�ȵ�֪ʶ��** ���ο���[zeroAC](https://www.acwing.com/solution/content/1393/)��

##### ���ڸ�һ��ķ���$ax + by = c$

�� $d = \gcd(a,b)$ �����н⵱�ҽ��� $d | c$

��ⷽ�����£�

��ŷ�������� $ax_0 + by_0 = d$ �Ľ�

�� $a(x_0 \times c / d) + b (y_0 \times c /d) = c$

�ʶ��ؽ�Ϊ $x' = x_0 \times c / d, y' = y_0 \times c / d$

�� **ͨ�� = �ؽ� + ��ν�**

����ν⼴Ϊ���� $ax + by = 0$ �Ľ�

�ʶ�ͨ��Ϊ $x = x' + k \times b / d, y = y' - k \times a / d, k \in \mathbb{Z}$

##### Ӧ�ã���һ��ͬ�෽��$ax\equiv b (\mod m)$

��ȼ�����

$$ax = m \times (-y) + b$$

$$ax + my = b$$

�н�����Ϊ $\gcd(a,m) | b$ ��Ȼ������չŷ�������⼴�ɡ�

�ر�أ��� $b = 1$ �� $a$ �� $m$ ����ʱ�� $x$ ��Ϊ $a$ ����Ԫ��

#### ����ͬ�෽������

- ���� n ������ $a_i,b_i,m_i$������ÿ�������һ�� $x_i$��ʹ������ $a_i \times x_i \equiv b_i(\mod m_i)$������޽������ `impossible`��

�����ʽ
- ��һ�а������� n��
- ������ n �У�ÿ�а���һ������ $a_i,b_i,m_i$��

�����ʽ
- ����� n �У�ÿ���������һ��������ʾһ������������ $x_i$������޽������ `impossible`��
- ÿ�����ݽ��ռһ�У�������ܲ�Ψһ���������һ�����������Ľ�����ɡ�
- ����𰸱����� `int` ��Χ֮�ڡ�

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n ;
    scanf("%d", &n);
    
    while (n -- )
    {
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if (b % d == 0) printf("%d\n", (LL) b / d * x % m);  // LL ��ֹ b / d * x �� int
        // x ���� b / d ���� % m ��Ϊ���� x �����ܵ�С
        else puts("impossible");
    }
    return 0;
}
```

### �й�ʣ�ඨ�����Ӷ���

$m_1 , m_2 , ... , m_k$ �������ʣ��� $x$ ʹ�ã�

$$x \equiv a_1 (\mod m_1)$$
$$x \equiv a_2 (\mod m_2)$$
$$ ... $$
$$x \equiv a_k (\mod m_k)$$

���Ǽǣ�

$$M = m_1 m_2 ... m_k$$

$$M_i = M / m_i$$

$ M_i^{-1} $ Ϊ $M_i$ ģ $m_i$ ����

���

$$x = a_1 M_1 M_1^{-1} + a_2 M_2 M_2^{-1} + ... + a_k M_k M_k^{-1}$$

#### ���⣺�����������ַ�ʽ

- ���� 2n ������ $a_1,a_2,��,a_n$ �� $m_1,m_2,��,m_n$����һ����С�ķǸ����� x������ $\forall i \in [1,n],x \equiv m_i(\mod a_i)$��

�����ʽ
- �� 1 �а������� n��
- �� 2��n+1 �У�ÿ i+1 �а����������� $a_i$ �� $m_i$����֮���ÿո������

�����ʽ
- �����С�Ǹ����� x����� x �����ڣ������ ?1��
- ������� x�������ݱ�֤ x һ���� 64 λ������Χ�ڡ�

**������**
- ��Ŀ��û���κ����ƣ�Ȼ�����й�ʣ�ඨ��Ҫ�� $m_i$ ��������
- ����ֻ���Ƶ�һ��

##### ������Ƶ�

�ο�[īȾ��](https://www.acwing.com/solution/content/3539/)��

![](./images/20210531sunzi01.png)
![](./images/20210531sunzi02.png)
![](./images/20210531sunzi03.png)
![](./images/20210531sunzi04.png)
![](./images/20210531sunzi05.png)
![](./images/20210531sunzi06.png)
![](./images/20210531sunzi07.png)
![](./images/20210531sunzi08.png)

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n ;
    scanf("%d", &n);
    
    LL x = 0, a1, m1;
    scanf("%lld%lld", &a1, &m1);  // ע�� "%lld"
    for (int i = 0; i < n - 1; i ++)
    {
        LL a2, m2;
        scanf("%lld%lld", &a2, &m2);

        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d)
        {
            x = -1;
            break;
        }
        
        k1 *= (m2 - m1) / d;
        k1 = (k1 % (a2/d) + a2/d) % (a2 / d);
        
        x = k1 * a1 + m1;
        
        LL a = abs(a1 / d * a2);
        m1 = k1 * a1 + m1;
        a1 = a;
    }

    if (x != -1) x = (m1 % a1 + a1) % a1;  // Ϊ��Ӧ�Ը���ȡģ
    
    printf("%lld", x);

    return 0;
}
```

**���飺**
- C++ ��Ը��� `x` ȡ `a` ��ģ `x = (x % a + a) % a`
