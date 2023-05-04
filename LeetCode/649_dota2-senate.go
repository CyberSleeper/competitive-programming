package main

func predictPartyVictory(senate string) string {
	n := len(senate)
	ded := make([]bool, n)
	R, D := false, false
	killR, killD := 0, 0
	for {
		R, D = false, false
		for i, v := range senate {
			if ded[i] {
				continue
			}
			if v == 'R' {
				if killR > 0 {
					ded[i] = true
					killR--
					continue
				}
				R = true
				killD++
			}
			if v == 'D' {
				if killD > 0 {
					ded[i] = true
					killD--
					continue
				}
				D = true
				killR++
			}
		}
		if (!R && D) || (R && !D) {
			break
		}
	}
	if R {
		return "Radiant"
	}
	return "Dire"
}