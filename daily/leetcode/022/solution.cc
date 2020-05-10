/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (72.52%)
 * Likes:    1009
 * Dislikes: 0
 * Total Accepted:    124.6K
 * Total Submissions: 165.3K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    /**
     * 简单的 DFS ，当左括号不为0的时候，直接扔进去左括号，因为左括号的插入优先级高
     * 如果右括号比左括号多的时候，应该补充进去，保证一个平衡关系，按照这个算法，左括号一定被先消耗完
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, n, n, "");
        return res;
    }

    void dfs(vector<string> & res, int left, int right, string str){
        if (left == 0 && right == 0){
            res.push_back(str);
            return;
        }

        if (left > 0){
            dfs(res, left-1, right, str + "(");
        }

        if (right > left){
            dfs(res, left, right - 1, str + ")");
        }
    }
};
// @lc code=end

