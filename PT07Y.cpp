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
// Tuy nhiên, đổi cách lưu từ Map[N][N] sang vector, lưu cách đỉnh kề với nó thì tốc độ đã cải thiện đáng kể

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> Map[10001];
bool Mark[10001], Queue[10001];
int M, N, Count;

bool BFS(int n) {
    Count = 0;
    queue<int> Q;
    Q.push(n);
    int p, Size, x;
    while (!Q.empty()) {
        Count++;
        if (Count == N)
            return true;
        p = Q.front();
        Q.pop();
        Mark[p] = true;
        Size = Map[p].size();
        for (int i = 0; i < Size; i++) {
            x = Map[p][i];
            if (!Mark[x]) {
                if (Queue[x])
                    return false;
                Queue[x] = true;
                Q.push(x);
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
    for (int i = 1; i <= N; i++)
        Mark[i] = Queue[i] = false;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }
    if (BFS(1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

