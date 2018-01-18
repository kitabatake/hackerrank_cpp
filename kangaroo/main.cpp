// https://www.hackerrank.com/challenges/kangaroo/problem
#include <iostream>
#include <algorithm>

using namespace std;

class kangaroo {
public:
    int x;
    int v;
    void move() {
        x += v;
    }
    void print() {
        cout << "x:" << x  << ", v:" << v << endl;
    }
    bool operator==(kangaroo k1) {
        return x == k1.x;
    }
};


bool judge(kangaroo faster, kangaroo slower) {
    faster.print();
    slower.print();
    if (faster.x > slower.x) return false;

    while(faster.x <= slower.x) {
        if (faster == slower) return true;
        faster.move();
        slower.move();
    }
    return false;
}

int main () {
    int x1, x2, v1, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    kangaroo k1 = {x1, v1}, k2 = {x2, v2}, faster, slower;
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