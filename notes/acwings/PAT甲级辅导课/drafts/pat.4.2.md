
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [插入还是归并 1089 Insert or Merge (25 point(s))](#插入还是归并-1089-insert-or-merge-25-points)

<!-- /code_chunk_output -->

### 插入还是归并 1089 Insert or Merge (25 point(s))

<p>根据维基百科：</p>

<p>插入排序迭代，每次将一个插入元素插入到排好序的输出序列中，每次迭代插入排序都会从输入数据中移除一个元素，并在已排好序的序列中找到它所属的位置，然后将其插入。直到没有输入元素剩余为止。</p>

归并排序的工作方式如下：将未排序的序列划分为 $N$ 个子序列，每个子序列包含 $1$ 个元素（将 $1$ 个元素的序列视为已排序）。然后重复合并两个相邻的子序列以产生新的排序子序列，直到仅剩 $1$ 个子序列为止。

<p>现在，给定初始序列，以及经过某种排序方法多次迭代后的序列，请你判断我们使用的哪一种排序方法。</p>

<h4>输入格式</h4>

第一行包含整数 $N$，表示序列中整数个数。

第二行包含 $N$ 个整数表示初始序列。

第三行包含 $N$ 个整数表示经过若干次迭代后的序列。

<p>假定排序的目标序列总是递增的。</p>

<h4>输出格式</h4>

<p>第一行输出 <code>Insertion Sort</code> 或 <code>Merge Sort</code>，以指明所采用的具体排序方法。</p>

<p>运用此方法再进行一次迭代，并在第二行输出本次迭代后的序列。</p>

<p>数据保证答案唯一。</p>

<h4>数据范围</h4>

$1 \le N \le 100$

<h4>输入样例1：</h4>

<pre><code>
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
Insertion Sort
1 2 3 5 7 8 9 4 6 0
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
Merge Sort
1 2 3 8 4 5 7 9 0 6
</code></pre>

#### 1089 Insert or Merge (25 point(s))
According to Wikipedia:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.

Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.

Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

```cpp
// 先判断是否为插排

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];

bool check()
{
    for (int i = 0; i < n; i ++ )
        if (a[i] != b[i])
            return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];

    int k = 0;
    while (b[k + 1] >= b[k]) k ++ ;

    bool match = true;
    for (int i = k + 1; i < n; i ++ )
        if (a[i] != b[i])
        {
            match = false;
            break;
        }

    if (match)  // 是插排
    {
        puts("Insertion Sort");
        sort(b, b + k + 2);  // 我们要排 0~k+1 但是sort(arg1, arg2) arg2 要求最后的位置的下一个位置
        cout << b[0];
        for (int i = 1; i < n; i ++ ) cout << ' ' << b[i];
        cout << endl;
    }
    else
    {
        puts("Merge Sort");

        int k = 1;
        while (true)
        {
            bool match = check();

            int len = 1 << k;  // 2 的 k 次方
            for (int i = 0; i < n; i += len)
                sort(a + i, a + min(n, i + len));

            if (match) break;  // 上次排序有效，说明迭代了
            k ++ ;
        }

        cout << a[0];
        for (int i = 1; i < n; i ++ ) cout << ' '<< a[i];
        cout << endl;
    }

    return 0;
}
```
