use algo::other::dimension_prefix_sum::*;


#[test]
fn dimension_prefix_sum_violence_test(){
  let matrix = vec![
    vec![0,-2,-7,0],
    vec![9,2,-6,2],
    vec![-4,1,-4,1],
    vec![-1,8,0,-2]
  ];
  let result = dimension_prefix_sum_violence(&matrix,(0,1),(1,3));
  assert_eq!(result, -9)
}

#[test]
fn dimensiom_prefix_sum_optmize_test(){
  let matrix = vec![
    vec![0,-2,-7,0],
    vec![9,2,-6,2],
    vec![-4,1,-4,1],
    vec![-1,8,0,-2]
  ];
  // let result = dimensiom_prefix_sum_optmize(&matrix,(0,1),(1,3));
  // assert_eq!(result, -9)
}