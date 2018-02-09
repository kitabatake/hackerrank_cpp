#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,  min = 0, max = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool consecutive = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            max++;
            if (consecutive) {
                consecutive = false;
            } else {
                consecutive = true;
                min++;
            }
        } else {
            consecutive = false;
        }
    }
    cout << min << " " << max << endl;
}