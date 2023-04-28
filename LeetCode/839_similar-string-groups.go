package main

type DSU struct {
	par []int
	size int
}

func NewDSU(n int) *DSU {
	var tmp DSU
	tmp.size = n
	for i := 0; i < n; i++ {
		tmp.par = append(tmp.par, i)
	}
	return &tmp
}

func (dsu *DSU) FindPar(x int) int {
	if dsu.par[x] != x {
		dsu.par[x] = dsu.FindPar(dsu.par[x])
	}
	return dsu.par[x]
}

func (dsu *DSU) Join(x, y int) bool {
	x = dsu.FindPar(x)
	y = dsu.FindPar(y)
	if x == y {
		return false
	}
	dsu.par[y] = x
	dsu.size--
	return true
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	team := NewDSU(n)
	for i := 0; i < n; i++ {
		for j := i+1; j < n; j++ {
			diff := 0
			for k := 0; k < len(strs[i]); k++ {
				if strs[i][k] != strs[j][k] {
					diff++
				}
			}
			if diff==2 || diff==0 {
				team.Join(i, j)
			}
		}
	}
	return team.size
}