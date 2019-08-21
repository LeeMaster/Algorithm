/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.49%)
 * Likes:    699
 * Dislikes: 0
 * Total Accepted:    148.2K
 * Total Submissions: 262.4K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 * 这个有点简单了吧 TAT
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // 小于0 多个- 肯定不是了
        if(x < 0 )return false;
        if(x < 10 && x >= 0)return true;
        long long direct = x;
        long long reverse = 0;
        while(x != 0){
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return direct == reverse;
    }
};

