<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [堆路径 1155 Heap Paths (30 point(s))](#堆路径-1155-heap-paths-30-points)

<!-- /code_chunk_output -->

### 堆路径 1155 Heap Paths (30 point(s))

<p>在计算机科学中，堆是一种的基于树的专用数据结构，它具有堆属性：</p>

如果 $P$ 是 $C$ 的父结点，则在大顶堆中 $P$ 结点的权值大于或等于 $C$ 结点的权值，在小顶堆中 $P$ 结点的权值小于或等于 $C$ 结点的权值。

<p>一种堆的常见实现是二叉堆，它是由完全二叉树来实现的。</p>

<p>可以肯定的是，在大顶/小顶堆中，任何从根到叶子的路径都必须按非递增/非递减顺序排列。</p>

<p>你的任务是检查给定完全二叉树中的每个路径，以判断它是否是堆。</p>

<h4>输入格式</h4>

第一行包含整数 $N$，表示树中结点数量。

第二行包含 $N$ 个 <strong>不同</strong> 的整数，表示给定完全二叉树的层序遍历序列。

<h4>输出格式</h4>

<p>对于给定的树，首先输出所有从根到叶子的路径。</p>

<p>每条路径占一行，数字之间用空格隔开，行首行尾不得有多余空格。</p>

<p>必须以如下顺序输出路径：对于树中的每个结点都必须满足，其右子树中的路径先于其左子树中的路径输出。</p>
<p>最后一行，如果是大顶堆，则输出 <code>Max Heap</code>，如果是小顶堆，则输出 <code>Min Heap</code>，如果不是堆，则输出 <code>Not Heap</code>。</p>

<h4>数据范围</h4>

<p>$1 < N \le 1000$</p>

<h4>输入样例1：</h4>

<pre><code>
8
98 72 86 60 65 12 23 50
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
98 86 23
98 86 12
98 72 65
98 72 60 50
Max Heap
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
8
8 38 25 58 52 82 70 60
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
8 25 70
8 25 82
8 38 52
8 38 58 60
Min Heap
</code></pre>

<h4>输入样例3：</h4>

<pre><code>
8
10 28 15 12 34 9 8 56
</code></pre>

<h4>输出样例3：</h4>

<pre><code>
10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap
</code></pre>

#### 1155 Heap Paths (30 point(s))
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))

One thing for sure is that all the keys along any path from the root to a leaf in a max/min heap must be in non-increasing/non-decreasing order.

Your job is to check every path in a given complete binary tree, in order to tell if it is a heap or not.

#### Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer $N (1<N≤1,000)$, the number of keys in the tree. Then the next line contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.

#### Output Specification:
For each given tree, first print all the paths from the root to the leaves. Each path occupies a line, with all the numbers separated by a space, and no extra space at the beginning or the end of the line. The paths must be printed in the following order: for each node in the tree, all the paths in its right subtree must be printed before those in its left subtree.

Finally print in a line `Max Heap` if it is a max heap, or `Min Heap` for a min heap, or `Not Heap` if it is not a heap at all.

```cpp
```
