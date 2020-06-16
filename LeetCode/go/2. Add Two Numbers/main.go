package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var l3 *ListNode
	carry := 0
	for l1 != nil || l2 != nil {
		l3 = &ListNode{0, nil}
		val := 0
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}
		if carry > 0 {
			val += carry
			carry = 0
		}
		if val >= 10 {
			val -= 10
			carry++
		}
		l3.Val = val
		l3 = l3.Next
	}
	return l3
}
