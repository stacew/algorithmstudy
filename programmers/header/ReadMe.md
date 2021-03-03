## 그래프
	
	가장 먼 노드 https://programmers.co.kr/learn/courses/30/lessons/49189
	graph(unordered_map<int, unordered_set<int>>)
	가장 멀리 있는 노드 카운트 bfs queue 

	순위 https://programmers.co.kr/learn/courses/30/lessons/49191
	순위를 알려면 탐색 시, 전체적인 연결이 필요, 승리 방향을 바꿔서 양쪽 다 탐색 count를 확인.
	unordered_map< int unordered_set >그래프
	dfs( stack , visited )
	
	방의 개수 https://programmers.co.kr/learn/courses/30/lessons/43236
	해시 특수화 할 때, 대충 만들면 느려질 수 있으니 주의
	equl이나 hash operator 재구현시 파라미터 끝에, const 붙여주기.
	uset<key> 대신 umap<key, bool>을 사용하면 너무 편하게 작성이 가능하다.(메모리는 추가로 사용하니 연습에서만..)

## 깊이,너비 우선 탐색(DFS,BFS)
	
	타겟 넘버 https://programmers.co.kr/learn/courses/30/lessons/43165
	Queue BFS
	
	네트워크 https://programmers.co.kr/learn/courses/30/lessons/43162
	따로 그래프 정보를 담아둘 필요는 없었음.
	queue bfs, visited
	
	단어 변환 https://programmers.co.kr/learn/courses/30/lessons/43163
	bfs(queue) 최소 도착 리턴
	visited(unordered_set)
	
	여행경로 https://programmers.co.kr/learn/courses/30/lessons/43164
	BackTrace recursion없이 Stack으로 풀기, Copy 필요 조건을 확실히 알기..

## 동적계획법(Dynamic Programming)
	
	N으로 표현 https://programmers.co.kr/learn/courses/30/lessons/42895
	실수 1 :  많이 넣는 부분이라서 rehash 및 bucket count, list로 낭비되는 부분때문에
	의심없이 vector로 저장했는데, 결국 많은 숫자를 만들어 찾는 루틴이 존재하므로 uSet을 택해야 햇음.
	실수 2 : 실수 1이 더 잘못했지만 2번이 성능에 큰 영향을 미치는 문제임.
	최소 값을 구하는 문제라서 최소 값을 다 카운팅 했으면 그 부분에서 결론을 확인했어야하는데
	LIMIT_COUNT 이후에 전부 찾아보려한 실수.
	문제가 어려워서 저번에 솔루션을 대충 읽어보고 오늘 되새기며 푼다고 좀 산만했지만,
	그래도 자료구조를 저장 외에 행위에 따라 성능 영향을 끼친다는 부분을 놓친게 아쉽다.
	vector -> uSet의 변화는 쉽게 실수한 곳이 많아 찾아서 적용할 때가 많아보인다.
	
	정수 삼각형 https://programmers.co.kr/learn/courses/30/lessons/43105
	
	등굣길 https://programmers.co.kr/learn/courses/30/lessons/42898
	mod(1000000007) 조건 : 중간 계산 기록할 때 마다 나머지 처리를 하기
	
	도둑질 https://programmers.co.kr/learn/courses/30/lessons/42897
	Circula 상태에서 최대 값 dp구하는 방법
	맨 뒤를 지운다, 맨 앞을 지운다. 최대 값을 비교한다.

## 스택, 큐
	
	다리를 지나는 트럭 https://programmers.co.kr/learn/courses/30/lessons/42583
	queue< pair < int, int > >, vector
	
	주식가격 https://programmers.co.kr/learn/courses/30/lessons/42584
	stack ( 인덱스 = 시간, pair 사용이 좋아보이지만 동일 값 )
	stack에서 pop 할 때, 차이로 얻을 수 있는 부분과 무조건 vector의 _back() 뒷 삽입이 아닌 점에 대해서도 생각이 필요
	pq(pair, auto compare( (greater top), lambda, decltype )
	
	기능개발 https://programmers.co.kr/learn/courses/30/lessons/42586
	q pair 넣는 방법 외에 미리 필요한 day를 계산해서 넣는 방식
	
	프린터 https://programmers.co.kr/learn/courses/30/lessons/42587
	pq, q, pair

## 완전탐색
	모의고사 https://programmers.co.kr/learn/courses/30/lessons/42840
	auto, iterator 전위, 후위 증가 확인
	
	소수 찾기 https://programmers.co.kr/learn/courses/30/lessons/42839
	next_permutation
	queue(bfs), uset, checkPrime
	fail: queue(bfs), stack(dfs)
	
	카펫 https://programmers.co.kr/learn/courses/30/lessons/42842
	조합 계산

## 이분탐색
	입국심사 https://programmers.co.kr/learn/courses/30/lessons/43238
	최소 value와 최대 value를 계속 테스트 해보면서 가능할 지 체크 하는 이분 탐색
	gcd 최대 공약수, lcm 최소 공배수 //std c++17
	
	징검다리 https://programmers.co.kr/learn/courses/30/lessons/43236
	풀이 방법)
	(0) "구해야 하는 정답"을 "기준값"으로 "가정"하고, "가능한 최소 ~ 최대값"을 이분 탐색하여 "답이 나오는지 시도"한다.
	(1 - 1) 기준값은 최대값을 구하는 것이기 때문에 "기준값 보다 작은 거리가 존재하면 지워질 돌이라는 의미다(지운 돌++)".
	(1 - 2) 이전에 지운 돌과 연속한 거리를 합해서 확인해야 한다.
	(2 - 1) 지운 돌의 개수가 타겟 n보다 많은 경우, 기준 값을 너무 크게 잡은 것이라서 r을 줄여준다.
	(2 - 2) 지운 돌의 개수가 타겟 n보다 적은 경우, 답이 될 수 있지만 가능한 최대값을 찾기 위해 더 진행을 한다.
	(3) 종료조건 : while (n <= r); 최대 값을 찾기 위해 모든 값을 시도 해야 한다.
	
	시간 복잡도 O(R * log distance)
	문제의 조건
	도착지점까지의 거리 distance는 1 이상 1, 000, 000, 000 이하
	바위는 1개 이상 50, 000개 이하
	최악의 TC에서, 약 5만 * 30 회로 가능

