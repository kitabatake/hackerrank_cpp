#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solveOne(vector<int> &a , int dest) {
    vector<int> adds{1, 3, 5};
    map<int, int>operations;
    for (int n: a) {
        int n1 = 0, n2 = 0, n5 = 0;
        while (n < dest) {
            if (dest - n >= 5) {
                n += 5;
                n5++;
            } else if (dest - n >= 2) {
                n += 2;
                n2++;
            } else {
                n += 1;
                n1++;
            }
        }
        operations[1] = max(operations[1], n1);
        operations[2] = max(operations[2], n2);
        operations[5] = max(operations[5], n5);
    }
    return operations[1] + operations[2] + operations[5];
}

int solve(vector<int> &a) {
    int max = *max_element(a.begin(), a.end());
    vector<int> dests {max, max + 1, max + 4};
    int ret;
    for (int i = 0; i < dests.size(); i++) {
        int counts = solveOne(a, dests[i]);
        if (i == 0) {
            ret = counts;
        } else {
            ret = min(counts, ret);
        }
    }
    return ret;
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        vector<int> a(N);
        for (int j = 0; j < N; j++) cin >> a[j];
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << solve(a) << endl;
    }
}