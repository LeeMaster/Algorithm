/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (64.41%)
 * Likes:    1017
 * Dislikes: 0
 * Total Accepted:    140.3K
 * Total Submissions: 216.2K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

// @lc code=start
#include <vector> 
using namespace std;
// 任何一个数字和 0 进行异或 都是原来的数字
// 任何一个数字和自己异或都返回0 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
// @lc code=end

