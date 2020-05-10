#include <iostream>
#include <queue>

using namespace std;

int main() {
    int Test, n, m;
    scanf("%d", &Test);
    for (int k = 0; k < Test; k++) {
        priority_queue<int> ql;
        priority_queue<int, vector<int>, greater<int>> qr;
        while (true) {
            scanf("%d", &n);
            if (n > 0) {
                if (ql.size() > 0)
                    m = ql.top();
                else
                    m = 999999;
                if (n > m)
                    qr.push(n);
                else
                    ql.push(n);
                if (ql.size() < qr.size()) {
                    m = qr.top();
                    qr.pop();
                    ql.push(m);
                } else if (ql.size() > qr.size() + 1) {
                    m = ql.top();
                    ql.pop();
                    qr.push(m);
                }
            } else if (n == -1) {
                if (ql.size() > 0) {
                    m = ql.top();
                    printf("%d\n", m);
                    ql.pop();
                    if (ql.size() == qr.size() - 1) {
                        m = qr.top();
                        qr.pop();
                        ql.push(m);
                    }
                }
            } else
                break;
        }
    }
    return 0;
}
