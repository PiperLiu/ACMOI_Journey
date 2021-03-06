/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.27%)
 * Likes:    1124
 * Dislikes: 0
 * Total Accepted:    118.9K
 * Total Submissions: 347K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                ans = max(ans, right * 2);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;  // 别忘记这句
        for (int i = (int)s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                right++;
            else
                left++;
            if (left == right)
                ans = max(ans, left * 2);
            else if (left > right)
                left = right = 0;
        }
        return ans;
    }
};
// @lc code=end
