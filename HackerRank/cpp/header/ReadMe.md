# Graphs
	Roads and Libraries
	https://www.hackerrank.com/challenges/torque-and-development/copy-from/202673052?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
    도중에 끊기는 부분 때문에 순회인 줄 알았는데,
    탐색 변경 후 sort 이후 단 방향으로 처리한 부분이 문제가 되었음. => 반례. 1->3, 2->3 경우 2를 체크 시점에 lib 카운트가 증가해버린다.
	탐색일 때는 무조건 양방향 확인을 합시다...

# Linked List
	Inserting a Node Into a Sorted Doubly Linked List
	https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists
	양방향 리스트에 추가
	앞에 추가할 경우에 더미 세팅해두면 좋음.
	자바랑 다르게 stack memory로 더미 만들기( 생성자 확인 )

	Find Merge Point of Two Lists
	https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
	두 LL의 교차 지점 찾기
	순회 중 nullptr을 만나면 반대 헤더에서 시작하여 순회하면, 다른 길이라도 결국 만나는 지점 존재
	공간 : O(1)
	시간 : O(N)

	Reverse a doubly linked list
	https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
	양방향 LL 뒤집기

	1. 양방향 LL은 제 자리에서 포인터를 변경 가능하므로, 포인터 swap 후 next로 넘겨주면 된다.
	2. 마지막 노드를 main의 head까지 리턴되도록 처리 추가
	공간 복잡도 : O(N) : 재귀 또는 스택
	시간 복잡도 : O(1)

	하지만 양방향 리스트는 반복문으로 처리할 수 있음.
	공간 복잡도 : O(1)

# Miscellaneous
	Time Complexity Primality
	https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	소수 구할 때 sqrt를 쓰면 O(root N)t 처리가 가능..

	Friend Circle Queries
	https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	kruskal 방식을 생각하고 만든 것은 괜찮은데,
	함수에 umap 자료구조 넘겨줄 때, refrence를 적지 않아서. 시간초과가 발생.
	큰 데이터를 넘겨주는 곳에서 많이 호출하면 심하게 느려지므로 확인할 것.

	Maximum Xor
	https://www.hackerrank.com/challenges/maximum-xor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	trie 구조 만들고, 반복 이용하기

	Flipping bits
	https://www.hackerrank.com/challenges/flipping-bits/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	해커랭크는 long 8 byte, MSVC long 4 byte로 결과가 다름.
	long long 처리로 unsigned를 붙이면 어떤 변화가 있는지 확인은 가능..


# Stacks and Queues
	Min Max Riddle
	TODO : 마지막 부분에 대한 정리가 필요