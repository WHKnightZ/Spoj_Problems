#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Queue[5050];
vector<int> List_Max;

int Current, Queue_Current, Queue_Max, Max_Current;

int Pqueue() {
    int Minute = 0;
    int Get;
    while (true) {
        Get = Queue[Queue_Current];
        if (Get != List_Max[Max_Current]) {
            Queue[Queue_Max] = Get;
            if (Current == Queue_Current)
                Current = Queue_Max;
            Queue_Max++;
        } else {
            Minute++;
            if (Current == Queue_Current)
                return Minute;
            Max_Current++;
        }
        Queue_Current++;
    }
}

int main() {
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        Max_Current = 0;
        Queue_Current = 0;
        cin >> n >> Current;
        Queue_Max = n;
        for (int j = 0; j < n; j++) {
            cin >> Queue[j];
            List_Max.push_back(Queue[j]);
        }
        sort(List_Max.begin(), List_Max.end(), greater<int>());
        cout << Pqueue() << endl;
        List_Max.clear();
    }
    return 0;
}
