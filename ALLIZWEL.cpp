#include <iostream>

using namespace std;

#define MAX 100

struct Vec2 {
    Vec2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int x, y;
};

Vec2 DRT[] = {Vec2(0, -1), Vec2(1, -1), Vec2(1, 0), Vec2(1, 1), Vec2(0, 1), Vec2(-1, 1), Vec2(-1, 0), Vec2(-1, -1)};
char DEG[] = "ALLIZZWELL";

char Map[MAX][MAX];
bool Mark[MAX][MAX];
int Max = 9;
bool Done;
int Max_X, Max_Y;

bool Check(int x, int y, int Drt, int Deg) {
    if (x < 0 || y < 0 || x == Max_X || y == Max_Y)
        return false;
    if (Mark[y][x])
        return false;
    return (Map[y][x] == DEG[Deg]);
}

void DFS(int x, int y, int Deg) {
    if (Done)
        return;
    Mark[y][x] = true;
    for (int i = 0; i < 8; i++) {
        int x2 = x + DRT[i].x;
        int y2 = y + DRT[i].y;
        int Deg2 = Deg + 1;
        if (Check(x2, y2, i, Deg2)) {
            if (Deg2 == Max) {
                Done = true;
                return;
            }
            DFS(x2, y2, Deg2);
        }
    }
    Mark[y][x] = false;
}

int main() {
    int Test;
    char c;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        cin >> Max_Y >> Max_X;
        for (int i = 0; i < Max_Y; i++) {
            for (int j = 0; j < Max_X; j++) {
                cin >> Map[i][j];
                Mark[i][j] = false;
            }
            cin.ignore();
        }
        Done = false;
        for (int i = 0; i < Max_Y; i++) {
            for (int j = 0; j < Max_X; j++) {
                if (Map[i][j] == 'A')
                    DFS(j, i, 0);
            }
        }
        if (Done)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
