#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    m[11] = 3;
    m[1] = 5;
    m[3] = 1;

    m[4]++;

    cout << m[2] << endl;

    for(auto x: m) {
        cout << x.first << ":" << x.second << endl;
    }
}