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
    for (int i = 0; i < N; i++) {
        Mark[i] = false;
        for (int j = 0; j < N; j++)
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
