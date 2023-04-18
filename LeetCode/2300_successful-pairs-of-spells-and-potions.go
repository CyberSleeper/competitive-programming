package main

import (
	"sort"
)

func successfulPairs(spells []int, potions []int, success int64) []int {
	var ret []int
	m := len(potions)
	sort.Ints(potions)
	for _, v := range spells {
		le, ri, ans := 0, m-1, m
		for le <= ri {
			if mi := (le + ri) / 2; int64(v*potions[mi]) >= success {
				ans = mi
				ri = mi - 1
			} else {
				le = mi + 1
			}
		}
		ret = append(ret, m-ans)
	}
	return ret
}
