#include <iostream>
#include <vector>

using namespace std;

struct Vec2 {
    Vec2() {}
    Vec2(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int x, y;
};

int main() {
    char First;
    string Needle, Hay;
    int NeedleLength, HayLength;
    vector<Vec2> Save;
    vector<Vec2>::iterator it;
    int Count, Last;
    while(cin >> NeedleLength) {
        cin >> Needle >> Hay;
        First = Needle[0];
        HayLength = Hay.size();
        Count = 0;
        Last = HayLength - NeedleLength;
        if (HayLength >= NeedleLength) {
            for (int i = 0; i < HayLength; i++) {
                it = Save.begin();
                while (it != Save.end()) {
                    if (Needle[it->y] == Hay[i]) {
                        it->y++;
                        if (it->y == NeedleLength) {
                            cout << it->x << endl;
                            it = Save.erase(it);
                        } else
                            it++;
                    } else {
                        it = Save.erase(it);
                    }
                }
                if (Hay[i] == First && i <= Last) {
                    Save.push_back(Vec2(i, 1));
                }
            }
        }
        if (Count == 0)
            cout << endl;
    }

    return 0;
}
