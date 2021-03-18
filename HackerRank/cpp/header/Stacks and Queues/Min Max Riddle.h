#pragma once
#if 0
https://www.hackerrank.com/challenges/min-max-riddle/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues

#endif

vector<long> riddle(vector<long> arr) {

	int n = arr.size();

	vector<int> lSpan(n);
	stack<int> stkIndex;
	stkIndex.push(-1);
	for (int i = 0; i < arr.size(); i++) {
		while (	stkIndex.top() != -1 && arr[stkIndex.top()] >= arr[i])
			stkIndex.pop();

		lSpan[i] = i - stkIndex.top();
		stkIndex.push(i);
	}

	vector<int> rSpan(n);
	stkIndex = stack<int>();
	stkIndex.push(n);
	for (int i = n - 1; i >= 0; i--) {
		while (	stkIndex.top() != n && arr[stkIndex.top()] >= arr[i])
			stkIndex.pop();

		rSpan[i] = stkIndex.top() - i;
		stkIndex.push(i);
	}


	vector<long> window(n + 1);
	for (int i = 0; i < n; i++) {
		int windowSize = rSpan[i] + lSpan[i] - 2 + 1;
		window[windowSize] = std::max(window[windowSize], arr[i]);
	}

	for (int i = n - 2; i >= 1; i--) {
		window[i] = std::max(window[i], window[i + 1]);
	}

	window.erase(window.begin());
	return window;
}


/*
vector<long> riddle(vector<long> arr) {
	int n = arr.size();

	vector<int> leftSpan(n);
	std::fill(leftSpan.begin(), leftSpan.end(), -1);

	stack<int> stkLeftIndex;
	for (int i = 0; i < arr.size(); i++) {
		while (stkLeftIndex.empty() == false && arr[stkLeftIndex.top()] >= arr[i])
			stkLeftIndex.pop();

		if (stkLeftIndex.empty() == false)
			leftSpan[i] = stkLeftIndex.top();

		stkLeftIndex.push(i);
	}

	stack<int> stkRightIndex;
	vector<int> rightSpan(n);
	std::fill(rightSpan.begin(), rightSpan.end(), n);
	for (int i = n - 1; i >= 0; i--) {
		while (stkRightIndex.empty() == false && arr[stkRightIndex.top()] >= arr[i])
			stkRightIndex.pop();

		if (stkRightIndex.empty() == false)
			rightSpan[i] = stkRightIndex.top();

		stkRightIndex.push(i);
	}

	vector<long> answer(n);
	for (int index = 0; index < n; index++) {
		const int windowSize = rightSpan[index] - leftSpan[index] - 2;
		answer[windowSize] = std::max(arr[index], answer[windowSize]);
	}
	for (int index = n - 2; index >= 0; index--) {
		answer[index] = std::max(answer[index], answer[index + 1]);
	}

	return answer;
}

*/

#if 0  //queue
truct indexMin{
    int winSize;
    long min;
};
vector<long> riddle(vector<long> arr) {
    arr.emplace_back(-1); // arr[i] >= 0
    int arrLen = arr.size();

    int n = arrLen - 1;
    vector<queue<indexMin>> qArr(n);

    for (int i = 0; i < n; i++) {
        auto& refQ = qArr[i];
        int qMin = arr[i];
        int winSize = 0;

        for (int j = i + 1; j < arrLen; j++) {
            winSize++;

            if (qMin > arr[j]) {
                refQ.push({ winSize, qMin });
                qMin = arr[j];
            }
        }

    }

    vector<long> answer(n);
    for (int w = 1; w <= n; w++) {
        long winMax = INT_MIN;

        for (int j = 0; j < n; j++) {
            auto& refQ = qArr[j];
            if (refQ.empty())
                break;

            winMax = std::max(winMax, refQ.front().min);
            //cout << winMax << ", " << refQ.front().winSize << endl;
            if (w == refQ.front().winSize)
                refQ.pop();
        }
        answer[w - 1] = winMax;
    }
  
    return answer;
}
#endif