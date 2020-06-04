#include <iostream>   
#include <algorithm>  
using namespace std;

int main()
{
	int nHeight = 0;
	cin >> nHeight;
	int** ppArr = (int**)malloc(sizeof(int*) * nHeight);
	for (int i = 0; i < nHeight; i++)
	{
		ppArr[i] = (int*)malloc(sizeof(int) * (i + 1));
		for (int j = 0; j <= i; j++)
			cin >> ppArr[i][j];
	}

	int* pArr = ppArr[0];
	int nRowIndex = 1;
	while (nRowIndex < nHeight)
	{
		int* pTemp = pArr;
		pArr = ppArr[nRowIndex];
		pArr[0] += pTemp[0];
		pArr[nRowIndex] += pTemp[nRowIndex - 1];

		for (int i = 1; i < nRowIndex; i++)
			pArr[i] += max(pTemp[i - 1], pTemp[i]);

		nRowIndex++;
	}

	int nMax = pArr[0];
	for (int i = 1; i < nHeight; i++)
		nMax = max(nMax, pArr[i]);

	cout << nMax;

	for (int i = 0; i < nHeight; i++)
		free(ppArr[i]);

	free(ppArr);
	return 0;
}