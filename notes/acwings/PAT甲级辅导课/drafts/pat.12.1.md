
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [魔术卷 1037 Magic Coupon (25 point(s))](#魔术卷-1037-magic-coupon-25-points)
- [排成最小的数字 1038 Recover the Smallest Number (30 point(s))](#排成最小的数字-1038-recover-the-smallest-number-30-points)
- [用 Swap(0, i) 操作进行排序 1067 Sort with Swap(0, i) (25 point(s))](#用-swap0-i-操作进行排序-1067-sort-with-swap0-i-25-points)

<!-- /code_chunk_output -->

### 魔术卷 1037 Magic Coupon (25 point(s))

<p>火星上的魔术商店正在提供一些魔术优惠券。</p>

每个优惠券上都印有一个整数 $N$，当你将此优惠券用于产品时，商店会给你 $N$ 倍于该商品价值的钱。

此外，该商店还免费提供一些赠品。

如果你将印有正整数 $N$ 的优惠券用于赠品，你就必须向商店支付 $N$ 乘以赠品价值的钱

但是，神奇的是，他们有一些 $N$ 为负数的优惠券！

例如，给定一组优惠券，上面印的数字依次为 <code>{1 2 4 -1}</code> 以及一组产品，价值分别为 <code>{7 6 -2 -3}</code>（产品价值为负的是赠品）。

你可以使用第三张优惠券购买第一个产品，得到 $28$ 元，使用第二张优惠券购买第二个产品，得到 $12$ 元，使用第四张优惠券购买第四个产品，得到 $3$ 元。

也就是说，你通过合理使用优惠券，最多可以从商店那里拿走 $43$ 元钱。

<p>现在，给定你若干的优惠券和若干的商品，每个优惠券和商品最多只能选择一次，请问你最多可以从商店里拿回多少钱。</p>

<h4>输入格式</h4>

第一行包含一个整数 $N_c$，表示优惠卷数量。

第二行包含 $N_c$ 个整数，表示各优惠券上印有的数值。

第三行包含一个整数 $N_p$，表示产品数量。

第四行包含 $N_p$ 个整数，表示各产品的价值。

<h4>输出格式</h4>

<p>输出一个整数，表示最多可以拿回的钱数。</p>

<h4>数据范围</h4>

- $1 \le N_c,N_p \le 10^5$,
- 输入的两个整数序列中的元素的绝对值均不超过 $100$。

<h4>输入样例：</h4>

<pre><code>
4
1 2 4 -1
4
7 6 -2 -3
</code></pre>

<h4>输出样例：</h4>

<pre><code>
43
</code></pre>

#### 1037 Magic Coupon (25 point(s))
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!

For example, given a set of coupons `{ 1 2 4 −1 }`, and a set of product values `{ 7 6 −2 −3 }` (in Mars dollars M\$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M\$7) to get M\$28 back; coupon 2 to product 2 to get M\$12 back; and coupon 4 to product 4 to get M$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M\$12 to the shop.

Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.

#### Input Specification:
Each input file contains one test case. For each case, the first line contains the number of coupons $N_C$, followed by a line with $N_C$ coupon integers. Then the next line contains the number of products $N_P$, followed by a line with $N_P$ product values. Here $1≤N_C,N_P≤10^5$, and it is guaranteed that all the numbers will not exceed $2^{30}$.

#### Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.

```cpp
```

### 排成最小的数字 1038 Recover the Smallest Number (30 point(s))

给定一个数组，数组中包含若干个整数，数组中整数可能包含前导 $0$。

<p>你需要将数组中的所有数字拼接起来排成一个数，并使得该数字尽可能小。</p>

例如，给定一个数组 $\lbrace 32, 321, 3214, 0229, 87 \rbrace$，我们可以将其中的数字排列成多种不同的数，例如 <code>32-321-3214-0229-87</code> 或 <code>0229-32-87-321-3214</code>，而能排列出的最小的数字为 <code>0229-321-3214-32-87</code>。

<h4>输入格式</h4>

共一行，首先包含一个整数 $N$，表示数组中元素的个数。接下来包含 $N$ 个非负数字，每个数字不超过 $8$ 位，可能包含前导 $0$。

<h4>输出格式</h4>

<p>输出能排列出的最小数字。</p>

注意，结果的前导 $0$ 要全部去掉。

<h4>数据范围</h4>

$1 \le N \le 10^4$

<h4>输入样例：</h4>

<pre><code>
5 32 321 3214 0229 87
</code></pre>

<h4>输出样例：</h4>

<pre><code>
22932132143287
</code></pre>

#### 1038 Recover the Smallest Number (30 point(s))
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given { 32, 321, 3214, 0229, 87 }, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

#### Input Specification:
Each input file contains one test case. Each case gives a positive integer $N (≤10^4)$ followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

#### Output Specification:
For each test case, print the smallest number in one line. Notice that the first digit must not be zero.

### 用 Swap(0, i) 操作进行排序 1067 Sort with Swap(0, i) (25 point(s))

给定一个 $0 \sim N-1$ 的随机排列，将其变为升序排列非常简单。

如果只能使用 <code>Swap(0, *)</code> 操作（将数字 $0$ 和另一个数字交换位置），使得序列变成升序排列呢？

<p>例如，给定序列 <code>{4, 0, 2, 1, 3}</code>，我们可以通过下列交换操作，得到升序序列：</p>

<pre><code>
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
</code></pre>

<p>现在，请你求出将给定序列按如上交换操作变为升序序列，至少需要多少步操作。</p>

<h4>输入格式</h4>

第一行包含整数 $N$，表示序列中元素个数。

第二行包含一个 $0 \sim N-1$ 的随机排列序列。

<h4>输出格式</h4>

<p>输出所需最少操作步数。</p>

<h4>数据范围</h4>

$1 \le N \le 10^5$

<h4>输入样例：</h4>

<pre><code>
10
3 5 7 2 6 4 9 0 8 1
</code></pre>

<h4>输出样例：</h4>

<pre><code>
9
</code></pre>

#### 1067 Sort with Swap(0, i) (25 point(s))
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if `Swap(0, *)` is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
```
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
```
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

#### Input Specification:
Each input file contains one test case, which gives a positive $N (≤10^5)$ followed by a permutation sequence of `{0, 1, ..., N−1}`. All the numbers in a line are separated by a space.

#### Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

```cpp
```
