#include <iostream> 
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
static int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

#define MAX_N 1001 // MAX_N
#define MAX_VALUE 1e+8
int z_N, z_K;
int z_nInterval;
double z_arrCalcArea[MAX_N][MAX_N] = { 0, };
typedef pair< double, double > XY;
vector< XY > z_oBlackXY;
#define x first
#define y second
XY GetXY2Line(XY a1, XY a2, XY b1, XY b2)
{
    double under = (b2.y - b1.y) * (a2.x - a1.x) - (b2.x - b1.x) * (a2.y - a1.y);
    if (under == 0)
        return XY(-1, -1);

    double _t = (b2.x - b1.x) * (a1.y - b1.y) - (b2.y - b1.y) * (a1.x - b1.x);
    double _s = (a2.x - a1.x) * (a1.y - b1.y) - (a2.y - a1.y) * (a1.x - b1.x);

    double t = _t / under;
    double s = _s / under;
    if (t < 0.0 || t>1.0 || s < 0.0 || s>1.0)
        return XY(-1, -1);

    return XY(a1.x + t * (a2.x - a1.x), a1.y + t * (a2.y - a1.y));
}
double GetAreaVecXY(vector< XY >& a_refVec)
{
    double nRes = 0;
    int nVecSize = a_refVec.size();
    for (int i = 0; i < nVecSize - 1; i++)
    {
        nRes += a_refVec[i].x * a_refVec[i + 1].y;
        nRes -= a_refVec[i].y * a_refVec[i + 1].x;
    }
    if (nRes < 0)
        nRes = -nRes;

    return nRes / 2;
}
double CalcArea(int a_nRedPos1, int a_nRedPos2)
{
    int nRedIndex1 = a_nRedPos1 - 1;
    int nRedIndex2 = a_nRedPos2 - 1;
    int nCurrentIndex = nRedIndex1;
    vector< XY > oBlueXY;
    while (z_oBlackXY[nCurrentIndex].x != z_oBlackXY[nRedIndex2].x)
    {
        XY oBluePoint = GetXY2Line(z_oBlackXY[nRedIndex1], z_oBlackXY[nRedIndex2], z_oBlackXY[nCurrentIndex], z_oBlackXY[nCurrentIndex + 1]);
        if (oBluePoint.x != -1)
            oBlueXY.push_back(oBluePoint);

        nCurrentIndex++;
    }

    int nBlueSize = oBlueXY.size();
    if (nBlueSize == 0)
        return 0;

    nCurrentIndex = nRedIndex1;
    double nCalcArea = 0;
    for (int i = 0; i < nBlueSize - 1; i++)
    {
        vector< XY > oAreaVecXY;
        oAreaVecXY.push_back(oBlueXY[i]);

        if (oBlueXY[i].x == z_oBlackXY[nCurrentIndex].x)
            nCurrentIndex++;

        bool bRightBlueTurn = false;
        do {
            if (oBlueXY[i + 1].x <= z_oBlackXY[nCurrentIndex].x)
                bRightBlueTurn = true;
            else
                oAreaVecXY.push_back(z_oBlackXY[nCurrentIndex++]);
        } while (bRightBlueTurn == false);

        oAreaVecXY.push_back(oBlueXY[i + 1]);//끝
        oAreaVecXY.push_back(oBlueXY[i]);//시작점 한 번 더

        nCalcArea += GetAreaVecXY(oAreaVecXY);
    }

    return nCalcArea;
}

bool IsException()
{
    if (z_nInterval == 0)
    {
        cout << 0;
        return true;
    }
    else if (z_K == 0)
    {
        cout << CalcArea(1, z_N);
        return true;
    }

    return false;
}
void makeCalcArea()
{
    int nTempInterval = z_nInterval;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            z_arrCalcArea[i][j] = MAX_VALUE;

    for (int i = 0; i < MAX_N; i++)
        z_arrCalcArea[i][i] = 0;

    int nBlackLastPos = z_oBlackXY.size();
    do {
        int nLeftPos = 0;
        int nRightPos = 0;
        do
        {
            nLeftPos++;
            nRightPos = nLeftPos + nTempInterval + 1;

            z_arrCalcArea[nLeftPos][nRightPos] = CalcArea(nLeftPos, nRightPos);
        } while (nRightPos != nBlackLastPos);

        nTempInterval--;
    } while (nTempInterval >= 0);
}

