#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int MAX_INT = 99999999;

struct Vec2 {
    Vec2() {}
    Vec2(int _x, int _t) {
        x = _x;
        t = _t;
    }
    int x, t;

    bool operator<(const Vec2 &v) const {
        return this->t < v.t;
    }
};

vector<Vec2> Queue;
vector<Vec2>::iterator it;

int Map[101][101];
bool Mark[101];
bool In_Queue[101];
int Distance[101];
int Count, Start, Time, Edge;

Vec2 *Get(int x) {
    int Size = Queue.size();
    for (int i = 0; i < Size; i++)
        if (Queue[i].x == x)
            return &Queue[i];
    return NULL;
}

void Dijkstra(int x) {
    Vec2 p, p2, *ptr;
    int x2, d;
    Queue.clear();
    Queue.push_back(Vec2(x, 0));
    while (!Queue.empty()) {
        p = Queue.front();
        Queue.erase(Queue.begin());
        x = p.x;
        Distance[x] = p.t;
        Mark[x] = true;
        for (int i = 1; i <= Count; i++) {
            d = Map[i][x];
            if (!Mark[i] && d < MAX_INT) {
                d += p.t;
                if (In_Queue[i]) {
                    ptr = Get(i);
                    if (ptr->t > d)
                        ptr->t = d;
                } else {
                    In_Queue[i] = true;
                    p2 = Vec2(i, d);
                    it = lower_bound(Queue.begin(), Queue.end(), p2);
                    Queue.insert(it, p2);
                }
            }
        }
    }
}

int main() {
    int a, b, c;
    cin >> Count >> Start >> Time >> Edge;
    for (int i = 1; i <= Count; i++) {
        Mark[i] = In_Queue[i] = false;
        Distance[i] = MAX_INT;
        for (int j = 1; j <= Count; j++) {
            Map[i][j] = MAX_INT;
        }
    }
    for (int i = 0; i < Edge; i++) {
        cin >> a >> b >> c;
        Map[a][b] = c;
    }
    Dijkstra(Start);
    int C = 0;
    for (int i = 1; i <= Count; i++)
        if (Distance[i] <= Time)
            C++;
    cout << C;
    return 0;
}
