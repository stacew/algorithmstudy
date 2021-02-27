#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42895
실수 1 :  많이 넣는 부분이라서 rehash 및 bucket count, list로 낭비되는 부분때문에
의심없이 vector로 저장했는데, 결국 많은 숫자를 만들어 찾는 루틴이 존재하므로 uSet을 택해야 햇음.

실수 2 : 실수 1이 더 잘못했지만 2번이 성능에 큰 영향을 미치는 문제임.
최소 값을 구하는 문제라서 최소 값을 다 카운팅 했으면 그 부분에서 결론을 확인했어야하는데
LIMIT_COUNT 이후에 전부 찾아보려한 실수.

문제가 어려워서 저번에 솔루션을 대충 읽어보고 오늘 되새기며 푼다고 좀 산만했지만,
그래도 자료구조를 저장 외에 행위에 따라 성능 영향을 끼친다는 부분을 놓친게 아쉽다.
vector -> uSet의 변화는 쉽게 실수한 곳이 많아 찾아서 적용할 때가 많아보인다.
#endif



//숫자 N을 사용해서 number를 만들 때, 최소 사용 횟수(answer)
//number 1~32000
//최솟값이 8보다 크면 -1을 return 합니다.
constexpr int LIMIT_COUNT = 8;
int solution(int N, int number) {
	unordered_set<int> cnUSet[LIMIT_COUNT + 1];//사용 : 1 ~ LIMIT_COUNT, 미사용 0
	
	// ex) N=2라면, 2, 22, 222, 2222, ~~~ 넣어준다.
	int temp = 0;
	for (int c = 1; c <= LIMIT_COUNT; c++) {
		temp += N;
		cnUSet[c].insert(temp);
		temp *= 10;
	}

	for (int c = 1; c <= LIMIT_COUNT; c++) {

		for (int i = 1; i < c; i++) {
			//ex ) c가 5라면
			//i, c - i => 1과 4, 2와 3, 3과 2, 4와 1을 이용한 결과들이
			//count 5개로 도출할 수 있는 숫자들
			auto uset1 = cnUSet[i];
			auto uset2 = cnUSet[c - i];
			for (const auto& n1 : uset1) {
				for (const auto& n2 : uset2) {
					cnUSet[c].insert(n1 + n2);
					cnUSet[c].insert(n1 - n2);
					cnUSet[c].insert(n1 * n2);
					if (n2 != 0)
						cnUSet[c].insert(n1 / n2);
				}
			}
		}

		//최적화 : 최소 c를 구하는 것이니, 여기서 확인
		for (const auto& n : cnUSet[c])
			if (n == number)
				return c;
	}

	return -1;
}

#if 0
int main()
{
	cout << solution(5, 12) << endl;//4
	cout << solution(2, 11) << endl;//3
}
#endif