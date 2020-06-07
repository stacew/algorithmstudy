type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSame(s *TreeNode, t *TreeNode) bool {
	if (s == nil) != (t == nil) {
		return false
	} else if s == nil {
		return true
	} else if s.Val != t.Val {
		return false
	}

	return isSame(s.Left, t.Left) && isSame(s.Right, t.Right)
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	if isSame(s, t) {
		return true
	} else if s.Left != nil && isSubtree(s.Left, t) {
		return true
	} else if s.Right != nil && isSubtree(s.Right, t) {
		return true
	}

	return false
}