package main

import (
	"sort"
)

var par []int

func FindPar(x int) int {
	if par[x] != x {
		par[x] = FindPar(par[x])
	}
	return par[x]
}

func Join(u, v int) {
	u = FindPar(u)
	v = FindPar(v)
	par[u] = v
}

func Same(u, v int) bool {
	u = FindPar(u)
	v = FindPar(v)
	return u == v
}

func distanceLimitedPathsExist(n int, edgeList [][]int, queries [][]int) []bool {
	ret := make([]bool, len(queries))
	par = make([]int, 0)
	for i := 0; i < n; i++ {
		par = append(par, i)
	}
	for i := range queries {
		queries[i] = append(queries[i], i)
	}

	sort.Slice(edgeList, func(i, j int) bool {
		return edgeList[i][2] < edgeList[j][2]
	})
	sort.Slice(queries, func(i, j int) bool {
		return queries[i][2] < queries[j][2]
	})

	edgePtr := 0
	for _, v := range queries {
		for edgePtr < len(edgeList) && edgeList[edgePtr][2] < v[2] {
			Join(edgeList[edgePtr][0], edgeList[edgePtr][1])
			edgePtr++
		}
		ret[v[3]] = Same(v[0], v[1])
	}

	return ret
}
