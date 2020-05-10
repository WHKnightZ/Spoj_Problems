#include <iostream>
#include <queue>

using namespace std;

struct Vec2 {
    Vec2() {}
    Vec2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int x, y;
};

struct Vec3 {
    Vec3() {}
    Vec3(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    int x, y, z;
};

Vec2 DRT[] = {Vec2(0, -1), Vec2(1, 0), Vec2(0, 1), Vec2(-1, 0)};

queue<Vec3> Queue;

int Max_X, Max_Y, Max_X1, Max_Y1, x, y;
char Map[20][20];
bool Mark[20][20];
Vec2 Dirty[11];
int Distance_Dirty[11][11];
int Map_Point_Dirty[20][20];
bool Mark_Dirty[11];
int Dirty_Count, Count;
bool Check, Ok;

bool (*Check_Inside[4])() = {[]{return y > 0;}, []{return x < Max_X1;}, []{return y < Max_Y1;}, []{return x > 0;}};

void BFS(int n) {
    if (!Check)
        return;
    int x2, y2;
    Vec3 p;
    Vec2 p2;
    Count = 0;
    x = Dirty[n].x;
    y = Dirty[n].y;
    Mark[y][x] = true;
    Queue.push(Vec3(x, y, 0));
    while (!Queue.empty()) {
        p = Queue.front();
        Queue.pop();
        x = p.x;
        y = p.y;
        if (Map[y][x] == '*') {
            Count++;
            if (Count > 1) {
                int m = Map_Point_Dirty[y][x];
                Distance_Dirty[m][n] = Distance_Dirty[n][m] = p.z;
                if (Count == Dirty_Count) {
                    return;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (Check_Inside[i]()) {
                x2 = x + DRT[i].x;
                y2 = y + DRT[i].y;
                if (!Mark[y2][x2] && Map[y2][x2] != 'x') {
                    Mark[y2][x2] = true;
                    Queue.push(Vec3(x2, y2, p.z + 1));
                }
            }
        }
    }
    Ok = false;
    Check = false;
}

int DFS(int n, int d) {
    if (d == Dirty_Count - 1) {
        return 0;
    }
    int m, k, Min = 99999;
    for (int i = 0; i < Dirty_Count; i++) {
        if (!Mark_Dirty[i]) {
            m = Distance_Dirty[n][i];
            if (m != 0) {
                Mark_Dirty[i] = true;
                k = m + TSP(i, d + 1);
                if (Min > k)
                    Min = k;
                Mark_Dirty[i] = false;
            }
        }
    }
    return Min;
}

int main() {
    int n, Start;
    char c;
    while (true) {
        cin >> Max_X >> Max_Y;
        if (Max_X == 0 || Max_Y == 0)
            return 0;
        Max_X1 = Max_X - 1;
        Max_Y1 = Max_Y - 1;
        Dirty_Count = 0;
        while(!Queue.empty())
            Queue.pop();
        for (int i = 0; i < Max_Y; i++) {
            for (int j = 0; j < Max_X; j++) {
                cin >> c;
                Map[i][j] = c;
                if (c == '*' || c == 'o') {
                    if (c == 'o') {
                        Map[i][j] = '*';
                        Start = Dirty_Count;
                    }
                    Map_Point_Dirty[i][j] = Dirty_Count;
                    Dirty[Dirty_Count] = Vec2(j, i);
                    Dirty_Count++;
                }
            }
            cin.ignore();
        }
        Ok = true;
        Check = true;
        for (int k = 0; k < Dirty_Count - 1; k++) {
            for (int i = 0; i < Max_Y; i++)
                for (int j = 0; j < Max_X; j++)
                    Mark[i][j] = false;
            while(!Queue.empty())
                Queue.pop();
            BFS(k);
        }
        if (Ok) {
            for (int i = 0; i < Dirty_Count; i++)
                Mark_Dirty[i] = false;
            Mark_Dirty[Start] = true;
            cout << DFS(Start, 0) << endl;
        } else
            cout << -1 << endl;
    }

    return 0;
}
