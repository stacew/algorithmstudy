#pragma once
#if 0 
https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
양방향 LL 뒤집기

1. 양방향 LL은 제 자리에서 포인터를 변경 가능하므로, 포인터 swap 후 next로 넘겨주면 된다.
2. 마지막 노드를 main의 head까지 리턴되도록 처리 추가
공간 복잡도 : O(N) : 재귀 또는 스택
시간 복잡도 : O(1)

하지만 양방향 리스트는 반복문으로 처리할 수 있음.
공간 복잡도 : O(1)

#endif

#if 1 //반복문
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