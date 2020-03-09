//! ## 回文串
//! 
//! * leetcode 234
//! * leetcode 009
//! * leetcode 125
//! * leetcode 005
//! * leetcode 131
//! * leetcode 132

//! ### Leetcode 题目
pub mod leetcode{

  /// leetcode 009 非常简单，回文串的定义就是，反转后的字符串和原字符串是相等的，那么就是回文串
  pub fn is_palindrome(x: i32) -> bool {
    if x.to_string().chars().rev().collect::<String>() == x.to_string(){
        return true;
    }else{
        return false;
    }
  }

  /// leetcode 005
  pub fn longest_palindrome(s: String) -> String {
    String::from("s: &'a str")
  }

}

pub mod manachar{
  
}