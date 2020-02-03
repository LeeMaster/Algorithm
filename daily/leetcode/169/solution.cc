/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.74%)
 * Likes:    419
 * Dislikes: 0
 * Total Accepted:    101.7K
 * Total Submissions: 166.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
//Boyer-Moore 投票算法
// 这个题目内，为了选出众数 所以对于集合中的任何一个数字只有两个选择，是或者不是
// 那么对于两个选择可以使用两个状态进行标记，是的话使用1 标记 不是使用 -1 标记
// 对于任意的一个count 等于0的状态，可以将当前位置认为是众数进行检查即可
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(auto num : nums){
            if(count == 0){
                candidate = num;
            }
            count += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end

