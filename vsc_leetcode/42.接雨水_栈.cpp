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
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int size = height.size();
        if (size == 0)
            return 0;
        int current = 0;
        stack<int> st;
        while (current < size)
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bound_height = min(height[current], height[st.top()]) - height[top];
                ans += bound_height * distance;
            }
            st.push(current);
            current++;
        }
        return ans;
    }
};
// @lc code=end
