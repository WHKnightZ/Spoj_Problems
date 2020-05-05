#include <iostream>
#include <vector>

using namespace std;

struct Cell {
    Cell(int _x, int _y, int _data) {
        x = _x;
        y = _y;
        data = _data;
    }
    int x, y, data;
};

int Map[8][8];

bool Row[8][9];
bool Column[8][9];
int Big[2][2][9];

vector<Cell> Backtrack;

char Text_Output[2][4] = {"NO", "YES"};

bool Is_Valid(int x, int y, int n) {
    if (Row[y][n])
        return false;
    if (Column[x][n])
        return false;
    if (Big[y / 4][x / 4][n] >= 2)
        return false;
    return true;
}

bool Solve() {
    int n, *pInt;
    Backtrack.clear();
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 9; j++)
            Row[i][j] = Column[i][j] = false;
    }
    for (int i = 1; i < 9; i++)
        Big[0][0][i] = Big[0][1][i] = Big[1][0][i] = Big[1][1][i] = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            n = Map[i][j];
            if (n != 0) {
                pInt = &Big[i / 4][j / 4][n];
                (*pInt)++;
                if (*pInt > 2 || Row[i][n] || Column[j][n])
                    return false;
                Row[i][n] = true;
                Column[j][n] = true;
            } else {
                Backtrack.push_back(Cell(j, i, 1));
            }
        }
    }
    int Current = 0;
    Cell *p;
    int Size = Backtrack.size();
    while (true) {
        p = &Backtrack[Current];
        while (!Is_Valid(p->x, p->y, p->data)) {
            p->data++;
            while (p->data == 9) {
                Current--;
                if (Current == -1)
                    return false;
                p = &Backtrack[Current];
                Row[p->y][p->data] = false;
                Column[p->x][p->data] = false;
                Big[p->y / 4][p->x / 4][p->data]--;
                p->data++;
            }
        }
        Row[p->y][p->data] = true;
        Column[p->x][p->data] = true;
        Big[p->y / 4][p->x / 4][p->data]++;
        Map[p->y][p->x] = p->data;
        Current++;
        if (Current == Size)
            break;
        Backtrack[Current].data = 1;
    }
    return true;
}

int main() {
    int Test, Value, n;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                cin >> Map[i][j];
        Value = Solve();
        cout << "Test case #" << k + 1 << ": " << Text_Output[Value] << endl;
        if (Value == 1) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++)
                    cout << Map[i][j] << ' ';
                cout << endl;
            }
        }

    }
    return 0;
}