/////////////////////////// Recursive ///////////////////////////
double Recursive(int a_nLeftPos, int a_nCurrentPos, int a_nPassingInterval, bool a_bBitPairRed)
{
    double nArea = 0;
    if (a_bBitPairRed == false)
    {
        a_nPassingInterval++;
        if (a_nPassingInterval > z_nInterval)
            return MAX_VALUE;
    }
    else
    {
        int nDiff = a_nCurrentPos - a_nLeftPos;
        nArea = z_arrCalcArea[a_nLeftPos][a_nCurrentPos];
        if (a_nPassingInterval == z_nInterval)
            return nArea;
        else if (a_nCurrentPos - a_nPassingInterval == z_N - z_nInterval + 1)
            return MAX_VALUE;

        a_nLeftPos = a_nCurrentPos;
    }

    if (a_nCurrentPos == z_N)//Pos 넘어가는 경우
        return MAX_VALUE;

    return nArea + min(Recursive(a_nLeftPos, a_nCurrentPos + 1, a_nPassingInterval, false), Recursive(a_nLeftPos, a_nCurrentPos + 1, a_nPassingInterval, true));
}
double Recursive_Process()
{
    return min(Recursive(1, 2, 0, false), Recursive(1, 2, 0, true));
}
/////////////////////////// Recursive ///////////////////////////

/////////////////////////// priority_queue ///////////////////////////
#include <queue>
class PQ_KeyValue {
public:
    PQ_KeyValue(double key, int a, int b, int c) : nCalcArea(key), nLeftPos(a), nRightPos(b), nPushLevel(c) {}
    double nCalcArea;
    int nLeftPos;
    int nRightPos;
    int nPushLevel;
    bool operator>(const PQ_KeyValue& b) const { return this->nCalcArea > b.nCalcArea; }
};
priority_queue< PQ_KeyValue, vector< PQ_KeyValue >, greater<PQ_KeyValue> > z_oPQ; //greater를 넣어야 최소힙이 됨.
void MapToPushPQ(int a_nLeftPos, double a_nArea, int a_nPushLevel)
{
    int nForLimit = z_nInterval + a_nLeftPos + 1;
    nForLimit = min(nForLimit, z_N);
    for (int nRightPos = a_nLeftPos + 1; nRightPos <= nForLimit; nRightPos++)
    {
        z_oPQ.push(PQ_KeyValue(z_arrCalcArea[a_nLeftPos][nRightPos] + a_nArea, a_nLeftPos, nRightPos, a_nPushLevel + 1));
    }
}
double PQ_Process()
{
    double nArea = MAX_VALUE;
    MapToPushPQ(1, 0, 0);
    while (z_oPQ.size())
    {
        PQ_KeyValue oKeyValue = z_oPQ.top();
        nArea = oKeyValue.nCalcArea;
        int nLeftPos = oKeyValue.nLeftPos;
        int nRightPos = oKeyValue.nRightPos;
        int nPushLevel = oKeyValue.nPushLevel;
        z_oPQ.pop();

        if (nPushLevel > z_K)
        {
            if (nRightPos != z_N)
                continue;

            break;
        }

        MapToPushPQ(nRightPos, nArea, nPushLevel);
    }
    return nArea;
}
/////////////////////////// priority_queue ///////////////////////////

/////////////////////////// Set_Process /////////////////////////// 
#include <set>
class SetKeyValue {
public:
    SetKeyValue(double a, int b, int c, int d) : nCalcArea(a), nLeftPos(b), nRightPos(c), nPushLevel(d) {}
    double nCalcArea;
    int nLeftPos;
    int nRightPos;
    int nPushLevel;
    bool operator<(const SetKeyValue& other) const {
        return nCalcArea < other.nCalcArea;
    }
};
set< SetKeyValue > z_oSet;

