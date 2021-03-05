#include "header/StlHeaders.h"
#include "header/Miscellaneous/Time Complexity Primality.h"

int main() {
	auto base = numeric_limits<long long>::max();
	//long long max prime 9223372036854775783 => sqrt 3037000499
	while (base) {
		if( checkPrime(--base) )
			break;
	}

	return 0;
}