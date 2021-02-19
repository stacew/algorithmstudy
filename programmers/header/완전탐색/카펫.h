#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/42842
조합 계산
#endif
vector<int> solution(int brown, int yellow) {
	int ver = 3; // >=3;
	int hor = 2000000 * 5000; // >=3 && hor >= ver
	int all = brown + yellow;

	while (hor >= ver) {
		if (all % ver == 0) {
			hor = all / ver;
			if ((hor - 2) * (ver - 2) == yellow)
				break;
		}
		ver++;
	}

	return { hor, ver };
}

//another
#if 0
vector<int> solution(int brown, int red) {

	int len = brown / 2 + 2;

	int w = len - 3;
	int h = 3;

	while (w >= h) {
		if (w * h == (brown + red)) break;

		w--;
		h++;
	}

	return vector<int>{w, h};
}
#endif