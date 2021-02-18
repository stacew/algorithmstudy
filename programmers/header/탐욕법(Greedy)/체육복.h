#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42862
//�׸��� : ���� ��Ȳ������ ������ �ظ� ���ϱ�..

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> clothes(n, 1); //n ũ��, �� 1 �ʱ�ȭ
	for (int i = 0; i < reserve.size(); i++)
		clothes[reserve[i] - 1]++;

	for (int i = 0; i < lost.size(); i++)
		clothes[lost[i] - 1]--;

	for (int i = 0; i < clothes.size(); i++){
		if (clothes[i] != 0)
			continue;
		
		if (i - 1 >= 0 && clothes[i - 1] == 2) {
			clothes[i - 1] = 1;
			clothes[i] = 1;
		}
		else if (i + 1 < clothes.size() && clothes[i + 1] == 2) {
			clothes[i + 1] = 1;
			clothes[i] = 1;
		}
	}
	
	for (const auto& c : clothes) {
		if (c > 0)
			answer++;
	}
	return answer;
}
