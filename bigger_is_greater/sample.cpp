//
// Created by Tatsuya Kitabatake on 2018/01/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a = "hoge";
    string b = a;
    a[1] = 'A';

    b += a[3];
    cout << a << endl << b << endl;
}