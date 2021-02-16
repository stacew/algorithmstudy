#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42748
//vector 생성자(이터레이터), sort
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const auto& command : commands) {
        int startIndex = command[0] - 1;
        int endIndex = command[1] - 1;
        int selectIndex = command[2] - 1;

        vector<int> temp(array.begin() + startIndex, array.begin() + endIndex + 1);
        sort(temp.begin(), temp.end());

        answer.push_back(temp[selectIndex]);
    }

    return answer;
}