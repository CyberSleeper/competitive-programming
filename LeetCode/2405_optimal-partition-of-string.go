package main

func partitionString(s string) int {
	ret := 1
	set := make(map[string]bool)
	for _, v := range s {
		if set[string(v)] {
			set = make(map[string]bool)
			ret++
		}
		set[string(v)] = true
	}
	return ret
}
