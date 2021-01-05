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
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans = 0, n = s.size();
        /*
        * 所谓动态规划
        * dp 就是保存：
        *   - 目前所处的窗口的已经积累的合理值
        * 本题中，遇到 "()" 则 +2
        * 遇到 ')' 则考虑之前是不是遇到过 '('：
        *   - 假如现在是这样 "xyz())"
        *   - 那么我要去检查 'z' 那里是不是 '('
        *   - 是的话，就构成了一个 '(())' 合理子串
        *   - 则 dp[i] = dp[i - 1] + 2
        *   - ！！还要注意，"xy"也有可能能是"()"
        *   - 这与当前的子串连接，他们共同构成一个合理子串
        *   - 如果是的话，dp[y] 的值会是 2
        *   - 因此我们最终的更新公式为
        *   - dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
        */
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    // 其实就是 dp[i] = dp[i - 2] + 2
                    // 条件三元运算符是为了防止 dp[i - 2] 下标越界
                    dp[i] = (i > 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                ans = max(dp[i], ans);
            }
        }
        return ans;
    }
};
// @lc code=end
