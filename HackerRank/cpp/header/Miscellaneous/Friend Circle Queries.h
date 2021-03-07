#pragma once
#if 0
https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
kruskal ����� �����ϰ� ���� ���� ��������,
�Լ��� umap �ڷᱸ�� �Ѱ��� ��, refrence�� ���� �ʾƼ�. �ð��ʰ��� �߻�.
ū �����͸� �Ѱ��ִ� ������ ���� ȣ���ϸ� ���ϰ� �������Ƿ� Ȯ���� ��.
#endif
using parentAndCount = pair<int, int>;
#if 0 
int getParent(unordered_map<int, parentAndCount>& umap, int cur) {
    if (umap[cur].first == cur)
        return umap[cur].first;

    umap[cur].first = getParent(umap, umap[cur].first); //���� = find ����ȭ
    return umap[cur].first;
}
#else
int getParent(unordered_map<int, parentAndCount>& umap, int cur) {
    int parent = cur;
    while (umap[parent].first != parent) {
        parent = umap[parent].first;
    }

    //find ����ȭ
    while (cur != parent) {
        int curTemp = cur;
        cur = umap[cur].first;
        umap[curTemp].first = parent;
    }
    return parent;
}
#endif

vector<int> maxCircle(vector<vector<int>> queries) {

    unordered_map<int, parentAndCount> umap;
    for (auto q : queries) {
        umap[q[0]] = make_pair(q[0], 1);
        umap[q[1]] = make_pair(q[1], 1);
    }

    vector<int> ret;
    int maxFriend = 1;
    for (auto q : queries) {
        int p1 = getParent(umap, q[0]);
        int p2 = getParent(umap, q[1]);
        if (p1 == p2) { //�θ� ������ continue
            ret.emplace_back(maxFriend);
            continue;
        }

        int newFriendCnt = umap[p1].second + umap[p2].second;
        if (umap[p1].second > umap[p2].second) { //���� ���� �θ� ( union ����ȭ )
            umap[p1].first = umap[p2].first; //�ڽĿ��� �θ� ���                   
            umap[p2].second = newFriendCnt; //�θ��� �ڽ� ���� ��            
        }
        else {
            umap[p2].first = umap[p1].first;
            umap[p1].second = newFriendCnt;
        }

        maxFriend = std::max(maxFriend, newFriendCnt);
        ret.emplace_back(maxFriend);
    }
    return ret;
}
