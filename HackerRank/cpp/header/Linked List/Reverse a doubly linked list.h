#pragma once
#if 0 
https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
����� LL ������

1. ����� LL�� �� �ڸ����� �����͸� ���� �����ϹǷ�, ������ swap �� next�� �Ѱ��ָ� �ȴ�.
2. ������ ��带 main�� head���� ���ϵǵ��� ó�� �߰�
���� ���⵵ : O(N) : ��� �Ǵ� ����
�ð� ���⵵ : O(1)

������ ����� ����Ʈ�� �ݺ������� ó���� �� ����.
���� ���⵵ : O(1)

#endif

#if 1 //�ݺ���
DoublyLinkedListNode * reverse(DoublyLinkedListNode * head) {
	auto cur = head;

	while (cur) {

		auto tempNext = cur->next;
		cur->next = cur->prev;
		cur->prev = tempNext;

		if (tempNext == nullptr)
			return cur;

		cur = tempNext;
	}
	return cur;
}

#else

DoublyLinkedListNode* recur(DoublyLinkedListNode* cur) {
	auto tempNext = cur->next;
	cur->next = cur->prev;
	cur->prev = tempNext;
	if (tempNext == nullptr)
		return cur;

	return recur(tempNext);
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
	head = recur(head);
	return head;
}
#endif