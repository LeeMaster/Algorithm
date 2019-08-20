package main

// Heap will be used as the filter to get the most suitable element in a senquence
// Heap support search method in O(n) time complexity

import "errors"
import "math"

// Comparer should implement this interface to compare with the same type
type Comparer interface {
	Compare(comparer Comparer) (int32, error)
}

// Heap is the heap interface of the ABT
type Heap interface {
	Insert(value Comparer) bool
	Minimum() Comparer
	ExtractMin() Comparer
	Union(heap Heap) bool
	DecreaseKey(origin, target Comparer) bool
	Delete(value Comparer)
}

type fabonaciNode struct {
	value  Comparer
	parent *fabonaciNode
	child  *fabonaciNode
	left   *fabonaciNode
	right  *fabonaciNode
	degree int  // FIXME: why this variable not be used
	mark   bool // this node is the smallest of the all child
}

// Implement Comparer trait then can compare two nodes directly
func (node *fabonaciNode) Compare(comparer Comparer) (int32, error) {
	other, ok := comparer.(*fabonaciNode)
	if ok {
		return node.value.Compare(other.value)
	}
	return -2, errors.New("Not suitable type input")
}

// FabonaciHeap is the FabonaciHeap struct
type FabonaciHeap struct {
	min  *fabonaciNode
	root *fabonaciNode // the minimum at the heap
	Len  int
	// is the D(n) the root linked list max length
	max int //FIXME:  when the root array to the max then traigger the decrease_key method ?
}

// NewFabonaciHeap create a new FabonaciHeap
func NewFabonaciHeap(rootMax int) FabonaciHeap {
	return FabonaciHeap{nil, nil, 0, rootMax}
}

// Insert a new compare value in to the heap
func (heap *FabonaciHeap) Insert(value Comparer) bool {
	waited := value.(*fabonaciNode)
	if heap.root == nil {
		heap.root = waited
		heap.min = heap.root
		heap.Len = 1
		//circularly linked
		waited.left = waited
		waited.right = waited
		return true
	}
	heap.insert(waited)
	return true
}

// Minimum get the minimum value of this heap
func (heap *FabonaciHeap) Minimum() Comparer {
	return heap.min
}

// ExtractMin return the min and then will re-adjust the heap to blance
func (heap *FabonaciHeap) ExtractMin() Comparer {
	pointer := heap.min
	if pointer != nil {
		precursor := pointer.left
		// if the precursor is nil then after some common operations the left shouldn't nil
		// FIXME: should keep circularly at the child circularly linked list
		for child := pointer.child; child != nil; child = child.right {
			child.parent = nil
			precursor.right = child
			child.left = precursor
			child.right = pointer.right
			pointer.right.left = child
			precursor = child
		}
		// remove pointer from the list

		//heapfy
		if pointer == pointer.right {
			heap.min = nil
		} else {
			//will find the left
			heap.consolidate()
		}
		heap.Len--
		return pointer
	}

	return nil
}

// Union two heap
func (heap *FabonaciHeap) Union(outer Heap) bool {
	innerHeap, ok := outer.(*FabonaciHeap)
	if !ok {
		// maybe the K-ary Heap but this thing cloud seem impossible !
		return ok
	}

	if innerHeap.Len == 0 {
		return true
	}

	if heap.root == nil {
		heap.root = innerHeap.root
		heap.min = innerHeap.min
		heap.Len = innerHeap.Len
		heap.max = int(math.Max(float64(heap.max), float64(innerHeap.max)))
		return true
	}
	// find the most right of this heap
	pointer := heap.min
	for pointer.right != nil {
		pointer = pointer.right
	}

	// concat the two heaps directly
	pointer.right = innerHeap.root
	innerHeap.root.left = pointer
	if res, err := heap.min.Compare(innerHeap.min); err == nil && res == -1 {
		heap.min = innerHeap.min
	}
	heap.Len += innerHeap.Len
	return true
}

// DecreaseKey will decrease the root list of this heap
func (heap *FabonaciHeap) DecreaseKey(origin, target Comparer) bool {
	return false
}

// Delete a node from this heap
func (heap *FabonaciHeap) Delete(value Comparer) {

}

// insert is inset with the node
func (heap *FabonaciHeap) insert(node *fabonaciNode) {
	pointer := heap.min

	// allways inset at the min left to keep circularly
	temp := pointer.left
	temp.right = node
	node.right = pointer
	node.left = temp
	pointer.left = node
	if res, err := node.Compare(pointer); err == nil && res == -1 {
		heap.min = node
	}
	heap.Len++
}

// consolidate will heapfy this heap
func (heap *FabonaciHeap) consolidate() {

}
