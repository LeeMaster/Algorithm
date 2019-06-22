package structure


type SkipNode struct {
	index Index 
	Element Order 
	RightNode *SkipNode
	BottomNode *SkipNode
}

type SkipList struct {
	Top *SkipNode
	Tail *SkipNode
}

// generate a node for skiplist 
func newSkipNode(ref Index,ele Order) SkipNode{
	return SkipNode{
		index: ref,
		Element: ele,
		RightNode: nil,
		BottomNode: nil,
	}
}

func BuildSkipList(list []Entry) SkipList{
	node := newSkipNode(list[0],list[0])
	res := SkipList{
		&node,
		&node,
	}

	for _,entry := range list[1:] {
		node := newSkipNode(entry,entry)
		res.Tail.RightNode = &node
		res.Tail =&node
	}

	return res 
}

// cal the random level 
func random(size ,index int) int {
	return 1
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

func (list *SkipList) KeySet()(Set,error){
	return nil,nil 
}


