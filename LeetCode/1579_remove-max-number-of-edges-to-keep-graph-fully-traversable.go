package main

import (
	"fmt"
	"sort"
)

type DSU []int

var par1, par2 DSU

func (dsu DSU) Find(x int) int {
	if dsu[x] != x {
		dsu[x] = dsu.Find(dsu[x])
	}
	return dsu[x]
}

func (dsu DSU) Join(u, v int) {
	u = dsu.Find(u)
	v = dsu.Find(v)
	dsu[u] = v
}

func (dsu DSU) Same(u, v int) bool {
	u = dsu.Find(u)
	v = dsu.Find(v)
	return u == v
}

func maxNumEdgesToRemove(n int, edges [][]int) int {
	par1 = make([]int, 0)
	par2 = make([]int, 0)
	for i := 0; i < n; i++ {
		par1 = append(par1, i)
		par2 = append(par2, i)
	}
	for _, v := range edges {
		v[0], v[2] = v[2], v[0]
		v[0]--
		v[1]--
	}
	sort.Slice(edges, func(i, j int) bool {
		return edges[i][2] > edges[j][2]
	})

	cnt := 0
	for _, v := range edges {
		fmt.Println(v)
		if v[2] == 1 {
			if !par1.Same(v[0], v[1]) {
				cnt++
				par1.Join(v[0], v[1])
			}
		} else if v[2] == 2 {
			if !par2.Same(v[0], v[1]) {
				cnt++
				par2.Join(v[0], v[1])
			}
		} else {
			if !par1.Same(v[0], v[1]) || !par2.Same(v[0], v[1]) {
				cnt++
				par1.Join(v[0], v[1])
				par2.Join(v[0], v[1])
			}
		}
	}
	for i := 1; i < n; i++ {
		if !par1.Same(0, i) || !par2.Same(0, i) {
			return -1
		}
	}
	return len(edges) - cnt
}