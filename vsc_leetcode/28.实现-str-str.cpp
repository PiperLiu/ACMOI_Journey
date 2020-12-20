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
    Solution(){};

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        int i = 0;
        char startChar = needle[0];
        for (auto hay : haystack)
        {
            printf("i: %d\n", i);
            if (hay == startChar)
            {
                if (haystack.size() - i < needle.size())
                    break;
                printf("ok i: %d\n", i);
                int ii = i + 1;
                for (; ii - i < needle.size(); ii++)
                {
                    printf("ii: %d\n", ii);
                    if (haystack[ii] != needle[ii - i])
                    {
                        ii = -1;
                        printf("break\n");
                        break;
                    }
                }
                printf("ii: %d i: %d\n", ii, i);
                if (ii - i - 1 == needle.size() - 1)
                    return i;
            }
            i++;
        }
        return -1;
    }
};
// @lc code=end

// int main(int argc, char const *argv[])
// {
//     Solution s;
//     int rts = s.strStr("hello", "ll");
//     printf("rts: %d\n", rts);
//     rts = s.strStr("a", "a");
//     printf("rts: %d\n", rts);
//     rts = s.strStr("", "");
//     printf("rts: %d\n", rts);
//     return 0;
// }
