#pragma once
#if 0
https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists
����� ����Ʈ ����, �տ� �߰��� ��쿡 ���� �����صθ� ����.
�ڹٶ� �ٸ��� stack memory�� ���� �����( ������ Ȯ�� )

#endif


/* class/stuct ���� �� ������ ǥ�ð� ��� ������ ������ Ȯ���ؾ� ��.
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