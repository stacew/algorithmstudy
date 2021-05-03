#pragma once
// dp로 가야 됨.


int inPlaceGold;
using LL = long long;
unordered_map<int, unordered_map<int, LL>> gp;  //from, to, gold
unordered_map<LL, vector<pair< int, int >> > goldTo;//gold, to
void buildInfo(int n, vector<vector<int>>& roads, int z) {
	inPlaceGold = z;

	//build graph & goldTo
	gp.clear();
	goldTo.clear();
	for (const auto& road : roads) {
		auto from = road[0];
		auto to = road[1];
		auto gold = road[2];
		gp[from][to] = gold;

		goldTo[gold].push_back(make_pair(from, to));
	}
}

LL getMinTurn(LL needGold, int from) {
	if (needGold == 0)
		return 0;

	LL minTurn = -1;

	// 1
	if (needGold >= inPlaceGold) {
		minTurn = getMinTurn(needGold - inPlaceGold, from);
	}
	if (minTurn != -1)
		return minTurn + 1;

	// 2
	LL minTurn1 = -1;
	for (const auto& ng : gp[from]) {
		auto to = ng.first;
		auto gold = ng.second;
		if (needGold < gold)
			continue;

		LL getSubMin = getMinTurn(needGold - gold, to);
		if (getSubMin == -1)
			continue;

		if (minTurn1 == -1 || minTurn1 > getSubMin)
			minTurn1 = getSubMin;
	}
	if (minTurn1 != -1)
		minTurn1 += 1;

	// 3
	for (const auto& gt : goldTo) {
		auto gold = gt.first;
		if (needGold < gold)
			continue;

		auto ftVec = gt.second;
		int checkFrom;
		for (const auto& ft : ftVec) {
			LL getSubMin = getMinTurn(needGold - gold, ft.second);
			if (getSubMin == -1)
				continue;

			if (minTurn == -1 || minTurn > getSubMin) {
				minTurn = getSubMin;
				checkFrom = ft.first;
			}

		}
		if (minTurn != -1) {
			minTurn += ((checkFrom == from) ? 1 : 2);
			break;
		}
	}

	if (minTurn1 > -1 && minTurn > -1)
	{
		if (minTurn1 < minTurn)
			return minTurn1;
		return minTurn;
	}
	if (minTurn1 > -1)
		return minTurn1;
	if (minTurn > -1)
		return minTurn;
	return -1;
}

vector<LL> solution(int n, int z, vector<vector<int>> roads, vector<LL> goldQuery100000s) {

	buildInfo(n, roads, z);

	vector<LL> answer;
	for (auto& gold : goldQuery100000s) {
		cout << gold << " : ";
		LL mul = 0;
		if (gold >= inPlaceGold * 2) {
			mul = gold / inPlaceGold - 1;//1,2,3,4,5 test
			gold -= mul * inPlaceGold;
		}
		LL min = getMinTurn(gold, 0);
		answer.emplace_back(min + mul);
		cout << min + mul << endl;
	}
	return answer;
}


#if 0 
#pragma once

using LL = long long;
unordered_map<LL, unordered_map<LL, LL>> gp;  //from, to, gold
unordered_set <LL> visited;
unordered_map <LL, LL> goldTurnMap;
unordered_set <LL> firstLine;
vector< pair < LL, LL > > goldTurnVec;

void buildGoldTurnMap(LL turn, LL goldSum, LL from) {
	if (gp.find(from) == gp.end() || gp[from].size() == 0)
		return;
	if (visited.find(from) != visited.end())
		return;
	visited.insert(from);

	for (const auto& nextAndGold : gp[from]) {
		LL gold = nextAndGold.second;
		if (goldTurnMap.find(goldSum + gold) == goldTurnMap.end() || goldTurnMap[goldSum + gold] > turn)
			goldTurnMap[goldSum + gold] = turn;

		buildGoldTurnMap(turn + 1, goldSum + gold, nextAndGold.first);
	}
}
void buildFirstLine(LL turn, LL goldSum, LL from) {
	if (gp.find(from) == gp.end() || gp[from].size() == 0)
		return;

	if (visited.find(from) != visited.end())
		return;
	visited.insert(from);

	for (const auto& nextAndGold : gp[from]) {
		LL gold = nextAndGold.second;
		if (goldTurnMap[goldSum + gold] == turn)
			firstLine.insert(goldSum + gold);

		buildFirstLine(turn + 1, goldSum + gold, nextAndGold.first);
	}
}

void buildInfo(int n, vector<vector<int>>& roads, int inPlaceGold) {
	//build graph
	gp.clear();
	for (const auto& road : roads)
		gp[road[0]][road[1]] = road[2];

	//build goldTurnMap;
	goldTurnMap.clear();
	goldTurnMap[inPlaceGold] = 1;
	for (int i = 0; i < n; i++) {
		visited.clear();
		buildGoldTurnMap(2, 0, i);
	}

	//build FirstLine
	firstLine.clear();
	visited.clear();
	buildFirstLine(2, 0, 0);

	//build goldTurnVec
	goldTurnVec.clear();
	for (const auto& gt : goldTurnMap)
		goldTurnVec.emplace_back(make_pair(gt.first, gt.second));

	sort(goldTurnVec.begin(), goldTurnVec.end(), [](const auto& gt1, const auto& gt2) {
		return ((double)gt1.second / gt1.first) < ((double)gt2.second / gt2.first);
		});
}

LL getMinTurn(LL needGold, bool zeroFirst) {
	if (needGold == 0)
		return 0;

	LL retTurn = -1;
	for (const auto& gt : goldTurnVec) {
		LL gold = gt.first;
		LL turn = gt.second;
		if (needGold < gold)
			continue;

		LL minTurn = getMinTurn(needGold % gold, turn == 1 ? true : false);
		if (minTurn == -1)
			continue;

		LL mul = needGold / gold;

		LL newTurn = mul * turn + minTurn;

		if (zeroFirst && firstLine.find(gold) != firstLine.end()) //firstLine
			newTurn--;

		if (retTurn == -1 || retTurn > newTurn) {
			retTurn = newTurn;
		}
	}

	return retTurn;
}

vector<LL> solution(int n, int z, vector<vector<int>> roads, vector<LL> goldQuery100000s) {
	vector<LL> answer;

	buildInfo(n, roads, z);

	for (const auto& gold : goldQuery100000s) {
		cout << gold << " : ";
		LL min = getMinTurn(gold, true);
		answer.emplace_back(min);
		cout << min << endl;
	}

	return answer;
}

#endif