extern crate algo;

use algo::primary::*;

#[test]
fn test_part_sum_dfs_solve(){
  let case_one = vec![1,2,4,7];
  let (result,record) = part_sum::part_sum_dfs_solve(&case_one,13);
  println!("{:?}",record);
  assert_eq!(true,result);
}