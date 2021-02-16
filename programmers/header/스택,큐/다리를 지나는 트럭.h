#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42583

//queue
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int cur_time = 0;
	queue < pair< int, int > > qBridge; //time, weight
	int weightOnBridge = 0;
	int tw_pos1 = 0;
	while (tw_pos1 != truck_weights.size() || qBridge.empty() == false) {
		cur_time++;

		//1. pop : check time
		if (qBridge.empty() == false && qBridge.front().first + bridge_length <= cur_time) {
			weightOnBridge -= qBridge.front().second;
			qBridge.pop();
		}

		//2. push : check weightOnBridge
		if (tw_pos1 < truck_weights.size() && (weightOnBridge + truck_weights[tw_pos1] <= weight)) {
			weightOnBridge += truck_weights[tw_pos1];
			qBridge.push(pair<int, int>(cur_time, truck_weights[tw_pos1++])); // ++
		}	
	}
	return cur_time;
}

//vector pos
int solution_vectorPos(int bridge_length, int weight, vector<int> truck_weights) {
	int cur_time = 0;

	vector<int> truck_time;
	truck_time.reserve(truck_weights.size());

	int weightOnBridge = 0;
	int tw_pos1 = 0;
	int tw_pos2 = 0;
	int tt_pos = 0;
	while (tw_pos1 != truck_weights.size() || weightOnBridge > 0) {

		cur_time++;

		//1. get out
		if (tt_pos < truck_time.size() && truck_time[tt_pos] + bridge_length <= cur_time) {
			weightOnBridge -= truck_weights[tw_pos2++]; // ++
			tt_pos++;
		}

		//2. enter
		if (tw_pos1 < truck_weights.size() && (weightOnBridge + truck_weights[tw_pos1] <= weight)) {
			weightOnBridge += truck_weights[tw_pos1++]; // ++
			truck_time.push_back(cur_time);
		}			
	}

	return cur_time;
}