// https://www.hackerrank.com/challenges/candies/problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Child {
public:
    int index;
    int rating;
    int candyNum;
    vector<Child*> neighbors;
    Child(int index, int rating) {
        this->index = index;
        this->rating = rating;
    }
    void print() {
        cout << "i:" << index << ", r:" << rating << ", c:" << candyNum << endl;
    }
    void setCandyNum() {
        candyNum = 1;
        for (Child* neighbor: neighbors) {
            if (neighbor->candyNum > 0 && neighbor->rating < rating) {
                candyNum = max(neighbor->candyNum + 1, candyNum);
            }
        }
    }
};

int N;

int main() {
    cin >> N;
    vector<Child*> children(N);
    int scanRating;
    for (int i = 0; i < N; i++) {
        cin >> scanRating;
        children[i] = new Child(i, scanRating);
        if (i != 0) {
            children[i - 1]->neighbors.push_back(children[i]);
            children[i]->neighbors.push_back(children[i - 1]);
        }
    }

    sort(
            children.begin(),
            children.end(),
            [](const Child* c1, const Child* c2) { return c1->rating < c2->rating; }
    );

    long long ans = 0;
    for(Child*c: children) {
        c->setCandyNum();
        ans += c->candyNum;
    }
    cout << ans << endl;
}