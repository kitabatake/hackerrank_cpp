#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, m, scan;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> scan;
        a[scan]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> scan;
        b[scan]++;
    }

    for (auto x: b) {
        if (x.second != a[x.first]) {
            cout << x.first << " ";
        }
    }
}