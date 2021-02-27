#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42895
�Ǽ� 1 :  ���� �ִ� �κ��̶� rehash �� bucket count, list�� ����Ǵ� �κж�����
�ǽɾ��� vector�� �����ߴµ�, �ᱹ ���� ���ڸ� ����� ã�� ��ƾ�� �����ϹǷ� uSet�� ���ؾ� ����.

�Ǽ� 2 : �Ǽ� 1�� �� �߸������� 2���� ���ɿ� ū ������ ��ġ�� ������.
�ּ� ���� ���ϴ� ������ �ּ� ���� �� ī���� ������ �� �κп��� ����� Ȯ���߾���ϴµ�
LIMIT_COUNT ���Ŀ� ���� ã�ƺ����� �Ǽ�.

������ ������� ������ �ַ���� ���� �о�� ���� �ǻ���� Ǭ�ٰ� �� �길������,
�׷��� �ڷᱸ���� ���� �ܿ� ������ ���� ���� ������ ��ģ�ٴ� �κ��� ��ģ�� �ƽ���.
vector -> uSet�� ��ȭ�� ���� �Ǽ��� ���� ���� ã�Ƽ� ������ ���� ���ƺ��δ�.
#endif



//���� N�� ����ؼ� number�� ���� ��, �ּ� ��� Ƚ��(answer)
//number 1~32000
//�ּڰ��� 8���� ũ�� -1�� return �մϴ�.
constexpr int LIMIT_COUNT = 8;
int solution(int N, int number) {
	unordered_set<int> cnUSet[LIMIT_COUNT + 1];//��� : 1 ~ LIMIT_COUNT, �̻�� 0
	
	// ex) N=2���, 2, 22, 222, 2222, ~~~ �־��ش�.
	int temp = 0;
	for (int c = 1; c <= LIMIT_COUNT; c++) {
		temp += N;
		cnUSet[c].insert(temp);
		temp *= 10;
	}

	for (int c = 1; c <= LIMIT_COUNT; c++) {

		for (int i = 1; i < c; i++) {
			//ex ) c�� 5���
			//i, c - i => 1�� 4, 2�� 3, 3�� 2, 4�� 1�� �̿��� �������
			//count 5���� ������ �� �ִ� ���ڵ�
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

		//����ȭ : �ּ� c�� ���ϴ� ���̴�, ���⼭ Ȯ��
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