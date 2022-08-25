https://leetcode-cn.com/problemset/all/?topicSlugs=linked-list&page=1


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [25. K 个一组翻转链表（自己总结的翻转部分链表模板）](#25-k-个一组翻转链表自己总结的翻转部分链表模板)
- [109. 有序链表转换二叉搜索树](#109-有序链表转换二叉搜索树)
- [简单题不详记](#简单题不详记)

<!-- /code_chunk_output -->

### 25. K 个一组翻转链表（自己总结的翻转部分链表模板）

https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

这种题做多了（大概快有5道了），心中已经有链表的形状和动画了，自己总结下模板：
- 首先声明两个指针 `p` 和 `q` 从哑节点出发， `q` 一步步往前走，直到满足翻转数量就开始翻转
- 然后翻转 `p->next` 到 `q` ，具体见下图

```
# u 是 q->next
# 现在要 reverse(p->next, q->next)
p->a->b->c->d->q->u
# reverse 后
p->a
q->d->c->b->a->u
# 因此 reverse 之后需要将 p->next = q
p->q->d->c->b->a->u
# 然后再让 p 和 q 抵达 a 的位置
```

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode *p = dummy, *q = dummy;
        int cnt = 0;

        auto reverse = [&](ListNode* sta, ListNode* end)
        {
            // 将 [sta, ..., end) 翻转
            auto prev = end;
            auto curr = sta;
            while (curr != end)
            {
                auto next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        };

        while (q->next)
        {
            if (cnt == k)
            {
                reverse(p->next, q->next);
                // 现在 p->next->next 等于了 q->next
                // 需要将 p 与 q 连起来
                auto tmp = p->next;
                p->next = q;
                // 开始新一轮 k 个
                p = tmp;
                q = tmp;
                cnt = 0;
            }
            q = q->next;
            ++ cnt ;
        }

        if (cnt == k)
        {
            reverse(p->next, nullptr);
            p->next = q;
        }

        return dummy->next;
    }
};
```

### 109. 有序链表转换二叉搜索树

https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

算是 [49. 二叉搜索树与双向链表（递归/不能创建新节点）](../../acwings/offers/drafts/20211115.md#49-二叉搜索树与双向链表递归不能创建新节点) 的兄弟题。并不是很难，就是边界条件自己得捋清楚，尤其是 `center` 有没有可能是空节点。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // 如何转换平衡二叉树？选最中间的点作为根节点
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) ++ n;

        function<TreeNode*(ListNode*, int)> dfs = [&](ListNode* u, int cnt) -> TreeNode*
        {
            if (cnt == 0) return nullptr;
            int v = cnt / 2;

            ListNode* center = u;
            for (int i = 0; i < v; ++ i) center = center->next;

            TreeNode* treeNode = new TreeNode(center->val);

            treeNode->left  = dfs(u, v);
            treeNode->right = dfs(center->next, cnt - v - 1);
            return treeNode;
        };

        TreeNode* root = dfs(head, n);
        return root;
    }
};
```

### 简单题不详记

- 2. 两数相加 https://leetcode-cn.com/problems/add-two-numbers/ 高精度加法+遍历两个链表
- 19. 删除链表的倒数第 N 个结点 https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/ 哑节点 `dummy` 保证一般性，且注意：一般一定要返回 `dummy->next` ，不能返回 `head` 因为 `head` 有可能被 `delete`
- 21. 合并两个有序链表 https://leetcode-cn.com/problems/merge-two-sorted-lists/ 哑节点
- 23. 合并K个升序链表 https://leetcode-cn.com/problems/merge-k-sorted-lists/ 优先队列辅助
- 24. 两两交换链表中的节点 https://leetcode-cn.com/problems/swap-nodes-in-pairs/ 严谨一些，注意记录可能变化的量，比如使用 `q->next` 前，要确认 `q` 这个节点没被改变过，是你想要的节点，否则，你就要将 `q->next` 记录下来再使用
- 61. 旋转链表 https://leetcode-cn.com/problems/rotate-list/ 建立一个环，找到地方断开
- 82. 删除排序链表中的重复元素 II https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/ 善于使用 `dummy` 和 `while (p->next)` ，检查 `p` 后面的元素是否重复，不重复再后移 `p`
- 83. 删除排序链表中的重复元素 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/ 和上一道题同一个模子，只不过每次必须移动一次 `p` 以保留元素
- 86. 分隔链表 https://leetcode-cn.com/problems/partition-list/ 建立两条链，一边遍历一边建
- 92. 反转链表 II https://leetcode-cn.com/problems/reverse-linked-list-ii/ 注意别用 `while (curr != q->next)` 判断，因为 `q->next` 会变化的，应该用 `auto end = q->next; while (curr != end)` 判断
