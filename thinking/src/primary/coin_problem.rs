//! 硬币问题
//!
//! 问题就是，给一堆硬币，并用这些硬币来支付，如何用最少的硬币来支付。
//!
//! 很明显是一个贪心问题，为了达成支付这个目标，并且使用最少的硬币，那么每次选用面值最大的硬币来进行支付，最后使
//! 使用的硬币数量自然是最少的
//!
//! 为什么是一个贪心问题呢，因为使用了一个硬币支付了一部分后，剩下的等待支付的部分和剩余的硬币组成了一个新的同类问
//! 题，比如支付金额为100
//! 我们首先支付一个最大面额为50的，那么硬币堆中自然就没有50这个硬币了（假设硬币的数量只有一个）
//! ok，那么剩下的钱如何支付呢？自然是从剩下的硬币中选取最大的面值来进行支付，问题被减小了一个复杂度
//!

use std::cmp;

#[allow(dead_code)]
pub fn coin_problem_greedy(coins: Vec<i32>, numbers: Vec<i32>, payment: i32) -> i32 {
    let mut payment = payment;
    let mut ans = 0;
    for (i,v) in coins.iter().rev().enumerate(){
      if payment == 0 {
        break;
      }
      let used = cmp::min(payment / v, numbers[i]);
      payment -= used * v;
      ans += used;
    }
    ans
}
