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