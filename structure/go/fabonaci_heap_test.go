package main

import "testing"

// why can I use the main package in the same path ???? fuck !!!
//import . "leemaster.cn/algorithm/structure"

type SomeCompare struct {
	value int32
}

func (some *SomeCompare) Compare(comparer Comparer) (int32, error) {
	return 0, nil
}

type Int int

func (i Int) Compare(comparer Comparer) (int32, error) {
	return 0, nil
}

func TestCompaerNode(t *testing.T) {

	value := SomeCompare{int32(1)}

	node := fabonaciNode{Int(0), nil, nil, nil, nil, 0, false}

	result, err := node.Compare(&value)
	if err != nil {
		t.Log(err)
	} else {
		t.Log(result)
		t.Fail()
	}

}

func TestSimpleFabonaciHeap(t *testing.T) {
	t.Log("Start Test")
}
