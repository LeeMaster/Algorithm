package structure

// should implement the Map Interface to support the map feature
import (
	"math/rand"
)

type SkipListEntry struct {
	Element Order
	Index   Index
}

func (entry *SkipListEntry) Cmp(other Order) int {
	return entry.Element.Cmp(other)
}

func (entry *SkipListEntry) Key() int {
	return entry.Index.Key()
}

type SkipNode struct {
	Element Entry
	Left    *SkipNode
	Right   *SkipNode
	Top     *SkipNode
	Bottom  *SkipNode
}

type SkipList struct {
	Head  *SkipNode
	Tail  *SkipNode
	Level int
	Size  int
}

// generate a node for skiplist
func newSkipNode(element Entry) SkipNode {
	return SkipNode{
		Element: element,
	}
}

func BuildSkipList(list []Entry) SkipList {
	node := newSkipNode(nil)
	// use the sentry head
	res := SkipList{
		&node,
		&node,
		1, // default level is 1
		0,
	}

	// for _,entry := range list[1:] {
	// 	node := newSkipNode(entry,entry)
	// 	res.Tail.RightNode = &node
	// 	res.Tail =&node
	// }

	return res
}

// TODO add the feature to find some specific level node linked list
func (list *SkipList) findPreviousNode(node *SkipNode) *SkipNode {
	if list.Size == 0 {
		return list.Head
	} else {
		cusor := list.Head
		// to find the bottom linked list head
		for list.Head.Bottom != nil {
			cusor = cusor.Bottom
		}

		cusor = cusor.Right

		// find the suit position
		for cusor.Right.Element.Cmp(node.Element) <= 0 {
			cusor = cusor.Right
		}

		return cusor
	}
}

// from the entry to build the skip list
func (list *SkipList) insert(entry Entry) error {

	currentNode := newSkipNode(entry)

	conactNodeFunc := func(pre *SkipNode, cur *SkipNode) {
		tempNode := pre.Right
		pre.Right = cur
		cur.Left = cur
		cur.Right = tempNode
		tempNode.Left = cur
	}

	conactNodeFunc(list.findPreviousNode(&currentNode), &currentNode)

	// TODO  use the random to generate the level and then do the build for level

	// buildLevelFunc := func

	//level := list.random(entry.Key())

	return nil
}

// cal the random level
func (list *SkipList) random(code int) int {
	seed := rand.Intn(list.Size)

	return seed
}

// use the random level to adjust the linked list
func (list *SkipList) adjustLevel(entry Entry) error {
	return nil
}

func (list *SkipList) Get(key Index) (Order, error) {
	return nil, nil
}

func (list *SkipList) Put(key Index, value Order) bool {
	entry := SkipListEntry{
		value,
		key,
	}
	// the entry is the implementation of the interface ,when call the method which use the interface type as the parameters
	// then should use the pointer to pass the reference of the entry type
	// this usage in golang is that accessing the address to get the real object for interface
	err := list.insert(&entry)

	return err == nil
}

func (list *SkipList) Remove(Key Index) bool {
	return false
}

func (list *SkipList) KeySet() (Set, error) {
	return nil, nil
}
