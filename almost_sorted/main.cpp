#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool canReverse(vector<int> &a, vector<int> &s, vector<int> &diffs) {
    int prevDiffIndex = -1;
    int prevValue;
    for (int d: diffs) {
        if (prevDiffIndex == -1) {
            prevDiffIndex = d;
            prevValue = a[d];
            continue;
        }

        if (d != prevDiffIndex + 1) {
            // diffの中間の要素がたまたまソート前後で一致しているケースは除く
            if (d - prevDiffIndex != 2 || a[d - 1] != s[d - 1]) {
                return false;
            }
        }
        if (a[d] > prevValue) {
            return false;
        }

        prevDiffIndex = d;
        prevValue = a[d];
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];
    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    vector<int> diffs;
    for (int i = 0; i < n; i++) {
        if (original[i] != sorted[i]) {
            diffs.push_back(i);
        }
    }

    if (diffs.empty()) {

    } else if (diffs.size() == 2) {
        int d1 = diffs[0], d2 = diffs[1];
        if (original[d1] == sorted[d2] && original[d2] == sorted[d1]) {
            cout << "yes" << endl;
            cout << "swap " << d1 + 1 << " " << d2 + 1 << endl;
        }
    } else if (diffs.size() > 2 && canReverse(original, sorted, diffs)) {
        cout << "yes" << endl;
        cout << "reverse " << diffs.front() + 1 << " " << diffs.back() + 1 << endl;

    } else {
        cout << "no" << endl;
    }
}