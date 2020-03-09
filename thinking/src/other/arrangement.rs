//! ## 全排列
//!
//! 从给定的一个序列中生成他们的全排列
//!
//! ## 全排列（带重复数字）
//!
//! 从给定的一个序列中生成他们的全排列（序列中的数字可能重复）

/// ## 全排列
/// 从给定的一个序列中生成他们的全排列
pub mod Permute {

    /// 直接DFS搜索，回溯，扫描到当前数字的时候将数字加入，然后再进行DFS，完成后再移除
    /// leetcode 46
    /// TODO: 后续思考一下能不能用宏实现一下
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        // should use this way to create a 2d vector on heap
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut temp: Vec<i32> = Vec::new();
        permute_dfs(nums.as_ref(), result.as_mut(), temp.as_mut());
        result
    }
    // inner dfs for this method
    fn permute_dfs(array: &Vec<i32>, result: &mut Vec<Vec<i32>>, temp: &mut Vec<i32>) {
        if temp.len() == array.len() {
            result.push(temp.clone());
        } else {
            for item in array {
                if !temp.contains(item) {
                    temp.push(*item);
                    permute_dfs(array, result, temp);
                    temp.remove(temp.len() - 1);
                }
            }
        }
    }

    // pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
    //     nums.iter().enumerate().rev().peekable();
    // }
}
