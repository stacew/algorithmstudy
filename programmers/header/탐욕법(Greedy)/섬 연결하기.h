#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42861
최소 신장 트리(MST : minimum spanning tree) 알고리즘
looping(cycle)이 없도록 모든 정점(Vertex)을 연결하는 트리, 최소 간선(Edge)의 합

크러스컬(kruskal) O(Edge log Vertex) : Edge가 적으면 kruskal
1. 최소 간선 비용 오름차순 정렬
2. 낮은 간선부터 두 노드(Group Find)의 부모 Group을 확인하여 같으면 Skip(Cycle)
3. 다르다면 한 부모 Group이 다른 부모 Group을 가리켜서 Group을 합침(Union)
4. 모든 간선을 처리할 때까지(2, 3) 반복, ( 정점 visit로 체크 하면 연결이 안 되는 경우 존재 )
Find 최적화 : 부모 Group 기록
Union 최적화 : Rank 처리, 작은 Rank 그룹이 큰 Rank 그룹을 가리키도록

프림(prim) : Edge가 많으면 prim
wiki : 힙을 이용해 구현할 경우 O(Edge log Vertex)의 시간복잡도를 가진다.
그래프가 충분히 빽빽한 경우(E = V log V) 피보나치 힙을 이용하여 훨씬 빠르게 구현할 수 있다.O(Edge + Vetex log Vertex)
1. 임의의 정점 방문
2. 방문 집합에서(방문 집합을 제외한) 최소 간선 비용을 선택하고, 해당 정점 방문 집합에 포함.
3. 방문 집합이 다 찰 때까지(2) 반복

간선이 적으면 희소 그래프(Sense Graph), 많으면 밀집 그래프(Dense Graph)
희소 그래프에는 크루스칼, 밀집 그래프라면 프림 알고리즘이 적절
#endif

//kruskal
int solution(int n, vector<vector<int>> costs) {

	sort(costs.begin(), costs.end(), [](const vector<int>& l, const vector<int>& r) {return l[2] < r[2]; });//1.

	vector< int > group(n); // node : 0 ~ n-1 사용
	for (int node = 1; node < group.size(); node++)
		group[node] = node;

	//find
	function<int(int)> fFind = [&](int node)->int {
		if (node == group[node])
			return group[node];

		return group[node] = fFind(group[node]);//find 최적화 : 시도 될 때 마다 부모 그룹을 기록
		//기본 return fFind(pa[node]);
	};


	//union
	vector< int > rank(n); //Rank 최적화용 : 0 초기화
	auto fUnionFind = [&](int node1, int node2) {
		int smallGroup = fFind(node1);
		int largeGroup = fFind(node2);
		if (smallGroup == largeGroup) //2.
			return false;

		//Rank 최적화 : 작은 그룹이 큰 그룹을 가리키는게 좋다.
		if (rank[smallGroup] > rank[largeGroup]) //small, large check
			swap(smallGroup, largeGroup);
		else if (rank[smallGroup] == rank[largeGroup]) //large 미리 증가
			rank[largeGroup]++;

		group[smallGroup] = largeGroup; //3.
		return true;
	};

	int answer = 0;
	for (int i = 0; i < costs.size(); i++) { //4.
		if (fUnionFind(costs[i][0], costs[i][1]))
			answer += costs[i][2]; //cost
	}

	return answer;
}


#if 0
//빌드에러 실수
struct myCompair.. operator() 를 operarot로 적어서 빌드에러..;

//pq를 밸류로 넣을 때 빌드 하는 법이...
auto myPairGreater = [](const pair< int, int >& l, const pair< int, int >& r) { return l.second > r.second; };
using myPQ = priority_queue< pair< int, int>, vector< pair< int, int > >, decltype(myPairGreater) >;
unordered_map<int, myPQ> dist;
#endif

//prim
struct myNumDist { int num;	int dist; };
struct myNumDistGreater { bool operator()(const myNumDist& l, const  myNumDist& r) { return l.dist > r.dist; } };
using myPQ = priority_queue< myNumDist, vector< myNumDist >, myNumDistGreater >;
int solution_prim(int n, vector<vector<int>> costs) {
	unordered_map<int, myPQ> nndMap;
	unordered_set<int> visitSet;
	for (const auto& cost : costs) {
		nndMap[cost[0]].push({ cost[1], cost[2] });
		nndMap[cost[1]].push({ cost[0], cost[2] });
	}

	int answer = 0;
	auto fMinVertexFind = [&]() {
		myNumDist minNumDist{ INT_MAX, INT_MAX };//최소 간선 구하기
		for (auto iter = visitSet.begin(); iter != visitSet.end(); iter++) {
			auto pq = nndMap[*iter];

			while (pq.size() > 0 && visitSet.find(pq.top().num) != visitSet.end()) { //방문했으면 pop
				pq.pop();
			}

			if (pq.size() > 0) {
				if (pq.top().dist < minNumDist.dist)
					minNumDist = pq.top();

				pq.pop();

			}
		}

		answer += minNumDist.dist;
		visitSet.insert(minNumDist.num); //해당 정점 방문 집합에 포함.
	};

	visitSet.insert(nndMap.begin()->first); //1.

	while (visitSet.size() != n) //3. ( V - 1 번 )	
		fMinVertexFind(); //2.

	return answer;
}