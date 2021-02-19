#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/49189
graph(unordered_map<int, unordered_set<int>>)
가장 멀리 있는 노드 카운트 bfs queue 
#endif

int solution(int n, vector<vector<int>> edge) {
    unordered_map<int, unordered_set<int>> graph;
    for (const auto& e : edge) {
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }

    vector<bool> checker(graph.size() + 1);
    queue<int> q;
    checker[1] = true;
    q.push(1);
    while (q.empty() == false) {
        int prevSize = q.size();
        bool bCheckNext = false;
        for (int i = 0; i < prevSize; i++) {
            int front = q.front();           
            q.pop();

            for (const auto& e : graph[front]) {
                if (checker[e])
                    continue;

                bCheckNext = true;
                checker[e] = true;
                q.push(e);
            }            
        }

        if (bCheckNext == false)
            return prevSize;
    }

    return -1;
}