
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [A. Consecutive Sum Riddle（观察+智商）](#a-consecutive-sum-riddle观察智商)
- [C. Make Them Equal（智商+逻辑）](#c-make-them-equal智商逻辑)
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

### C. Make Them Equal（智商+逻辑）
https://codeforces.com/contest/1594/problem/C

对于一个字符串`s = aaab`，问你最少几次操作能把`s`中的字符全部转为`c`。

操作需要满足什么条件？每次只能选择一个 `1 \le x \le n` ，将所有不可以整除 `x` 的位置（下标从 1 开始）的字符转换。

答案很牛逼。顶多操作两次：
- 对于 `1~n-1` ，我选择 `x=n` 就行；
- 如果 `n` 也是不符合要求的，那么我在选择 `x=n-1` 在操作一次就行。

下面这个官方答案的代码过于牛逼了，一个 `bool ok` 既判断了是否只把某一个位置的倍数挑出来就行，还判断了把是否最后一个数是否符合要求。

```cpp
// Problem: C. Make Them Equal
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        
        bool ok = true;
        vector<int> ans;
        for (auto&& ss: s)
        {
            if (ss != c) ok = false;
        }

        if (!ok)
        {
            for (int i = 1; i < n + 1; ++ i)
            {
                // 看看有没有某个倍数的位置上全满足要求
                // 这样只操作这个就行
                ok = true;
                for (int j = i; j < n + 1; ++ j)
                {
                    ok &= (s[j - 1] == c);
                    j += i - 1;
                }
                
                // 只操作这个就行
                if (ok)
                {
                    ans.push_back(i);
                    break;
                }
            }
            
            // 没有这样的数，最后一位也不行
            // 因此只能 n-1 n 都操作一遍
            if (!ok)
            {
                ans.push_back(n);
                ans.push_back(n - 1);
            }
        }
        
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++ i)
            cout << ans[i] << " ";
        cout << endl;
    }
}
```

`cf` 真的不考察算法，太考察动脑和思维严谨了...

### 简单题不详记

- [B. Queue at the School](https://codeforces.com/problemset/problem/266/B) 题目很简单但是 WA 了一次，我是傻逼
- [A. Insomnia cures](https://codeforces.com/problemset/problem/148/A)
- [A. Anton and Letters](https://codeforces.com/problemset/problem/443/A)
- [B. Special Numbers](https://codeforces.com/contest/1594/problem/B)
