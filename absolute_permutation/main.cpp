#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

void printAnswer(int n, int k) {
    if (k == 0) {
        for (int i = 0; i < n; i++) cout << i + 1 << " ";
    } else if (n % (2 * k) != 0) {
        cout << -1;
    } else {
        for (int i = 0; i < n / (2 * k); i++) {
            int base = i * 2 * k;
            for (int j = 1; j <= k; j++) cout << base + k + j << " ";
            for (int j = 1; j <= k; j++) cout << base + j << " ";
        }
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