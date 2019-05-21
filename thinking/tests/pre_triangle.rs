extern crate algo;

use algo::prepare::*;

#[test]
fn test_triangle_algo_violence(){
  let case_one = vec![2,3,4,5,10];
  let result = triangle::max_triangle_perimeter_violence(&case_one);
  assert_eq!(12,result);
}