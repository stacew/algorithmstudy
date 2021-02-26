#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42884
������ �ּ� �������� ���� ����� ����
#endif
int solution(vector<vector<int>> routes) {
	//���⵵ ���� ���� �� 0�� �ε����� ���ؾ��ϴ� �κ� ����
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

////////////////////////// �ؿ� ���� 
//solution2 �߰� ���� ���� �ϳ�. ������ ũ�� ���� ����, ���� ������ �ؼ� ���� ũ�Ⱑ �޶�����. sort �켱���� ����!!
//solution2 ���� ���� ������ �ݷ�. 0,2, 2,3, 3,4, 4,6
//�������� �����Ͽ� ��� 3�� ��������� ���� �� ���� ���μҰ� �Ǿ������ (0~2, 3, 4~6) 3���� �Ǿ����
//���� ���� 2�� ( 2�� 4�� ��ġ�ؾ� ��.)

//���� ������ ���� ���� start �����ص� Ǯ �� ������,
//����� comp�� �߸� ����� Ȯ���� ������ ��������� �����ϸ� ������ ����.
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

	//����/���� ����
	for (int i = 0; i < routes.size(); i++)
		sort(routes[i].begin(), routes[i].end(), [](const int& l, const int& r) {return l < r; });

	//1. ���̰� ���� �κ����� ����
	sort(routes.begin(), routes.end(), [](const vector<int>& l, const vector<int>& r) {
		if (l[1] - l[0] == r[1] - r[0])
			return l[0] < r[0];

		return l[1] - l[0] < r[1] - r[0];
		});

	//2. ���μ��� ī�޶� ���� ������ �����Ѵ�.
	//3 - 1. ���� ���� ������ �� ī�޶� ���� ������ ������ ��� skip
	//3 - 2. ��ĥ ��� ������ ���ÿ� ���� ������ �ϳ��� �ɰ��� �Ѵ�. ( ī�޶�� ���̶� ���� ���� ���ص� ��)
	//4. �Ȱɸ��� ī�޶� ������ �߰��Ѵ�.
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