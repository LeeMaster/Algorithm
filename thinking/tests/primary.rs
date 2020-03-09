use algo::primary::*;

#[test]
fn coin_problem(){
  let res = coin_problem::coin_problem_greedy(vec![1,5,10,50,100,500], vec![1,2,3,4,5], 100);
  assert_eq!(1, res);
}

#[test]
fn test_part_sum_dfs_solve() {
    let case_one = vec![1, 2, 4, 7];
    let (result, record) = part_sum::part_sum_dfs_solve(&case_one, 13);
    println!("{:?}", record);
    assert_eq!(true, result);
}
