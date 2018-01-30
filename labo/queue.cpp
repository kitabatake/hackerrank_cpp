//
// Created by Tatsuya Kitabatake on 2018/01/20.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> que;
    que.push(3);
    que.push(2);
    que.push(1);

    while(!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }
}