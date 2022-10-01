
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [LCP 64. 二叉树灯饰（奇偶状态压缩+记忆化搜索+树形DP）](#lcp-64-二叉树灯饰奇偶状态压缩记忆化搜索树形dp)
- [LCP 65. 舒适的湿度（思维题+DP）](#lcp-65-舒适的湿度思维题dp)

<!-- /code_chunk_output -->

https://leetcode.cn/contest/season/2022-fall/ranking/solo/

没参加，但是要学习一下。毕竟灵佬直播也讲了这期，而且我也好久没做过 DP 了。

灵佬讲解：https://www.bilibili.com/video/BV1zN4y1K762/

### LCP 64. 二叉树灯饰（奇偶状态压缩+记忆化搜索+树形DP）

https://leetcode.cn/problems/U7WvvU/

读题的时候想到「拉灯」这道题。这道题的难点在于，如何把这个节点对于其之后的节点的影响传下去。

灵佬的解法很巧妙，如下。

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func closeLampInTree(root *TreeNode) (ans int) {
    // 如何设置状态？
    // 当前灯是否切换“开或关”只受两个影响（如下，若本灯切换“开或关”）：
    // 1. 其祖先节点中开关 2 点击次数累计为奇数（一个布尔量）
    // 2. 其父节点中开关 3 点击了（一个布尔量）
    // 若上述二者同时满足，则本灯也不切换
    // 因此：
    /* 
跑一个树形 DP。如果当前受到祖先节点的开关影响后，变成开灯状态，那么可以操作一个或三个开关：
操作开关 1；
操作开关 2；
操作开关 3；
操作开关 123；
这四种操作取最小值。

如果变成关灯状态，那么可以操作零个或两个开关：
不操作任何一个开关；
操作开关 12；
操作开关 13；
操作开关 23；
这四种操作取最小值。

作者：endlesscheng
链接：https://leetcode.cn/problems/U7WvvU/solution/shu-xing-dp-by-endlesscheng-isuo/
*/
	type tuple struct {
		node             *TreeNode
		switch2, switch3 bool
	}
	dp := map[tuple]int{} // 记忆化搜索
	var f func(*TreeNode, bool, bool) int
    // switch2 表示祖先节点中累计使用开关 2 的次数是否为偶数
	f = func(node *TreeNode, switch2, switch3 bool) int {
		if node == nil {
			return 0
		}
		p := tuple{node, switch2, switch3}
		if res, ok := dp[p]; ok {
			return res
		}
		if node.Val == 1 == (switch2 == switch3) { // 当前节点为开灯
			res1 := f(node.Left, switch2, false) + f(node.Right, switch2, false) + 1  // 开关 1
			res2 := f(node.Left, !switch2, false) + f(node.Right, !switch2, false) + 1  // 开关 2
			res3 := f(node.Left, switch2, true) + f(node.Right, switch2, true) + 1  // 开关 3
			r123 := f(node.Left, !switch2, true) + f(node.Right, !switch2, true) + 3  // 开关 123
			dp[p] = min(res1, res2, res3, r123)
		} else { // 当前节点为关灯
			res0 := f(node.Left, switch2, false) + f(node.Right, switch2, false)
			res12 := f(node.Left, !switch2, false) + f(node.Right, !switch2, false) + 2
			res13 := f(node.Left, switch2, true) + f(node.Right, switch2, true) + 2
			res23 := f(node.Left, !switch2, true) + f(node.Right, !switch2, true) + 2
			dp[p] = min(res0, res12, res13, res23)
		}
		return dp[p]
	}
	return f(root, false, false)
}

func min(a, b, c, d int) int {
	if b < a {
		a = b
	}
	if c < a {
		a = c
	}
	if d < a {
		a = d
	}
	return a
}
```

### LCP 65. 舒适的湿度（思维题+DP）

这题真的很难。推荐去看灵佬视频。

```cpp
// 1. 转换题意：
//    把一些数变成负数，最小化 max(最大字段和, |最小字段和|)
//
// 想到动态规划、树形结合
// 可以想象为折一根木棍，让其最上点与最下点距离最小
// 状态 j 比较难定义，为目前最末端（最右端）与最底端（在纵坐标上）的距离
// f[i][j] 为选了前 i 木棍状态为 j 时木棍最高和最低两端的距离的最小值

class Solution {
public:
    int unSuitability(vector<int> &operate) {
        int mx = *max_element(operate.begin(), operate.end()) * 2 + 1;
        // 滚动数组省略 i
        int pre[mx], f[mx];
        memset(pre, 0x3f, sizeof(pre));
        pre[0] = 0;
        for (int x : operate) {
            memset(f, 0x3f, sizeof(f));
            for (int j = 0; j < mx; ++j) {
                int dis = pre[j];
                if (dis == 0x3f3f3f3f) continue; // 无效的长度（无法组成）
                // x 取正号
                if (j + x < mx) f[j + x] = min(f[j + x], max(dis, j + x));
                // x 取负号
                if (j >= x) f[j - x] = min(f[j - x], dis);  // 没越界
                else f[0] = min(f[0], dis - j + x);  // 越界
            }
            memcpy(pre, f, sizeof(f));
        }
        return *min_element(pre, pre + mx);
    }
};

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/3aqs1c/solution/by-endlesscheng-fu9b/
```
