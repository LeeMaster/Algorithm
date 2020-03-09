use algo::other::palindrome::*;

#[test]
fn leetcode9(){
  let res = leetcode::is_palindrome(121);
  assert_eq!(true, res);
  let res = leetcode::is_palindrome(122);
  assert_eq!(false, res);
  let res = leetcode::is_palindrome(2332);
  assert_eq!(true, res);
}