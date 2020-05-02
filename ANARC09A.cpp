#include <iostream>

using namespace std;

int CountMissing(char s[], int n) {
    int Stack_Count = 0;
    int Count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{')
            Stack_Count++;
        else {
            if (Stack_Count > 0)
                Stack_Count--;
            else
                Count++;
        }
    }
    return Count / 2 + Count % 2 + Stack_Count / 2 + Stack_Count % 2;
}

int main() {
    int k = 1, n;
    char s[2001];
    while (true) {
        cin >> s;
        if (s[0] != '{' && s[0] != '}')
            break;
        n = 0;
        while (s[n] != '\0')
            n++;
        cout << k << '.' << ' ' << CountMissing(s, n) << endl;
        k++;
    }
    return 0;
}
