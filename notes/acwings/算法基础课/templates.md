
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [数列题模板](#数列题模板)

<!-- /code_chunk_output -->

### 数列题模板
```cpp
#include <iostream>
#define mem(x, num) memset(x, num, sizeof x)

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;  // N 是输入序列最大长度

int n;     // n 是序列长度
int q[N];  // q 是输入序列
// 注意：有其他要加入的变量吗？

// 你的函数体：注意修改返回值/参数类型！
// void func(int q[], int l, int r)
// {

// }

int main()
{
    // 接收输入序列
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    // 你的函数
    // func(q, 0, n - 1);

    // 输出序列
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}
```