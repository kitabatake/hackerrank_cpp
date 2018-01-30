//
// Created by Tatsuya Kitabatake on 2018/01/20.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}