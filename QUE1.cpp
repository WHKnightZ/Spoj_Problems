#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    Person(int h, int t) {
        Height = h;
        Taller = t;
    }
    int Height;
    int Taller;
};

vector<Person> People;

bool Compare(Person &p1, Person &p2) {
    return p1.Height < p2.Height;
}

int Height[1000];
bool Mark[1000];
int Origin[1000];

int main() {
    int k, n, m, l, o;
    int Count;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> Count;
        for (int j = 0; j < Count; j++) {
            Mark[j] = false;
            cin >> Height[j];
        }
        for (int j = 0; j < Count; j++) {
            cin >> n;
            People.push_back(Person(Height[j], n));
        }
        sort(People.begin(), People.end(), Compare);
        for (int j = 0; j < Count; j++) {
            l = People[j].Taller + 1;
            m = 0;
            o = Mark[m] ? 0 : 1;
            while (o < l) {
                m++;
                if (!Mark[m])
                    o++;
            }
            Origin[m] = People[j].Height;
            Mark[m] = true;
        }
        for (int j = 0; j < Count; j++)
            cout << Origin[j] << " ";
        cout << endl;
        People.clear();
    }
    return 0;
}
