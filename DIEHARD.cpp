#include <iostream>

using namespace std;

#define MAX 1000

// AIR 0, WATER 1, FIRE 2

int Health_Inc[3] = {3, -5, -20};
int Armor_Inc[3] = {2, -10, 5};

int Cases[3][2] = {{1, 2}, {2, 0}, {0, 1}};

int Save[3][MAX][MAX];

int Die_Hard(int Current, int Health, int Armor) {
    int *p = &Save[Current][Health][Armor];
    if (*p != -1)
        return *p;
    int Health_New = Health + Health_Inc[Current];
    if (Health_New <= 0)
        return *p = 0;
    int Armor_New = Armor + Armor_Inc[Current];
    if (Armor_New <= 0)
        return *p = 0;
    int Case1 = Die_Hard(Cases[Current][0], Health_New, Armor_New);
    int Case2 = Die_Hard(Cases[Current][1], Health_New, Armor_New);
    return *p = ((Case1 > Case2 ? Case1 : Case2) + 1);
}

int main() {
    int Test;
    int Health, Armor;
    int Current;
    cin >> Test;
    for (int i = 0; i < Test; i++) {
        cin >> Health >> Armor;
        Current = 0;
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++) {
                Save[0][j][k] = Save[1][j][k] = Save[2][j][k] = -1;
            }
        cout << Die_Hard(Current, Health, Armor) << endl;
    }

    return 0;
}
