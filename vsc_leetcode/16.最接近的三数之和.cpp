/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    632
 * Dislikes: 0
 * Total Accepted:    170.2K
 * Total Submissions: 371.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = 1e6;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int a = 0; a < n; a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            int b = a + 1;
            int c = n - 1;
            while (b < c)
            {
                int sum = nums[a] + nums[b] + nums[c];
                if (abs(sum - target) == 0)
                    return sum;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
                if (sum > target)
                {
                    c--;
                    while (b < c && nums[c] == nums[c + 1])
                        c--;
                }
                else
                {
                    b++;
                    while (b < c && nums[b] == nums[b - 1])
                        b++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
