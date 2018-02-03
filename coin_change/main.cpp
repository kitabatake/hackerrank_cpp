#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n ,m;
    cin >> n >> m;
    vector<int> cws(m);
    for (int i = 0; i < m; i++) cin >> cws[i];

    vector<vector<long>> memo(m + 1, vector<long>(n + 1));
    for (int cv = 1; cv <= m; cv++) {
        int cw = cws[cv - 1];
        for (int t = 0; t <= n; t++) {
            if (t < cw) {
                memo[cv][t] = memo[cv - 1][t];
            } else if(t == cw) {
                memo[cv][t] = memo[cv - 1][t] + 1;
            }
            else {
                memo[cv][t] = memo[cv - 1][t] + memo[cv][t - cw];
            }
        }
    }

//    for (vector<int> row: memo) {
//        for (int i: row) cout << i << " ";
//        cout << endl;
//    }

    cout << memo[m][n] << endl;
}