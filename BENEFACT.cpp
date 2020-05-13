#include <iostream>
#include <vector>
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

int N, Dest;
bool Mark[50001];
vector<Vec2> Edges[50001];

int BFS(int n) {
    for (int i = 1; i <= N; i++)
        Mark[i] = false;
    int Max = -1;
    Vec2 p, *ptr;
    int x, y, Size;
    queue<Vec2> Q;
    Q.push(Vec2(n, 0));
    Mark[n] = true;
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        x = p.x;
        y = p.y;
        if (Max < y) {
            Max = y;
            Dest = x;
        }
        Size = Edges[x].size();
        for (int i = 0; i < Size; i++) {
            ptr = &Edges[x][i];
            if (!Mark[ptr->x]) {
                Mark[ptr->x] = true;
                Q.push(Vec2(ptr->x, y + ptr->y));
            }
        }
    }
    return Max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Test, a, b, c;
    cin >> Test;
    for (int k = 0; k < Test; k++) {
        cin >> N;
        for (int i = 1; i < N; i++) {
            cin >> a >> b >> c;
            Edges[a].push_back(Vec2(b, c));
            Edges[b].push_back(Vec2(a, c));
        }
        BFS(1);
        cout << BFS(Dest) << endl;
        for (int i = 1; i <= N; i++)
            Edges[i].clear();
    }

    return 0;
}
