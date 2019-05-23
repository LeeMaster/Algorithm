//! # 二维前缀和
//!
//! 对于给定的矩阵，分别给出左上角和右下角的两个坐标，求由这两个坐标确定的子矩阵的元素和。查询可能由多次，最多能达到矩阵元素个数n
//!
//! 首先可以考虑暴力算法，使用数组对矩阵进行表示，所以只需要对子矩阵进行遍历则可以得到结果，这样的话算法的复杂度是3次方的复杂度，因为有n次查询。
//! 而优化的算法则利用容斥定理来进行计算，使用之前需要对矩阵进行处理。
//!
//! ## 容斥定理
//! 
//! 容斥定理描述的是，对于多个有相交部分的集合，可以通过冗余的加法进行计数，再减去冗余部分即可。
//!
//! 而这个问题，很容易使用容斥定理，只需要画一下图就可以看出来。


/// # 暴力解法
/// 直接循环迭代进行计算，因为一次计算的结果是n2所以如果多次查询则复杂度是n3
#[allow(dead_code)]
pub fn dimension_prefix_sum_violence(matrix: &Vec<Vec<i32>>,left_top_point:(i32,i32),right_bottom_point:(i32,i32)) -> i32 {
    let mut sum = 0;
    for i in left_top_point.0..right_bottom_point.0{
        for j in left_top_point.1..right_bottom_point.1{
            sum += matrix[i as usize][j as usize];
        }
    }
    sum
}

//let mut dp = Box(Vec<Vec<i32>> )

/// # 容斥定理解法
///
/// 对结果进行预先处理，再进行查询
#[allow(dead_code)]
pub fn dimensiom_prefix_sum_optmize(matrix: &Vec<Vec<i32>>,left_top_point:(i32,i32),right_bottom_point:(i32,i32)) -> i32 {
    let mut sum = 0;

    sum
}
