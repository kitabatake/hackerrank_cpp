#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

bool isPrimeNumber(int n) {
    float s = sqrt(n);
    for (int i = 2; i <= s; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

ull divide(ull n) {
    ull ret = 0;
    ull d = 2;
    while (!isPrimeNumber(n)) {
        if (isPrimeNumber(d) && n % d == 0) {
            n /= d;
            ret = max(d, ret);
        }
        d++;
    }
    ret = max(n, ret);
    return ret;
};

int main() {
    int T;
    cin >> T;
    ull n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << divide(n) << endl;
    }
}