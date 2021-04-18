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
