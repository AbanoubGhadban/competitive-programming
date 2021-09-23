#include <iostream>

using namespace std;
#define ll long long

#define UP 0
#define LEFT 1
#define BOTTOM 2
#define RIGHT 3

int main() {
    ll sz, p;
    while (cin >> sz >> p, sz) {
        ll l = sz*sz;
        ll cur = 1, curx = sz/2 + 1, cury = sz/2 + 1;
        ll dir = UP, step = 0;
        
        while (cur != p) {
            if (dir == UP || dir == BOTTOM) {
                ++step;
            }
            step = min(step, p - cur);

            if (dir == UP) {
                cury += step;
                dir = LEFT;
            } else if (dir == LEFT) {
                curx -= step;
                dir = BOTTOM;
            } else if (dir == BOTTOM) {
                cury -= step;
                dir = RIGHT;
            } else { // right
                curx += step;
                dir = UP;
            }
            cur += step;
        }

        cout << "Line = " << cury << ", column = " << curx << "." << "\n";
    }
}
