/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.93%)
 * Likes:    1362
 * Dislikes: 0
 * Total Accepted:    403.8K
 * Total Submissions: 1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if (num == 0) return "";
        string prefix = strs[0];
        for (int i=0; i<num; i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) break;
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int idx = 0;
        int len = min(str1.size(), str2.size());
        if (len == 0) return "";
        while (idx < len && str1[idx] == str2[idx]) {
            idx ++;
        }
        return str1.substr(0, idx);
    }
};
// @lc code=end

