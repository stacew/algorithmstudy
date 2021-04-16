#pragma once


using LL = long long;
void dfs(int count, LL sum, int from, unordered_map<int, unordered_map<int, int >>& gp, unordered_map <LL, int>& vcmap) {
	if (gp[from].size() == 0)
		return;
	
	for (auto tw : gp[from]) {
		auto toV = tw.first;
		LL weight = tw.second;
		if (vcmap.find(sum + weight) == vcmap.end() || vcmap[sum + weight] > count)
			vcmap[sum + weight] = count;

		dfs(count + 1, sum + weight, toV, gp, vcmap);
	}
}
void dfsFirstSet(int count, LL sum, int from, unordered_map<int, unordered_map<int, int >>& gp, unordered_map <LL, int>& vcmap, unordered_set <LL>& firstSet) {
	if (gp[from].size() == 0)
		return;

	for (auto tw : gp[from]) {
		auto toV = tw.first;
		LL weight = tw.second;
		if (vcmap[sum + weight] == count)
			firstSet.insert(sum + weight);

		dfs(count + 1, sum + weight, toV, gp, vcmap);
	}
}

void buildGraphAndSetMin(int n, vector<vector<int>>& roads, unordered_map <LL, int>& vcmap, unordered_set <LL>& firstSet) {
	unordered_map<int, unordered_map<int, int >> gp; // from, to, weight;
	for (const auto& road : roads)
		gp[road[0]][road[1]] = road[2];

	for (int i = 0; i < n; i++)
		dfs(2, 0, i, gp, vcmap);

	dfsFirstSet(2, 0, 0, gp, vcmap, firstSet);
}

LL getMinDistance(unordered_map <LL, int>& vcmap, LL q, bool start, unordered_set <LL>& firstSet) {
	if (q == 0)
		return 0;

	LL ret = -1;

	for ( const auto& vc : vcmap){
		LL value = vc.first;
		if (q < value)
			continue;
		
		LL min = getMinDistance(vcmap, q % value, false, firstSet);
		if (min == -1)
			continue;

		LL mul = q / value;
		int count = vc.second;
		LL newValue = mul * count + min;

		if (vcmap.find(q) == vcmap.end() || vcmap[q] > (int)newValue) //memo Ãß°¡
			vcmap[q] = (int)newValue;

		if (start && firstSet.find(value) != firstSet.end())
			newValue--;

		if (ret == -1 || ret > newValue)
			ret = newValue;
	}

	return ret;
}

vector<LL> solution(int n, int z, vector<vector<int>> roads, vector<LL> queries) {
	unordered_map <LL, int> vcmap;
	unordered_set <LL> firstSet;
	vcmap[z] = 1;

	buildGraphAndSetMin(n, roads, vcmap, firstSet);

	vector<LL> answer;
	for (const auto& q : queries)
		answer.emplace_back(getMinDistance(vcmap, q, true, firstSet));

	return answer;
}
