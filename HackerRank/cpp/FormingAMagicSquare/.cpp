int arr[8][9] = {
	{8, 1, 6, 3, 5, 7, 4, 9, 2},
	{6, 7, 2, 1, 5, 9, 8, 3, 4},
	{2, 9, 4, 7, 5, 3, 6, 1, 8},
	{4, 3, 8, 9, 5, 1, 2, 7, 6},
	{6, 1, 8, 7, 5, 3, 2, 9, 4},
	{2, 7, 6, 9, 5, 1, 4, 3, 8},
	{4, 9, 2, 3, 5, 7, 8, 1, 6},
	{8, 3, 4, 1, 5, 9, 6, 7, 2}};

int abs(int a)
{
	return a > 0 ? a : -a;
}
// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s)
{
	int nMin = 1000;

	for (int aa = 0; aa < 8; aa++)
	{
		int nSum = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				nSum += abs(arr[aa][i * 3 + j] - s[i][j]);
			}
		}
		if (nMin > nSum)
			nMin = nSum;
	}

	return nMin;
}