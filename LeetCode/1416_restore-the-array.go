import "strconv"

const MOD = 1000000007

var DP [100007]int

func numberOfArrays(s string, k int) int {
	n := len(s)
	s = "0" + s
	for i := 1; i < len(DP); i++ {
		DP[i] = 0
	}
	DP[0] = 1
	for i := 1; i < len(s); i++ {
		tmp := ""
		for j := i; j > 0 && i-j <= 9; j-- {
			tmp = string(s[j]) + tmp
			if string(s[j]) == "0" {
				continue
			}
			curVal, _ := strconv.Atoi(tmp)
			if 1 <= curVal && curVal <= k {
				DP[i] = (DP[i] + DP[j-1]) % MOD
			}
		}
	}
	return DP[n]
}
