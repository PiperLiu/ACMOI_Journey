
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [快速排序（基于分治）](#快速排序基于分治)
  - [快排模板](#快排模板)
- [归并排序（从中心分治）](#归并排序从中心分治)
  - [归并模板](#归并模板)
- [整数二分（很多边界问题）](#整数二分很多边界问题)
  - [整数二分模板](#整数二分模板)
  - [整数二分模板挑选心得](#整数二分模板挑选心得)
- [浮点数二分](#浮点数二分)
  - [浮点数二分模板](#浮点数二分模板)

<!-- /code_chunk_output -->

### 快速排序（基于分治）
![](./images/20210504快排.png)
- 首先，确定分界点：`q[l], q[(l+r)/2], q[r]` 或者随机确定一个也可
- 调整区间：使得第一个区间的数都小于等于`x`，第二个区间的数都大于等于`x`
- 递归处理左右两段

##### 调整区间一种优美方法：用两个指针
双指针`i与j`往中间走。

![](./images/20210504双指针.png)

`i`遇到比`x`大的停下，`j`遇到比`x`小的停下，此时`i和j`值交换；两个指针接着按照这个规则向中间走，直到两个指针相遇。

为什么合理：
- 保证了任何时刻，`i`左边的数都小于等于`x`
- 证了任何时刻，`j`左边的数都小于等于`y`

**处理边界问题，建议大家背模板。**

#### 快排模板
```cpp
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    // 没数就不用排序了
    if (l >= r) return;

    // 先把指针向中间移动一次，因此定义分界点时时有偏移量
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        // 如果 i 和 j 没相遇，交换
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    quick_sort(q, 0, n-1);

    for (int i = 0; i < n; i ++) print("%d ", q[i]);

    return 0;
}
```

强调：
- swap 是交换两个数，如果用的语言没有 swao 可以手写

```cpp
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
```

### 归并排序（从中心分治）
- 第一步，确定分界点 `mid=(1+r)/2`
- 第二步，先递归两边
- 第三步，归并（合二为一），把两个有序的数组合起来

双指针算法做归并：
- 两个排好序的序列
- 两个指针分别指向两个序列最左边（最小值）
- 比较两个指针指向的值
- 谁小，就把谁的值加到 `res` 里，同时指针后移
  - 当两个数相同时，我们倾向于把第一个序列的数移到后面去
- 有任何一个指针移到自己序列的最右端，就把另一个序列指针右边的序列直接补到 `res` 里

排序算法是 **稳定** 的：指原序列里两个数值相同，排序后，其位置不发生变化。快排是不稳定的，归并排序是稳定的。如何把快排变稳定？让快排里数唯一：变成`pair`如`a_i => <a_i, i>`

##### 为何归并时间复杂度`nlog(n)`
![](./images/20210504快排nlogn.png)
如上，一共进行了$log_2(n)$层，每层都是检测一次元素$n$。所以是`nlog_2(n)`。

#### 归并模板
```cpp
const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    // 有没有数
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    // i指向序列一起点
    // j指向序列二起点
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        // 每次把小的放在答案里去
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    // 把没移到末端的指针移到末端，放到tmp里
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}
```

### 整数二分（很多边界问题）
#### 整数二分模板
```cpp
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}

// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

##### 二分的本质
二分的本质并不是单调性。

有单调性一定可以二分，没有单调性也可能可以二分。

![](./images/20210504二分性质.png)

二分的本质是边界：
- 使得左边满足性质，右边不满足性质。

![](./images/20210504二分做法.png)

怎么做：
第一个模板：
- `mid = (l+r) / 2`
  - `if (check(mid))`
    - true 则答案在 `[l, mid]`，写 `r = mid`
        - false 则答案在 `[mid+1, r]`，写 `l = mid + 1`

第二个模板：
- `mid = (l+r+1) / 2`
  - `if (check(mid))`
    - true 则答案在 `[mid, r]`，写 `l=mid`
    - false 则答案在 `[l, mid - 1]`，写 `r = mid - 1`

做的流程：
- 先写一个 check() 函数
- 考虑 check() 是 true 或 false 时 mid 如何赋值给 r 或 l
- 选择模板，具体看下面的题

##### 何时用什么模板？
> 789. 数的范围
> 给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。

> 对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0 开始计数）。

> 如果数组中不存在该元素，则返回 -1 -1。

> 输入格式
> - 第一行包含整数 n 和 q，表示数组长度和询问个数。

> - 第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。

> - 接下来 q 行，每行包含一个整数 k，表示一个询问元素。

输入：
```
6 3
1 2 2 3 3 4
3
4
5
```

输出：
```
3 4
5 5
-1 -1
```

![](./images/20210504二分模板判断.png)

```cpp
#include <iostream>
using namespace std;

#define N 100010

int arr[N];

int find_left(int arr[], int n, int k) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (arr[mid] >= k) {
            // 说明左边界 可能还在左边，但也有可能是当前元素，所以以当前元素为右端点，向左找
            r = mid;
            // ！！判断性质后，用 mid 更新 r ，因此之前要 mid = l + r >> 1; 否则可能陷入死循环
        } else l = mid + 1;
    }
    if (arr[l] != k) return -1;
    else return l;
}


int find_right(int arr[], int n, int k) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[mid] <= k) {
            // 说明右边界 可能还在右边，但也有可能是当前元素，所以以当前元素为左端点，向右找
            l = mid;
            // ！！判断性质后，用 mid 更新 l ，因此之前要 mid = l + r + 1 >> 1; 否则可能陷入死循环
        } else r = mid - 1;
    }
    if (arr[l] != k) return -1;
    else return l;
}

int main() {
    // 使用二分法，分别查找该值左右边界

    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> arr[i];
    int k;
    while (q--) {
        cin >> k;
        cout << find_left(arr, n, k) << " " << find_right(arr, n, k) << endl;
    }
}

作者：blalalt
链接：https://www.acwing.com/solution/content/12542/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

上题中，我们用了两次二分，**每次二分实际上都是在根据某种性质切割一个区间：**
- 第一个二分，实际上定义的性质是`右区间>=k，左区间不是`
- 第二个二分，实际上定义的性质是`左区间<=k，右区间不是`

注意二分一定能给出一个解，但可能不是可行解，因此我们这里做了异常判断。

#### 整数二分模板挑选心得

显而易见，如果只有序列中只有两个数，那么为了不陷入死循环：
- 如果使用 `r = mid; l = mid + 1` 这种更新方式，则要求开始时 `mid` 就不同于 `r` ，所以有 `mid = l + r >> 2`
- 如果使用 `l = mid; r = mid - 1` 这种更新方式，则要求开始时 `mid` 就不同于 `l` ，所以有 `mid = l + r + 1>> 2`
- （`>> 2` 是向下取整）

记忆：
- `l=mid`则`+1`

### 浮点数二分
#### 浮点数二分模板
```cpp
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        // 如果左区间满足性质
        // r 往左移
        // 否则 l 右移
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

经验：
- 如果题目要求四位小数，则 `eps = 1e-6`，五位则 `eps = 1e-7`