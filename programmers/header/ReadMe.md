## 그래프
- 가장 먼 노드 https://programmers.co.kr/learn/courses/30/lessons/49189
- graph(unordered_map<int, unordered_set<int>>)
- 가장 멀리 있는 노드 카운트 bfs queue 
- 순위 https://programmers.co.kr/learn/courses/30/lessons/49191
- 순위를 알려면 탐색 시, 전체적인 연결이 필요, 승리 방향을 바꿔서 양쪽 다 탐색 count를 확인.
- unordered_map< int unordered_set >그래프
- dfs( stack , visited )

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
- 기능개발 https://programmers.co.kr/learn/courses/30/lessons/42586
- q pair 넣는 방법 외에 미리 필요한 day를 계산해서 넣는 방식
- 프린터 https://programmers.co.kr/learn/courses/30/lessons/42587
- pq, q, pair

## 완전탐색
- 모의고사 https://programmers.co.kr/learn/courses/30/lessons/42840
- auto, iterator 전위, 후위 증가 확인
- 소수 찾기 https://programmers.co.kr/learn/courses/30/lessons/42839
- next_permutation
- queue(bfs), uset, checkPrime
- fail: queue(bfs), stack(dfs)
	
- 카펫 https://programmers.co.kr/learn/courses/30/lessons/42842
- 조합 계산

## 이분탐색
- https://programmers.co.kr/learn/courses/30/lessons/43238
- 최소 value와 최대 value를 계속 테스트 해보면서 가능할 지 체크 하는 이분 탐색
- gcd 최대 공약수, lcm 최소 공배수 //std c++17

## 정렬
- H-Index https://programmers.co.kr/learn/courses/30/lessons/42747
- K번째수 https://programmers.co.kr/learn/courses/30/lessons/42748
- vector 생성자(이터레이터), sort
- 가장 큰 수 https://programmers.co.kr/learn/courses/30/lessons/42746
- sort compare lambda( 숫자 비교 -> 붙인 문자 비교), case : zero full

## 탐욕법(Greedy)
- 체육복 https://programmers.co.kr/learn/courses/30/lessons/42862
- 그리드 : 현재 상황에서만 최적의 해를 구하기..
- 구명보트 https://programmers.co.kr/learn/courses/30/lessons/42885
- iterator 비교, 인덱스가 더 보기 쉬움.
- 조이스틱 https://programmers.co.kr/learn/courses/30/lessons/42860
- 단순히 양 옆만 보고 이동
- todo 알파벳은 어차피 전부 answer에 합쳐지니까 추가 계산이나 array가 필요없음, 좌우 이동만 A가 아닌지 확인하면 됨.
- 큰 수 만들기 https://programmers.co.kr/learn/courses/30/lessons/42883
- max_element(begin, end)
- string.erase(begin, end)
- distance(begin, end);//end - begin
- string <=> num ( stoi(), to_string() )

## 해시
- 완주하지 못한 선수 https://programmers.co.kr/learn/courses/30/lessons/42576
- hash counting. forRange hash, ( other. sort 후 앞, 뒤 비교 )
- 전화번호 목록 https://programmers.co.kr/learn/courses/30/lessons/42577
- custom hasher, equal
- sort, string compare(== substr)
- 위장 https://programmers.co.kr/learn/courses/30/lessons/42578
- umap, uset
- 조합 accumulate, multiplies<int>()
- 베스트앨범 https://programmers.co.kr/learn/courses/30/lessons/42579
- pair 보다 정보는 구조체 쓰는게 더 편하고 빠른 구현 되는 듯. pair 쓰지 말기..
- vector 구조체 push_back { }
- priority_queue 쓸 때, sort로 바꿀 생각 하기.

## 힙(Heap)
- 더 맵게 https://programmers.co.kr/learn/courses/30/lessons/42626
- stl pq( =heap ), in-place sort ( small top = greater ), include <queue>
- 디스크 컨트롤러 https://programmers.co.kr/learn/courses/30/lessons/42627
- 작업 시간 pq Next Time 처리하기(복잡함)
- 이중우선순위큐 https://programmers.co.kr/learn/courses/30/lessons/42628
- multiset 최소, 최대 구하기가 더 쉬웠음.
- 성능 테스트 결과(다양한 데이터 테스트 X)
- solution : solution_pqpquMap = 5(3052ms~15062ms) : 4(2404ms~11812ms)
- pqpqMap이 약간 빠름
- 메모리는 pqpqMap이 좀 더 많음.Delete 없이 Insert만 해도 비례로 차이날 듯.
- 결론 : 코드 복잡해지면 multiset 사용 고려!