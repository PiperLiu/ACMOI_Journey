/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.36%)
 * Likes:    2023
 * Dislikes: 0
 * Total Accepted:    473.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 != 0)
            return false;
        
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;
        for (char c: s)
        {
            if (pairs.count(c))
            {
                if (stk.empty() || stk.top() != pairs.at(c))
                    return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
// @lc code=end
