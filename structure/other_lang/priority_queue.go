package structure

type Queue interface {
	Enqueue(item *Ord) bool
	Dequeue() *Ord
	Front() *Ord
	Tail() *Ord
	Empty() bool
}

type Ord interface {
	Cmp(other *Ord) int
}

type PriorityQueue struct {
	length  uint
	inner   []*Ord
	reverse bool
}

func heapParent(int ch) int {
	return ch / 2
}

func heapLchild(int pa) int {
	return pa * 2
}

func heapRchild(int pa) int {
	return pa*2 + 1
}

func NewPriorityQueue(reverse bool) PriorityQueue {
	return PriorityQueue{
		length:  0,
		inner:   []*Ord{},
		reverse: reverse,
	}
}

func (queue *PriorityQueue) shiftUp(pos int) {

}

func (queue *PriorityQueue) shiftDown(pos int) {

}

func (queue *PriorityQueue) swap(i, j int) {
	queue.inner[i], queue.inner[j] = queue.inner[j], queue.inner[i]
}

func (queue *PriorityQueue) Empty() bool {
	return queue.length == 0
}

func (self *int) Cmp(other *int) int {
	return self - other
}
