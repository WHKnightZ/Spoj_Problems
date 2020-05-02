#include <iostream>

using namespace std;

#define MAX 1000000

unsigned long Save[MAX];

unsigned long Coins(unsigned long x) {
    unsigned long x0 = x / 2, x1 = x / 3, x2 = x / 4;
    if (x0 + x1 + x2 > x) {
        if (x0 < MAX) {
            if (Save[x0] != -1)
                x0 = Save[x0];
            else
                x0 = Save[x0] = Coins(x0);
        } else
            x0 = Coins(x0);

        if (x1 < MAX) {
            if (Save[x1] != -1)
                x1 = Save[x1];
            else
                x1 = Save[x1] = Coins(x1);
        } else
            x1 = Coins(x1);

        if (x2 < MAX) {
            if (Save[x2] != -1)
                x2 = Save[x2];
            else
                x2 = Save[x2] = Coins(x2);
        } else
            x2 = Coins(x2);
        return  x0 + x1 + x2;
    }
    return x;
}

int main() {
    unsigned long n;
    for (int i = 0; i < MAX; i++)
        Save[i] = -1;
    while (cin >> n) {
        cout << Coins(n) << endl;
    }
    return 0;
}
