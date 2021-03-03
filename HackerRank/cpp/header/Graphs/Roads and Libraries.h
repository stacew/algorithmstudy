#pragma once
#if 0
https://www.hackerrank.com/challenges/torque-and-development/copy-from/202673052?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
���߿� ����� �κ� ������ ��ȸ�� �� �˾Ҵµ�,
Ž�� ���� �� sort ���� �� �������� ó���� �κ��� ������ �Ǿ���. => �ݷ�. 1->3, 2->3 ��� 2�� üũ ������ lib ī��Ʈ�� �����ع�����.
Ž���� ���� ������ ����� Ȯ���� �սô�...
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