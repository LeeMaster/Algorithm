/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.16%)
 * Likes:    3063
 * Dislikes: 0
 * Total Accepted:    329.2K
 * Total Submissions: 1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        auto len = s.size();
        int i = 0, j = 0, ans = 0;
        // 滑动窗口
        // i 和 j 组成滑动窗口 
        // 如果当前位置的字符存在在窗口内，那么需要缩小窗口了，否则扩张窗口
        while(i < len && j < len){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                ans = max(ans, j - i);
            }else{
                auto it = set.find(s[i++]);
                set.erase(it);   
            }
        }
        return ans;
    }
};
// @lc code=end

