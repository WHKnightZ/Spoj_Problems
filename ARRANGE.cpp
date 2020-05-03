#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> Array;
    int Test, n, m;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        Array.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> m;
            if (m == 1)
                cout << m << ' ';
            else
                Array.push_back(m);
        }
        sort(Array.begin(), Array.end(), greater<int>());
        if (Array.size() == 2 && Array[0] == 3 && Array[1] == 2)
            cout << 2 << ' ' << 3 << endl;
        else {
            for (int i : Array)
                cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}
