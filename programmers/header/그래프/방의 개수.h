#pragma once
#if 0
https://programmers.co.kr/learn/courses/30/lessons/43236
해시 특수화 할 때, 대충 만들면 느려질 수 있으니 주의
equl이나 hash operator 재구현시 파라미터 끝에, const 붙여주기.
uset<key> 대신 umap<key, bool>을 사용하면 너무 편하게 작성이 가능하다.(메모리는 추가로 사용하니 연습에서만..)

#endif
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

#if 1
#define x first
#define y second
using po = pair<int, int>;
using edge = pair< po, po >;
template<>
struct hash<po> { size_t operator()(const po& e) const { return (e.x << 20) + e.y; } };
template<>
struct hash<edge> { size_t operator()(const edge& e) const { return (e.x.x << 20) + (e.x.y << 15) + e.y.x + e.y.y; } };

int solution(vector<int> arrows) {
	int answer = 0;
	unordered_map<po, bool> vp; //visited Point
	unordered_map<edge, bool> ve; //visited Edge		

	auto checkSlash = [&](const int& a, const po& bp) {
		if (a % 2 == 1) {//대각선 check
			//dx만 사용, dy만 사용하면 대각선이 가능
			if (ve.find({ { bp.x + dx[a], bp.y}, { bp.x, bp.y + dy[a]} }) != ve.end()) { //3. 교차하는 대각선이 존재한다면
				answer++;
			}
		}
	};

	po bp{ 0,0 }; //base Point
	vp[bp] = true;;
	for (const auto& a : arrows) {
		po np{ bp.x + dx[a], bp.y + dy[a] }; //next Point
		edge ne{ bp, np }; //next Edge
		if (vp[np]) { //1. 방문했던 점을 방문했을 때,
			if (ve[ne] == false) {//2. 새로운 선이라면 
				answer++;
				checkSlash(a, bp);
			}
		}
		else {
			checkSlash(a, bp);
		}
		vp[np] = true;

		//대각선 두 점 다 삽입 방법!!!
		ve[ne] = true;
		ve[{np, bp}] = true;
		bp = np;
	}

	return answer;
}
#endif


#if 0
// 여긴 구조체 생성 시, 정렬을 해서 대각선을 하나로 압축.
struct po {
	int x; int y;
	bool operator==(const po& r) const { return this->x == r.x && this->y == r.y; }
};
template<>
struct hash<po> { size_t operator()(const po& p) const { return (p.x << 5) + p.y; } };

struct edge {
	po p1;	po p2;
	edge(po _1, po _2) {
		if ((_1.x == _2.x && _1.y < _2.y) || _1.x < _2.x) { p1 = _1; p2 = _2; }
		else { p1 = _2; p2 = _1; }
	}
	bool operator==(const edge& r) const { return this->p1 == r.p1 && this->p2 == r.p2; }
};
template<>
struct hash<edge> { size_t operator()(const edge& e) const { return (e.p1.x << 15) + (e.p1.y << 12) + (e.p2.x << 9) + e.p2.y; } };

int solution(vector<int> arrows) {
	int answer = 0;
	unordered_set<po> vp; //visited Point
	unordered_set<edge> ve; //visited Edge		

	auto checkSlash = [&](const int& a, const po& bp) {
		if (a % 2 == 1) {//대각선 check
			if (ve.find({ { bp.x + dx[a], bp.y}, { bp.x, bp.y + dy[a]} }) != ve.end()) { //3. 교차하는 대각선이 존재한다면
				answer++;
			}
		}
	};

	po bp{ 0,0 }; //base Point
	vp.insert(bp);
	for (const auto& a : arrows) {
		po np{ bp.x + dx[a], bp.y + dy[a] }; //next Point
		edge ne{ bp, np }; //next Edge
		if (vp.find(np) != vp.end()) { //1. 방문했던 점을 방문했을 때,
			if (ve.find(ne) == ve.end()) {//2. 새로운 선이라면 
				answer++;
				checkSlash(a, bp);
			}
		}
		else {
			checkSlash(a, bp);
		}
		vp.insert(np);
		ve.insert(ne);
		bp = np;
	}

	return answer;
}
#endif

#if 0
int main()
{
	cout << solution({ 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 }); //3
}
#endif