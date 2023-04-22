var (
	DP [502][502]int
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func minInsertions(s string) int {
	for i := range s {
		DP[i][i] = 1
		if i > 0 {
			if s[i-1] == s[i] {
				DP[i-1][i] = 2
			} else {	
				DP[i-1][i] = 1
			}
		}
	}
	for sz := 3; sz <= len(s); sz++ {
		for i := 0; i <= len(s)-sz; i++ {
			j := i + sz - 1
			if s[i] == s[j] {
				DP[i][j] = DP[i+1][j-1] + 2
			} else {
				DP[i][j] = max(DP[i+1][j], DP[i][j-1])
			}
		}
	}
	return len(s) - DP[0][len(s)-1]
}
