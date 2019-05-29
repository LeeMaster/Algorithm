package main 

// 分析问题后发现，每一个项目和之前的项目都没有关联，也就是做第一个项目并不会影响第二个项目，子问题并不重叠，那么每一次选取最优的
// 结果就好了。最优的条件就是，利润和成本差值最大的项目。
// 
// TODO now is WA  cloud use the proorityQueue to solve this problem
func findMaximizedCapital(k int, W int, Profits []int, Capital []int) int {
	sumCapital := W // init captial 
	// k次选择都选择最优的方案，那么结果就是最优的
	record := map[int]bool{}
	for i := 0; i < k; i += 1{
		tempCaptial := sumCapital
		tempIndex := 0
		for index := 0;index < len(Profits); index += 1{
			
			if sumCapital >= Capital[index]{
				innerCaptial := tempCaptial + Profits[index] - Capital[index]
				if innerCaptial > tempCaptial{
					record[index] = true
					tempCaptial = innerCaptial
					record[tempIndex] = false
				}

				tempIndex = index
			}
		}
		sumCapital = tempCaptial
	}

	return sumCapital
}

func main(){

}