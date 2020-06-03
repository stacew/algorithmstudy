package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getChildSum(node *TreeNode) int {
	sum := 0
	if node.Left != nil {
		sum += node.Left.Val
	}
	if node.Right != nil {
		sum += node.Right.Val
	}

	return sum
}

func sumEvenGrandparent(root *TreeNode) int {
	if root == nil {
		return 0
	}
	sum := 0
	bGetSum := root.Val%2 > 0
	if root.Left != nil {
		sum += sumEvenGrandparent(root.Left)
		if bGetSum {
			sum += getChildSum(root.Left)
		}
	}
	if root.Right != nil {
		sum += sumEvenGrandparent(root.Right)
		if bGetSum {
			sum += getChildSum(root.Right)
		}
	}
	return sum
}

func main() {
	//https: //leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
}
