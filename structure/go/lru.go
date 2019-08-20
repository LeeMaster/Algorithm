package main

type node struct {
	Key   Index
	Value Order
	Prev  *node
	Next  *node
}

type LRU struct {
	head  *node
	tail  *node
	table map[Index]*node
	limit int
	size  int
}

func NewLRU(capcity int) LRU {
	return LRU{
		head:  nil,
		tail:  nil,
		table: make(map[Index]*node),
		limit: capcity,
		size:  0}
}

type NotEmitCacheError struct {
}

func (err *NotEmitCacheError) Error() string {
	return "Not emit the cache with the Key "
}

func (lru *LRU) Get(key Index) (Order, error) {
	if lru.size == 0 {
		return nil, nil
	}

	return nil, nil
}

func (lru *LRU) Put(key Index, val Order) bool {
	return false
}

func (lru *LRU) Remove(key Index) bool {
	return false
}

// func (lru *LRU) KeySet() (Ser, error) {
// 	return nil, nil
// }
