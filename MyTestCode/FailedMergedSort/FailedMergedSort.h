#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int SIZE = 10;
void loopMergedSort();
std::vector<int> arr{ 7,7,6,8,8,9,9,4,4,3,4, };
std::vector<int> stdArr;
int main() {

	for (int i = 0; i < SIZE; i++)
		arr.push_back(i);
	stdArr = arr;


	loopMergedSort();
	std::stable_sort(stdArr.begin(), stdArr.end());

	bool bEE = true;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != stdArr[i]) {

			cout << "false" << endl;
			bEE = false;
			break;
		}
	}

	cout << "end" << endl;
}

//loopMergedSort
void loopMergedSort() {
	int count = 2;
	int EndOfArray = arr.size();
	while (count <= EndOfArray * 2) {
		int start = 0;
		int mid = count / 2;
		while (start < EndOfArray) {

#if 1
			//queue를 쓰면 O(n/2 + 1) 까지는 가능할 듯 ㅠ
#else
			int right = start + mid;
			//1. skip : already sorted.
			if (right >= EndOfArray || arr[right - 1] <= arr[right]) {
				start += count;
				continue;
			}

			//2 - 1. find pos : left [index] > [right]
			//It always exists under condition "1. skip"
			int index = start;
			while (index < right) {
				if (arr[index] > arr[right])
					break;
				index++;
			}

			//2 - 2. swap find pos, set left & this end, right inc
			std::swap(arr[index], arr[right]);
			index += 1;
			int left = right;
			right += 1;
			int EndOfThis = EndOfArray < (start + count) ? EndOfArray : (start + count);
			//if (index == EndOfThis - 1) {
				//start += count;
				//continue;
			//}


			//3. (arr[left] <= arr[right]) ? swap(arr[index], arr[left]) : swap(arr[index], arr[right])
			while (left < EndOfThis) {
				if (right == EndOfThis || arr[left] <= arr[right]) {
					swap(arr[index], arr[left]);
					index++;
				}
				else {
					swap(arr[index], arr[right]);
					index++;
				}

				if (right + 1 < EndOfThis && arr[right] > arr[right + 1])
					right++;
				if (left + 1 != right && arr[left] > arr[left + 1])
					left++;
			}


#endif
			start += count;
		}
		count *= 2;
	}
}