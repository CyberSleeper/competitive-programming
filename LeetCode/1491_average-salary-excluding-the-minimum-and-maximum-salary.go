package main

func average(salary []int) float64 {
    var ret, lo, hi float64 = 0.0, 1000000007, -1
		for _, v := range salary {
			f := float64(v)
			if f < lo {
				lo = f
			}
			if f > hi {
				hi = f
			}
			ret += f
		}
		ret -= lo + hi
		return ret / float64(len(salary)-2)
}