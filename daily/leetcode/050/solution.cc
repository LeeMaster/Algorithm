/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.50%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 125.2K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 快速幂 基于 幂的幂运算性质
    double fastPow(double x, int n){
        if (n == 0)return 1.0;
        double helf = fastPow(x, n / 2);
        if(n % 2 == 0){
            return helf * helf;
        }else{
            return helf * helf * x;
        }
    }
    double myPow(double x, int n) {
        // 看起来这个东西需要用long long 转换一下了哦
        long long N = n;
        if (N < 0){
            x = 1 / x;
            N = -N;
        }
        return fastPow(x,N);
    }
};
// @lc code=end

