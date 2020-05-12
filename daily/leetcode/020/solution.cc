/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.30%)
 * Likes:    989
 * Dislikes: 0
 * Total Accepted:    109.6K
 * Total Submissions: 279K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0 ) return true;
        stack<char> state;

        for(auto ch : s){
            if (ch == '(' || ch == '[' || ch == '{'){
                state.push(ch);
            } else {
                if (state.empty()) return false;
                
                auto top = state.top();
                if (ch == ')'){
                    if (top != '(') return false;
                    state.pop();
                }

                if (ch == ']'){
                    if (top != '[') return false;
                    state.pop();
                }

                if (ch == '}'){
                    if (top != '{') return false;
                    state.pop();
                }
            }
        }   

        return state.empty();     
    }
};
// @lc code=end

