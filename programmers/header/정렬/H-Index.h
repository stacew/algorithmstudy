#pragma once
//https://programmers.co.kr/learn/courses/30/lessons/42747

int solution(vector<int> citations) {
  
    sort(citations.begin(), citations.end());
  
    int lSum = accumulate(citations.begin(), citations.end(), 0);        
	for (int i = citations.size() - 1; i >= 0; i--) {
        lSum -= citations[i];

        int Hsize = citations.size() - i;
        int checkH = citations[i];
        if (lSum <= checkH && checkH <= Hsize ) {
            return checkH;
        }        
    }
  
    return 0;
}