/*
 * @lc app=leetcode.cn id=74 lang=rust
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    35.9K
 * Total Submissions: 95.5K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */

// @lc code=start
impl Solution {
  pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
      let row = matrix.len();
      let col = matrix[0].len();
      let mut start = 0;
      let mut end = row * col - 1;
      while start <= end {
          let mid = start + (end - start) / 2;
          // 二分查找的思路，将整个矩阵给扯平就行了
          if matrix[(mid / col) as usize][(mid % col) as usize] == target{
              return true;
          }

          if matrix[(mid / col) as usize][(mid % col) as usize] > target{
              end = mid - 1;
          }else{
              start = mid + 1;
          }

      }
      false
  }
}
// @lc code=end

