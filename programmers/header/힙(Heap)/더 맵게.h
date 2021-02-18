#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42626
//stl pq( =heap ), in-place sort ( small top = greater ), include <queue>
int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); //small top
    while (pq.top() < K) {
        auto s1 = pq.top();
        pq.pop();
        if (pq.empty())
            return -1;

        auto s2 = pq.top();
        pq.pop();

        pq.push(s1 + s2 * 2);
        answer++;
    }
    
    return answer;
}