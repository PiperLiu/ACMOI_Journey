/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (30.12%)
 * Likes:    2784
 * Dislikes: 0
 * Total Accepted:    371.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (!nums.size())
            return ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n; a++)
        {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            int c = n - 1;
            for (int b = a + 1; b < n; b++)
            {
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                while (b < c && nums[a] + nums[b] + nums[c] > 0)
                {
                    c--;
                }
                if (b == c) break;
                if (nums[a] + nums[b] + nums[c] == 0) {
                    ans.push_back({nums[a], nums[b], nums[c]});
                }
            }
        }

        return ans;
    }
};
// @lc code=end
