package main

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func mergeAlternately(word1 string, word2 string) string {
	ret := ""
	for i := 0; i < max(len(word1), len(word2)); i++ {
		if i < len(word1) {
			ret += string(word1[i])
		}
		if i < len(word2) {
			ret += string(word2[i])
		}
	}
	return ret
}
