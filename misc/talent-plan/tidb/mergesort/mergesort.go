package main

// MergeSort performs the merge sort algorithm.
// Please supplement this function to accomplish the home work.
func MergeSort(src []int64) {
	resChan := make(chan []int64)
	go simpleParalleMergeSort(src, resChan)
	result := <-resChan
	for i, v := range result {
		src[i] = v
	}
}

// this function alloc many space for sorting
// FIXME: sort on the origin Slice
func simpleParalleMerge(ldata []int64, rdata []int64) (result []int64) {
	result = make([]int64, len(ldata)+len(rdata))
	lidx, ridx := 0, 0

	for i := 0; i < cap(result); i++ {
		switch {
		case lidx >= len(ldata):
			result[i] = rdata[ridx]
			ridx++
		case ridx >= len(rdata):
			result[i] = ldata[lidx]
			lidx++
		case ldata[lidx] < rdata[ridx]:
			result[i] = ldata[lidx]
			lidx++
		default:
			result[i] = rdata[ridx]
			ridx++
		}
	}

	return
}

func simpleParalleMergeSort(data []int64, r chan []int64) {
	if len(data) == 1 {
		r <- data
		return
	}

	leftChan := make(chan []int64)
	rightChan := make(chan []int64)
	middle := len(data) / 2

	go simpleParalleMergeSort(data[:middle], leftChan)
	go simpleParalleMergeSort(data[middle:], rightChan)

	ldata := <-leftChan
	rdata := <-rightChan

	close(leftChan)
	close(rightChan)
	r <- simpleParalleMerge(ldata, rdata)
	return
}
