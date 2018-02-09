#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    string s;
    for (int i = 0; i< q; i++) {
        cin >> s;
        int len = s.size();
        if (len >= 7 && s.substr(0, 5) == "hydro" && s.substr(len - 2, 2) == "ic") {
            cout << "non-metal acid" << endl;
        } else if(s.substr(len - 2, 2) == "ic") {
            cout << "polyatomic acid" << endl;
        } else {
            cout << "not an acid" << endl;
        }
    }
}