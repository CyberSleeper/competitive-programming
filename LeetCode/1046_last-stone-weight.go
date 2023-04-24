package main

import (
	"container/heap"
)

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	*h = old[:n-1]
	return old[n-1]
}

func lastStoneWeight(stones []int) int {
	maxHeap := MaxHeap(stones)
	heap.Init(&maxHeap)
	for len(maxHeap) > 1 {
		y := heap.Pop(&maxHeap).(int)
		x := heap.Pop(&maxHeap).(int)
		if x < y {
			heap.Push(&maxHeap, y-x)
		}
	}
	if len(maxHeap) == 1 {
		return maxHeap[0]
	}
	return 0
}
