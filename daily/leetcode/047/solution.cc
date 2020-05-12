/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (58.55%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 98K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int> >result;

    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
 
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int level){
        if (level == nums.size()){
            result.emplace_back(nums);
            return;
        }

        unordered_set<int> track;
        for(auto index = level; index < nums.size(); index++){
            if (track.count(nums[index])){
                continue;
            }
            track.insert(nums[index]);
            
            swap(nums[index], nums[level]);
            backtrack(nums, level+1);
            swap(nums[index], nums[level]);
        }

    }
};
// @lc code=end

