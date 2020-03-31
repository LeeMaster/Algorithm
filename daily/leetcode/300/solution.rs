/*
 * @lc app=leetcode.cn id=300 lang=rust
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.45%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 173.7K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut dp = vec![1; nums.len()];
        // nums[0..i] 可以通过 nums[0..i-1] 扩展而来
        // 如果 nums[i-1] < nums[j] 那么 dp[i] = dp[i-1] + 1
        // 那么直接对每一个子序列计算从0开始的子序列上升的长度就好了
        (0..nums.len()).for_each(
            |i| (0..i).for_each(
                |j|
                if nums[i] > nums[j]{
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            )
        );
        *dp.iter().max().unwrap_or(&0) as i32
    }
}
// @lc code=end

