package main
// 这个问题看起来可能比较难
//
// 但是对于这个题目思考一下会发现，这个问题的本质是，给一个集合，修补集合，使得集合成为一个新的集合，并且这个新的集合中的各个子数组和的枚举
// 会构成一个 [1,n] 的集合覆盖
//
// 这个问题的解决思路，用数学归纳法描述如下
//
// * 前提，当数组为[1,1]时候，可以得到 [1] [1,1] 两个子数组，并且能覆盖的集合为 [1,2]
// * 假设，当数组为[1,x]时候可以覆盖[1,t]的集合，且令n=x+1
// * 演绎，当数组为[1,x+1]时，如果x与x+1 不连续，那么如果不进行补充，那么必然有[x,x+1]不连续覆盖，且根据假设可知，如果2*t > x+1 那么只需要填充t即可解决

func minPatches(nums []int, n int) int {

	suffix_sum := 1
	index := 0
	count := 0
	size := len(nums)
	for suffix_sum <= n {
		if index < size && suffix_sum >= nums[index] {
			suffix_sum += nums[index]
			index += 1
		} else {
			count += 1
			suffix_sum = suffix_sum << 1
		}
	}
	return 0
}

func main(){
	
}