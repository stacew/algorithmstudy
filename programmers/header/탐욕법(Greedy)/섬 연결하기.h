#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42861
�ּ� ���� Ʈ��(MST : minimum spanning tree) �˰���
looping(cycle)�� ������ ��� ����(Vertex)�� �����ϴ� Ʈ��, �ּ� ����(Edge)�� ��

ũ������(kruskal) O(Edge log Vertex) : Edge�� ������ kruskal
1. �ּ� ���� ��� �������� ����
2. ���� �������� �� ���(Group Find)�� �θ� Group�� Ȯ���Ͽ� ������ Skip(Cycle)
3. �ٸ��ٸ� �� �θ� Group�� �ٸ� �θ� Group�� �����Ѽ� Group�� ��ħ(Union)
4. ��� ������ ó���� ������(2, 3) �ݺ�, ( ���� visit�� üũ �ϸ� ������ �� �Ǵ� ��� ���� )
Find ����ȭ : �θ� Group ���
Union ����ȭ : Rank ó��, ���� Rank �׷��� ū Rank �׷��� ����Ű����

����(prim) : Edge�� ������ prim
wiki : ���� �̿��� ������ ��� O(Edge log Vertex)�� �ð����⵵�� ������.
�׷����� ����� ������ ���(E = V log V) �Ǻ���ġ ���� �̿��Ͽ� �ξ� ������ ������ �� �ִ�.O(Edge + Vetex log Vertex)
1. ������ ���� �湮
2. �湮 ���տ���(�湮 ������ ������) �ּ� ���� ����� �����ϰ�, �ش� ���� �湮 ���տ� ����.
3. �湮 ������ �� �� ������(2) �ݺ�

������ ������ ��� �׷���(Sense Graph), ������ ���� �׷���(Dense Graph)
��� �׷������� ũ�罺Į, ���� �׷������ ���� �˰����� ����
#endif

//kruskal
int solution(int n, vector<vector<int>> costs) {

	sort(costs.begin(), costs.end(), [](const vector<int>& l, const vector<int>& r) {return l[2] < r[2]; });//1.

	vector< int > group(n); // node : 0 ~ n-1 ���
	for (int node = 1; node < group.size(); node++)
		group[node] = node;

	//find
	function<int(int)> fFind = [&](int node) {
		if (node == group[node])
			return group[node];

		return group[node] = fFind(group[node]);//find ����ȭ : �õ� �� �� ���� �θ� �׷��� ���
		//�⺻ return fFind(pa[node]);
	};


	//union
	vector< int > rank(n); //Rank ����ȭ�� : 0 �ʱ�ȭ
	auto fUnionFind = [&](int node1, int node2) {
		int smallGroup = fFind(node1);
		int largeGroup = fFind(node2);
		if (smallGroup == largeGroup) //2.
			return false;

		//Rank ����ȭ : ���� �׷��� ū �׷��� ����Ű�°� ����.
		if (rank[smallGroup] > rank[largeGroup]) //small, large check
			swap(smallGroup, largeGroup);
		else if (rank[smallGroup] == rank[largeGroup]) //large �̸� ����
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
//���忡�� �Ǽ�
struct myCompair.. operator() �� operarot�� ��� ���忡��..;

//pq�� ����� ���� �� ���� �ϴ� ����...
auto myPairGreater = [](const pair< int, int >& l, const pair< int, int >& r) { return l.second > r.second; };
using myPQ = priority_queue< pair< int, int>, vector< pair< int, int > >, decltype(myPairGreater) >;
#endif

//prim
int solution_prim(int n, vector<vector<int>> costs) {
#if 1
	struct myNumDist { int num;	int dist; };
	struct myNumDistGreater { bool operator()(const myNumDist& l, const  myNumDist& r) { return l.dist > r.dist; } };
	using myPQ = priority_queue< myNumDist, vector< myNumDist >, myNumDistGreater >;
#else //����� �Ǵ��� ��Ÿ�� crash
	using myNumDist = pair<int, int>;
#define num first
#define dist second
	function<bool(const myNumDist, const myNumDist)> myNumDistGreater = [](const myNumDist& l, const myNumDist& r) { return l.dist > r.dist; };
	using myPQ = priority_queue< myNumDist, vector< myNumDist >, decltype(myNumDistGreater)>;
#endif	
	unordered_map<int, myPQ> nndMap;
	unordered_set<int> visitSet;
	for (const auto& cost : costs) {
		nndMap[cost[0]].push({ cost[1], cost[2] });
		nndMap[cost[1]].push({ cost[0], cost[2] });
	}

	int answer = 0;
	auto fMinVertexFind = [&]() {
		myNumDist minNumDist{ INT_MAX, INT_MAX };//�ּ� ���� ���ϱ�
		for (auto iter = visitSet.begin(); iter != visitSet.end(); iter++) {
			auto pq = nndMap[*iter];

			while (pq.size() > 0 && visitSet.find(pq.top().num) != visitSet.end()) { //�湮������ pop
				pq.pop();
			}

			if (pq.size() > 0) {
				if (pq.top().dist < minNumDist.dist)
					minNumDist = pq.top();

				pq.pop();

			}
		}

		answer += minNumDist.dist;
		visitSet.insert(minNumDist.num); //�ش� ���� �湮 ���տ� ����.
	};

	visitSet.insert(nndMap.begin()->first); //1.

	while (visitSet.size() != n) //3. ( V - 1 �� )	
		fMinVertexFind(); //2.

	return answer;
}

#if 0
cout << solution(4, { {0, 1, 1}, {0, 2, 2}, {1, 2, 3}, {1, 3, 4}, {2, 3, 5} });
//output : 7
cout << endl;

cout << solution(5, { {0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4} });
//output : 8
cout << endl;

cout << solution(4, { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8} });
//output: 4
cout << endl;

cout << solution(6, { {0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4} });
//output: 11
cout << endl;

cout << solution(4, { {0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4} });
//output : 9
cout << endl;

cout << solution(5, { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 3}, {2, 3, 8}, {3, 4, 1} });
//output : 7
cout << endl;

cout << solution(4, { {0, 1, 3}, {0, 2, 4}, {1, 2, 7}, {1, 3, 3}, {2, 3, 10} });
//output : 10
cout << endl;
#endif