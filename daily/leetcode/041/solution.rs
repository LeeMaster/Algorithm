/*
 * @lc app=leetcode.cn id=41 lang=rust
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (37.08%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 111.1K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 说明:
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 * 
 */

// @lc code=start
impl Solution {
  // nums  作为一个 HashMap 当 数字大于0 的时候 
  // nums[i] = i + 1
  // 如果某个 nums[i] != i + 1 那么这个 i+1 就是要找的数字
  pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
      let mut nums = nums;
      (0..nums.len()).for_each(
          |i| 
          while nums[i] > 0 && 
          (nums[i] as usize) < nums.len() && 
          nums[(nums[i] - 1) as usize] != nums[i]{
              let pos = (nums[i]-1) as usize;
              nums.swap(pos, i); 
          }
      );  
      for i in (0..nums.len()){
          if nums[i] != (i+1) as i32{
              return (i+1) as i32;
          }
      }
      return (nums.len() + 1) as i32;
  }
}
// @lc code=end

