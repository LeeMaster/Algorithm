/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.25%)
 * Likes:    591
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 104.3K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */
#include<string>

using namespace std;

/**
 * 二者分别为0的时候
 * 1. P 为 0 当且仅当 S 为 0 返回 true 
 * 2. S 为 0 当且仅当 P 为 * 返回 true 
 * 二者均不为0时
 * TODO: 这个 DP 的玩法需要写点注释，讲道理有点懵逼
 */
class Solution {
public:
    bool isMatch(string s, string p) {
       int lens = s.length(), lenp = p.length();
	bool ** dp = new bool*[lens + 2];
	for (int i = 0; i < lens+2; i++)
		dp[i] = new bool[lenp + 2];
 
	for (int i = 0; i < lens+2; i++)
		for (int j = 0; j < lenp+2; j++)
			dp[i][j] = false;
	dp[0][0] = true;
 
	for (int i = 1; i < lenp; i++)
		if (p[i] == '*'&&dp[0][i - 1])
			dp[0][i + 1] = true;
 
	for (int i = 0; i < lens; i++)
		for (int j = 0; j < lenp; j++)
		{
			if (s[i] == p[j] || p[j] == '.')
				dp[i + 1][j + 1] = dp[i][j];
			else if (p[j] == '*')
			{
				if (p[j - 1] != s[i] && p[j - 1] != '.')
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				else
					dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
			}
		}
 
 
	return dp[lens][lenp];
    }
};

