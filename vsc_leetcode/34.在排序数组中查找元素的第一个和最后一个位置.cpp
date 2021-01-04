/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.07%)
 * Likes:    792
 * Dislikes: 0
 * Total Accepted:    195.3K
 * Total Submissions: 464.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
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
    int binarySearch(vector<int> &nums, int target, bool lower)
    {
        /*
        * 注意这里 必须为 ans 赋值 nums.size()
        * 以例子 [1] \n 1 为例
        * 在求 rightIndex 时，会直接返回 ans
        * ans 必须默认为最大索引，这样才可以让 rightIndex 
        * 有意义，即 “比 target 大一点的数的索引减一”
        */
        // int l = 0, r = nums.size() - 1, ans;
        int l = 0, r = nums.size() - 1, ans = nums.size();
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if (leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target && nums[rightIndex] == target)
            return vector<int> {leftIndex, rightIndex};
        return vector<int>{-1, -1};
    }
};
// @lc code=end
