
/// leetcode 122 
///
/// 贪心算法来解决，首先分析一下题目，要求求的是最佳的股票交易日期，即需要一个买入和一个卖出时间，那么卖出和买入时间应该能组成一个逆序对
/// 目的是为了获得最大的收益，最大的收益是我们每一次都在价值谷底买入，价值高峰卖出，那么我们就可以一直在收益。
/// 那么这个问题变成了寻找距离最近的波峰和波谷的问题，自然用贪心就可以解决了。
/// 
/// tricky 是，我后来发现波谷和波峰之间的距离可以用多个次波峰的差值进行叠加得到。
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_count = 0;
        for idx in 1..prices.len(){
            if prices[idx as usize ] > prices[(idx - 1) as usize]{
                max_count += prices[idx as usize] - prices[(idx - 1) as usize];
            }
        }
        
        max_count
    }
}
