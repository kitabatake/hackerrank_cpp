// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;

class Player {
public:
    int score;
    int rank;
    Player(int score) {
        this->score = score;
    }
    void print() {
        cout << "score:" << score << ", rank:" << rank << endl;
    }
};

void setPlayersRank(vector<Player*> players) {
    int currentRank = 1;
    for (int i = 0;i < N; i++) {
        Player* p = players[i];
        if (i != 0) {
            if (p->score < players[i-1]->score) {
                currentRank++;
            }
        }
        p->rank = currentRank;
    }
}

int calcRank(int score, vector<Player*>::iterator& it, vector<Player*>& players) {
    Player *p;
    for (; it != players.begin() - 1; it--) {
        p = *it;
        if (score < p->score) {
            return p->rank + 1;
        } else if(score == p->score) {
            return p->rank;
        }
    }
    return 1;
}

int main() {
    cin >> N;
    vector<Player*> players(N);
    int inScore;
    for (int i = 0; i < N; i++) {
        cin >> inScore;
        players[i] = new Player(inScore);
    }
    setPlayersRank(players);

    cin >> M;
    vector<Player*>::iterator it = players.end() - 1;
    for (int i = 0; i < M; i++) {
        cin >> inScore;
        cout << calcRank(inScore, it, players) << endl;
    }
}

