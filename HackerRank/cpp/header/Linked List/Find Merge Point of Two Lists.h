#pragma once
#if 0
https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
�� LL�� ���� ���� ã��
��ȸ �� nullptr�� ������ �ݴ� ������� �����Ͽ� ��ȸ�ϸ�, �ٸ� ���̶� �ᱹ ������ ���� ����
���� : O(1)
�ð� : O(N)

#endif

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* cur1 = head1;
    SinglyLinkedListNode* cur2 = head2;
    while (cur1 != cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;

        if (cur1 == nullptr)
            cur1 = head2;
        if (cur2 == nullptr)
            cur2 = head1;
    }

    return cur1->data;
}