// https://www.hackerrank.com/contests/projecteuler/challenges/euler002
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef unsigned long long ull;


ull calc(ull N) {
    if (N < 8) return 2;

    ull sum = 2;
    ull pp = 0;
    ull p = 2;
    ull current = 4 * p + pp;

    while (current <= N) {
        sum += current;
        pp = p;
        p = current;
        current = 4 * p + pp;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    ull N;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << calc(N) << endl;
    }
}