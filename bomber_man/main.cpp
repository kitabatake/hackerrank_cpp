// https://www.hackerrank.com/challenges/bomber-man/problem
#include <iostream>
#include <vector>

using namespace std;

int R, C, N;

void outputState(vector<string> state) {
    for (string row: state) {
        cout << row << endl;
    }
}

bool isDetonate(vector<string> state, int r, int c) {
    if (state[r][c] == 'O') return true;

    vector<vector<int>> diffs {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    int cr, cc;
    for (vector<int> &diff: diffs) {
        cr = r + diff[0];
        cc = c + diff[1];
        if (cr < 0 || cr >= R || cc < 0 || cc >= C) continue;
        if (state[cr][cc] == 'O') {
            return true;
        }
    }
    return false;
}

vector<string> calcNextState(vector<string> state) {
    vector<string> nextState(R);
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            nextState[r] += isDetonate(state, r, c)? '.' : 'O';
        }
    }
    return nextState;
}


int main() {
    cin >> R >> C >> N;
    vector<string> initialState(R);
    for (int i = 0; i < R; i++) {
        cin >> initialState[i];
    }

    if (N == 1) {
        outputState(initialState);
    } else if(N % 2 == 0) {
        vector<string> evenState(R);
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) evenState[r] += 'O';
        outputState(evenState);
    } else if(N % 4 == 3) {
        outputState(calcNextState(initialState));
    } else if(N % 4 == 1) {
        outputState(calcNextState(calcNextState(initialState)));
    }
}





