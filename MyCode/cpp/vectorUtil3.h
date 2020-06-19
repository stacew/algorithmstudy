#include <vector>
#include <algorithm>
using namespace std;

template <typename BasicType>
struct BasicLess
{
    bool operator()(const BasicType &t1, const BasicType &t2) const { return t1 < t2; }
};
template <typename BasicType>
struct BasicGreater
{
    bool operator()(const BasicType &t1, const BasicType &t2) const { return t1 > t2; }
};
template <typename BasicPointerType>
struct BasicPointerLess
{
    bool operator()(const BasicPointerType &t1, const BasicPointerType &t2) const { return *t1 < *t2; }
};
template <typename BasicPointerType>
struct BasicPointerGreater
{
    bool operator()(const BasicPointerType &t1, const BasicPointerType &t2) const { return *t1 > *t2; }
};
template <typename Type, class Comp = BasicLess<Type>>
class VectorSort
{
public:
    static void Sort(vector<Type> &a_rArray)
    {
        std::sort(a_rArray.begin(), a_rArray.end(), Comp());
    }
};
template <typename Type, class Comp = BasicPointerLess<Type>>
class VectorSortPointer
{
public:
    static void Sort(vector<Type> &a_rArray)
    {
        std::sort(a_rArray.begin(), a_rArray.end(), Comp());
    }
};