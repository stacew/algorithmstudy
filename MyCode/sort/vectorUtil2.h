#include <vector>
#include <algorithm>
using namespace std;

template <typename Type>
struct Compare
{
    char operator()(Type &t1, Type &t2)
    {
        return t1 > t2 ? 1 : (t1 == t2 ? 0 : -1);
    }
};

template <typename Pointer>
struct ComparePointer
{
    char operator()(Pointer &t1, Pointer &t2)
    {
        return *t1 > *t2 ? 1 : (*t1 == *t2 ? 0 : -1);
    }
};

template <typename vectorType, class compareClass>
class VectorUtil2
{
public:
    static void QSort(vector<vectorType> &a_rArray)
    {
        qsortAscend(a_rArray, 0, a_rArray.size() - 1);
    }

private:
    static void swap(vector<vectorType> &a_rArray, int &a_nLeft, int &a_nRight)
    {
        vectorType temp = a_rArray[a_nLeft];
        a_rArray[a_nLeft] = a_rArray[a_nRight];
        a_rArray[a_nRight] = temp;
    }
    static void qsortAscend(vector<vectorType> &a_rArray, int a_nStartIndex, int a_nEndIndex)
    {
        if (a_nStartIndex >= a_nEndIndex)
            return;

        int nMidIndex = (a_nStartIndex + a_nEndIndex) / 2;
        if (compareClass()(a_rArray[a_nStartIndex], a_rArray[nMidIndex]) > 0)
            swap(a_rArray, a_nStartIndex, nMidIndex);
        if (compareClass()(a_rArray[nMidIndex], a_rArray[a_nEndIndex]) > 0)
        {
            swap(a_rArray, nMidIndex, a_nEndIndex);
            if (compareClass()(a_rArray[a_nStartIndex], a_rArray[nMidIndex]) > 0)
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
            } while (nLeftIndex < a_nEndIndex && compareClass()(a_rArray[nLeftIndex], a_rArray[nPivotIndex]) < 0);

            do
            {
                --nRightIndex;
            } while (a_nStartIndex < nRightIndex && compareClass()(a_rArray[nPivotIndex], a_rArray[nRightIndex]) < 0);

            if (nLeftIndex >= nRightIndex)
                break;

            swap(a_rArray, nLeftIndex, nRightIndex);
        }
        swap(a_rArray, nLeftIndex, nPivotIndex);

        qsortAscend(a_rArray, a_nStartIndex, nLeftIndex - 1);
        qsortAscend(a_rArray, nLeftIndex + 1, a_nEndIndex);
    }
};