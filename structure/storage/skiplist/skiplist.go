package main

// Compartor To implement this interface could compare with each other same type elements
type Compartor interface {
	// To compare the element
	Compare(other Compartor) int
}

// Iterator
type Iterator interface {
	End() interface{}

	Next() interface{}
}

// Simple Map interface
type Map interface {
	// Get method
	Get(key Compartor) (error, interface{})

	// Put method
	Put(key Compartor, value interface{}) error

	// Remove method
	Remove(key Compartor) error

	// Iterator method
	Iter() (error, Iterator)
}

// listNode which will be used in the inner SkipList
type listNode struct {
	Value interface{}
	Key   Compartor
	// Pointer fields
	// TODO: 这里的实现需要考虑一下，通过某些手段实现Node节点的递增
}

// SkipList implementation
type SkipList struct {
}
