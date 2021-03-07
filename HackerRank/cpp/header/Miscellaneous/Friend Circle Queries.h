#pragma once
#if 0
https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
kruskal 방식을 생각하고 만든 것은 괜찮은데,
함수에 umap 자료구조 넘겨줄 때, refrence를 적지 않아서. 시간초과가 발생.
큰 데이터를 넘겨주는 곳에서 많이 호출하면 심하게 느려지므로 확인할 것.
#endif
using parentAndCount = pair<int, int>;
#if 0 
int getParent(unordered_map<int, parentAndCount>& umap, int cur) {
    if (umap[cur].first == cur)
        return umap[cur].first;

    umap[cur].first = getParent(umap, umap[cur].first); //대입 = find 최적화
    return umap[cur].first;
}
#else
int getParent(unordered_map<int, parentAndCount>& umap, int cur) {
    int parent = cur;
    while (umap[parent].first != parent) {
        parent = umap[parent].first;
    }

    //find 최적화
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
        if (p1 == p2) { //부모가 같으면 continue
            ret.emplace_back(maxFriend);
            continue;
        }

        int newFriendCnt = umap[p1].second + umap[p2].second;
        if (umap[p1].second > umap[p2].second) { //작은 쪽이 부모 ( union 최적화 )
            umap[p1].first = umap[p2].first; //자식에게 부모를 기록                   
            umap[p2].second = newFriendCnt; //부모의 자식 개수 합            
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
