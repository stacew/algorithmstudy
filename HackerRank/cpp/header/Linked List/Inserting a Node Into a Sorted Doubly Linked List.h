#pragma once
#if 0
https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists
양방향 리스트 연결, 앞에 추가할 경우에 더미 세팅해두면 좋음.
자바랑 다르게 stack memory로 더미 만들기( 생성자 확인 )

#endif


/* class/stuct 구분 및 생성자 표시가 없어서 컴파일 에러로 확인해야 함.
DoublyLinkedListNode{
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};
*/

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    if (head == nullptr)
        return head;

    DoublyLinkedListNode dummy(-1);
    dummy.next = head;
    head->prev = &dummy;

    DoublyLinkedListNode* prev = nullptr;
    while (head != nullptr) {
        if (data < head->data) {
            DoublyLinkedListNode* p = new DoublyLinkedListNode(data);

            p->next = head;
            p->prev = head->prev->next;
            head->prev->next = p;
            head->prev = p;
            return dummy.next;

        }
        prev = head;
        head = head->next;
    }
    prev->next = new DoublyLinkedListNode(data);
    prev->next->prev = prev;

    return dummy.next;
}