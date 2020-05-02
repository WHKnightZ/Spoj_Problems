#include <iostream>

using namespace std;

#define MAX 10
#define MAX_DIRECTION 8

struct Vec2 {
    int x, y;
};

Vec2 Direction[] = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};
//Vec2 Direction[] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

char Txt_Reach[2][29] = {" square can not be reached.", " squares can not be reached."};

bool Board[MAX][MAX];
int x, y;

int Step_Direction[100];
int Step;
int Max_Cell, Count_Cell;
int Max;

bool Check_Can_Move(int &x, int &y) {
    if (x < 0 || y < 0 || x >= MAX || y >= MAX)
        return false;
    return Board[y][x];
}

int Count_Cant_Reach() {
    int x2, y2;
    int *pInt;
    Vec2 *pVec2;
    Step = 0;
    Step_Direction[0] = 0;
    Count_Cell = 1;
    Max = Count_Cell;
    Board[y][x] = false;
    while (true) {
        pInt = &Step_Direction[Step];
        pVec2 = &Direction[*pInt];
        x2 = x + pVec2->x;
        y2 = y + pVec2->y;
        if (Check_Can_Move(x2, y2)) {
            Count_Cell++;
            if (Count_Cell == Max_Cell)
                return 0;
            if (Max < Count_Cell)
                Max = Count_Cell;
            x = x2;
            y = y2;
            Board[y][x] = false;
            Step++;
            Step_Direction[Step] = 0;
        } else {
            (*pInt)++;
            while (*pInt == MAX_DIRECTION) {
                Board[y][x] = true;
                Step--;
                if (Step == -1)
                    return Max_Cell - Max;
                pInt = &Step_Direction[Step];
                pVec2 = &Direction[*pInt];
                x -= pVec2->x;
                y -= pVec2->y;
                (*pInt)++;
                Count_Cell--;
            }
        }
    }
}

int main() {
    int k, n, s, c = 0;
    bool Is_Init;
    while (true) {
        c++;
        // Import Board
        Max_Cell = 0;
        Is_Init = false;
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++) {
            cin >> n >> s;
            for (int j = 0; j < n; j++)
                Board[i][j] = false;
            s += n;
            for (int j = n; j < s; j++) {
                if (!Is_Init) {
                    x = j;
                    y = i;
                    Is_Init = true;
                }
                Board[i][j] = true;
                Max_Cell++;
            }
            for (int j = s; j < MAX; j++)
                Board[i][j] = false;
        }
        for (int i = k; i < MAX; i++) {
            for (int j = 0; j < MAX; j++)
                Board[i][j] = false;
        }

        // Process
        n = Count_Cant_Reach();
        cout << "Case " << c << ", " << n << Txt_Reach[n == 1 ? 0 : 1] << endl;

    }
    return 0;
}
