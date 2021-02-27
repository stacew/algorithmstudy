/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func increasingBST(root *TreeNode) *TreeNode {
    if root == nil{
        return nil
    }
    
    var node, temp *TreeNode
    if root.Left != nil{
        node = increasingBST(root.Left)
    }
    
    if node == nil {
        node = &TreeNode{Val:root.Val}
        temp = node
    }else {
        temp = node        
        for temp.Right != nil {
            temp = temp.Right
        }
        temp.Right = &TreeNode{Val:root.Val}
        temp = temp.Right
    }
    
    if root.Right != nil{
        temp.Right = increasingBST(root.Right)        
    }
    return node
}