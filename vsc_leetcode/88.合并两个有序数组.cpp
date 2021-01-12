/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (49.12%)
 * Likes:    731
 * Dislikes: 0
 * Total Accepted:    252.8K
 * Total Submissions: 514.6K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 有足够的空间（空间大小等于 m + n）来保存 nums2
 * 中的元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 1 
 * nums1.length == m + n
 * nums2.length == n
 * -10^9 
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = n - 1;
        int pe = m + n - 1;
        while (p2 >= 0)
        {
            /*
            * 利用两个数组都是有序的特点
            * 倒着遍历，把目前最大的数从 nums1 后面压入
            * 这个 while 的停止条件值得注意：
            *     p2 不再大于等于 0 了
            *     说明填充 m+n 完成
            */
            if (p1 >= 0)
                nums1[pe--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
            else
                nums1[pe--] = nums2[p2--];
        }
    }
};
// @lc code=end
