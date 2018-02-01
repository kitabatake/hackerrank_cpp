#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int N, D;

float countsToMedian(vector<int> &counts) {
//    for (int c: counts) cout << c << " ";
//    cout << endl;

    int totalCount = 0;
    int prev = -1;
    for (int i = 0; i < 201; i++) {
        totalCount += counts[i];
        if (totalCount > (float)D / 2) {
            if (D % 2 == 1) {
                return (float)i;
            } else {
                if (totalCount - counts[i] == D / 2 - 1){
//                    cout << "hoge: "<< i << " + " << prev << ". " << totalCount << ". i is" << i <<  endl;
                    return (float)(i + prev) / 2;
                } else {
                    return (float)(i * 2) / 2;
                }
            }
        }
        if (counts[i] != 0) prev = i;
    }
    return -1;
}

bool isNotify(int e, vector<int> &counts) {
    float median = countsToMedian(counts);
//    cout << median << endl;
    return (2 * median) <= e;
}

int main() {
    cin >> N >> D;
    vector<int> expenditures(N);
    for (int i = 0; i < N; i++) cin >> expenditures[i];

    int ans = 0;
    vector<int> counts(201);
    for (int i = 0; i < D; i++) counts[expenditures[i]]++;
    for (int i = D; i < N; i++) {
        if (isNotify(expenditures[i], counts)) ans++;
        counts[expenditures[i]]++;
        counts[expenditures[i - D]]--;
    }
    cout << ans << endl;
}