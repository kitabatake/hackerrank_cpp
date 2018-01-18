// https://www.hackerrank.com/challenges/kangaroo/problem
#include <iostream>
#include <algorithm>

using namespace std;

struct kangaroo {
    int x;
    int v;
};

ostream &operator << (ostream &os, kangaroo const &r) {
    return os << r.x << ":" << r.v;
}


bool judge(kangaroo faster, kangaroo slower) {
    if (faster.x > slower.x) return false;

    while(faster.x <= slower.x) {
        if (faster.x == slower.x) return true;
        faster.x += faster.v;
        slower.x += slower.v;
    }
    return false;
}

int main () {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    struct kangaroo k1 = {x1, v1}, k2 = {x2, v2}, faster, slower;
    if (k1.v >= k2.v) {
        faster = k1;
        slower = k2;
    } else {
        faster = k2;
        slower = k1;
    }

    if (judge(faster, slower)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}