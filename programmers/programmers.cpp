#include "header/StlHeaders.h"


#if 0
1. 해시, dfs / bfs, 정렬, 완전탐색
2. 스택 / 큐, 힙
3. DP, 그래프, 탐욕법, 이분탐색
#endif

//#include "header/깊이,너비 우선 탐색(DFS,BFS)/네트워크.h"
//#include "header/깊이,너비 우선 탐색(DFS,BFS)/단어 변환.h"
//#include "header/깊이,너비 우선 탐색(DFS,BFS)/여행경로.h"
#include "header/탐욕법(Greedy)/섬 연결하기.h"
#if 0

#include "header/탐욕법(Greedy)/단속카메라.h"
#include "header/동적계획법(Dynamic Programming)/N으로 표현.h"
#include "header/동적계획법(Dynamic Programming)/정수 삼각형.h"
#include "header/동적계획법(Dynamic Programming)/등굣길.h"
#include "header/동적계획법(Dynamic Programming)/도둑질.h"
#include "header/이분탐색/징검다리.h"
#include "header/그래프/방의 개수.h"
#endif

int main()
{
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

#if 0
	for (const auto& n : solution({ {"I", "B"},		{"B", "I"},		{"I", "A"},		{"A", "D"},		{"D", "A"} }))
		cout << n << " , ";//I , B , I , A , D , A ,

	cout << endl << "--------------" << endl;
	for (const auto& n : solution({ {"ICN", "SFO"},		{"ICN", "ATL"},		{"SFO", "ATL"},		{"ATL", "ICN"},		{"ATL", "SFO"} }))
		cout << n << " , ";//ICN , ATL , ICN , SFO , ATL , SFO ,

	cout << endl << "--------------" << endl;
	for (const auto& n : solution({ {"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"} }))
		cout << n << " , ";//{ICN, B, ICN, A}

	cout << endl << "--------------" << endl;
	for (const auto& n : solution({ {"A", "C"} , {"ICN", "A"}, {"ICN", "A"}, {"A", "ICN"}, }))
		cout << n << " , ";//{ICN, A, ICN, A, C}

	cout << endl << "--------------" << endl;
	for (const auto& n : solution({ {"ICN", "A"}, { "ICN", "B" }, { "B", "ICN" } }))
		cout << n << " , ";//{ICN, B, ICN, A}

#endif


#if 0
	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
#endif
#if 0
	//solution({ {0, 3},{1, 9},{2, 6} });
	//solution({ {0, 3},{4, 3},{8, 3} });
	//solution({ {0, 10}, { 2, 10 }, { 9, 10 }, { 15, 2 }});
	//cout << solution({{0, 3}, {4, 3}, {8, 3}}) << 3 << endl;
	//cout << solution({{0, 5}, {6, 1}, {6, 2}}) << 3 << endl;
	//cout << solution({{0, 5}, {6, 2}, {6, 1}}) << 3 << endl;
	//cout << solution({{0, 5}, {2, 2}, {5, 3}}) << 5 << endl;
	//cout << solution({{0, 5}, {2, 2}, {4, 2}}) << 5 << endl;
	//cout << solution({ {0, 20}, {3, 4}, {3, 5}, {17, 2 } });// <<  << endl;
#if 0
	cout << 9 << solution({ {0, 3}, {1, 9}, {2, 6} }) << endl;
	cout << 9 << solution({ {1, 10}, {3, 3}, {10, 3} }) << endl;
	cout << 15 << solution({ {0, 10}, {4, 10}, {5, 11}, {15, 2} }) << endl;
	cout << 10 << solution({ {0, 10} }) << endl;
	cout << 9 << solution({ {0, 3}, {1, 9}, {2, 6}, {4, 3} }) << endl;
	cout << 3 << solution({ {0, 1}, {1, 2}, {500, 6} }) << endl;
	cout << 6 << solution({ {0, 3}, {1, 9}, {500, 6} }) << endl;
	cout << 1 << solution({ {0, 1}, {0, 1}, {1, 0} }) << endl;
	cout << 3 << solution({ {0, 3}, {4, 3}, {8, 3} }) << endl;
	cout << 3 << solution({ {0, 3}, {4, 3}, {10, 3} }) << endl;
	cout << 3 << solution({ {0, 5}, {6, 2}, {6, 1} }) << endl;
	cout << 3 << solution({ {0, 5}, {6, 1}, {6, 2} }) << endl;
	cout << 5 << solution({ {0, 5}, {2, 2}, {5, 3} }) << endl;
	cout << 5 << solution({ {0, 5}, {2, 2}, {4, 2} }) << endl;
	cout << 4 << solution({ {0, 3}, {0, 1}, {4, 7} }) << endl;
	cout << 3 << solution({ {0, 2}, {3, 6}, {3, 1} }) << endl;
	cout << 6 << solution({ {0, 5}, {1, 2}, {5, 5} }) << endl;
	cout << 13 << solution({ {0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3} }) << endl;
#endif
	cout << 72 << solution({ {24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1} }) << endl;
	cout << 72 << solution({ {24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1} }) << endl;
	//cout << 13 << solution({ {1, 9}, {1, 4}, {1, 5}, {1, 7}, {1, 3} }) << endl;
	//solution({ {0, 10}, { 2, 10 }, { 25, 10}, { 25, 2 }});
#endif
#if 0
	solution(5, { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} });

