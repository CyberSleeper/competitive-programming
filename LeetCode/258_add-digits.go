package main

func addDigits(num int) int {
	res := 0
	nonZero := false
	for num > 0 {
		nonZero = true
		res += num % 10
		res %= 9
		num /= 10
	}
	if nonZero && res == 0 {
		res = 9
	}
	return res
}
