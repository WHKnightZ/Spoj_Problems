#include <iostream>

using namespace std;

#define MAX 30

struct Struct {
    Struct() {}
    Struct(int _Max, int _Deg, int _Sum) {
        Max = _Max;
        Deg = _Deg;
        Sum = _Sum;
    }
    int Max, Deg, Sum;
};

int Array[MAX];
int k, n;

Struct Save[MAX][MAX];

Struct Dumb(int l, int r) {
    if (Save[l][r].Deg != -1)
        return Save[l][r];
    if (l == r)
        return Save[l][r] = Struct(Array[l], 0, 0);
    Struct SL = Dumb(l + 1, r);
    Struct SR = Dumb(l, r - 1);
    int L = Array[l] - SL.Max;
    int R = Array[r] - SR.Max;
    int D = 1 - SL.Deg;
    if ((D == 1 && L > R) || (D == 0 && L < R))
        return Save[l][r] = Struct(L, D, SL.Sum + D * Array[l]);
    else
        return Save[l][r] = Struct(R, D, SR.Sum + D * Array[r]);
}

Struct Smart(int l, int r) {
    if (Save[l][r].Deg != -1)
        return Save[l][r];
    if (l == r)
        return Save[l][r] = Struct(Array[l], 0, 0);
    Struct SL = Smart(l + 1, r);
    Struct SR = Smart(l, r - 1);
    int L = Array[l] - SL.Max;
    int R = Array[r] - SR.Max;
    int D = 1 - SL.Deg;
    if (L > R)
        return Save[l][r] = Struct(L, D, SL.Sum + D * Array[l]);
    else
        return Save[l][r] = Struct(R, D, SR.Sum + D * Array[r]);
}

int main() {
    int D, S;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> Array[j];

        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                Save[j][k].Deg = -1;
        D = Dumb(0, n - 1).Sum;

        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++)
                Save[j][k].Deg = -1;
        S = Smart(0, n - 1).Sum;

        cout << D << ' ' << S << endl;
    }
    return 0;
}
