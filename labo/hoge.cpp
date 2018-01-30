//
// Created by Tatsuya Kitabatake on 2018/01/29.
//
#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> a {1, 3, 5, 6};
//    a = vector(a.begin(), a.begin() + 2);
    a.resize(2);
    for (int i:a) cout << i << " ";
};