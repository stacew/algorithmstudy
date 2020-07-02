type SinglyLinkedListNode struct
{
    data int32
    next *SinglyLinkedListNode
}

func insertNodeAtPosition(llist *SinglyLinkedListNode, data int32, position int32) *SinglyLinkedListNode {
    
    var pHead *SinglyLinkedListNode = llist
    for i:=0; i < int(position) - 1; i++{
         llist = llist.next
    }    
    llist.next = &SinglyLinkedListNode{data:data, next:llist.next}
    return pHead
}
