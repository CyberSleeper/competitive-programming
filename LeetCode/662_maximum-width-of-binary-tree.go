package main

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

var leMost, riMost []int

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func DFS(curNode *TreeNode, depth int, idx int) {
	if len(leMost) <= depth {
		leMost = append(leMost, idx)
	}
	leMost[depth] = min(leMost[depth], idx)

	if len(riMost) <= depth {
		riMost = append(riMost, idx)
	}
	riMost[depth] = max(riMost[depth], idx)

	if curNode.Left != nil {
		DFS(curNode.Left, depth+1, idx*2)
	}
	if curNode.Right != nil {
		DFS(curNode.Right, depth+1, idx*2+1)
	}
}

func widthOfBinaryTree(root *TreeNode) int {
	leMost, riMost = make([]int, 0), make([]int, 0)
	DFS(root, 0, 0)
	ans := 1
	for i := 0; i < len(leMost); i++ {
		ans = max(ans, riMost[i]-leMost[i]+1)
	}

	return ans
}
