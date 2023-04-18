package main

import (
	"sort"
)

func numRescueBoats(people []int, limit int) int {
    var ret int = 0
		n := len(people)
		sort.Ints(people)
		le, ri := 0, n-1
		for le <= ri {
			if people[le] + people[ri] <= limit {
				le++
			}
			ret++
			ri--
		}
		return ret
}