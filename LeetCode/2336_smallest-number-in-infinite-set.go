package main

type SmallestInfiniteSet struct {
	set   map[int]struct{}
	first int
}

func Constructor() SmallestInfiniteSet {
	return SmallestInfiniteSet{map[int]struct{}{}, 1}
}

func (this *SmallestInfiniteSet) PopSmallest() int {
	smallest := this.first
	this.set[smallest] = struct{}{}
	this.first++
	_, ok := this.set[this.first]
	for ok {
		this.first++
		_, ok = this.set[this.first]
	}
	return smallest
}

func (this *SmallestInfiniteSet) AddBack(num int) {
	if _, ok := this.set[num]; ok {
		delete(this.set, num)
		if num < this.first {
			this.first = num
		}
	}
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.PopSmallest();
 * obj.AddBack(num);
 */
