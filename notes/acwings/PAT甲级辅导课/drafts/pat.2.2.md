
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [霍格沃茨的 A + B 1058 A+B in Hogwarts (20 point(s))](#霍格沃茨的-a-b-1058-ab-in-hogwarts-20-points)
- [延迟的回文数 1136 A Delayed Palindrome (20 point(s))](#延迟的回文数-1136-a-delayed-palindrome-20-points)

<!-- /code_chunk_output -->

### 霍格沃茨的 A + B 1058 A+B in Hogwarts (20 point(s))

<p>如果你是哈利波特的粉丝，你就会知道魔术世界有其自己的货币体系。</p>

正如海格对哈利解释的那样：“$17$ 个银镰刀（Sickle）可以换 $1$ 个帆船（Galleon），$29$ 个克努特（Knut）可以换 $1$ 个银镰刀。”


你的工作是编写一个计算 $A+B$ 的程序，其中 $A$ 和 $B$ 以 <code>Galleon.Sickle.Knut</code> 的标准形式给出（<code>Galleon</code> 是一个范围在 $[0,10^7]$ 的整数，<code>Sickle</code> 是一个范围在 $[0,17)$ 的整数，<code>Knut</code> 是一个范围在 $[0,29)$ 的整数）。

<h4>输入格式</h4>

共一行，包含 $A$ 和 $B$，格式如题目所述。

<h4>输出格式</h4>

按照题目所述标准格式，输出 $A+B$ 的结果。

<h4>输入样例：</h4>

<pre><code>
3.2.1 10.16.27
</code></pre>

<h4>输出样例：</h4>

<pre><code>
14.1.28
</code></pre>

#### 1058 A+B in Hogwarts (20 point(s))
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of Galleon.Sickle.Knut (Galleon is an integer in $[0,10^7]$, Sickle is an integer in $[0, 17)$, and Knut is an integer in $[0, 29)$).

#### Input Specification:
Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

#### Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input.

```cpp
```

### 延迟的回文数 1136 A Delayed Palindrome (20 point(s))

给定一个 $k+1$ 位的正整数 $N$，写成 $a_k \cdots a_1a_0$ 的形式，其中对所有 $i$ 有 $0 \le a_i < 10$ 且 $a_k$ 大于 $0$。

$N$ 被称为一个回文数，当且仅当对所有 $i$ 有 $a_i = a_{k-i}$。

<p>零也被定义为一个回文数。</p>

<p>非回文数也可以通过一系列操作变出回文数。</p>

<p>首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，直到一个回文数出现。</p>

<p>如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。</p>

<p>给定任意一个正整数，本题要求你找到其变出的那个回文数。</p>

<h4>输入格式</h4>

输入在一行中给出一个不超过 $1000$ 位的正整数。

<h4>输出格式</h4>

<p>对给定的整数，一行一行输出其变出回文数的过程。</p>

每行格式如下：

<pre><code>
A + B = C
</code></pre>

其中 <code>A</code> 是原始的数字，<code>B</code> 是 <code>A</code> 的逆转数，<code>C</code> 是它们的和。<code>A</code> 从输入的整数开始。

重复操作直到 <code>C</code> 在 $10$ 步以内变成回文数，这时在一行中输出 <code>C is a palindromic number.</code>；

或者如果 $10$ 步都没能得到回文数，最后就在一行中输出 <code>Not found in 10 iterations.</code>。

<h4>输入样例1：</h4>

<pre><code>
97152
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
196
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
</code></pre>

#### 1136 A Delayed Palindrome (20 point(s))
Consider a positive integer N written in standard notation with k+1 digits $a_i$ as $a_k \cdots a_1a_0$ with $0 \le a_i < 10$ for all i and $a_k>0$. Then N is palindromic if and only if $a_i = a_{k−i}$ for all i. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )

Given any positive integer, you are supposed to find its paired palindromic number.

#### Input Specification:
Each input file contains one test case which gives a positive integer no more than 1000 digits.

#### Output Specification:
For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:
```
A + B = C
```
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line C is a palindromic number.; or if a palindromic number cannot be found in 10 iterations, print Not found in 10 iterations. instead.

```cpp

```