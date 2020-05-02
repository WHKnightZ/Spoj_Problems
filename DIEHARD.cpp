#if 0

Sau khi chuyển trạng thái từ Air->Water(Fire), ở đây còn xét cả trường hợp
chuyển tiếp sang Fire(Water), thực ra chỉ cần xét chuyển sang Air là đủ do
    Air cả Health và Armor đều tăng nên sẽ viết lại xuống dưới

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

#endif

#include <iostream>

using namespace std;

#define MAX 1000

#define HEALTH_AIR 3
#define ARMOR_AIR 2
#define HEALTH_WATER -5
#define ARMOR_WATER -10
#define HEALTH_FIRE -20
#define ARMOR_FIRE 5

int Save[MAX][MAX];

int Die_Hard(int Health, int Armor) {
    int *p = &Save[Health][Armor];
    if (*p != -1)
        return *p;
    int Health_Water = Health + HEALTH_WATER;
    int Armor_Water = Armor + ARMOR_WATER;
    int Health_Fire = Health + HEALTH_FIRE;
    int Armor_Fire = Armor + ARMOR_FIRE;
    int Case1 = ((Health_Water > 0 && Armor_Water > 0) ? Die_Hard(Health_Water + HEALTH_AIR, Armor_Water + ARMOR_AIR) + 2 : 0);
    int Case2 = ((Health_Fire > 0 && Armor_Fire > 0) ? Die_Hard(Health_Fire + HEALTH_AIR, Armor_Fire + ARMOR_AIR) + 2 : 0);
    return *p = (Case1 > Case2 ? Case1 : Case2);
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
            for (int k = 0; k < MAX; k++)
                Save[j][k] = -1;
        Health += HEALTH_AIR;
        Armor += ARMOR_AIR;
        cout << Die_Hard(Health, Armor) + 1 << endl;
    }

    return 0;
}
