/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (55.54%)
 * Likes:    1022
 * Dislikes: 0
 * Total Accepted:    198.3K
 * Total Submissions: 357.1K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> rts;
    // 这里命名，可以是 phoneMap 比 num_to_words 好
    unordered_map<string, vector<char>> num_to_words = {
        // 直接 <string, string> 就行
        // 但是 <string, vector<char>> 也有好处，比如快
        // Your runtime beats 100 % of cpp submissions
        {"2", {'a', 'b', 'c'}},
        {"3", {'d', 'e', 'f'}},
        {"4", {'g', 'h', 'i'}},
        {"5", {'j', 'k', 'l'}},
        {"6", {'m', 'n', 'o'}},
        {"7", {'p', 'q', 'r', 's'}},
        {"8", {'t', 'u', 'v'}},
        {"9", {'w', 'x', 'y', 'z'}}
    };

    vector<string> letterCombinations(string digits)
    {
        rts.clear();
        // 如果没有这个 if 则会在应该给出 [] 时给出 [""]
        if (digits.length() == 0) return rts;
        string combination;
        dfs(combination, 0, digits);
        return rts;
    }
    void dfs(string& combination, int idx, const string& digits)
    {
        if (combination.length() == digits.length()) {
            rts.push_back(combination);
        } else {
            string digit = digits.substr(idx, 1);
            const vector<char>& letters = num_to_words[digit];
            for (const char& letter: letters)
            {
                combination.push_back(letter);
                dfs(combination, idx + 1, digits);
                combination.pop_back();
            }
        }
    }
};

// @lc code=end
