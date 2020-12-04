/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (39.41%)
 * Likes:    687
 * Dislikes: 0
 * Total Accepted:    139.3K
 * Total Submissions: 353.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> rts;
        // 不要忘了排序
        sort(nums.begin(), nums.end());
        if (nums.size() < 4)
            return rts;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                if (k == l)
                    break;
                while (k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        rts.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k+1] == nums[k])
                            k ++;
                        k ++;
                        while (k < l && nums[l-1] == nums[l])
                            l --;
                        l --;
                    }
                    else if (sum < target)
                    {
                        k ++;
                    }
                    else if (sum > target)
                    {
                        l --;
                    }
                }
            }
        }
        return rts;
    }
};