#pragma once
#if 0
https://www.hackerrank.com/challenges/torque-and-development/copy-from/202673052?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
도중에 끊기는 부분 때문에 순회인 줄 알았는데,
탐색 변경 후 sort 이후 단 방향으로 처리한 부분이 문제가 되었음. => 반례. 1->3, 2->3 경우 2를 체크 시점에 lib 카운트가 증가해버린다.
탐색일 때는 무조건 양방향 확인을 합시다...
#endif

long long  roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    long  cityCount = n;
    if (c_lib <= c_road)
        return cityCount * c_lib;

    vector< unordered_set< int > > info(n + 1);  // not use first 0
    for (auto& city12 : cities) {
        //sort(city12.begin(), city12.end());
        info[city12[0]].insert(city12[1]);
        info[city12[1]].insert(city12[0]);
    }


    vector<bool> visit(n + 1);            //not use 0  
    stack<int> stk;

    long lib = 0;
    long buildRoad = 0;
    for (int i = 1; i <= n; i++) {
        if (visit[i])
            continue;

        lib++;
        visit[i] = true;
        stk.push(i);

        while (stk.empty() == false) {
            int top = stk.top();
            stk.pop();

            for (const auto& toCity : info[top]) {
                if (visit[toCity])
                    continue;

                visit[toCity] = true;
                stk.push(toCity);
                buildRoad++;
            }
        }
    }

    long  res = lib * c_lib;
    return res + buildRoad * c_road;
}