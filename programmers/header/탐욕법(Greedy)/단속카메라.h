#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42884
구간의 최소 교집합의 개수 남기는 문제
#endif
int solution(vector<vector<int>> routes) {
	//여기도 내부 정렬 후 0번 인덱스를 비교해야하는 부분 주의
	for (int i = 0; i < routes.size(); i++)
		sort(routes[i].begin(), routes[i].end(), [](const int& l, const int& r) {return l < r; });

	sort(routes.begin(), routes.end(), [](const vector<int>& l, const vector<int>& r) {return l[0] < r[0]; });

	int answer = 0;
	int prevEnd = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		int start = routes[i][0];
		int end = routes[i][1];
		if (prevEnd < start) {
			answer++;
			prevEnd = end;
		}
		else if (end < prevEnd) {
			prevEnd = end;
		}
	}

	return answer + 1;
}

////////////////////////// 밑에 실패 
//solution2 중간 실패 원인 하나. 구간의 크기 정렬 이후, 내부 정렬을 해서 구간 크기가 달라졌음. sort 우선순위 주의!!
//solution2 최종 실패 원인은 반례. 0,2, 2,3, 3,4, 4,6
//구간으로 정렬하여 가운데 3이 만들어지는 순간 양 옆이 서로소가 되어버려서 (0~2, 3, 4~6) 3개가 되어버림
//원래 답은 2개 ( 2랑 4에 설치해야 함.)

//위의 문제는 구간 이후 start 정렬해도 풀 수 없지만,
//어려운 comp를 잘못 만들면 확실한 검증이 어려워지니 웬만하면 방향을 변경.
vector<vector<int>> cam;
bool isContain(int car1, int car2, int i) {
	return car1 <= cam[i][0] && cam[i][1] <= car2;
}
bool isIntersect(int car1, int car2, int i) {
	return (car1 <= cam[i][0] && cam[i][0] <= car2) || (car1 <= cam[i][1] && cam[i][1] <= car2);
}
void cutIntersect(int car1, int car2, int i) {
	if (car1 <= cam[i][0] && cam[i][0] <= car2)
		cam[i][1] = car2;
	else
		cam[i][0] = car1;
}

int solution2(vector<vector<int>> routes) {
	cam.resize(0);

	//진입/진출 정렬
	for (int i = 0; i < routes.size(); i++)
		sort(routes[i].begin(), routes[i].end(), [](const int& l, const int& r) {return l < r; });

	//1. 길이가 작은 부분으로 정렬
	sort(routes.begin(), routes.end(), [](const vector<int>& l, const vector<int>& r) {
		if (l[1] - l[0] == r[1] - r[0])
			return l[0] < r[0];

		return l[1] - l[0] < r[1] - r[0];
		});

	//2. 서로소인 카메라 구간 집합을 생성한다.
	//3 - 1. 만약 다음 차량이 이 카메라 구간 집합을 포함할 경우 skip
	//3 - 2. 겹칠 경우 삭제와 동시에 작은 길이중 하나를 쪼개야 한다. ( 카메라는 점이라서 다음 생각 안해도 됨)
	//4. 안걸리면 카메라 구간을 추가한다.
	for (int i = 0; i < routes.size(); i++) {
		bool bContain = false;
		int nIntersectCam = -1;
		for (int j = 0; j < cam.size(); j++) {
			if (isContain(routes[i][0], routes[i][1], j)) {
				bContain = true;
				break;
			}

			if (isIntersect(routes[i][0], routes[i][1], j)) {
				nIntersectCam = j;
			}
		}
		if (bContain)
			continue;

		if (nIntersectCam != -1) {
			cutIntersect(routes[i][0], routes[i][1], nIntersectCam);
			continue;
		}

		cam.push_back(routes[i]);
	}

	return cam.size();
}
#if 0
cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
cout << endl;
cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
cout << endl;
cout << solution({ {0, 0}, });//1
cout << endl;
cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
cout << endl;
cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
cout << endl;
cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
cout << endl;
cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
cout << endl;
cout << solution({ {2,2},{0,1},{-10,9} });//2
cout << endl;
cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
cout << endl;
cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
cout << endl;
cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
cout << endl;
cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
cout << endl;
cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
cout << endl;
#endif


#if 0

int main()
{
	int testCount = 0;
	vector<vector<int>> routes;
	while (true) {
		routes.resize(0);
		for (int i = 0; i < 5; i++) {
			routes.push_back({ rand() % 7, rand() % 7 });
		}
		for (int i = 0; i < routes.size(); i++)
			sort(routes[i].begin(), routes[i].end(), [](const int& l, const int& r) {return l < r; });

		if (solution(routes) != solution2(routes)) {
			cout << "cout << solution({";
			for (const auto& r : routes) {
				cout << "{" << r[0] << "," << r[1] << "},";
			}
			cout << "}) << endl;";
			break;
		}

		cout << ++testCount << ", ";
	}
}
#endif