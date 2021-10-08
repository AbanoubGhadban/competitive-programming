#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct Car
{
    int id;
    int arrival;
    int depart;

    inline bool operator<(const Car& other) {
        return id < other.id;
    }
};


int main() {
    int c;
    cin >> c;

    while (c--) {
        queue<Car> left, right;
        int ferry = 0;
        int n, t, m;
        string b;
        cin >> n >> t >> m;
        int id = 0;
        while (m--) {
            Car car;
            cin >> car.arrival >> b;
            car.id = id++;
            if (b == "left")
                left.push(car);
            else
                right.push(car);
        }

        queue<Car> *curB = &left, *nextB = &right; // left
        vector<Car> cars;
        int curT = 0;
        while (left.size() || right.size()) {
            while (ferry < n && curB->size() && curB->front().arrival <= curT) {
                curB->front().depart = curT + t;
                ferry++;
                cars.push_back(curB->front());
                curB->pop();
            }

            if (!ferry) {
                if (!nextB->size() || (curB->size() && curB->front().arrival <= nextB->front().arrival)) {
                    curT = curB->front().arrival;
                } else {
                    curT = max(curT, nextB->front().arrival) + t;
                    swap(curB, nextB);
                }
            } else {
                curT += t;
                ferry = 0;
                swap(curB, nextB);
            }
        }
        sort(cars.begin(), cars.end());

        for (vector<Car>::iterator it = cars.begin(); it != cars.end(); ++it) {
            cout << it->depart << "\n";
        }

        if (c)
            cout << "\n";
    }

    return 0;
}
