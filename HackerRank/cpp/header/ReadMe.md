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

# Miscellaneous
	Time Complexity Primality
	https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	소수 구할 떄 sqrt를 쓰면 O(root N)t 처리가 가능..

	Friend Circle Queries
	https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	kruskal 방식을 생각하고 만든 것은 괜찮은데,
	함수에 umap 자료구조 넘겨줄 때, refrence를 적지 않아서. 시간초과가 발생.
	큰 데이터를 넘겨주는 곳에서 많이 호출하면 심하게 느려지므로 확인할 것.

	Maximum Xor
	https://www.hackerrank.com/challenges/maximum-xor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
	trie 구조 만들고, 반복 이용하기