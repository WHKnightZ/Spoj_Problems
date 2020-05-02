#include <iostream>

using namespace std;

#define MAX 200000

long long Inv;

void Merge(int Array[], int l, int m, int r) {
    int *Temp = new int[r - l + 1];
    for (int i = l; i <= r; i++)
        Temp[i - l] = Array[i];
    int i = 0, j = m - l + 1, k = l;
    int nl = m - l, nr = r - l;
    while (i <= nl && j <= nr) {
        if (Temp[i] > Temp[j]) {
            Array[k++] = Temp[i++];
            Inv += nr - j + 1;
        } else {
            Array[k++] = Temp[j++];
        }
    }
    while (i <= nl)
        Array[k++] = Temp[i++];
    while (j <= nr)
        Array[k++] = Temp[j++];
    delete [] Temp;
}

void Merge_Sort(int Array[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        Merge_Sort(Array, l, m);
        Merge_Sort(Array, m + 1, r);
        Merge(Array, l, m, r);
    }
}

int main() {
    int Test, n;
    int Array[MAX];
    cin >> Test;
    for (int i = 0; i < Test; i++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> Array[i];
        Inv = 0;
        Merge_Sort(Array, 0, n - 1);
        cout << Inv << endl;
    }
    return 0;
}
