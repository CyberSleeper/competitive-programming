package main

var (
	ret int
)

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func DFS(curNode *TreeNode, dir bool, step int) {
	if curNode == nil {
		return
	}
	ret = max(ret, step)
	if !dir {
		DFS(curNode.Left, !dir, step+1)
		DFS(curNode.Right, dir, 1)
	} else {
		DFS(curNode.Right, !dir, step+1)
		DFS(curNode.Left, dir, 1)
	}
}

func longestZigZag(root *TreeNode) int {
	ret = 0
	DFS(root, true, 0)
	DFS(root, false, 0)
	return ret
}
