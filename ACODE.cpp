#include <iostream>

using namespace std;

#define MAX 5001

char Str[MAX];
int Length;

int Save[MAX];

int GetNum(char s0, char s1) {
    return (s0 - '0') * 10 + s1 - '0';
}

int Acode(int pos) {
    if (Save[pos] != -1)
        return Save[pos];
    
    char s0 = Str[pos];
    char s1 = Str[pos + 1];
    char s2 = Str[pos + 2];
    
    if (pos + 2 < Length) {
        if (s1 != '0') {
            if (s2 != '0' && GetNum(s0, s1) <= 26)
                return Save[pos] = Acode(pos + 1) + Acode(pos + 2);
            else
                return Save[pos] = Acode(pos + 1);
        } else {
            if (s2 != '0' && s0 <= '2')
                return Save[pos] = Acode(pos + 2);
            else
                return Save[pos] = 0;
        }
    }

    if (pos + 2 == Length) {
        return Save[pos] = (s1 != '0' ? 1 : 0) + (GetNum(s0, s1) <= 26 ? 1 : 0);
    }

    return Save[pos] = 1;
}

int main() {
    while (true) {
        cin >> Str;
        if (Str[0] == '0')
            break;
        Length = 0;
        while (Str[Length] != '\0') {
            Save[Length] = -1;
            Length++;
        }
        cout << Acode(0) << endl;
    }
    return 0;
}
