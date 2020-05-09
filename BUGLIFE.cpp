#if 0

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

int N, I;
bool Map[2001][2001];
bool Mark[2001];
int Queue[2001];
bool Check;

void BFS(int n) {
    if (Mark[n])
        return;
    queue<Vec2> Q;
    Q.push(Vec2(n, 1));
    Vec2 p;
    int x, y;
    while (!Q.empty()) {
        p = Q.front();
        x = p.x;
        y = p.y;
        Q.pop();
        Mark[x] = true;
        for (int i = 1; i <= N; i++) {
            if (Map[x][i]) {
                if (Queue[i] == y) {
                    Check = true;
                    return;
                }
                Map[x][i] = Map[i][x] = false;
                Queue[i] = 3 - y;
                Q.push(Vec2(i, 3 - y));
            }
        }
    }
}

int main() {
    freopen ("Input.txt", "r", stdin);

    int Test, n, a, b;
    cin >> Test;
    for (int k = 1; k <= Test; k++) {
        cin >> N >> I;
        for (int i = 1; i <= N; i++) {
            Mark[i] = false;
            Queue[i] = 0;
            for (int j = 1; j <= N; j++)
                Map[i][j] = false;
        }
        for (int i = 1; i <= I; i++) {
            cin >> a >> b;
            Map[a][b] = Map[b][a] = true;
        }
        Check = false;
        for (int i = 1; i <= N; i++)
            BFS(i);
        cout << "Scenario #" << k << ':' << endl;
        if (Check)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }

    return 0;
}

#endif

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

int N, I;
vector<int> Map[2001];
bool Mark[2001];
int Queue[2001];
bool Check;

void BFS(int n) {
    if (Mark[n])
        return;
    queue<Vec2> Q;
    Q.push(Vec2(n, 1));
    Vec2 p;
    int x, y, k, Size;
    while (!Q.empty()) {
        p = Q.front();
        x = p.x;
        y = p.y;
        Q.pop();
        Mark[x] = true;
        Size = Map[x].size();
        for (int i = 0; i < Size; i++) {
            k = Map[x][i];
            if (!Mark[k]) {
                if (Queue[k] == y) {
                    Check = true;
                    return;
                }
                Queue[k] = 3 - y;
                Q.push(Vec2(k, 3 - y));
            }
        }
    }
}

int main() {
    int Test, n, a, b;
    cin >> Test;
    for (int k = 1; k <= Test; k++) {
        cin >> N >> I;
        for (int i = 1; i <= N; i++) {
            Mark[i] = false;
            Queue[i] = 0;
            Map[i].clear();
        }
        for (int i = 1; i <= I; i++) {
            cin >> a >> b;
            Map[a].push_back(b);
            Map[b].push_back(a);
        }
        Check = false;
        for (int i = 1; i <= N; i++)
            BFS(i);
        cout << "Scenario #" << k << ':' << endl;
        if (Check)
            cout << "Suspicious bugs found!" << endl;
        else
            cout << "No suspicious bugs found!" << endl;
    }

    return 0;
}
