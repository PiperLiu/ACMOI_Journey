/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.59%)
 * Likes:    647
 * Dislikes: 0
 * Total Accepted:    269.9K
 * Total Submissions: 681.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
#include <string>
#include <stdio.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    Solution() {}
    /*
    * https://leetcode-cn.com/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode/
    */

    int strStr(string haystack, string needle)
    {
        if (needle == "")
        {
            return 0;
        }
        if (haystack == "")
        {
            return -1;
        }

        // 构造KMP中的dp矩阵
        int m = needle.length();
        // 各个状态(行)遇到下一个字符(列)跳转到哪个状态
        int dp[m][256];
        // 影子状态
        int X = 0;
        dp[0][needle[0]] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                //假设下个字符不匹配，此时要回去看影子状态，从而得知跳转到哪个状态
                dp[i][j] = dp[X][j];
            }
            // 只有pat上i的字符匹配，跳转到下个状态
            dp[i][needle[i]] = i + 1;
            // 更新影子状态
            X = dp[X][needle[i]];
        }

        // 构造dp完成后，开始search
        // 初始状态为0
        int s = 0;
        for (int i = 0; i < haystack.length(); i++)
        {
            s = dp[s][haystack[i]];
            if (s == m)
            {
                return i - m + 1;
            }
        }

        // 匹配失败，返回-1
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    printf("start\n");
    int rts = s.strStr("hello", "ll");
    printf("rts: %d\n", rts);
    rts = s.strStr("a", "a");
    printf("rts: %d\n", rts);
    rts = s.strStr("", "");
    printf("rts: %d\n", rts);
    return 0;
}
