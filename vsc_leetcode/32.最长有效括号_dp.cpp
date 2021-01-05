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
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        stack<int> stk;
        /*
        * 当 stk 为空时，放入当前 ')' 对应下标
        * 很巧妙的一步，将之前的合理字串与之后的合理子串连接了起来
        * 最后仅通过 i - stk.top() 就可以得到当前合理子串长度
        * 最为巧妙的是，开始时先压入 -1
        */
        stk.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    ans = max(ans, i - stk.top());
            }
        }
        return ans;
    }
};
// @lc code=end
