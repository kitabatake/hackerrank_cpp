// https://www.hackerrank.com/challenges/between-two-sets/problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> void debug_vector (vector<T> v) {
    for (int i = 0, s = v.size(); i < s; i++) {
        cout << v[i];
        if (i < s - 1) cout << "\t"; else cout << endl;
    }
}

bool groupNumsIsAllFactor(int x, vector<int> group) {
    for(int i = 0; i < group.size(); i++) {
        if (x % group[i] != 0) {
            return false;
        }
    }
    return true;
}

bool xIsAllFactor(int x, vector<int> group) {
    for(int i = 0; i < group.size(); i++) {
        if (group[i] % x != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    int min = *max_element(a.begin(), a.end());
    int max = *min_element(b.begin(), b.end());
    int ans = 0;

    for (int i = min; i <= max; i++) {
        if (groupNumsIsAllFactor(i, a) && xIsAllFactor(i, b)) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

