#if 0

#include <iostream>

using namespace std;

bool Map[10001][10001];
bool Mark[10001];
int M, N, Count;
bool Done;

void DFS(int n) {
    if (Done)
        return;
    for (int i = 1; i <= N; i++) {
        if (Map[n][i] && !Mark[i]) {
            Mark[i] = true;
            Count++;
            if (Count == N) {
                Done = true;
                return;
            }
            DFS(i);
        }
    }
}

int main() {
    int a, b;
    cin >> N >> M;
    if (M != N - 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        Mark[i] = false;
        for (int j = 1; j <= N; j++)
            Map[i][j] = false;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Map[b][a] = Map[a][b] = true;
    }
    Mark[1] = true;
    Count = 1;
    DFS(1);
    if (Done)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

#endif // 0

// Thử chuyển sang BFS cùng với việc check xem đồ thị có chu trình không nhưng tốc độ cũng chẳng cải thiện mấy

#include <iostream>
#include <queue>

using namespace std;

bool Map[10001][10001];
bool Mark[10001];
int M, N, Count;

bool BFS(int n) {
    Count = 0;
    queue<int> Q;
    Q.push(n);
    int p;
    while (!Q.empty()) {
        Count++;
        if (Count == N)
            return true;
        p = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++) {
            if (Map[p][i]) {
                if (Mark[i])
                    return false;
                Map[p][i] = Map[i][p] = false;
                Mark[i] = true;
                Q.push(i);
            }
        }
    }
    return false;
}

int main() {
    int a, b;
    cin >> N >> M;
    if (M != N - 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        Mark[i] = false;
        for (int j = 1; j <= N; j++)
            Map[i][j] = false;
    }
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        Map[b][a] = Map[a][b] = true;
    }
    if (BFS(1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

