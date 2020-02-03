/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.01%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 97.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> track;
        backtrack(res, track, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int> > & res, vector<int> vec, vector<int> & nums, int level){
        if(level == nums.size()){
            res.emplace_back(vec);
            return ;
        }
        for(auto i = 0; i < nums.size();i++){
            int j = 0;
            // 全排列 加 枚举
            for(;j<vec.size();j++)
                if(nums[i]==vec[j]) break; 
            if(j!=vec.size()) continue; 
            vec.emplace_back(nums[i]);
            backtrack(res,vec,nums,level+1);
            vec.pop_back();
        }
    }
};
// @lc code=end

