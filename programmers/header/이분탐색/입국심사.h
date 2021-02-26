#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43238
최소 value와 최대 value를 계속 테스트 해보면서 가능할 지 체크 하는 이분 탐색

gcd 최대 공약수, lcm 최소 공배수 //std c++17
#endif

//n명의 대기, 사람마다 검사 시간이 다름
//한 심사대 당 동시에 한명만 심사 가능
//return 비어있는 심사대로 이동해서 시간 최소로.
//times는 심사관 당 검사 시간.
//n : 사람 1 ~ 10억
//심사관 1~ 10만명
//시간은 1 ~ 10억
//*. 완료 시간에 심사대가 비어도 기다렸다가 더 빠른 심사대가 있으면 기다림.

long long solution(int people, vector<int> times) {

	sort(times.begin(), times.end());
	long long lTime = 1; //최소 시간
	long long rTime = (long long)(times[times.size() - 1]) * people; //최대 시간

	long long answer = rTime;

	while (lTime <= rTime) {
		long long midTime = (lTime + rTime) / 2;
		
		//해당 시간에 몇 명이나 처리 가능한지 체크
		long long peopleCount = 0;
		for (const auto& t : times) {
			peopleCount += midTime / t;
		}

		if (peopleCount >= people) { //가능한 조건이 될 때 마다 answer 갱신.
			answer = midTime; 
			rTime = midTime - 1;
		}
		else {
			lTime = midTime + 1;
		}
	}

	return answer;
}

#if 0
int fGCD(int a, int b) {
	int m = min(a, b);
	int M = max(a, b);
	while (m != 0) {
		int temp = M % m;
		M = m;
		m = temp;
	}
	return M;
}
auto fLCM = [](int a, int b) {
	int gcd = fGCD(a, b);
	return a * b / gcd;
}
#endif