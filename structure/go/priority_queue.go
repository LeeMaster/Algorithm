package main

type PQueue interface {
	Enqueue(item Ord) bool
	Dequeue() Ord
	Front() Ord
	Tail() Ord
	Empty() bool
}

type Ord interface {
	// can't not use the pointer to the interface type
	// for the interface the type need not to know which type finally use
	Cmp(other Ord) int
}

type PriorityQueue struct {
	length  uint
	tail    uint
	inner   []Ord
	reverse bool
}

func heapParent(ch int) int {
	return ch / 2
}

func heapLchild(pa int) int {
	return pa * 2
}

func heapRchild(pa int) int {
	return pa*2 + 1
}

func NewPriorityQueue(reverse bool) PriorityQueue {
	return PriorityQueue{
		length:  0,
		tail:    0,
		inner:   []Ord{},
		reverse: reverse,
	}
}

func (queue *PriorityQueue) swap(i, j int) {
	queue.inner[i], queue.inner[j] = queue.inner[j], queue.inner[i]
}

// 上浮方法
// 通过将最后插入的一个数进行上浮，上浮到其合适的位置，从而保证顺序的队列
func (queue *PriorityQueue) shiftUp(pos int) {
	for parent := heapParent(pos); parent > 0; parent /= 2 {
		rel := queue.inner[pos].Cmp(queue.inner[parent]) > 0 && queue.reverse
		if rel {
			queue.swap(pos, parent)
		} else {
			break
		}
	}
}

// 下沉方法
// 从头部开始下沉，分别比较左右孩子，是否和当前节点形成逆序，如果逆序，则向下浮动。
func (queue *PriorityQueue) shiftDown(pos int) {
	for child := heapLchild(pos); child < int(queue.length-1); child *= 2 {
		parent := child / 2
		if queue.inner[child].Cmp(queue.inner[child+1]) < 0 {
			child += 1
		}
		if queue.inner[parent].Cmp(queue.inner[child]) > 0 && queue.reverse {
			break
		}
		queue.swap(parent, child)
	}
}

// 入队
func (queue *PriorityQueue) Enqueue(elem Ord) bool {
	queue.inner = append(queue.inner, elem)
	queue.length += 1
	queue.tail += 1
	queue.shiftUp(int(queue.tail))
	return true
}

// 出队
// TODO 看一下golang 相关的 slice 源码，来优化操作减少不必要的调用
func (queue *PriorityQueue) Dequeue() Ord {
	return nil
}

func (queue *PriorityQueue) Empty() bool {
	return queue.length == 0
}
