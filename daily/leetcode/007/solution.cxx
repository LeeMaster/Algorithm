/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (32.84%)
 * Likes:    1239
 * Dislikes: 0
 * Total Accepted:    167.4K
 * Total Submissions: 509.7K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

/*
* 典型的反转，这里面其实就是利用了 Stack 的思想 反转数字
* 每次新的数字都会扩大10倍
*/

class Solution {
public:
    #define INT_MAX 2147483647
    #define INT_MIN (-INT_MAX-1)
    int reverse(int x) {
        int flag=x<0?-1:1;
        int num=0;
        while(x){
            if((flag==-1&&(INT_MIN/10>num))||(flag==1&&INT_MAX/10<num))return 0;
            num=num*10+x%10;
            x/=10;
        }
        return num;
    }

};

