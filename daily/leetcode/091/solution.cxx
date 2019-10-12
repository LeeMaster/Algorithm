/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.56%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 84.1K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s.empty()) return 0;
        if(s[0]=='0') return 0;
        vector<int> dp(n+1,0); 
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;++i)
        {
           //https://github.leemaster.io/2019/10/12/leetcode-91/
            if(s[i-1]!='0') dp[i]+=dp[i-1];
            if(s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") dp[i]+=dp[i-2];
        }
        return dp[n];
    }

};
// @lc code=end

