/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    var node *TreeNode
    if t1 == nil && t2 == nil {
        return nil
    }
    
    node = &TreeNode{}       
    var L1,L2,R1,R2 *TreeNode
     
    if t1 != nil {
        node.Val = node.Val + t1.Val
        L1 = t1.Left
        R1 = t1.Right
    }
    if t2 != nil {
        node.Val = node.Val + t2.Val
        L2 = t2.Left
        R2 = t2.Right
    }

    node.Left = mergeTrees(L1, L2)
    node.Right = mergeTrees(R1, R2)
    return node
}