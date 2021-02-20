#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42860
단순히 양 옆만 보고 이동
todo 알파벳은 어차피 전부 answer에 합쳐지니까 추가 계산이나 array가 필요없음, 좌우 이동만 A가 아닌지 확인하면 됨.
#endif


int solution(string name) {
	int answer = 0;

	//Base 'A' Circula Diff.
	array<int, 'Z' - 'A' + 1> alphaCounter;
	for (int i = 0; i < alphaCounter.size(); i++)
		alphaCounter[i] = i;
	for (int i = alphaCounter.size() - 1, j = 0; i >= 0; i--)
		alphaCounter[i] = min(alphaCounter[i], ++j);

	vector<int> arr;
	int remain = 0;
	for (const auto& c : name) {
		int count = alphaCounter[c - 'A'];
		arr.push_back(count);
		remain += count;
	}



	int pos = 0;
	while (remain > 0) { //exit ( remain == 0 )

		//1. calc
		if (arr[pos] > 0) {
			remain -= arr[pos];
			answer += arr[pos]; // joystick counter
			arr[pos] = 0;
			continue;
		}

		//2. move 
		int right = pos;
		int rightCount = 0;
		while (++right < arr.size()) {
			rightCount++;
			if (arr[right] > 0)
				break;
		}
		int left = pos;//( left : -1 to back Circula )
		int leftCount = 0;
		while (((--left + arr.size()) % arr.size()) != pos) {
			leftCount++;
			if (arr[(left + arr.size()) % arr.size()] > 0)
				break;
		}
		left = (left + arr.size()) % arr.size();

		if (left != pos && right < arr.size()) {
			int minCount = min(rightCount, leftCount);
			answer += minCount;// joystick <, >			
			pos = (rightCount == minCount) ? right : left;
		}
		else if (right < arr.size()) {
			answer += rightCount;
			pos = right;
		}
		else {
			answer += leftCount;
			pos = left;
		}
	}

	return answer;
}