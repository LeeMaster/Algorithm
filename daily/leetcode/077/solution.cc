/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.65%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 66.7K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> track;
        backtrack(result, n, k, track, 1);
        return result;
    }

    void backtrack(vector<vector<int> >& result,int & n, int& k, vector<int> track, int level){
        if (track.size() == k){
            result.emplace_back(track);
            return;
        }

        for (auto num = level; num <= n; num ++){
            track.push_back(num);
            backtrack(result, n, k, track, (num + 1));
            track.pop_back();
        }
    }
};
// @lc code=end