#endif
#if 0
	for (const auto& n : solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }))
		cout << n << " , ";
#endif 
#if 0
	cout << solution({ 70,50,80,50 }, 100) << endl;
	cout << solution({ 100,100,10,10 }, 100) << endl;
	cout << solution({ 10, 20, 30, 40, 50, 60, 70, 80, 90 }, 100) << endl;
#endif
#if 0
	cout << solution("1924", 2) << " = " << 94 << endl;
	cout << solution("1231234", 3) << " = " << 3234 << endl;
	cout << solution("4177252841", 4) << " = " << 775841 << endl;
	cout << solution("9", 0) << " = " << 9 << endl;
	cout << solution("999", 2) << " = " << 9 << endl;
	cout << solution("4321", 2) << " = " << 43 << endl;
	cout << solution("1234", 2) << " = " << 34 << endl;
	cout << solution("999", 1) << " = " << 99 << endl;
	cout << solution("4321", 1) << " = " << 432 << endl;
	cout << solution("123456789", 7) << " = " << 89 << endl;
	cout << solution("987654321", 7) << " = " << 98 << endl;
#endif
#if 0
	cout << solution("JEROEN") << " = " << 56 << endl;
	cout << solution("JAN") << " = " << 23 << endl;
#endif
#if 0
	cout << solution({ 2,1,3,2 }, 2) << ", " << 1 << endl;
	cout << solution({ 1, 1, 9,1,1,1 }, 0) << ", " << 5 << endl;
#endif
#if 0
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };
	for (const auto& n : solution(progresses, speeds))
		cout << n << " , ";  //2,1
	auto s2 = solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });
	for (const auto& n : s2)
		cout << n << " , ";  //1,3,2
	for (const auto& n : solution({ 1,11,1,1,1 }, { 100, 100, 100, 100,100 }))
		cout << n << " , ";
	cout << endl << "-----------------------" << endl;
	for (const auto& n : solution({ }, {}))
		cout << n << " , ";
	cout << endl << "-----------------------" << endl;
	for (const auto& n : solution({ 1,95,1 }, { 100, 4,30 }))
		cout << n << " , ";
#endif
#if 0

	int n = 6;
	vector<vector<int>> edge = { {3, 6}, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 } };
	cout << solution(n, edge) << endl;
#endif
#if 0
	vector<vector<string>> vvs1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };//5
	cout << solution(vvs1) << endl;
	vector<vector<string>> vvs2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };//3
	cout << solution(vvs2) << endl;
	vector<vector<string>> vvs3 = { {"crow_mask", "face"} };
	cout << solution(vvs3) << endl;
#endif
#if 0
	vector<int> res = solution(10, 2);
	for (const auto& n : res)
		cout << n << ", ";//4,3
	cout << endl << "-----------------------" << endl;
	vector<int> res2 = solution(8, 1);
	for (const auto& n : res2)
		cout << n << ", ";//3,3
	cout << endl << "-----------------------" << endl;
	vector<int> res3 = solution(24, 24);
	for (const auto& n : res3)
		cout << n << ", ";//8,6
	cout << endl << "-----------------------" << endl;
	vector<int> res4 = solution(8, 1);
	for (const auto& n : res4)
		cout << n << ", ";
	cout << endl << "-----------------------" << endl;
	vector<int> res5 = solution(5000, 2000000);
	for (const auto& n : res5)
		cout << n << ", ";
#endif
#if 0
	cout << solution(8, 1) << endl;
	cout << "-----------------------" << endl;
	cout << solution(5000, 200000); << endl;
#endif
#if 0	
	vector<int> res = solution({ 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 });
	for (const auto& n : res)
		cout << n << endl;
#endif

	//	cout << endl << endl;
}