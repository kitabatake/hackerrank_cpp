#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool dfs(int n, int k, int i, map<int, int> used, vector<int> &buffer) {
//    cout << "i:" << i << endl;
//    for (int b: buffer) cout << b << " ";
//    cout << endl;
    if (buffer.size() == n) return true;

    bool flag = false;
    vector<int> diffs { -k, k };
    for (int diff: diffs) {
        buffer.resize(i - 1);
        int x = i + diff;
//        if (i == 99) {
//            cout << "x is " << x << endl;
//            for (int hoge: buffer) cout << hoge << " ";
//            cout << endl;
//        }
        if (x >= 1 && x <= n && !used[x]) {
            used[x] = true;
            buffer.push_back(x);
            flag = dfs(n, k, i + 1, used, buffer);
            if (flag) break;
        }
    }
    return flag;
}

void printAnswer(int n, int k) {
    vector<int> ans;
    map<int, int> used;
    bool flag = dfs(n, k, 1, used, ans);
    if (flag){
        for (int x: ans) cout << x << " ";
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    int T, N, K;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        printAnswer(N, K);
    }
}