#include <iostream>

using namespace std;

int main() {
    long N, M, k, s;
    long Max = -1;
    cin >> N >> M;
    int Array[N];
    for (int i = 0; i < N; i++) {
        cin >> k;
        Array[i] = k;
        if (Max < k)
            Max = k;
    }
    long l = 0, h = 0, r = Max;
    while (l <= r) {
        int m = (l + r) / 2;
        s = 0;
        for (int i = 0; i < N; i++) {
            k = Array[i] - m;
            s += (k > 0 ? k : 0);
        }
        if (s > M) {
            l = m + 1;
            if (m > h)
                h = m;
        } else if (s < M) {
            r = m - 1;
        } else {
            h = m;
            break;
        }
    }
    cout << h;
    return 0;
}
