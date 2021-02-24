#include <iostream>
#include <algorithm>
#include <time.h>
#include "vectorUtil.h"
#include "vectorUtil2.h"
#include "vectorUtil3.h"

bool CheckSortPrint(vector<int> &a_rVec)
{
    int nMax = a_rVec[0];
    for (int i = 1; i < a_rVec.size(); i++)
    {
        if (nMax > a_rVec[i])
        {
            cout << "sort false" << endl;
            return false;
        }
        nMax = a_rVec[i];
    }
    cout << "sort true" << endl;
    return true;
}

int main()
{
    time_t start;
    vector<int> oVec0, oVec1, oVec2, oVec3;
    cout << "start" << endl;
    for (int i = 0; i < 50000000; i++)
    {
        int nRand = rand();
        oVec0.push_back(nRand);
        oVec1.push_back(nRand);
        oVec2.push_back(nRand);
        oVec3.push_back(nRand);
    }
    start = time(NULL);
    std::sort(oVec0.begin(), oVec0.end(), std::less<int>());
    std::sort(oVec0.begin(), oVec0.end(), std::less<int>());
    cout << time(NULL) - start << endl;
    CheckSortPrint(oVec0);

    start = time(NULL);
    VectorUtil<int>::QSort(oVec1);
    VectorUtil<int>::QSort(oVec1);
    cout << time(NULL) - start << endl;
    CheckSortPrint(oVec1);

    start = time(NULL);
    VectorUtil2<int, Compare<int>>::QSort(oVec2);
    VectorUtil2<int, Compare<int>>::QSort(oVec2);
    cout << time(NULL) - start << endl;
    CheckSortPrint(oVec2);

    start = time(NULL);
    VectorSort<int>::Sort(oVec3);
    VectorSort<int>::Sort(oVec3);
    cout << time(NULL) - start << endl;
    CheckSortPrint(oVec3);

    return 0;
}