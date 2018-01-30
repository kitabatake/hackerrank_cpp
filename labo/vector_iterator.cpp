#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<int> a{1, 2, 3, 5};


    for (vector<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << endl;
    }

    for (vector<int>::iterator it = a.end() - 1; it != a.begin() - 1; it--) {
        cout << *it << endl;
    }
}