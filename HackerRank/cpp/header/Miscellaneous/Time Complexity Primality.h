#pragma once
#if 0
https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
�Ҽ� ���� �� sqrt�� ���� root N�� ó���� ����..

#endif

//unordered_map<long long, bool> memo;
bool checkPrime(long long n) {
	if (n == 1)
		return false;

	//if (memo.find(n) != memo.end()) { return memo[n]; } //not sqrtN

	long long sqrtN = (long long)sqrt(n); // 2 is 1 -> 2 true
	for (long long i = 2; i <= sqrtN; i++) {
		if (n % i == 0) {
			//memo[n] = false;
			return false;
		}
	}

	//memo[n] = true;
	return true;
}

#if 0
int main() {
	auto base = numeric_limits<long long>::max();
	//long long max prime 9223372036854775783 => sqrt 3037000499
	while (base) {
		if (checkPrime(--base))
			break;
	}
	return 0;
}
#endif