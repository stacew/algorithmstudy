#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43238
�ּ� value�� �ִ� value�� ��� �׽�Ʈ �غ��鼭 ������ �� üũ �ϴ� �̺� Ž��

gcd �ִ� �����, lcm �ּ� ����� //std c++17
#endif

//n���� ���, ������� �˻� �ð��� �ٸ�
//�� �ɻ�� �� ���ÿ� �Ѹ� �ɻ� ����
//return ����ִ� �ɻ��� �̵��ؼ� �ð� �ּҷ�.
//times�� �ɻ�� �� �˻� �ð�.
//n : ��� 1 ~ 10��
//�ɻ�� 1~ 10����
//�ð��� 1 ~ 10��
//*. �Ϸ� �ð��� �ɻ�밡 �� ��ٷȴٰ� �� ���� �ɻ�밡 ������ ��ٸ�.

long long solution(int people, vector<int> times) {

	sort(times.begin(), times.end());
	long long lTime = 1; //�ּ� �ð�
	long long rTime = (long long)(times[times.size() - 1]) * people; //�ִ� �ð�

	long long answer = rTime;

	while (lTime <= rTime) {
		long long midTime = (lTime + rTime) / 2;
		
		//�ش� �ð��� �� ���̳� ó�� �������� üũ
		long long peopleCount = 0;
		for (const auto& t : times) {
			peopleCount += midTime / t;
		}

		if (peopleCount >= people) { //������ ������ �� �� ���� answer ����.
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