## 정렬
	
	H-Index https://programmers.co.kr/learn/courses/30/lessons/42747

	K번째수 https://programmers.co.kr/learn/courses/30/lessons/42748
	vector 생성자(이터레이터), sort

	가장 큰 수 https://programmers.co.kr/learn/courses/30/lessons/42746
	sort compare lambda( 숫자 비교 -> 붙인 문자 비교), case : zero full

## 탐욕법(Greedy)

	체육복 https://programmers.co.kr/learn/courses/30/lessons/42862
	그리드 : 현재 상황에서만 최적의 해를 구하기..
	
	구명보트 https://programmers.co.kr/learn/courses/30/lessons/42885
	iterator 비교, 인덱스가 더 보기 쉬움.
	
	조이스틱 https://programmers.co.kr/learn/courses/30/lessons/42860
	단순히 양 옆만 보고 이동
	todo 알파벳은 어차피 전부 answer에 합쳐지니까 추가 계산이나 array가 필요없음, 좌우 이동만 A가 아닌지 확인하면 됨.
	
	큰 수 만들기 https://programmers.co.kr/learn/courses/30/lessons/42883
	max_element(begin, end)
	string.erase(begin, end)
	distance(begin, end);//end - begin
	string <=> num ( stoi(), to_string() )
	
	섬 연결하기 https://programmers.co.kr/learn/courses/30/lessons/42861
	최소 신장 트리(MST : minimum spanning tree) 알고리즘
	looping(cycle)이 없도록 모든 정점(Vertex)을 연결하는 트리, 최소 간선(Edge)의 합
	
	크러스컬(kruskal) O(Edge log Vertex) : Edge가 적으면 kruskal
	(1) 최소 간선 비용 오름차순 정렬
	(2) 낮은 간선부터 두 노드(Group Find)의 부모 Group을 확인하여 같으면 Skip(Cycle)
	(3) 다르다면 한 부모 Group이 다른 부모 Group을 가리켜서 Group을 합침(Union)
	(4) 모든 간선을 처리할 때까지(2, 3) 반복, ( 정점 visit로 체크 하면 연결이 안 되는 경우 존재 )
	Find 최적화 : 부모 Group 기록
	Union 최적화 : Rank 처리, 작은 Rank 그룹이 큰 Rank 그룹을 가리키도록
	
	프림(prim) : Edge가 많으면 prim
	wiki : 힙을 이용해 구현할 경우 O(Edge log Vertex)의 시간복잡도를 가진다.
	그래프가 충분히 빽빽한 경우(E = V log V) 피보나치 힙을 이용하여 훨씬 빠르게 구현할 수 있다.O(Edge + Vetex log Vertex)
	(1) 임의의 정점 방문
	(2) 방문 집합에서(방문 집합을 제외한) 최소 간선 비용을 선택하고, 해당 정점 방문 집합에 포함.
	(3) 방문 집합이 다 찰 때까지(2) 반복
	
	단속카메라 https://programmers.co.kr/learn/courses/30/lessons/42884
	구간의 최소 교집합의 개수 남기는 문제

## 해시
	
	완주하지 못한 선수 https://programmers.co.kr/learn/courses/30/lessons/42576
	hash counting. forRange hash, ( other. sort 후 앞, 뒤 비교 )
	
	전화번호 목록 https://programmers.co.kr/learn/courses/30/lessons/42577
	custom hasher, equal
	sort, string compare(== substr)
	
	위장 https://programmers.co.kr/learn/courses/30/lessons/42578
	umap, uset
	조합 accumulate, multiplies<int>()
	
	베스트앨범 https://programmers.co.kr/learn/courses/30/lessons/42579
	pair 보다 정보는 구조체 쓰는게 더 편하고 빠른 구현 되는 듯. pair 쓰지 말기..
	vector 구조체 push_back { }
	priority_queue 쓸 때, sort로 바꿀 생각 하기.

## 힙(Heap)
	
	더 맵게 https://programmers.co.kr/learn/courses/30/lessons/42626
	stl pq( =heap ), in-place sort ( small top = greater ), include <queue>
	
	디스크 컨트롤러 https://programmers.co.kr/learn/courses/30/lessons/42627
	작업 시간 pq Next Time 처리하기(복잡함)
	
	이중우선순위큐 https://programmers.co.kr/learn/courses/30/lessons/42628
	multiset 최소, 최대 구하기가 더 쉬웠음.
	성능 테스트 결과(다양한 데이터 테스트 X)
	solution : solution_pqpquMap = 5(3052ms~15062ms) : 4(2404ms~11812ms)
	pqpqMap이 약간 빠름
	메모리는 pqpqMap이 좀 더 많음.Delete 없이 Insert만 해도 비례로 차이날 듯.
	결론 : 코드 복잡해지면 multiset 사용 고려!