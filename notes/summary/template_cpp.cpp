#include <iostream>
#include <cstdio>
#include <map>

// define 宏定义
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

// 开 LL
typedef long long LL;

// template T
template <typename T>
void chkMax(T &x, T y)
{
    if (y > x)
        x = y;
}
template <typename T>
void chkMin(T &x, T y)
{
    if (y < x)
        x = y;
}

// 字符串转数字 read(a[i]);
template <typename T>
void inline read(T &x)
{
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0' || s > '9')
    {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s <= '9' && s >= '0')
        x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;
