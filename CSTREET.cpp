#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vec4 {
    Vec4() {}
    Vec4(int _x, int _y, int _z, bool _c) {
        x = _x;
        y = _y;
        z = _z;
        c = _c;
    }
    int x, y, z;
    bool c;

    bool operator < (const Vec4& v) const {
        return this->z < v.z;
    }
};

vector<Vec4> Array;
bool Mark[1001];

int main() {
    int Test, p, n, m;
    int Index, Count, Price;
    Vec4 *ptr;
    int a, b, t;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        Array.clear();
        cin >> p >> n >> m;
        for (int i = 0; i < n; i++)
            Mark[i] = false;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> t;
            Array.push_back(Vec4(a, b, t, false));
        }
        sort(Array.begin(), Array.end());
        Count = 1;
        ptr = &Array[0];
        Price = ptr->z;
        Mark[ptr->x] = Mark[ptr->y] = true;
        Index = 1;
        while (Index < m) {
            ptr = &Array[Index];
            if (!ptr->c && (Mark[ptr->x] ^ Mark[ptr->y])) {
                ptr->c = true;
                Count++;
                Mark[ptr->x] = Mark[ptr->y] = true;
                Price += ptr->z;
                if (Count == n - 1)
                    break;
                Index = 0;
            }
            Index++;
        }
        cout << Price * p << endl;
    }
    return 0;
}
