//! # 最长三角形周长问题
//! 
//! 给定一个数组，从中寻找三个边，使其能组成的三角形周长最长，并输出周长

use std::cmp::max;

/// ## 暴力解法
/// 思考如何寻找一个三角形，如果需要三个边，那么对一个数组的处理自然从最开始的三个数开始迭代，
/// 如果前三个数不能组成三角形，那么换一个边继续迭代，3次方的解法
/// 
// the violence loop to solve the problem 
#[allow(dead_code)]
pub fn max_triangle_perimeter_violence(array:& Vec<i32>) -> i32 {
    let mut ans:i32 = 0;
    let size = array.len();
    // could use the slice for the vec to traverse
    for i in 0..size{
        for j in i+1..size{
            for k in j+1..size{
                let max_side = max(array[i],max(array[j],array[k]));
                let perimeter = array[i] + array[j] + array[k];
                let rest = perimeter - max_side ;
                if rest > max_side {
                    ans = max(ans,perimeter);
                }
            }        
        }    
    }
    ans
}

/// ## 优化的解法
/// 先排序，从最大边开始迭代，第一个构成的三角形自然就是最大的三角形
// nlogn solution
#[allow(dead_code)]
pub fn max_triangle_perimeter_nlogn(array:& Vec<i32>) -> i32 {
    let mut sortable_arr = array.clone();
    sortable_arr.sort();
    sortable_arr.reverse();
    let mut i = 0;
    while i < array.len(){
        if sortable_arr[i + 1 as usize] + sortable_arr[i + 2 as usize] > sortable_arr[i as usize] {
           return  sortable_arr[i + 1 as usize] + sortable_arr[i + 2 as usize] + sortable_arr[i as usize]; 
        }
        i += 3;
    }
    0
}
