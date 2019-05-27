//! ## 标记点问题
//!
//! 直线上有N个点，每一个点的位置是Xi从这N个点中选取若干个点进行标记，保证其每一个点在左右相距R的范围内都有一个带标记的点。

/// 直接使用贪心算法，来解决问题，这个问题看起来很像集合的覆盖问题，但是有一个特点，我们认为标记点其实是可以互相进行覆盖的。
/// 首先问题的关键是，任意的一个点被标记之后，那么他可以覆盖的位置是左右的距离为R的区域，那么如果从开始进行寻找的话，第一个点一定是小于物理位置上的第一个点减去R的距离
///
/// 这个问题的解决思路还是比较简单的，首先从第一个未被覆盖的点进行遍历，遍历的时候记录下一个可以进行覆盖的点，先清理左边，后清理右边
/// 对于这种在一个集合中，某个位置左右两侧都要进行相同处理的问题，可以将左右两个条件列出来，然后统一进行处理。这样思考比较完整

#[allow(dead_lock)]
pub fn solve_saruman_armys(armys: & Vec<i32>,R:i32) -> i32 {
    let mut index = 0;
    let mut sum = 0;
    while index <  armys.len() {
        let start = armys[index as usize ];
        // handle the left of the point to sign 
        while index < armys.len() && start + R >= armys[index as usize] {
            index += 1;
        }

        let end = armys[index as usize];

        // handle the right of the point to sign 
        while index < armys.len() && end + R >= armys[index as usize] {
            index += 1;
        }
        sum += 1;
    }
    sum
}
