/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (63.71%)
 * Likes:    821
 * Dislikes: 0
 * Total Accepted:    120.3K
 * Total Submissions: 188.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 */

// @lc code=start
#include <utility>
using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    pair <ListNode*, ListNode*> reverse1Group(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next;
        ListNode* p = head;  // 定义 p 只是为了临时存储一下头节点
        while (prev != tail)
        {
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return {tail, p};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);  // 定义 hair 只是为了存储头节点，返回时用
        hair->next = head;  // hair 与链表连接起来
        ListNode* pre = hair;  // 每次翻转，都反转 pre 后面的链表

        while (head)
        {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++)
            {
                tail = tail->next;
                if (!tail)
                    return hair->next;
            }
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> result = reverse1Group(head, tail);
            tail = result.second;
            pre->next = result.first;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};
// @lc code=end

