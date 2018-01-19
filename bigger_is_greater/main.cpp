// https://www.hackerrank.com/challenges/bigger-is-greater/problem
#include <iostream>
#include <vector>
using namespace std;

template<typename T> void debug_vector (vector<T> v) {
    for (int i = 0, s = v.size(); i < s; i++) {
        cout << v[i];
        if (i < s - 1) cout << "\t"; else cout << endl;
    }
}

int findGreaterIndex(string target, string s) {
    int i = 0;
    int ret = -1;
    for (char& c : s) {
        if (c > target[0]) {
            ret = i;
        }
        i++;
    }
    return ret;
}
string rearrangeTargetAndSecond(string target, int replaceIndex, string second) {
    string newSecond = second;
    newSecond[replaceIndex] = target[0];
    string ret = second.substr(replaceIndex, 1);
    for (int i = newSecond.size() - 1; i >= 0; i--) {
        ret += newSecond[i];
    }
    return ret;
}

string traverseFromBackward(string first, string second) {
    if (first.size() == 0) {
        return second;
    }
    string target = first.substr(first.size() - 1, 1);
    int greaterIndex = findGreaterIndex(target, second);
    if (greaterIndex == -1) {
        return traverseFromBackward(first.substr(0, first.size() - 1), target + second);
    } else {
        return first.substr(0, first.size() - 1) + rearrangeTargetAndSecond(target, greaterIndex, second);
    }
}

string rearrangeBiggerSmallest(string s) {
    if (s.size() < 2) {
        return s;
    }
    return traverseFromBackward(s.substr(0, s.size() - 1), s.substr(s.size() - 1, 1));
}

int N;
int main() {
    cin >> N;
    string s, rearranged;
    for (int i = 0; i < N; i++) {
        cin >> s;
        rearranged = rearrangeBiggerSmallest(s);
        if (s == rearranged) {
            cout << "no answer" << endl;
        } else {
            cout << rearranged << endl;
        }
    }
}
