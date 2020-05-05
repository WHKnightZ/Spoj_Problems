#include <iostream>

using namespace std;

struct Vec2 {
    Vec2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int x, y;
};

Vec2 DRT[] = {Vec2(0, -1), Vec2(1, 0), Vec2(0, 1), Vec2(-1, 0)};

int Max_X, Max_Y;
char Map[40][40];
bool Mark[2][40][40];
bool Done;

void DFS(int x, int y, int life, int state) {
    if (Done)
        return;
    Mark[state][y][x] = true;
    bool Change_State = false;
    switch (Map[y][x]) {
    case 's':
        life--;
        break;
    case '@':
        if (state == 1) {
            Done = true;
            return;
        }
        break;
    case 'x':
        Change_State = true;
        state = 1;
        Mark[state][y][x] = true;
        break;
    }
    if (life >= 0)
        for (int i = 0; i < 4; i++) {
            int x2 = x + DRT[i].x;
            int y2 = y + DRT[i].y;
            if (x2 >= 0 && x2 < Max_X && y2 >= 0 && y2 < Max_Y && !Mark[state][y2][x2] && Map[y2][x2] != '#') {
                DFS(x2, y2, life, state);
            }
        }
    if (Change_State) {
        Mark[0][y][x] = Mark[1][y][x] = false;
    } else {
        Mark[state][y][x] = false;
    }
}

int main() {
    int Life;
    cin >> Max_X >> Max_Y >> Life;
    for (int i = 0; i < Max_Y; i++) {
        for (int j = 0; j < Max_X; j++) {
            cin >> Map[i][j];
            Mark[0][i][j] = Mark[1][i][j] = false;
        }
        cin.ignore();
    }
    Done = false;
    for (int i = 0; i < Max_Y; i++)
        for (int j = 0; j < Max_X; j++)
            if (Map[i][j] == '@')
                DFS(j, i, Life, 0);
    if (Done)
        cout << "SUCCESS";
    else
        cout << "IMPOSSIBLE";
    return 0;
}
