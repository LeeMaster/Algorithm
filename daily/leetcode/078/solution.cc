/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (75.65%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    55.6K
 * Total Submissions: 73K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        // 每一个元素都可以选择和不被选择，所以状态的总数 为  2^nums.size()
        // 内层遍历对每一个状态进行检查即可
        // 因为二元状态，所以内层循环状态为 0 1 来表示选和不选，外层已经枚举了全部的状态
        for(auto i = 0; i < (1 << nums.size()); i++){
            vector<int> sub;
            for(auto j = 0; j < nums.size(); j++){
                if(((i>>j) & 1) == 1) sub.push_back(nums[j]); 
            }
            res.push_back(sub);
        }
        return res;
    }
};
// @lc code=end

