/*
 * @lc app=leetcode.cn id=120 lang=rust
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (62.88%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    45.6K
 * Total Submissions: 71.3K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
impl Solution {
  pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
      let rows = triangle.len();
      // 倒着DP ，从倒数第二行开始，每一个数字都换成下面两个数字中小的+当前这个数字，非常像线段树
      (0..rows-1)
      .rev()
      .for_each(|r| (0..r+1)
      .for_each(|c| 
             triangle[r][c] += std::cmp::min(triangle[r+1][c], triangle[r+1][c+1])));
      triangle[0][0]
  }
}
// @lc code=end

