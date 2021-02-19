
## 그래프


## 깊이,너비 우선 탐색(DFS,BFS)
- 타겟 넘버 https://programmers.co.kr/learn/courses/30/lessons/43165
- Queue BFS

## 동적계획법(Dynamic Programming)

## 스택, 큐
- 다리를 지나는 트럭 https://programmers.co.kr/learn/courses/30/lessons/42583
- queue< pair < int, int > >, vector
- 주식가격 https://programmers.co.kr/learn/courses/30/lessons/42584
- stack ( 인덱스 = 시간, pair 사용이 좋아보이지만 동일 값 )
	- stack에서 pop 할 때, 차이로 얻을 수 있는 부분과 무조건 vector의 _back() 뒷 삽입이 아닌 점에 대해서도 생각이 필요
- pq(pair, auto compare( (greater top), lambda, decltype )

## 완전탐색
모의고사 https://programmers.co.kr/learn/courses/30/lessons/42840
- auto, iterator 전위, 후위 증가 확인
소수 찾기 https://programmers.co.kr/learn/courses/30/lessons/42839
- next_permutation
	- queue(bfs), uset, checkPrime
	- fail: queue(bfs), stack(dfs)
## 이분탐색

## 정렬
- H-Index https://programmers.co.kr/learn/courses/30/lessons/42747
- K번째수 https://programmers.co.kr/learn/courses/30/lessons/42748
- vector 생성자(이터레이터), sort
- 가장 큰 수 https://programmers.co.kr/learn/courses/30/lessons/42746
- sort compare lambda( 숫자 비교 -> 붙인 문자 비교), case : zero full

## 탐욕법(Greedy)
- 체육복 https://programmers.co.kr/learn/courses/30/lessons/42862
- 그리드 : 현재 상황에서만 최적의 해를 구하기..

## 해시
- 완주하지 못한 선수 https://programmers.co.kr/learn/courses/30/lessons/42576
- hash counting. forRange hash, ( other. sort 후 앞, 뒤 비교 )
- 전화번호 목록 https://programmers.co.kr/learn/courses/30/lessons/42577
- custom hasher, equal
- sort, string compare(== substr)

## 힙(Heap)
- 더 맵게 https://programmers.co.kr/learn/courses/30/lessons/42626
- stl pq( =heap ), in-place sort ( small top = greater ), include <queue>