void MapToInsertSet(int a_nLeftPos, double a_nArea, int a_nPushLevel)
{
    int nForLimit = z_nInterval + a_nLeftPos + 1;
    nForLimit = min(nForLimit, z_N);
    for (int nRightPos = a_nLeftPos + 1; nRightPos <= nForLimit; nRightPos++)
        z_oSet.insert(SetKeyValue(z_arrCalcArea[a_nLeftPos][nRightPos] + a_nArea, a_nLeftPos, nRightPos, a_nPushLevel + 1));
}
double Set_Process()
{
    double nArea = MAX_VALUE;
    MapToInsertSet(1, 0, 0);
    while (z_oSet.size())
    {
        auto iterTop = z_oSet.begin();
        SetKeyValue oKeyValue = *iterTop;
        nArea = oKeyValue.nCalcArea;
        int nLeftPos = oKeyValue.nLeftPos;
        int nRightPos = oKeyValue.nRightPos;
        int nPushLevel = oKeyValue.nPushLevel;
        z_oSet.erase(iterTop);

        if (nPushLevel > z_K)
        {
            if (nRightPos != z_N)
                continue;

            break;
        }

        MapToInsertSet(nRightPos, nArea, nPushLevel);
    }

    return nArea;
}
/////////////////////////// Set_Process ///////////////////////////

/////////////////////////// Set_Process(Ignore Duple) /////////////////////////// priority_queue, Set과 다른 점은 Key 중복값 정의로 무시
class SetDupleKeyValue {
public:
    SetDupleKeyValue(double a, int b, int c, int d) : nCalcArea(a), nLeftPos(b), nRightPos(c), nPushLevel(d) {}
    double nCalcArea;
    int nLeftPos;
    int nRightPos;
    int nPushLevel;
    bool operator<(const SetDupleKeyValue& other) const {
        if (nCalcArea == other.nCalcArea && nPushLevel == other.nPushLevel && nPushLevel == other.nPushLevel)
            return false; //false를 보내버리면 (Debug모드 xutility _Debug_lt_pred에서 검사 안 하기 때문에 assert 없음) 중복 무시.
        else if (nCalcArea != other.nCalcArea)
            return nCalcArea < other.nCalcArea;     // < 계산 영역 낮은 것 상단에
        else if (nPushLevel != other.nPushLevel)
            return nPushLevel < other.nPushLevel; // > 푸시 레벨 높은 것 상단에
        else //if(nRightPos != other.nRightPos)
            return nRightPos > other.nRightPos;     // > Right Pos 높은 것 상단에
    }
};
set< SetDupleKeyValue > z_oDupleSet;

void MapToInsertDupleSet(int a_nLeftPos, double a_nArea, int a_nPushLevel)
{
    int nForLimit = z_nInterval + a_nLeftPos + 1;
    nForLimit = min(nForLimit, z_N);
    for (int nRightPos = a_nLeftPos + 1; nRightPos <= nForLimit; nRightPos++)
        z_oDupleSet.insert(SetDupleKeyValue(z_arrCalcArea[a_nLeftPos][nRightPos] + a_nArea, a_nLeftPos, nRightPos, a_nPushLevel + 1));
}
double Set_DupleProcess()
{

    double nArea = MAX_VALUE;
    MapToInsertDupleSet(1, 0, 0);
    while (z_oDupleSet.size())
    {
        auto iterTop = z_oDupleSet.begin();
        SetDupleKeyValue oKeyValue = *iterTop;
        nArea = oKeyValue.nCalcArea;
        int nLeftPos = oKeyValue.nLeftPos;
        int nRightPos = oKeyValue.nRightPos;
        int nPushLevel = oKeyValue.nPushLevel;
        z_oDupleSet.erase(iterTop);

        if (nPushLevel > z_K)
        {
            if (nRightPos != z_N)
                continue;

            break;
        }

        MapToInsertDupleSet(nRightPos, nArea, nPushLevel);
    }

    return nArea;
}
/////////////////////////// Set_Process(Ignore Duple) ///////////////////////////

/////////////////////////// DynamicProgrammingTopDown ///////////////////////////
double z_DP_TD[MAX_N][MAX_N] = { 0, };
double DP_TD(int a_n, int a_k)
{
    if (z_DP_TD[a_n][a_k] != -1)
        return z_DP_TD[a_n][a_k];

    if (a_k == 1)
        return z_DP_TD[a_n][1] = z_arrCalcArea[1][a_n];

    z_DP_TD[a_n][a_k] = MAX_VALUE;
    for (int aa = a_n - 1; aa > a_k - 1; aa--)
        z_DP_TD[a_n][a_k] = min(z_DP_TD[a_n][a_k], DP_TD(aa, a_k - 1) + z_arrCalcArea[aa][a_n]);

    return z_DP_TD[a_n][a_k];
}

