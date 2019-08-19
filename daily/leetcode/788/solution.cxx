/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 *
 * https://leetcode-cn.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (56.65%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 9.8K
 * Testcase Example:  '10'
 *
 * 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
 * 
 * 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和
 * 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
 * 
 * 现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
 * 
 * 
 * 示例:
 * 输入: 10
 * 输出: 4
 * 解释: 
 * 在[1, 10]中有四个好数： 2, 5, 6, 9。
 * 注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 * 
 * 
 * 注意:
 * 
 * 
 * N 的取值范围是 [1, 10000]。
 * 
 * 0 1 8 旋转之后不变
 * 2 5 6 9 旋转之后发生了改变 
 * 2 5 6 9 有任意一个即可 
 * 3 4 7 不能有 
 * 因为有范围 所以最多只有4位 
 * 
 * 0 在第一位的 是 0 - x - x 
 * 首先根据 N 的大小确定 位数
 */
class Solution {
public:
    int rotatedDigits(int N) {
        int count=0;
        int countpos;
        int countneg;
        int temp;
        int mod;
        for(int i=1;i<=N;i++)
        {
            countpos=0;
            countneg=0;
            temp=i;
            while(temp)
            {
                mod=temp%10;
                if(mod==4 || mod==7 || mod==3)
                {
                    break;
                }
                else
                {
                    if(mod==2 || mod==5 || mod==6 || mod==9)
                    {
                        countpos++;
                    }
                } 
                temp/=10;
            }
            if(temp==0 && countpos>0)
            {
                count++;
            }
        }
        return count;
    }
};

