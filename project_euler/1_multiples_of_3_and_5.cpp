// https://www.hackerrank.com/contests/projecteuler/challenges/euler001
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long ull;

ull calc(ull n) {
    long n3 = (n - 1) / 3;
    ull sum3 =  3 * n3 * (n3 + 1) / 2;

    long n5 = (n - 1) / 5;
    ull sum5 = 5 * n5 * (n5 + 1) / 2;

    long n15 = (n - 1) / 15;
    ull sum15 = 15 * n15 * (n15 + 1) / 2;

    return sum3 + sum5 - sum15;
}

int main () {
    int T;
    cin >> T;

    ull n;
    for (int i = 0; i < T; i++) {
        cin >> n;
        cout << calc(n) << endl;
    }
}