#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43236

풀이 방법)
0) "구해야 하는 정답"을 "기준값"으로 "가정"하고, "가능한 최소 ~ 최대값"을 이분 탐색하여 "답이 나오는지 시도"한다.
1 - 1) 기준값은 최대값을 구하는 것이기 때문에 "기준값 보다 작은 거리가 존재하면 지워질 돌이라는 의미다(지운 돌++)".
1 - 2) 이전에 지운 돌과 연속한 거리를 합해서 확인해야 한다.
2 - 1) 지운 돌의 개수가 타겟 n보다 많은 경우, 기준 값을 너무 크게 잡은 것이라서 r을 줄여준다.
2 - 2) 지운 돌의 개수가 타겟 n보다 적은 경우, 답이 될 수 있지만 가능한 최대값을 찾기 위해 더 진행을 한다.
3) 종료조건 : while (n <= r); 최대 값을 찾기 위해 모든 값을 시도 해야 한다.

시간 복잡도 O(R * log distance)
문제의 조건
도착지점까지의 거리 distance는 1 이상 1, 000, 000, 000 이하
바위는 1개 이상 50, 000개 이하
최악의 TC에서, 약 5만 * 30 회로 가능

#endif

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	int left = 1;
	int right = distance;

	int answer = 0;
	while (left <= right) { // 3) l > r 종료 조건

		// 0) 시도할 기준 값
		int midDistance = (left + right) / 2;

		// 1 - 1 ) 
		int removeRockCnt = 0;
		{
			int prev = 0; // 이전 지점까지의 길이 저장 ( 시작 : 0 )
			for (int rock : rocks) {
				if ((rock - prev) < midDistance)
					removeRockCnt++; // 1 - 2 ) 지워진 돌의 prev는 갱신하지 않음.
				else
					prev = rock;
			}
			if (distance - prev < midDistance)
				removeRockCnt++;
		}

		if (removeRockCnt > n) { // 2 - 1) 지운 돌이 n보다 많다. 무조건 답이 아니니, 기준 값을 낮춘다.
			right = midDistance - 1;
		}
		else {
			// 2 - 2) 지운 돌이 n보다 적거나 같다.
			// 기준 값의 "최대값"을 구해야 하기 때문에, 다음 기준값을 높여서 시도한다.
			answer = midDistance;
			left = midDistance + 1;
		}
	}

	return answer;
}

#if 0
int main()
{
	cout << solution(25, { 2, 11, 14, 17, 21 }, 2); //4
	cout << solution(18, { 2, 4, 7, 10, 14 }, 2);	//4
	cout << solution(24, { 3, 5, 10, 13, 19 }, 2);	//5 => minDis, removeRock//3, 1//4,2//5,2//6,4
	cout << solution(1000000, { 1, 2, 3, 4, 5,6,7,8 }, 0); //1
}
#endif