double DP_TD_Process()
{
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            z_DP_TD[i][j] = -1;

    return DP_TD(z_N, z_K + 1);
}
/////////////////////////// DynamicProgrammingTopDown ///////////////////////////

/////////////////////////// DynamicProgrammingBottomUp ///////////////////////////
double z_DP_BU[MAX_N][MAX_N] = { 0, };
double DP_BU_Process()
{
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            z_DP_BU[i][j] = MAX_VALUE;

    int nInitPos = 2;
    for (; nInitPos <= z_N - z_K; nInitPos++)
        z_DP_BU[nInitPos][1] = z_arrCalcArea[1][nInitPos];

    for (int aa = nInitPos; aa <= z_N; aa++)
    {
        int nRightPos = aa - z_nInterval - 1;
        for (int bb = aa; bb > nRightPos; bb--)
        {
            z_DP_BU[bb][nRightPos] = MAX_VALUE;
            for (int cc = bb - 1; cc >= nRightPos; cc--)
                z_DP_BU[bb][nRightPos] = min(z_DP_BU[bb][nRightPos], z_DP_BU[cc][nRightPos - 1] + z_arrCalcArea[cc][bb]);
        }
    }

    return z_DP_BU[z_N][z_K + 1];//끝까지 가려면 꼭지점 +1 만큼 영역 계산 진행이 필요
}
/////////////////////////// DynamicProgrammingBottomUp ///////////////////////////

#include <time.h>
int main()
{
    cout.precision(20);
    cout << "Input N \"4 ~ " << MAX_N - 1 << "\" : ";
    cin >> z_N;
#if 1
    srand((unsigned int)time(NULL));
    if (z_N <= 3 || z_N >= MAX_N)
        return 0;
    z_K = z_N / 2;
    z_oBlackXY.reserve(z_N);
    for (int i = 0; i < z_N; i++)
        z_oBlackXY.push_back(XY(i * 10 + rand() % 10, rand() % 10000));
    cout << "- - - Random Input - - - " << endl;
    cout << z_N << " " << z_K << endl;
    for (auto XY : z_oBlackXY)
        cout << XY.first << " " << XY.second << " ";
    cout << endl << "- - - Random Input - - - " << endl;
#else
    cin >> z_K;
    z_oBlackXY.reserve(z_N);
    int input[2];
    for (int i = 0; i < z_N; i++)
    {
        cin >> input[0] >> input[1];
        z_oBlackXY.push_back(XY(input[0], input[1]));
    }
#endif
    cout << endl << "CalcAreaMap Start ~~~ ";
    z_nInterval = z_N - 2 - z_K;
    if (IsException())
        return 0;

    makeCalcArea();
    cout << "CalcAreaMap Complete" << endl << endl;
    double nArea = MAX_VALUE;
    clock_t start;
    if (z_N <= 30) { start = clock();   nArea = Recursive_Process();    cout.width(20); cout << "Recursive : " << nArea << " 시간 : " << clock() - start << endl; }
    if (z_N <= 35) { start = clock();   nArea = PQ_Process();           cout.width(20); cout << "Priority Queue : " << nArea << " 시간 : " << clock() - start << endl; }
    if (z_N <= 35) { start = clock();   nArea = Set_Process();          cout.width(20); cout << "Set() : " << nArea << " 시간 : " << clock() - start << endl; }
    if (z_N <= 35) { start = clock();   nArea = Set_DupleProcess();     cout.width(20); cout << "Set(Ignore Duple) : " << nArea << " 시간 : " << clock() - start << endl; 

    start = clock();                    nArea = DP_BU_Process();        cout.width(20); cout << "BottomUp DP : " << nArea << " 시간 : " << clock() - start << endl;
    start = clock();                    nArea = DP_TD_Process();        cout.width(20); cout << "TopDown DP : " << nArea << " 시간 : " << clock() - start << endl;

    return 0;
}


