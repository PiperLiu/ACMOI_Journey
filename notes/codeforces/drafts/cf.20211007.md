
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [A. Consecutive Sum Riddle（观察+智商）](#a-consecutive-sum-riddle观察智商)
- [简单题不详记](#简单题不详记)

<!-- /code_chunk_output -->

### A. Consecutive Sum Riddle（观察+智商）
https://codeforces.com/contest/1594/problem/A

给你 $n\in \{ [1, 10^{18}] \}$ ，让你求 $l,r$ 其中 $l + (l+1) + ... + (r-1) + r = n$ ， $-10^{18} \le l < r \le 10^{18}$ 。

第一眼以为是前缀和。实际上我是傻逼。

首先 $10^{18}$ 根本没空也没地方处理前缀和。

其次知道了前缀和也还是要遍历，那更不可能。

答案是：

思考一下 $-1 + 0 + 1 + 2 = 2$ 有什么规律。实际上规律是：

$$(-n + 1) + (-n + 2) + ... + (n-1) + n = n$$

思考：我应该多多观察，已经有了 `2=2` ，那么，剩下就是构造出一个和为 0 的连续数组？

$$(-n+1) + (-n+2) + ... + (n-2) + (n-1)$$

看到了吗，这公式的符号是中心对称的。

### 简单题不详记

- [B. Queue at the School](https://codeforces.com/problemset/problem/266/B) 题目很简单但是 WA 了一次，我是傻逼
- [A. Insomnia cures](https://codeforces.com/problemset/problem/148/A)
- [A. Anton and Letters](https://codeforces.com/problemset/problem/443/A)
- [B. Special Numbers](https://codeforces.com/contest/1594/problem/B)
