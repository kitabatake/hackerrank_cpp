#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int N, D;

vector<int> countsToSorted(vector<int> &counts) {
    vector<int> sorted;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < counts[i]; j++) sorted.push_back(i);
    }
    return sorted;
}

float median(vector<int> array) {
    if (D % 2 == 1) {
        return (float)array[D / 2];
    } else {
        return (float)(array[D / 2] + array[D / 2 - 1]) / 2;
    }
}

bool isNotify(int e, vector<int> &counts) {
    return (2 * median(countsToSorted(counts))) <= e;
}

int main() {
    cin >> N >> D;
    vector<int> counts(200);
    int e, ans = 0;
    int prev = -1;
    for (int i = 0; i < N; i++) {
        cin >> e;
        counts[e]++;
        if (i < D) continue;
        if (prev != -1) {
            counts[prev]--;
        }
        if (isNotify(e, counts)) ans++;
        prev = e;
    }
    cout << ans << endl;
}