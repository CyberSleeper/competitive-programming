package main

func signFunc(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

func arraySign(nums []int) int {
    product := 1
		for _, v := range nums {
			product *= signFunc(v)
		}
		return product
}