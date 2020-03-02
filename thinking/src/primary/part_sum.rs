//! ## 部分和问题
//!
//! 判断从a1到an N个数中是否可以选出若干数使其值为K

/// ### 错误解法
///
/// 最开始思考这个问题是，如果从头开始计算就好了，但是通过算法代码看到了一个问题，如果第二轮循环开始，那么永远不会加上第一个数，并不能知道
/// 到底是否需要加上第一个数，因为这样做，并不能保证如果数字在第五个数大于了value，那么是否需要减去第二个数字再计算。很容易看起来正确，
/// 但是实际是漏掉了结果了。根本在于没有合理的利用数学对其进行建模。
#[allow(dead_code)]
pub fn part_sum_fault(array: &Vec<i32>, value: i32) -> (bool, Vec<i32>) {
    let mut sum = 0;
    let mut res = Vec::new();
    for i in 0..array.len() {
        res.push(array[i as usize]);
        sum += array[i as usize];
        for j in i..array.len() {
            res.push(array[j as usize]);
            if sum + array[j as usize] == value {
                return (true, res);
            } else {
                if sum + array[j as usize] > value {
                    res.pop();
                }
            }
        }
        sum -= 0;
        res.clear();
    }
    (false, res)
}

/// ### 正确的使用DFS
///
/// 首先抽象这个问题，这个问题本质是一个组合问题，即从一个集合中抽取一个集合，其值是否可以为Value值，那么对于任何一个数来说，都可以选择加入
/// 和不加入，那么复杂度自然是2^n 复杂度。
///
/// 算法的思路是进行DFS，向后进行迭代,分别进行两条路径的搜索，即加上当前操作数或者不加当前操作数。那么对于组合问题，即从某个集合选取某几个数
/// 构成新的集合之类的问题都可以通过DFS进行处理。当选取路径失败的时候，需要将记录栈弹出一个，同时减少总数
///
/// TODO Rust 代码肯定有问题，稍后再看下闭包的玩法，这么写太费劲了。也许可以使用tuple + type 来实现。
#[allow(non_snake_case, unused_variables, dead_code)]
pub fn part_sum_dfs_solve(array: &Vec<i32>, value: i32) -> (bool, Vec<i32>) {
    let mut res = Vec::new();
    let mut sum = 0;
    let index = 0;

    struct DFS<'a> {
        record: &'a mut Vec<i32>,
        array: &'a Vec<i32>,
        value: &'a i32,
        sum: &'a mut i32,
    }

    // should use the function to do the recurion
    fn dfs<'a>(DFS: &'a mut DFS, index: i32) -> bool {
        if index as usize == DFS.array.len() {
            return DFS.sum == DFS.value;
        }

        if dfs(DFS, index + 1) {
            return true;
        }

        *DFS.sum += DFS.array[index as usize];
        DFS.record.push(DFS.array[index as usize]);

        if dfs(DFS, index + 1) {
            return true;
        }

        // to record the path and the sum when at this situation then should pop the path and decrease the sum
        // this skill is backtrack
        DFS.record.pop();
        *DFS.sum -= DFS.array[index as usize];
        false
    }

    let mut internal_dfs = DFS {
        record: &mut res,
        array: array,
        value: &value,
        sum: &mut sum,
    };

    let index = 0;
    let result = dfs(&mut internal_dfs, index);

    (result, internal_dfs.record.clone())
}
