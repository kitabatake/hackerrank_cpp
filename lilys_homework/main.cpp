#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;

class Element {
public:
    int index;
    int value;
    Element(int index, int value) {
        this->index = index;
        this->value = value;
    }
    void print() {
        cout << "i:" << index << ", v:" << value << endl;
    }
};

int countSwap(vector<int> array, vector<Element*> &sortedPosition, map<int, Element*> &valueElement) {
    int ans = 0, tmp;
    for (int i = 0; i < N; i++) {
        Element* e = sortedPosition[i];
        if (array[i] == e->value) continue;
        tmp = array[i];
        array[i] = e->value;
        array[e->index] = tmp;
        valueElement[tmp]->index = e->index;
        ans++;
    }
    return ans;
}

void initPositions(map<int, int> &originalPosition, vector<int> &sorted, vector<Element*> &sortedPosition, map<int, Element*> &valueElement) {
    for (int i = 0; i < N; i++) {
        sortedPosition[i] = new Element(originalPosition[sorted[i]], sorted[i]);
        valueElement[sorted[i]] = sortedPosition[i];
    }
}


int main() {
    cin >> N;
    vector<int> array(N);
    map<int, int> originalPosition;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        array[i] = n;
        originalPosition[n] = i;
    }

    vector<int> sorted = array;
    vector<Element*> sortedPosition(N);
    map<int, Element*> valueElement;

    sort(sorted.begin(), sorted.end());
    initPositions(originalPosition, sorted, sortedPosition, valueElement);
    int ans = countSwap(array, sortedPosition, valueElement);

    sort(sorted.begin(), sorted.end(), greater<int>());
    initPositions(originalPosition, sorted, sortedPosition, valueElement);
    ans = min(ans, countSwap(array, sortedPosition, valueElement));
    cout << ans << endl;
}