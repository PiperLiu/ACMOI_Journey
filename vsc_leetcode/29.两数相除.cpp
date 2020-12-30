/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (20.26%)
 * Likes:    470
 * Dislikes: 0
 * Total Accepted:    72.4K
 * Total Submissions: 357.3K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            return dividend > INT_MIN ? - dividend : INT_MAX;
        }
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = - 1;
        dividend = dividend < 0 ? dividend : - dividend;  // 转为负数防溢出
        divisor  = divisor  < 0 ? divisor  : - divisor;
        int res = div(dividend, divisor);
        return sign > 0 ? res : - res;
    }
    int div(int dividend, int divisor)
    {
        if (dividend > divisor)
            return 0;
        int count = 1;
        int temp_divisor = divisor;
        // temp_divisor + temp_divisor >= dividend
        // temp_divisor - dividend + temp_divisor >= 0
        // 不同，可参考算例 -2147483648, 2
        while (temp_divisor - dividend + temp_divisor >= 0)
        {
            count = count + count;
            temp_divisor = temp_divisor + temp_divisor;
        }
        return count + div(dividend - temp_divisor, divisor);
    }
};
// @lc code=end

