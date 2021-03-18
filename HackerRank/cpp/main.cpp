#include "header/StlHeaders.h"
#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    string name;
    int score;
};

class Checker {
public:
    // complete this method
    static int comparator(Player a, Player b) {
        if (a.score == b.score)
            return a.name < b.name ? 1 : -1;

        return a.score > b.score ? 1 : -1;
    }
};


bool compare(Player a, Player b) {
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}
int main()
{
    vector< Player > players{ {"amy", 100},{"david", 100},{"heraldo",50},{"aakansha", 75},{"aleksa", 150}, };
    auto comp = [](const Player& a, const Player& b) {
        if (a.score == b.score)
            return a.name < b.name;
        return a.score > b.score;
    };
    sort(players.begin(), players.end(), comp);
    for (int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}