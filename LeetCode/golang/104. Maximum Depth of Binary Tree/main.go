package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func myMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func addDepth(node *TreeNode) int {
	if node == nil {
		return 0
	}
	left := addDepth(node.Left)
	right := addDepth(node.Right)
	return 1 + myMax(left, right)
}

func maxDepth(root *TreeNode) int {
	return addDepth(root)
}

func main() {

}
