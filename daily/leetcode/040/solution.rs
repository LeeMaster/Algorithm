/*
 * @lc app=leetcode.cn id=46 lang=rust
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (71.24%)
 * Likes:    551
 * Dislikes: 0
 * Total Accepted:    82.9K
 * Total Submissions: 111.8K
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
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut temp: Vec<i32> = Vec::new();
        Solution::dfs(&nums, result.as_mut(), temp.as_mut());
        result
    }

    fn dfs(array: &Vec<i32>, result: &mut Vec<Vec<i32>>, temp: &mut Vec<i32>) {
        if temp.len() == array.len() {
            result.push(temp.clone());
        } else {
            for item in array {
                if !temp.contains(item) {
                    temp.push(*item);
                    Solution::dfs(array, result, temp);
                    temp.remove(temp.len() - 1);
                }
            }
        }
    }
}
// @lc code=end
