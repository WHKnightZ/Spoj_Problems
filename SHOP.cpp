#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vec2 {
    Vec2() {}
    Vec2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int x, y;
};

Vec2 DRT[] = {Vec2(0, -1), Vec2(1, 0), Vec2(0, 1), Vec2(-1, 0)};

struct Vec3 {
    Vec3() {}
    Vec3(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    int x, y, z;

    bool operator < (const Vec3& v) const {
        return this->z < v.z;
    }
};

vector<Vec3> Queue;
vector<Vec3>::iterator it;

int Max_X, Max_Y, Max_X1, Max_Y1, x, y;
char Map[25][25];
bool Mark[25][25], In_Queue[25][25];

bool (*Check_Inside[4])() = {[]{return y > 0;}, []{return x < Max_X1;}, []{return y < Max_Y1;}, []{return x > 0;}};

Vec3 * Get(int x, int y) {
    int Size = Queue.size();
    for (int i = 0; i < Size; i++)
        if (Queue[i].x == x && Queue[i].y == y)
            return &Queue[i];
    return NULL;
}

int Shop() {
    Vec3 p, p2, *ptr;
    int x2, y2;
    char c;
    int f;
    Queue.clear();
    Queue.push_back(Vec3(x, y, 0));
    while (!Queue.empty()) {
        p = Queue.front();
        Queue.erase(Queue.begin());
        x = p.x;
        y = p.y;
        if (Map[y][x] == 'D')
            return p.z;
        Mark[y][x] = true;
        for (int i = 0; i < 4; i++) {
            if (Check_Inside[i]()) {
                x2 = x + DRT[i].x;
                y2 = y + DRT[i].y;
                if (!Mark[y2][x2]) {
                    c = Map[y2][x2];
                    if (c != 'X') {
                        if (c == 'D')
                            c = '0';
                        f = p.z + (c - '0');
                        if (!In_Queue[y2][x2]) {
                            In_Queue[y2][x2] = true;
                            p2 = Vec3(x2, y2, f);
                            it = lower_bound(Queue.begin(), Queue.end(), p2);
                            Queue.insert(it, p2);
                        } else {
                            ptr = Get(x2, y2);
                            if (ptr->z > f)
                                ptr->z = f;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    char n;
    while (true) {
        cin >> Max_X >> Max_Y;
        if (Max_X == 0 || Max_Y == 0)
            break;
        Max_X1 = Max_X - 1;
        Max_Y1 = Max_Y - 1;
        for (int i = 0; i < Max_Y; i++) {
            for (int j = 0; j < Max_X; j++) {
                Mark[i][j] = In_Queue[i][j] = false;
                cin >> n;
                Map[i][j] = n;
                if (n == 'S') {
                    x = j;
                    y = i;
                }
            }
            cin.ignore();
        }
        cout << Shop() << endl;
    }
    return 0;
}
