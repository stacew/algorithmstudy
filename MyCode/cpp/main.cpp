#include <iostream>
#include "vectorUtil.h"

int main()
{
    vector<int> oVec = {1, 213, 13, 13, 1, 31, 31, 42, 3423, 42, 34, 24, 32, 4, 13, 12, 3, 435, 456, 57, 6, 879, 7, 78979};
    VectorUtil<int>::QSortBase(oVec);
    for (int i = 0; i < oVec.size(); i++)
    {
        cout << oVec[i] << " ";
    }
}