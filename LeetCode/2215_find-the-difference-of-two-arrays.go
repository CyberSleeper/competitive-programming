package main

func findDifference(nums1 []int, nums2 []int) [][]int {
	ret := [][]int{{}, {}}
	set := map[int]struct{}{}
	set1 := map[int]struct{}{}
	set2 := map[int]struct{}{}

	for _, v := range nums1 {
		set1[v] = struct{}{}
	}
	for _, v := range nums2 {
		if _, ok := set1[v]; ok {
			set[v] = struct{}{}
		}
	}

	set1 = map[int]struct{}{}

	for _, v := range nums1 {
		if _, ok := set[v]; !ok {
			set1[v] = struct{}{}
		}
	}
	for _, v := range nums2 {
		if _, ok := set[v]; !ok {
			set2[v] = struct{}{}
		}
	}

	for key := range set1 {
		ret[0] = append(ret[0], key)
	}
	for key := range set2 {
		ret[1] = append(ret[1], key)
	}

	return ret
}
