package main

const MOD = 1000000007

func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
		ans := -1

		var DP1 [2][107]int
		DP1[1][0] = 1
		for i := range group {
			now, bef := i%2, (i+1)%2
			for j := 0; j <= n; j++ {
				DP1[now][j] = DP1[bef][j]
				if j >= group[i] {
					DP1[now][j] += DP1[bef][j-group[i]]
				}
				DP1[now][j] %= MOD
			}
		}
		for j := 0; j <= n; j++ {
			ans = (ans + DP1[(len(group)+1)%2][j]) % MOD
		}

		var DP2 [2][107][107]int
		DP2[1][0][0] = 1
		for i := range group {
			now, bef := i%2, (i+1)%2
			for j := 0; j <= n; j++ {
				for k := 0; k < minProfit; k++ {
					DP2[now][j][k] = DP2[bef][j][k]
					if j >= group[i] && k >= profit[i] {
						DP2[now][j][k] += DP2[bef][j-group[i]][k-profit[i]]
					}
					DP2[now][j][k] %= MOD
				}
			}
		}
		for j := 1; j <= n; j++ {
			for k := 0; k < minProfit; k++ {
				ans = (ans - DP2[(len(group)+1)%2][j][k]) % MOD
			}
		}
		return (ans + MOD) % MOD
}