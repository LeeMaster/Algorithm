package structure

import (
	"math/rand"
)

type SkipNode struct {
	Element Entry 
	RightNode *SkipNode
	BottomNode *SkipNode
}

type SkipList struct {
	Top *SkipNode
	Tail *SkipNode
	Level int
	Size int 
}

// generate a node for skiplist 
func newSkipNode(element Entry) SkipNode{
	return SkipNode{
		Element: element,
		RightNode: nil,
		BottomNode: nil,
	}
}

func BuildSkipList(list []Entry) SkipList{
	node := newSkipNode(list[0])
	res := SkipList{
		&node,
		&node,
		0,
		0,
	}

	// for _,entry := range list[1:] {
	// 	node := newSkipNode(entry,entry)
	// 	res.Tail.RightNode = &node
	// 	res.Tail =&node
	// }

	return res 
}

// from the entry to build the skip list 
func (list *SkipList) insert(entry Entry) error {
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

func (list *SkipList) Get(key Index) (Order,error){
	return nil,nil
}

func (list *SkipList) Put(key Index,value Order) bool{
	return false
}

func (list *SkipList) Remove(Key Index) bool{
	return false
}

func (list *SkipList) KeySet()(Set,error){
	return nil,nil 
}


