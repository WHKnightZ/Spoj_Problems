#include <iostream>

using namespace std;

#define MAX 1000

int Stack[MAX];
int Stack_Size;

char Output_Text[][4] = {"no", "yes"};

int main() {
    int Array[MAX];
    int n;
    int Check;
    int Current, Index;

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> Array[i];
        Stack_Size = 0;
        Check = 1;
        Current = 1;
        Index = 0;
        while (Current < n) {
            if (Stack[Stack_Size - 1] == Current) {
                Stack_Size--;
                Current++;
            } else if (Array[Index] > Current) {
                if (Stack_Size > 0 && Array[Index] > Stack[Stack_Size - 1]) {
                    Check = 0;
                    break;
                }
                Stack[Stack_Size] = Array[Index];
                Stack_Size++;
                Index++;
            } else {
                Current++;
                Index++;
            }
        }
        cout << Output_Text[Check] << endl;
    }
    return 0;
}
