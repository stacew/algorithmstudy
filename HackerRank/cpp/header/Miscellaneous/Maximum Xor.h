#pragma once
#if 0
https://www.hackerrank.com/challenges/maximum-xor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
trie 구조 만들고, 반복 이용하기

#endif
#define STD_COMPILE 0 //해커랭크 컴파일 에러로 수정
#if STD_COMPILE
struct trie {
	unordered_map<bool, trie*> child;
};
void makrTrie(trie& root, int a) {
	trie* cur = &root;
	unsigned int bit = 0x80000000; //unsigned is to put 0 when a right shift.
	while (bit != 0) {
		int aBit = a & (int)bit;
		cur->child.insert(std::make_pair(aBit ? 1 : 0, new trie()));
		cur = cur->child[aBit ? 1 : 0];
		bit >>= 1;
	}
}
int searchMax(trie& root, int q) {
	int retMax = 0;
	trie* cur = &root;
	unsigned int bit = 0x80000000;
	while (bit != 0) {
		int qBit = q & (int)bit;
		qBit = qBit ? 1 : 0;
		auto maxiter = cur->child.find(qBit ? 0 : 1);
		if (maxiter != cur->child.end()) {
			retMax |= bit;
			cur = maxiter->second;
		}
		else if (cur->child.find(qBit ? 1 : 0) != cur->child.end()) {
			cur = cur->child.find(qBit ? 1 : 0)->second;
		}

		bit >>= 1;
	}
	return retMax;
}
#else
struct trie {
	unordered_map<bool, trie> child;
};
void makrTrie(trie& root, int a) {
	trie* cur = &root;
	unsigned int bit = 0x80000000; //unsigned is to put 0 when a right shift.
	while (bit != 0) {
		int aBit = a & (int)bit;
		cur = &cur->child[aBit ? 1 : 0]; // make & next
		bit >>= 1;
	}
}
int searchMax(trie& root, int q) {
	int retMax = 0;
	trie* cur = &root;
	unsigned int bit = 0x80000000;
	while (bit != 0) {
		int qBit = q & (int)bit;
		qBit = qBit ? 1 : 0;
		auto maxiter = cur->child.find(qBit ? 0 : 1);
		if (maxiter != cur->child.end()) {
			retMax |= bit;
			cur = &maxiter->second;
		}
		else if (cur->child.find(qBit ? 1 : 0) != cur->child.end()) {
			cur = &cur->child.find(qBit ? 1 : 0)->second;
		}

		bit >>= 1;
	}
	return retMax;
}
#endif

vector<int> maxXor(vector<int> arr, vector<int> queries) {
	vector<int> ret;
	trie root;
	for (const auto& a : arr)
		makrTrie(root, a);

	for (const auto& q : queries)
		ret.emplace_back(searchMax(root, q));

	return ret;
}