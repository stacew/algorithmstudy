#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43236

Ǯ�� ���)
0) "���ؾ� �ϴ� ����"�� "���ذ�"���� "����"�ϰ�, "������ �ּ� ~ �ִ밪"�� �̺� Ž���Ͽ� "���� �������� �õ�"�Ѵ�.
1 - 1) ���ذ��� �ִ밪�� ���ϴ� ���̱� ������ "���ذ� ���� ���� �Ÿ��� �����ϸ� ������ ���̶�� �ǹ̴�(���� ��++)".
1 - 2) ������ ���� ���� ������ �Ÿ��� ���ؼ� Ȯ���ؾ� �Ѵ�.
2 - 1) ���� ���� ������ Ÿ�� n���� ���� ���, ���� ���� �ʹ� ũ�� ���� ���̶� r�� �ٿ��ش�.
2 - 2) ���� ���� ������ Ÿ�� n���� ���� ���, ���� �� �� ������ ������ �ִ밪�� ã�� ���� �� ������ �Ѵ�.
3) �������� : while (n <= r); �ִ� ���� ã�� ���� ��� ���� �õ� �ؾ� �Ѵ�.

�ð� ���⵵ O(R * log distance)
������ ����
�������������� �Ÿ� distance�� 1 �̻� 1, 000, 000, 000 ����
������ 1�� �̻� 50, 000�� ����
�־��� TC����, �� 5�� * 30 ȸ�� ����

#endif

int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	int left = 1;
	int right = distance;

	int answer = 0;
	while (left <= right) { // 3) l > r ���� ����

		// 0) �õ��� ���� ��
		int midDistance = (left + right) / 2;

		// 1 - 1 ) 
		int removeRockCnt = 0;
		{
			int prev = 0; // ���� ���������� ���� ���� ( ���� : 0 )
			for (int rock : rocks) {
				if ((rock - prev) < midDistance)
					removeRockCnt++; // 1 - 2 ) ������ ���� prev�� �������� ����.
				else
					prev = rock;
			}
			if (distance - prev < midDistance)
				removeRockCnt++;
		}

		if (removeRockCnt > n) { // 2 - 1) ���� ���� n���� ����. ������ ���� �ƴϴ�, ���� ���� �����.
			right = midDistance - 1;
		}
		else {
			// 2 - 2) ���� ���� n���� ���ų� ����.
			// ���� ���� "�ִ밪"�� ���ؾ� �ϱ� ������, ���� ���ذ��� ������ �õ��Ѵ�.
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