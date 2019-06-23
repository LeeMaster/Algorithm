package structure

// base type interface
type Order interface {
	// Cmp will return the 0 if the two object is equal less is -1 grather is 1
	Cmp(other Order) int
}

// Key interface could use in the map 
type Index interface {
    Key() int
}

type Entry interface{
	Order
	Index
}

type Interable interface{
    // HasNext
    HasNext() bool
    // Next 
    Next() Order 
}

type List interface {
	// Get element in the list of index
	Get(index int) (Order, error)
	// insert element at the index
	Insert(index int, element Order) bool
	// remove the element at the index
	Remove(index int) (Order, error)
	// return the list size
	Size() int
	// if the list is empty
	IsEmpty() bool
}

type Stack interface {
	List
	// Push
	Push(element Order) bool
	// Pop
	Pop() (Order, error)
	// Peek
	Peek() (Order, error)
}

type Queue interface {
	List
	// enqueue
	Enqueue(element Order) bool
	// dequeue
	Dequeue() (Order, error)
	// Head
	Head() (Order, error)
	// Tail
	Tail() (Order, error)
}

type Set interface {
    Interable 
    List
    Contains(element Index) bool 
}

type Map interface{
    Get(key Index) (Order,error)
	Put(key Index,value Order) bool
	Remove(Key Index) bool
    KeySet()(Set,error)
}
