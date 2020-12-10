/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (53.45%)
 * Likes:    1859
 * Dislikes: 0
 * Total Accepted:    172.9K
 * Total Submissions: 323.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int size = height.size();
        // size == 0 的判断很必要
        if (size == 0) return 0;
        vector<int> left_maxs(size), right_maxs(size);
        // left maxs
        left_maxs[0] = height[0];
        for (int i = 1; i < size; i++)
            left_maxs[i] = max(height[i], left_maxs[i - 1]);
        // right maxs
        right_maxs[size - 1] = height[size - 1];
        for (int j = size - 2; j >= 0; j--)
            right_maxs[j] = max(height[j], right_maxs[j + 1]);

        for (int k = 1; k < size - 1; k++)
            ans += min(left_maxs[k], right_maxs[k]) - height[k];

        return ans;
    }
};
// @lc code=end
