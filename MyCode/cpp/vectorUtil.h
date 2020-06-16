#include <vector>
using namespace std;

template <typename type>
class VectorUtil
{
public:
    static void QSortCustom(vector<type> &a_rArray, int (*sCmpFunc)(type t1, type t2))
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, sCmpFunc);
    }
    static void QSortBase(vector<type> &a_rArray)
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, baseTypeCompare);
    }
    static void QSortRef(vector<type> &a_rArray)
    {
        qsortAscendFunc(a_rArray, 0, a_rArray.size() - 1, baseRefTypeCompare);
    }

private:
    static int baseTypeCompare(type t1, type t2)
    {
        return t1 == t2 ? 0 : (t1 > t2 ? 1 : -1);
    }
    static int baseRefTypeCompare(type t1, type t2)
    {
        return *t1 == *t2 ? 0 : (*t1 > *t2 ? 1 : -1);
    }
    static void swap(vector<type> &a_rArray, int a_nLeft, int a_nRight)
    {
        type temp = a_rArray[a_nLeft];
        a_rArray[a_nLeft] = a_rArray[a_nRight];
        a_rArray[a_nRight] = temp;
    }
    static void qsortAscendFunc(vector<type> &a_rArray, int a_nStartIndex, int a_nEndIndex, int (*sCmpFunc)(type t1, type t2))
    {
        if (a_nStartIndex >= a_nEndIndex)
            return;

        int nMidIndex = (a_nStartIndex + a_nEndIndex) / 2;

        type tStart = a_rArray[a_nStartIndex];
        type tMidPivot = a_rArray[nMidIndex];
        type tEnd = a_rArray[a_nEndIndex];
        if (sCmpFunc(tStart, tMidPivot) > 0)
        {
            swap(a_rArray, a_nStartIndex, nMidIndex);
            type tTemp = tStart;
            tStart = tMidPivot;
            tMidPivot = tTemp;
        }
        if (sCmpFunc(tMidPivot, tEnd) > 0)
        {
            swap(a_rArray, nMidIndex, a_nEndIndex);
            tMidPivot = tEnd;
            if (sCmpFunc(tStart, tMidPivot) > 0)
            {
                swap(a_rArray, a_nStartIndex, nMidIndex);
                tMidPivot = tStart;
            }
        }

        if (a_nEndIndex - a_nStartIndex < 3)
            return;

        swap(a_rArray, nMidIndex, a_nEndIndex - 1);
        int nLeftIndex = a_nStartIndex;
        int nRightIndex = a_nEndIndex - 1;
        while (true)
        {
            do
            {
                ++nLeftIndex;
            } while (nLeftIndex < a_nEndIndex && sCmpFunc(a_rArray[nLeftIndex], tMidPivot) < 0);

            do
            {
                --nRightIndex;
            } while (a_nStartIndex < nRightIndex && sCmpFunc(tMidPivot, a_rArray[nRightIndex]) < 0);

            if (nLeftIndex >= nRightIndex)
                break;

            swap(a_rArray, nLeftIndex, nRightIndex);
        }
        swap(a_rArray, nLeftIndex, a_nEndIndex - 1);

        qsortAscendFunc(a_rArray, a_nStartIndex, nLeftIndex - 1, sCmpFunc);
        qsortAscendFunc(a_rArray, nLeftIndex + 1, a_nEndIndex, sCmpFunc);
    }
};