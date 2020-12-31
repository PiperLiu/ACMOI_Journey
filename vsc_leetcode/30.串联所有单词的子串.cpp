/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (33.18%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 157K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (s.size() == 0 || words.size() == 0)
            return {};

        vector<int> rts;
        int word_len = words[0].size();
        int word_num = words.size();

        unordered_map<string, int> m1;
        for (const auto &w : words)
            m1[w]++;

        for (int i = 0; i < word_len; i++)
        {
            unordered_map<string, int> m2;
            int count = 0;
            int left = i, right = i;
            // 注意下面是 <= 而非 <
            // 可以以 word_len = 1 的情况思考
            while (right + word_len <= s.size())
            {
                string substr = s.substr(right, word_len);
                right += word_len;

                if (m1[substr] == 0)
                {
                    left = right;
                    count = 0;
                    m2.clear();
                }
                else
                {
                    m2[substr]++;
                    count ++;
                    while (m2[substr] > m1[substr])
                    {
                        string temp = s.substr(left, word_len);
                        m2[temp] --;
                        left += word_len;
                        count --;
                    }
                }
                if (count == word_num)
                    rts.push_back(left);
            }
        }
        return rts;
    }
};
// @lc code=end
