#include "header/StlHeaders.h"

//#include "header/해시/완주하지 못한 선수.h"
//#include "header/해시/전화번호 목록.h"
#include "header/정렬/가장 큰 수.h"

int main()
{
	vector<string> vs1 = { "leo", "kiki", "eden" };
	vector<string> vs2 = { "eden", "kiki" };
	vector<string> vs3 = { "12","999","99","123","1234","12345" };
	vector<string> vs4 = { "1234","99"};
	vector<string> vs5 = {};
	vector<int> vi1 = { 1, 5, 2, 6, 3, 7, 4, 10, 23, 12 };
	vector<vector<int>> vvi1 = { {2, 5, 3}, { 4, 4, 1 }, { 1, 7, 3 } };

	cout << solution(vi1) << endl;

#if 0	
	vector<int> res = solution(vi1, vvi1);
	for (const auto& n : res)
		cout << n << endl;
#endif

	cout << endl << endl;
}