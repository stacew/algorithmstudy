#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42577
//1. custom hasher, equal
//2. sort, string compare(== substr)

struct myHasher {
	size_t operator()(const string& s) const {
		//constexpr size_t MAX_USE_HASH_COUNT = 1;//각 전화번호의 길이는 1 이상
		//hash<string> hasher;
		//size_t h = hasher(s.substr(0, MAX_USE_HASH_COUNT));
		//return h;

		return s[0];
	}
};

struct myEqual {
	bool operator()(const string& _Left, const string& _Right) const {
		auto lSize = _Left.length();
		auto rSize = _Right.length();

		lSize = min(lSize, rSize);
		for (size_t i = 0; i < lSize; i++) {
			if (_Left[i] != _Right[i])
				return false;
		}
		return true;
	}
};
bool solution(vector<string> phone_book) {
	unordered_set<string, myHasher, myEqual> usBook;
	for (const auto& phNumber : phone_book) {
		if (usBook.find(phNumber) != usBook.end())
			return false;

		usBook.insert(phNumber);
	}

	return true;
}

bool solution_sort(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	for (size_t i = 1; i < phone_book.size(); i++) {
		if (phone_book[i].compare(0, phone_book[i - 1].length(), phone_book[i - 1]) == 0) //left가 긴 경우도 있는데 됨.( ex) "1234", "99" )
			return false;
		//if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].size()))
		//	return false;
	}

	return true;
}
