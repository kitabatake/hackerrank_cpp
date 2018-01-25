#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

string S;

int main() {
    cin >> S;
    double sSqrt = sqrt(double(S.size()));
    int columns = ceil(sSqrt);
    int rows = floor(sSqrt);
    if (columns * rows < S.size()) rows++;

    vector<vector<char>> arranged(rows);
    for(int i = 0; i < S.size(); i++) {
        arranged[i / columns].push_back(S[i]);
    }

    for(int c = 0; c < columns; c++) {
        for (int r = 0; r < rows; r++) {
            if (c < arranged[r].size()) {
                cout << arranged[r][c];
            }
        }
        if (c != columns - 1) {
            cout << " ";
        }
    }
}

