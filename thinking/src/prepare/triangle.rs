use std::cmp::max;

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

// nlogn solution
#[allow(dead_code)]
pub fn max_triangle_perimeter_nlogn(array:& Vec<i32>) -> i32 {
    
    0
}
