#include <iostream>
#include <vector>

using namespace std;

int Map[100][100];
int Save[100][100];

int Max_X, Max_Y;

int Max3(int &x, int &y, int &z) {
    int Max = x;
    if (Max < y)
        Max = y;
    if (Max < z)
        Max = z;
    return Max;
}

int Get(int x, int y) {
    if (Save[y][x] != -1)
        return Save[y][x];
    if (y == Max_Y - 1)
        return Save[y][x] = Map[y][x];
    int a = (x - 1 >= 0 ? Get(x - 1, y + 1) : 0);
    int b = Get(x, y + 1);
    int c = (x + 1 < Max_X ? Get(x + 1, y + 1) : 0);
    return Save[y][x] = Map[y][x] + Max3(a, b, c);
}

int main() {
    int Test, n, Max, Tmp;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        cin >> Max_Y >> Max_X;
        for (int i = 0; i < Max_Y; i++) {
            for (int j = 0; j < Max_X; j++) {
                cin >> Map[i][j];
                Save[i][j] = -1;
            }
        }
        Max = Get(0, 0);
        for (int i = 1; i < Max_X; i++) {
            Tmp = Get(i, 0);
            if (Max < Tmp)
                Max = Tmp;
        }
        cout << Max << endl;
    }
    return 0;
}
