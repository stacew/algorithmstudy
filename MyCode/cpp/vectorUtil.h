#include <vector>
using namespace std;

template <typename vectorType, typename paramType = vectorType>
class VectorUtil
{
public:
    static void QSortCustom(vector<vectorType> &a_rArray, char (*sCmpFunc)(paramType &t1, paramType &t2))
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, sCmpFunc);
    }
    static void QSort(vector<vectorType> &a_rArray)
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, compare);
    }
    static void QSortPointer(vector<vectorType> &a_rArray)
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, comparePointer);
    }

private:
    static char compare(paramType &t1, paramType &t2)
    {
        return t1 > t2 ? 1 : (t1 == t2 ? 0 : -1);
    }
    static char comparePointer(paramType &t1, paramType &t2)
    {
        return *t1 > *t2 ? 1 : (*t1 == *t2 ? 0 : -1);
    }
    static void swap(vector<vectorType> &a_rArray, int &a_nLeft, int &a_nRight)
    {
        vectorType temp = a_rArray[a_nLeft];
        a_rArray[a_nLeft] = a_rArray[a_nRight];
        a_rArray[a_nRight] = temp;
    }
    static void qsortAscendFunc(vector<vectorType> &a_rArray, int a_nStartIndex, int a_nEndIndex, char (*sCmpFunc)(paramType &t1, paramType &t2))
    {
        if (a_nStartIndex >= a_nEndIndex)
            return;

        int nMidIndex = (a_nStartIndex + a_nEndIndex) / 2;
        if (sCmpFunc(a_rArray[a_nStartIndex], a_rArray[nMidIndex]) > 0)
            swap(a_rArray, a_nStartIndex, nMidIndex);
        if (sCmpFunc(a_rArray[nMidIndex], a_rArray[a_nEndIndex]) > 0)
        {
            swap(a_rArray, nMidIndex, a_nEndIndex);
            if (sCmpFunc(a_rArray[a_nStartIndex], a_rArray[nMidIndex]) > 0)
                swap(a_rArray, a_nStartIndex, nMidIndex);
        }
        if (a_nEndIndex - a_nStartIndex < 3)
            return;

        int nPivotIndex = a_nEndIndex - 1;
        swap(a_rArray, nMidIndex, nPivotIndex);
        int nLeftIndex = a_nStartIndex;
        int nRightIndex = nPivotIndex;
        while (true)
        {
            do
            {
                ++nLeftIndex;
            } while (nLeftIndex < a_nEndIndex && sCmpFunc(a_rArray[nLeftIndex], a_rArray[nPivotIndex]) < 0);

            do
            {
                --nRightIndex;
            } while (a_nStartIndex < nRightIndex && sCmpFunc(a_rArray[nPivotIndex], a_rArray[nRightIndex]) < 0);

            if (nLeftIndex >= nRightIndex)
                break;

            swap(a_rArray, nLeftIndex, nRightIndex);
        }
        swap(a_rArray, nLeftIndex, nPivotIndex);

        qsortAscendFunc(a_rArray, a_nStartIndex, nLeftIndex - 1, sCmpFunc);
        qsortAscendFunc(a_rArray, nLeftIndex + 1, a_nEndIndex, sCmpFunc);
    }
};